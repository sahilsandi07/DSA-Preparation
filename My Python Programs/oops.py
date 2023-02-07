class Shape:
    def __init__(self,d1,d2):
        self.dimension1=d1
        self.dimension2=d2 
    def area(self):
        print("ERROR!!!!!")

class Rect(Shape):
    def __init__(self,d1,d2):
        super().__init__(d1,d2)
    def area(self):
        return(self.dimension1*self.dimension2)

class Triangle(Shape):
    def __init__(self,d1,d2):
        super().__init__(d1,d2)
    def area(self):
        return(0.5*self.dimension1*self.dimension2)

t = Rect(int(input("Enter Dimension 1:\n")),int(input("Enter Dimension 2:\n")))
print("Area Of Rectangle is: ",t.area())
t = Triangle(int(input("Enter Dimension 1:\n")),int(input("Enter Dimension 2:\n")))
print("Area Of Triangle is: ",t.area())
