class Rect:
    def __init__(self,len,wid):
        self.length=len
        self.width=wid
    def area(self):
        print(self.length*self.width)
    def peri(self):
        print(2*(self.width+self.length))
t = Rect(20,30)
t.area()
t.peri()
