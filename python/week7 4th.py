file=open('cowboy.txt','a+')
file.write(("{0:<20s}{1:<10s}\n".format("Winchester Rifle",'20.50')))
file.close
file=open('cowboy.txt','r')
print(file.read())
