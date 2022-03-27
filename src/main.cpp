#include <Arduino.h>
#include <modulePort.hpp>
#include <screen.hpp>
#include <string.h>
#include <Thread.h>

ModPort firstMod(1, 22);
ModPort secoundMod(1, 24);
Screen  screen;

Thread FMTh = Thread();
Thread SMTh = Thread();


void updateFM(){firstMod.updateMod();}
void updateSM(){secoundMod.updateMod();}


void setup() {
    Serial.begin(9600);
    Serial1.begin(115200);
    Serial2.begin(9600);

    FMTh.onRun(updateFM);
    FMTh.setInterval(500);

    SMTh.onRun(updateSM);
    SMTh.setInterval(500);

    // firstMod   = new ModPort;
    // secoundMod = new ModPort;
    // screen     = new Screen();
}

void loop() {

    if(firstMod.isConnected()){
        if(FMTh.shouldRun()){FMTh.run();}
        screen.print("Mod 1: " + String(firstMod.value) + String(" ?u"), 0);
    }
    else
    {
        screen.clear(0);
    }

    if(secoundMod.isConnected())
    {
        if(SMTh.shouldRun()){SMTh.run();}
        screen.print("Mod 2: " + String(secoundMod.value) + String(" ??"), 1);
    }
    else
    {
        screen.clear(1);
    }

    //if(Serial1.available()){Serial.println(Serial1.read());}
}