from turtle import *

S = Screen()
etch = Turtle()
S.tracer(4, 0)
etch.hideturtle()
etch.circle(20)
etch.penup()
etch.forward(100)
etch.pendown()
etch.circle(20)
etch.penup()
etch.right(90)
etch.forward(50)
etch.pendown()
etch.forward(20)
etch.right(90)
etch.forward(100)
etch.right(90)
etch.forward(20)
etch.penup()
while True:
	waitExit = input()
	exit()