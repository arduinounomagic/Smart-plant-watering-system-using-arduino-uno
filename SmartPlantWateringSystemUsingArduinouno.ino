/*
*Smart Plant Watering System main module
*SmartPlantWateringSystemUsingArduinouno.ino    create on: 28/10/2018
*Copyright (C) 2007 Free Software Foundation, Inc. <arduinounomagic@gmail.com>
*
*For more detail please visit:https://www.arduinounomagic.com/2018/10/smart-plant-watering-system-using.html
*
*for more projects please visit://www.arduinounomagic.com
*/

#define WATERPUMP 13 //pump connected to pin 13
#define SENSOR  8 //soil sensor digital pin connected to pin 8
#define LDR  A0//light dependent resistor is connected to A0
#define PORTNUMBER  9600 // opens serial port, sets data rate to 9600 bps

void setup()
{
   Serial.begin(PORTNUMBER); 
   pinMode(WATERPUMP,OUTPUT); //Set pin 13 as OUTPUT pin
   pinMode(SENSOR,INPUT); //Set pin 8 as input pin, to receive data from Soil moisture sensor.
   pinMode(LDR,INPUT);
   digitalWrite(WATERPUMP,LOW);//pump should be off initally

}

void loop() 
{ 
  
  int val = digitalRead(SENSOR); //stores the value received from Soil moisture sensor in variable val 
  int LDRValue=analogRead(LDR);//stores the value received from LDR in variable LDRValue 
  
   if(LDRValue <= 400)
  {
    // if its dark then doesn't matter whether moisture is low or high, pump should not be off
     Serial.print("its dark, so pump will off. LDR value is: ");
     Serial.println(LDRValue);//Print LDR value
     digitalWrite(WATERPUMP,HIGH);//pump will off
     return;   
  }

  if( val == HIGH)
  {
      
     Serial.print("its not dark and moisture is high so pump should turn on, LDR value is: ");
     Serial.println(LDRValue);//print LDR value
     Serial.print("\n moisture value is: ");
     Serial.println(val);//print soil moisture sensor value
     digitalWrite(WATERPUMP,LOW); //pump goes on
  }
  else
  {
      Serial.print("its not dark and moisture is low so pump will off, LDR value is: ");
      Serial.println(LDRValue);//print LDR value
      digitalWrite(WATERPUMP,HIGH);//and pump goes on 
  }
  delay(400); //Wait for few second and then continue the loop.

}
