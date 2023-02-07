#take Elements OF First Matrix

print("Enter MAtrix Elements Of First Matrix\n")
m1=[]
for i in range(3):
    m1.append([])
    for j in range(3):
        m1[i].append(int(input()))


#take Elements OF Second Matrix
print("Enter MAtrix Elements Of Second Matrix\n")
m2=[]
for i in range(3):
    m2.append([])
    for j in range(3):
        m2[i].append(int(input()))

#add both matrices

m3=[]
for i in range(3):
    m3.append([])
    for j in range(3):
        m3[i].append(m1[i][j]+m2[i][j])
print("Matrix Addition is:\n",m3)



