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
        
        float value;
        int serialPort;
        String type = "?";

        bool isConnected();
        void updateMod();
        float getData();
        int getData(DynamicJsonDocument json_t, String measurement_t, int value_t);


    private:
        int checkerPin;
        char data[7];
};