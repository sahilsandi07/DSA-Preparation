from tkinter import *
import tkinter.messagebox as m

def click():
    str="Your Selection Is:"
    if i1.get()==1:
        str+="C/C++"        
    if i2.get()==1:
        str+="Python"    
    if i3.get()==1:
        str+="JAVA"
    l1['text']=str



root=Tk()
root.title("CheckButton")
root.geometry("300x300")


l=Label(root,text="Please Enter Your Choice")
l.grid(row=0,column=1)

i1=IntVar()
c1=Checkbutton(root,text="c/c++",onvalue=1,offvalue=0,variable=i1)
c1.grid(row=1,column=1)

i2=IntVar()
c2=Checkbutton(root,text="Python",onvalue=1,offvalue=0,variable=i2)
c2.grid(row=2,column=1)

i3=IntVar()
c3=Checkbutton(root,text="JAVA",onvalue=1,offvalue=0,variable=i3)
c3.grid(row=3,column=1)

l1=Label(root,text="")
l1.grid(row=5,column=0)

b1=Button(root,text="show",command=click)
b1.grid(row=4,column=1)




root.mainloop()