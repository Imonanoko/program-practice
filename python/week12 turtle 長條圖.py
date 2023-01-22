import turtle
height=[753,172,70]
def main():
    t=turtle.Turtle()
    t.hideturtle()
    for i in range(3):
        drawFilledRectangle(t,-200+76*i,0,76,height[i]/4,"black",'light blue')
    displayText(t)
def drawFilledRectangle(t,x,y,w,h,colorP='black',colorF='white'):
    t.pencolor(colorP)
    t.fillcolor(colorF)
    t.up()
    t.goto(x,y)
    t.down()
    t.begin_fill()
    t.goto(x+w,y)
    t.goto(x+w,y+h)
    t.goto(x,y+h)
    t.goto(x,y)
    t.end_fill()
def displayText(t):
    language=['Public','Private','Other']
    t.pencolor('blue')
    t.up()
    for i in range(3):
        t.goto(-162+(76*i),height[i]/4)
        t.write(str(height[i]),align='center',font=('Arial',10,'normal'))
        t.goto(-162+(76*i),0)
        t.write(language[i],align='center',font=('Arial',10,'normal'))
        t.goto(-200,-25)
        t.write('Type of high school attended by fall 2013 College freshmen',font=('Arial',10,'normal'))
main()

