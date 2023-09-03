#include <TinyGPS++.h>
#include <TinyGPSPlus.h>

#include <SoftwareSerial.h>

SoftwareSerial gpsmodul(4,3);
TinyGPSPlus gps;

void setup() {
  Serial.begin(9600);
  gpsmodul.begin(9600); 

}

void loop() {
  while(gpsmodul.available()>0)
  {
    if(gps.encode(gpsmodul.read()))
    {
      if(gps.speed.isValid())
      {
        Serial.print("hiz:");
        Serial.print  (gps.speed.kmph());
        Serial.println(" km/h");
      }

    }
  }
  

}
