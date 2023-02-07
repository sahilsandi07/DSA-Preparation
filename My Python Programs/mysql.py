from tkinter import *
import tkinter.messagebox as m
import mysql.connector 

def click():
    con=mysql.connector.connect(host='localhost',user='root',passwd='root',database='studenttable')
    cur=con.cursor()
    
    r=e1.get()
    n=e2.get()
    a=e3.get()
    m=e4.get()

    sql="insert into studentinfo values (%s,%s,%s,%s)"
    vals = (r,n,a,m)

    cur.execute(sql,vals)
    con.commit()
    con.close()



root=Tk()
root.title("Students Info")
root.geometry("300x300")

l1=Label(root,text="Roll Number")
l1.grid(row=0,column=0)
e1=Entry(root)
e1.grid(row=0,column=1)

l2=Label(root,text="Name")
l2.grid(row=1,column=0)
e2=Entry(root)
e2.grid(row=1,column=1)

l3=Label(root,text="Address")
l3.grid(row=2,column=0)
e3=Entry(root)
e3.grid(row=2,column=1)

l4=Label(root,text="Marks")
l4.grid(row=3,column=0)
e4=Entry(root)
e4.grid(row=3,column=1)

b1=Button(root,text="Submit",command=click)
b1.grid()


root.mainloop()