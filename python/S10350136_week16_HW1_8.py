from tkinter import *
L=['Atlantic','Pacific','Indian','Dasher','Arctic','Antarctic']
window=Tk()
window.title('Oceans')
x=StringVar()
x.set(tuple(L))
yscroll=Scrollbar(window,orient=VERTICAL)
yscroll.grid(row=0,column=1,rowspan=4,padx=(0,100),pady=15,sticky=NS)
y=Listbox(window,listvariable=x,width=14,height=4,yscrollcommand=yscroll.set)
y.grid(row=0,column=0,rowspan=4,padx=(100,0),pady=15)
yscroll['command']=y.yview
window.mainloop()
