from tkinter import *
def function():
    y=x.get()
    if entName['fg']=='blue':
        entName['fg']='red'
        entName['textvariable']=''
        x.set(y)
    else:
        entName['fg']='blue'
        entName['textvariable']=''
        x.set(y)
window= Tk()
window.title('Entry widget')
x=StringVar()
x.set('')
entName=Entry(window,fg='blue',textvariable=x)
entName.grid(row=0,column=0,padx=100,pady=15)
button=Button(window,text='push',command=function)
button.grid(row=0,column=1,padx=100,pady=15)
window.mainloop()
