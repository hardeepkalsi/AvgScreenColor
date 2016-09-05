import serial
from PIL import ImageGrab
import turtle
import time
screenHeight = 1080
screenWidth = 1920
skip = 10
screenArea = (screenHeight*screenWidth)/(skip*skip)
totalColor = red = green = blue = 0

serialport = "COM5"
ser = serial.Serial(serialport, 9600)
while(1):
    screen = ImageGrab.grab()
    for y in range(0, screenHeight, skip):
        for x in range(0, screenWidth, skip):
            color = screen.getpixel((x, y))
            red += color[0]
            green += color[1]
            blue += color[2]
    red = red/screenArea
    green = green/screenArea
    blue = blue/screenArea

    averageColor = str(red) + "," + str(green) +"," + str(blue)
    print averageColor
    #ser = serial.Serial('/dev/tty.usbserial', 9600)

    #while(1):
     #   val=ser.readline().decode( 'ascii' ).strip()
      #  print (val)
    #while(1):
    if(blue < 128):
        blue = 0
    if(green < 128):
        green = 0
    if(red < 128):
        red = 0
    ser.write(str(red)+"r")
    #print str(red)
    time.sleep(2)
    ser.write(str(green)+"g")
    time.sleep(2)
    ser.write(str(blue)+"b")
    time.sleep(2)
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
   # visualizeColor()