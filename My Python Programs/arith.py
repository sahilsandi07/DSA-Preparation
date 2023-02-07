from tkinter import *
import tkinter.messagebox as m

def check():
    fnum=int(e1.get())
    snum=int(e2.get())
    x=fnum+snum
    m.showinfo("Addition Is",x)
def check1():
    fnum=int(e1.get())
    snum=int(e2.get())
    x=fnum-snum
    m.showinfo("Subtraction Is",x)
def check2():
    fnum=int(e1.get())
    snum=int(e2.get())
    x=fnum*snum
    m.showinfo("Multiplication Is",x)
def check3():
    fnum=int(e1.get())
    snum=int(e2.get())
    x=fnum/snum
    m.showinfo("Division Is",x)


root=Tk()
root.title("Mini Calculator")
root.geometry("300x300")


root.columnconfigure(0,weight=1)
root.columnconfigure(1,weight=3)




l=Label(root,text="First Number")
l.grid(row=0,column=0)
e1=Entry(root)
e1.grid(row=0,column=1)


p=Label(root,text="Second Number")
p.grid(row=1,column=0)
e2=Entry(root)
e2.grid(row=1,column=1)

b=Button(root,text="+",command=check)
b.grid(row=2,column=0)

b1=Button(root,text="-",command=check1)
b1.grid(row=2,column=1)

b2=Button(root,text="*",command=check2)
b2.grid(row=3,column=0)

b3=Button(root,text="/",command=check3)
b3.grid(row=3,column=1)



root.mainloop()