class circle:
    def __init__(self,r):
        self.radius=r
    def area(self):
        return(3.14 * self.radius * self.radius)
    def circum(self):
        return(2* 3.14 * self.radius) 
t = circle(int(input("Enter Radius Of The Circle: ")))
t.area()
t.circum()
print("Area Is:",t.area())
print("Circumference Is:",t.circum())