#include <modulePort.hpp>
#include <Arduino.h>

void threadCallbk(){
    
}

ModPort::ModPort(int conPort_t, int checkerPin_t){
    serialPort = conPort_t;
    checkerPin = checkerPin_t;

    //Setup the checker pin
    pinMode(checkerPin, INPUT);
}

ModPort::~ModPort(){}

float ModPort::getData(){
    float data;
    DynamicJsonDocument jsonObj(1024);

    switch (serialPort)
    {
    case 0:
        data = Serial.read();
        break;
    case 1:
        if(Serial1.available()){
            deserializeJson(jsonObj, Serial1);
            String t = jsonObj["ms"];
            type = t;

            String ff = jsonObj["value"];
            String dd = String(ff);
            
            value = dd.toInt();
            data = value;
        }

        break;
    case 2:
            deserializeJson(jsonObj, Serial2);
            String t = jsonObj["ms"];
            type = t;

            String ff = jsonObj["value"];
            String dd = String(ff);
            
            value = dd.toInt();
            data = value;
        break;
    case 3:
        data = Serial3.read();
        break;
    
    default:
        break;
    }

    if(data < 0.1 || data > 6000000.00) {data =0;}
    return data / 100;

}

bool ModPort::isConnected(){
    if(digitalRead(checkerPin) == HIGH){
        return true;
    }
    return false;
}

void ModPort::updateMod(){
//TODO: Turn of the activation LED if a module is connected
    value = getData();
}
