l=[1,2,3,4,5,6,6,7,8]
def square(x):
    return x*x


def even(x):
    return x%2==0


def add(x,y):
    return x+y

l1=list(map(square,l))
print("Your New List is:",l1)


l2=list( map ( square , filter ( even , l )))
print("Your Second New List is:",l2)


from functools import reduce


l3=reduce(add, list( map ( square , filter ( even , l ))))
print("Your Third New List is:",l3)