radius=[2,3,4,5,6,7]

def CircleArea(r):
    return 3.142*r*r

area=list(map(CircleArea,radius))

print("The List Of Area Of Circle is:",area)