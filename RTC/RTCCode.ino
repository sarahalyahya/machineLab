#include "RTClib.h"

RTC_DS1307 rtc;

//Use these Global Variables in your code
int currentTimeHours;
int currentTimeMinutes;
int currentTimeSeconds;

void setup () {
  //Power for the RTC
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
  digitalWrite(A3,HIGH);
  digitalWrite(A2,LOW);
  Serial.begin(57600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. 
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    
    // One-time local time adjustment
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
 
  }

 
}

void loop () {
    //Re-assigning variables every second
    DateTime now = rtc.now();
    currentTimeHours = now.hour(); 
    currentTimeMinutes = now.minute();
    currentTimeSeconds = now.second(); 
  
//For testing purposes
//     Serial.print(currentTimeHours);
//     Serial.print(":");
//     Serial.print(currentTimeMinutes);
//     Serial.print(":");
//     Serial.print(currentTimeSeconds);
//     Serial.println(); 

    delay(1000);

    
      
    
}
