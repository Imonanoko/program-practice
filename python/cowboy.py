file=open('cowboy.txt','w')
file.write(("{0:<20s}{1:<10s}\n".format("Item","Price($)")))
file.write(("{0:<20s}{1:<10s}\n".format("Colt Peacemaker",'12.20')))
file.write(("{0:<20s}{1:<10s}\n".format("Holster",'2.00')))
file.write(("{0:<20s}{1:<10s}\n".format("Levi Strauss jeans",'1.35')))
file.write(("{0:<20s}{1:<10s}\n".format("Saddle",'40')))
file.write(("{0:<20s}{1:<10s}\n".format("Stetson",'10.00')))
file.close
file=open('cowboy.txt','r')
print(file.read())



