/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
int redPin = 11;
int greenPin = 13;
int bluePin = 12;
String incoming;
int input;
int red = 0;
int green = 0;
int blue = 0;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.setTimeout(100);

}

// the loop routine runs over and over again forever:
void loop() {

// read the input on analog pin 0:
  // print out the value you read:
  //Serial.println("Hello World");
  //analogWrite(redPin, 0);
  //analogWrite(greenPin, 255);
  //analogWrite(bluePin, 255);
   //Serial.println("LOL");
   /*for(int i = 0; i < 3; i++)
   {
     incoming = Serial.readStringUntil(',');
     if(i == 0)
     {
       red = incoming;
     }
     else if(i == 1)
     {
       green = incoming;
     }
     else
     {
       blue = incoming;
     }
   }*/
   
//   input = strtok_r(incoming, ",");


if(Serial.available() > 0)
{
//int lol = Serial.read() - '0';

//Serial.println(lol);
    //Serial.println("Reading Red");
    red = Serial.parseInt();
   // Serial.println(red);
   // Serial.println("Reading Green");
    green = Serial.parseInt();
   // Serial.println(green);
   // Serial.println("Reading Blue");
    blue = Serial.parseInt();
   // Serial.println(blue);
   
   /*incoming = Serial.readString();
   const char * inputString = incoming.c_str();
   //if(incoming.charAt(0)== 'r')
   if(incoming.endsWith("r"))
   {
     //const char * inputString = incoming.c_str();
     //incoming = incoming.c_str();
     red = atoi(inputString);
     //Serial.println(redPin);
    // analogWrite(redPin, red);
    // delay(500);
    // analogWrite(redPin, 0);
   }
   else if(incoming.endsWith("g"))
   {
     green = atoi(inputString);
     //green < 130 ? analogWrite(greenPin,130);
    // analogWrite(greenPin, 128);
    // delay(500);
    // analogWrite(greenPin, 0);
   }
   else if(incoming.endsWith("b"))
   {
     blue = atoi(inputString);
l     
     //analogWrite(bluePin, 128);
     //delay(500);
    //analogWrite(bluePin, 0);
     //Serial.println(blue);
   }
   */
}
   setColor(red, green, blue);
   //delay(100);
}

void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue); 
}
