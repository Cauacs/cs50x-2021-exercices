from cs50 import get_string

credit = get_string("Number: ")
def main():

    if len(credit) != 13 and len(credit) != 15 and len(credit) != 16:
        print("INVALID")
        return 0

    num = int(credit)

    soma1 = 0
    soma2 = 0

    while num > 0:
        op1 = int(num % 10)
        num = int(num / 10)
        soma1 = int(soma1 + op1)

        op2 = int(num % 10)
        num = int(num / 10)
        op2 = int(op2 * 2)
        op3 = int(op2 % 10)
        op4 = int(op2 / 10)
        soma2 = int(soma2 + op3 + op4)


    total = soma1 + soma2
    
    
    if(total % 10 !=0):
        print("INVALID")
        return 0

    x = int(credit)

    while x > 100:
        x = int(x/10)

    if x == 51 or x == 52 or x == 53 or x == 54 or x == 55:
        print("Mastercard")
    elif x == 34 or x == 37:
        print("AMEX")
    elif x / 10 == 4:
        print("Visa")
    else:
        print("INVALID")
        
        
main()