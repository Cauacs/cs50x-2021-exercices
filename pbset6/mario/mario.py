from cs50 import get_int

n = -5

while n < 0 or n > 8:
    n = get_int("Height: ")

for a in range(n):
    for b in range(1, n-a):
        print(" ", end="")
    for c in range(a + 1):
        print("#", end="")
    print("  ", end="")
    for d in range(a + 1):
        print("#", end="")
    print("")