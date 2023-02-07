def fact(n):
    if n==1:
        return 1
    n=n*fact(n-1)
    return n
f=fact(int(input("Enter Number to Find Factorial: \n")))
print("Factorial is: ",f)