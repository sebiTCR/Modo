#include <modulePort.hpp>
#include <Arduino.h>

// template<typename T>
// void initCom(int baudRate, T serialPort){
//     T.write()
// }

void threadCallbk(){
    
}

ModPort::ModPort(int conPort_t, int checkerPin_t){
    serialPort = conPort_t;
    checkerPin = checkerPin_t;
    //currentType = getType();

    //Setup the checker pin
    pinMode(checkerPin, INPUT);
}

ModPort::~ModPort(){}

float ModPort::getData(){
    float data;

    //Serial.println("Pulling data...");
    switch (serialPort)
    {
    case 0:
        data = Serial.read();
        Serial.println(Serial.read());
        break;
    case 1:
        if(Serial1.available()){
            DynamicJsonDocument jsonObj(1024);
            deserializeJson(jsonObj, Serial1);
            String ff = jsonObj["value"];
            String dd = String(ff);
            //TODO: Deserialize Json
            Serial.println(dd);
        }

        break;
    case 2:
        data = Serial2.read();
        // Serial2.println(data);
        break;
    case 3:
        data = Serial3.read();
        // Serial3.println(data);
        break;
    
    default:
        break;
    }
    // Serial.print("Data pulled: ");
    //Serial.println(Serial1.read());

    if(data < 0.1) {data =0;}
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
    Serial.println(value);
}
