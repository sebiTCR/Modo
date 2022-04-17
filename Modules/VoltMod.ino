#include <ArduinoJson.h>
#define MEASUREMENT "V"

float input_voltage = 0.0;
float temp=0.0;
bool isEnabled = false;
DynamicJsonDocument data(1024);

void sendData(float m_value){

    m_value = 100; 

    char fchar[4];
    itoa(m_value, fchar, 10);
    data["value"] = m_value;

    serializeJson(data, Serial);
    delay(500);
}

void setup(){
   pinMode(A0, INPUT);
   Serial.begin(115200);
   data["ms"] = MEASUREMENT;
}

void loop(){

     int analog_value = analogRead(A0);
     input_voltage = (analog_value 5.0) / 1024.0; 
     if (input_voltage < 0.1) 
     {
       input_voltage=0.0;
     } 
    sendData(input_voltage / 1.04);

}
