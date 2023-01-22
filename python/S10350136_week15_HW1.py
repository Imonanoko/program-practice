from tkinter import *
def change():
    if x['text']=='HELLO':
        x['text']='GOODBYE'
    else:
        x['text']='HELLO'
window=Tk()
window.title('Button')
x=Button(window,text='HELLO',fg='blue',command=change)
x.grid(padx=100,pady=15)
window.mainloop()
