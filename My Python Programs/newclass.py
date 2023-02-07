class Rect:
    def __init__(self,l,w):
        self.length=l
        self.width=w
    def area(self):
        return(self.length*self.width)
    def peri(self):
        return(2*(self.width+self.length))
t = Rect(20,30)
t.area()
t.peri()
print("Area Is:",t.area())
print("Perimeter Is:",t.peri())
