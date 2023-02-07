def SmartDiv(func):
    def num(x,y):
        if x==0 or y==0:
            print("Zero Not Allowed!!")
        else :
            if x>y:            
                func(x,y)
            else:
                func(y,x)
    return num
    
@SmartDiv
def Div(a,b):
    print(a/b)
    

Div(10,0)
Div(10,5)
Div(5,10)