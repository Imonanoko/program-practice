import random
class Contestant:
    def __init__(self,human='',computer=''):
        self.human=human
        self.computer=computer
        self.computerchoice=''
        self.humanchoice=''
        self.humanscore=0
        self.computerscore=0
    def __str__(self):
        return (str(self.computer)+' choice '+str(self.computerchoice))
class Human(Contestant):
    def choice(self):
        x=['paper','scissors','rock']
        while True:
            self.humanchoice=input(self.human+',enter your choice:').lower()
            if self.humanchoice in x:
                break
        return self.humanchoice
    def score(self):
        self.humanscore+=1
    def getscore(self):
        return self.humanscore
class Computer(Contestant):
    def choice(self):
       self.computerchoice=random.choice(['paper','scissors','rock'])
       return self.computerchoice
    def score(self):
        self.computerscore+=1
    def getscore(self):
        return self.computerscore

        
human=input('Enter name of human:')
computer=input("Enter name of computer:")
H=Human(human,computer)
C=Computer(human,computer)
while C.getscore()<2 and H.getscore()<2:
    x=C.choice()
    y=H.choice()
    if x=='paper':
        if y=='paper':
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
        elif y=='scissors':
            H.score()
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
        else:
            C.score()
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
    elif x=='scissors':
        if y=='scissors':
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
        elif y=='rock':
            H.score()
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
        else:
            C.score()
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
    else:
        if y=='rock':
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
        elif y=='paper':
            H.score()
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
        else:
            C.score()
            print(computer,'chooses',x)
            print(human,':',H.getscore(),computer,':',C.getscore(),'\n')
x1=human.upper()
x2=computer.upper()
if  H.getscore()==2:
    print(x1,'WIN')
elif C.getscore()==2:
    print(x2,'WIN')













        
            



