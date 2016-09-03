from PIL import ImageGrab
import turtle
screenHeight = 1080
screenWidth = 1920
skip = 10
screenArea = (screenHeight*screenWidth)/(skip*skip)
totalColor = red = green = blue = 0

screen = ImageGrab.grab()
for y in range(0, screenHeight, skip):
    for x in range(0, screenWidth, skip):
        color = screen.getpixel((x, y))
        red += color[0]
        green += color[1]
        blue += color[2]
averageColor = str(red/screenArea) + ", " + str(green/screenArea) +", " + str(blue/screenArea)
def visualizeColor():

    turtle.colormode(255)
    turtle.penup()
    turtle.setx(-50)
    turtle.sety(45)
    turtle.pendown()
    turtle.setup(100,100)
    turtle.begin_fill()
    turtle.right(90)
    turtle.forward(91)
    turtle.left(90)
    turtle.forward(91)
    turtle.left(90)
    turtle.forward(91)
    turtle.color(red/screenArea, green/screenArea, blue/screenArea)
    turtle.end_fill()
    turtle.done()
visualizeColor()