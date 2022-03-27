#include <screen.hpp>
#include <Arduino.h>

Screen::Screen(){
    lcd = new LiquidCrystal(rs, en, d4, d5, d6, d7);
    lcd->begin(16,2);
    //lcd->print("OGST-E Modulizer");
    //delay(200);
    lcd->clear(); 
}

Screen::~Screen(){}

void Screen::print(String data_t, int row){
    //lcd->clear();
    lcd->setCursor(0, row);
    lcd->print(data_t);
    delay(250);
}

void Screen::clear(int row_t){
   lcd->setCursor(0, row_t);
   lcd->print("                 ");

}