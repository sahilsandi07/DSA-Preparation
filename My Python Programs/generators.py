def fib_num(nums):
    x=0
    y=1
    for i in range(nums):
        x=y
        y=x+y
        yield x

def square(nums):
    for i in nums:
        yield i**2

for i in square(fib_num(int(input("Enter Any Number:\n")))):
    print(i)



