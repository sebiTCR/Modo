/**
 * @file screen.hpp
 * @author SebiTCR (SebiTCR)
 * @brief Controls the LCD Screen
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <Wire.h>
#include <Arduino/LiquidCrystal.h>

typedef enum{
    OHM,
    VOLT,
} symbols;

class Screen
{

    public:
        Screen();
        ~Screen();
        
        void print(String data_t, int row);
        void clear(int row_t);

    private:
        LiquidCrystal* lcd;
        const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
};

