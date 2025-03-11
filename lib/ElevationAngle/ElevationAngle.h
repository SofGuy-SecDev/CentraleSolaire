#ifndef HEIGHT_ANGLE_H
#define HEIGHT_ANGLE_H

#include <Arduino.h>
#include "MyRTCLibrary.h"       
#include "HoraryAngle.h"

struct ElevationResult {
    float h_float;
    int h_int;
};

class ElevationAngle {
public:
    ElevationAngle(float latitude);
    ElevationResult getAngle();
    void printElevationAngle();

private:
    MyRTCLibrary Myrtc;
    float latitude;
    ElevationResult calculate(float horaryAngle, uint16_t Daynum);
};

#endif