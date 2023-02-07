class AgeException(Exception):
    pass
def CheckAge(age):
    if age<=18:
        raise AgeException()
    print("You Are Welcome")
try:
    CheckAge(int(input("Enter Age:\n")))
except AgeException as e:
    print("You Are Not Allowed!!") 