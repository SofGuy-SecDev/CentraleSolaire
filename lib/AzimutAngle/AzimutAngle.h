#ifndef AZIMUT_ANGLE_H
#define AZIMUT_ANGLE_H

#include <Arduino.h>
#include "MyRTCLibrary.h"       

struct AzimutResult {
    float A_float;
    int A_int;
};

class AzimutAngle {
public:
    AzimutAngle(float latitude);
    AzimutResult getAngle();
    void printAzimutAngle();

private:
    MyRTCLibrary Myrtc;
    float latitude;
    AzimutResult calculate(float H, float h, uint16_t Daynum);
};

#endif