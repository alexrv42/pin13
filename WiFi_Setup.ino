#include <SoftwareSerial.h>

const byte rxPin = 2; //Wire this to Tx Pin of ESP8266
const byte txPin = 3; // Wire this to Rx Pin of ESP8266




// We'll use a software serial interface to connect to ESP8266
SoftwareSerial ESP8266 (rxPin, txPin);

void setup() {
  Serial.begin(38400);
  ESP8266.begin(38400); // Change this to the baudrate used by ESP8266
  delay(1000); // Let the module self-initialize

}

void loop() {
     if (ESP8266.available())
     {
        char c = ESP8266.read();
        Serial.print(c);
        delay(10);
     }
     if (Serial.available())
     {
        char c = Serial.read();
        ESP8266.print(c);
        delay(10);
     }

//     if(Serial.find("+IPD,"))
//    {
//      delay(1000); // wait for the serial buffer to fill up (read all the serial data)
//      // get the connection id so that we can then disconnect
//      int connectionId = ESP8266.read()-48; // subtract 48 because the read() function returns 
//                                           // the ASCII decimal value and 0 (the first decimal number) starts at 48
//          
//      Serial.find("pin="); // advance cursor to "pin="
//     
//      int pinNumber = (ESP8266.read()-48)*10; // get first number i.e. if the pin 13 then the 1st number is 1, then multiply to get 10
//
//      pinNumber += (ESP8266.read()-48); // get second number, i.e. if the pin number is 13 then the 2nd number is 3, then add to the first number
//     
//      digitalWrite(pinNumber, !digitalRead(pinNumber)); // toggle pin
//      delay(1000);
//    }
}


