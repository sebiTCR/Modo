#include <Arduino.h>
#include <modulePort.hpp>
#include <screen.hpp>
#include <string.h>
#include <Thread.h>

DynamicJsonDocument iBuff(1024);

ModPort firstMod(1, 22);
ModPort secoundMod(2, 24);
Screen  screen;

Thread FMTh = Thread();
Thread SMTh = Thread();
Thread buffInterface = Thread();

void updateFM(){firstMod.updateMod();}
void updateSM(){secoundMod.updateMod();}

void updateIBuff(){
    String buffer = "";
    iBuff["Modules"]["M1"]["isConnected"] = firstMod.isConnected();
    iBuff["Modules"]["M1"]["Measurement"] = firstMod.type;
    iBuff["Modules"]["M1"]["Value"]       = firstMod.value;

    iBuff["Modules"]["M2"]["isConnected"] = secoundMod.isConnected();
    iBuff["Modules"]["M2"]["Measurement"] = secoundMod.type;
    iBuff["Modules"]["M2"]["Value"]       = secoundMod.value;

    
    serializeJson(iBuff, buffer);
    Serial.println(buffer);
}

void setup() {
    Serial.begin(115200);
    Serial1.begin(115200);
    Serial2.begin(115200);

    FMTh.onRun(updateFM);
    FMTh.setInterval(500);

    SMTh.onRun(updateSM);
    SMTh.setInterval(500);

    buffInterface.onRun(updateIBuff);
    buffInterface.setInterval(1000);

    // firstMod   = new ModPort;
    // secoundMod = new ModPort;
    // screen     = new Screen();
}

void loop() {

    if(firstMod.isConnected()){
        if(FMTh.shouldRun()){FMTh.run();}
        screen.print("Mod 1: " + String(firstMod.value) + firstMod.type, 0);

    }
    else{
        screen.clear(0);
    }

    if(secoundMod.isConnected()){
       if(SMTh.shouldRun()){SMTh.run();}
       screen.print("Mod 2: " + String(secoundMod.value) + secoundMod.type, 1);
    }
    else{
       screen.clear(1);
    }

    if(buffInterface.shouldRun()){buffInterface.run();}


    //if(Serial1.available()){Serial.println(Serial1.read());}
}