from tkinter import *
import tkinter.messagebox as m

def click():
    str="Your Selection Is:"
    if i1.get()==1:
        str+="CASH"        
    if i1.get()==2:
        str+="CARD"    
    
    l1['text']=str



root=Tk()
root.title("RadioButton")
root.geometry("300x300")


l=Label(root,text="Please Enter Your Choice")
l.grid(row=0,column=1)

i1=IntVar()
c1=Radiobutton(root,text="CASH",value=1,variable=i1)
c1.grid(row=1,column=1)


c2=Radiobutton(root,text="CARD",value=2,variable=i1)
c2.grid(row=2,column=1)


l1=Label(root,text="")
l1.grid(row=5,column=0)

b1=Button(root,text="show",command=click)
b1.grid(row=4,column=1)




root.mainloop()