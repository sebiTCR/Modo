/**
 * @file modulePort.hpp
 * @author SebiTCR (sebitcr1@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <ArduinoJson.h>

struct Type{
    char name[7];
    char symbol;
};

/**
 * @brief Represents the hardware module port
 * 
 */
class ModPort{
    public:
        /**
         * @brief Construct a new Module Port object
         * 
         * @param conPort_t Serial connection port 
         * @param checkerPin_t Selected pin for checking if a module is connected
         */
        ModPort(int conPort_t, int checkerPin_t);
        ~ModPort();

        // template<typename T>
        // void initCom(int baudRate, T serialPort);

        
        float value;
        int serialPort;
        bool isConnected();

        Type getType();
        Type currentType;

        void updateMod();
        float getData();


    private:
        Type modType;
        int checkerPin;
        char data[7];
};