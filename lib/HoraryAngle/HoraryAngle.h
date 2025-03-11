#ifndef HORARY_ANGLE_H
#define HORARY_ANGLE_H

#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include "MyRTCLibrary.h"

class HoraryAngle {
public:
    HoraryAngle(const float longitude);
    float getAngle();
    void printHoraryAngle();
    

private:
    RTC_DS3231 rtc;
    MyRTCLibrary Myrtc;
    float longitude;
    float calculate(DateTime now, uint16_t Daynum);
};

#endif
