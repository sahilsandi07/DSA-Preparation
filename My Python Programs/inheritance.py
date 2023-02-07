class person:
    def __init__(self,a,n):
        self.age=a
        self.name=n
    def printperson(self):
        print("Age is:",self.age)
        print("Name is:",self.name)

class student(person):
    def __init__(self,a,n,m):
        super().__init__(a,n)
        self.marks=m
    def printstudent(self):
        super().printperson()
        print("Marks Are:",self.marks)
t=student(int(input("Enter Your Age:\n")),input("Enter Your Name:\n"),int(input("Enter Your Marks:\n")))
t.printstudent()
