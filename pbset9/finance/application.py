import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    ## Pass to html = stock name, sum of num_shares, price from lookup * num shares, total cash price +  cash in db

    stocks = db.execute("SELECT stock_name, SUM(num_shares) FROM history WHERE user_id = ? GROUP BY stock_name HAVING (SUM(num_shares)) > 0", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    tcash = cash[0]['cash']

    for i in range(len(stocks)):
        lk = lookup(stocks[i]['stock_name'])
        stocks[i].update({'price' : lk['price']})
        stocks[i].update({'total' : (lk['price'] * stocks[i]["SUM(num_shares)"])})
        tcash = tcash + lk['price'] * stocks[i]["SUM(num_shares)"]

    return render_template("index.html", stocks=stocks, cash=cash, tcash=tcash)



@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "POST":
        stock = lookup(request.form.get("symbol"))
        if stock == None:
            return apology("Stock not found")

        if isinstance(int(request.form.get("shares")), int) == False:
            return apology("Number of shares must be a integer")

        money = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        if money[0]['cash'] < (stock['price'] * float(request.form.get("shares"))):
            return apology("Not enough money")

        #Atualizar o historico

        date = db.execute("SELECT date('now')")


        db.execute("INSERT INTO history (user_id, stock_name, num_shares, price, time) VALUES (?, ?, ?, ?, ?)", session["user_id"], stock["symbol"], request.form.get("shares"), stock["price"], date[0]["date('now')"])

        moneyf = money[0]['cash'] - (stock["price"] * float(request.form.get("shares")))

        db.execute("UPDATE users SET cash = ? WHERE id = ?", moneyf, session["user_id"])

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    stocks = db.execute("SELECT stock_name, num_shares, price, time FROM history WHERE user_id = ?", session["user_id"])

    return render_template("history.html", stocks=stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():

    if request.method == ("POST"):
        if not request.form.get("symbol"):
            return apology("must provide a symbol")


        elif lookup(request.form.get("symbol")) == None:
            return apology("Stock not found")

        else:
            result = lookup(request.form.get("symbol"))
            return render_template("quoted.html",result=result)

    else:
        return render_template("quote.html")



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":


        if not request.form.get("username"):
            return apology("must insert username", 403)

        elif not request.form.get("password"):
            return apology("must insert password", 403)

        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("passwords dont match", 403)

        name = request.form.get("username")

        rows = db.execute("SELECT username FROM users WHERE username = ?", name)

        if len(rows) != 0:
            return apology("Username already registred")

        hashedpw = generate_password_hash(request.form.get("password"))

        db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", name, hashedpw)

        apology("Registration completed", 403)

        return redirect("/login")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():

    if request.method == "POST":
        stocks = db.execute("SELECT stock_name, SUM(num_shares) FROM history WHERE user_id = ? AND stock_name = ?", session["user_id"], request.form.get("symbol"))
        if not stocks:
            return apology("Stock invalid")

        elif not int(request.form.get("shares")):
            return apology("Number of shares invalid")

        elif int(request.form.get("shares")) < 1 or int(request.form.get("shares")) > stocks[0]["SUM(num_shares)"]:
            return apology("Number of shares invalid")

        stocklk = lookup(request.form.get("symbol"))

        date = db.execute("SELECT date('now')")

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])

        cashf = cash[0]['cash'] + (stocklk['price'] * int(request.form.get("shares")))

        db.execute("INSERT INTO history (user_id, stock_name, num_shares, price, time) VALUES (?, ?, ?, ?, ?)", session["user_id"], stocks[0]["stock_name"], (int(request.form.get("shares")) * -1), stocklk['price'], date[0]["date('now')"])

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cashf, session["user_id"])
        return redirect("/")

    else:
        stocks_names = db.execute("SELECT stock_name FROM history WHERE user_id = ? GROUP BY stock_name HAVING (SUM(num_shares)) > 0", session["user_id"])
        return render_template("sell.html", stocks_names=stocks_names)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
