from tkinter import *
import tkinter.messagebox as m

def check():
    uname = e1.get()
    passw =e2.get()
    if uname=="xyz" and passw == "xyz":
        m.showinfo("Succcess" , "Successfully Login")
    else:
        m.showerror("Error","Wrong Uname/Passwd")


root=Tk()
root.title("Log In")
root.geometry("300x300")


root.columnconfigure(0,weight=1)
root.columnconfigure(1,weight=3)


l=Label(root,text="Username")
l.grid(row=0,column=0)
e1=Entry(root)
e1.grid(row=0,column=1)


p=Label(root,text="Password")
p.grid(row=1,column=0)
e2=Entry(root)
e2.grid(row=1,column=1)

b=Button(root,text="Log In",command=check)
b.grid(row=2,column=1)



root.mainloop()