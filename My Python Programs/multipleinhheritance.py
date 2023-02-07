class Box:
    def __init__(self,l,w):
        self.length=l
        self.width=w  
    def area(self):
        return(self.length*self.width)

class BoxVolume(Box):
    def __init__(self,l,w,h):
        super().__init__(l,w)
        self.height=h
    def volume(self):
        return(self.length*self.width*self.height)

class BoxColour(BoxVolume):
    def __init__(self,l,w,h,c):
        super().__init__(l,w,h)
        self.colour=c
    def printdata(self):
        print("Area Is:",super().area())
        print("Volume Is:",super().volume())
        print("Colour Is:",self.colour)

        
    
t = BoxColour(int(input("Enter Length:\n")),int(input("Enter Width:\n")),int(input("Enter Height:\n")),input("Enter Box Colour:\n"))
t.printdata()