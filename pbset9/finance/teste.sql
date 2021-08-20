CREATE TABLE history(
id INTEGER,
user_id INTEGER,
stock_name TEXT NOT NULL,
num_shares INTEGER,
price NUMERIC NOT NULL,
time TEXT NOT NULL,
PRIMARY KEY(id),
FOREIGN KEY(user_id) REFERENCES users(id)
);

SELECT stock_name, SUM(price), SUM(num_shares)
FROM history
WHERE user_id = 1
GROUP BY stock_name
HAVING (price) > 0;