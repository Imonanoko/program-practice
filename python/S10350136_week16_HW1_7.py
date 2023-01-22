from tkinter import *
L=['Cupid','Comet','Dancer','Dasher','Donder','Prancer','Vixen']
window=Tk()
window.title('Reindeer')
x=StringVar()
x.set(tuple(L))
yscroll=Scrollbar(window,orient=VERTICAL)
yscroll.grid(row=0,column=1,rowspan=5,padx=(0,100),pady=15,sticky=NS)
y=Listbox(window,listvariable=x,width=14,height=5,yscrollcommand=yscroll.set)
y.grid(row=0,column=0,rowspan=5,padx=(100,0),pady=15)
yscroll['command']=y.yview
window.mainloop()
