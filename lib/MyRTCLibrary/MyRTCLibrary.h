#ifndef MYRTCLIBRARY_H
#define MYRTCLIBRARY_H

#include <Wire.h>
#include <RTClib.h>

class MyRTCLibrary {
public:
    MyRTCLibrary();
    bool begin();
    uint16_t getDayOfYear();
    void printDayOfYear();

private:
    RTC_DS3231 rtc;
    uint16_t nb_day_in_the_years(DateTime now);
};

#endif