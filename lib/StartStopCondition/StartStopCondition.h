#ifndef STARTSTOP_CONDITION_H
#define STARTSTOP_CONDITION_H

#include <Arduino.h>
#include <RTClib.h>
#include "HeightAngle.h"
#include "SyncMotorAngle.h"

// Classe principale de la bibliothèque
class StartStopCondition {
public:
    StartStopCondition();
    void ConditionMotorWithElevation(int height, DateTime now);
    void ConditionMotorWithAzimut(int azimut, DateTime now);

private:
    RTC_DS3231 Myrtc;
    bool activationSyncHeight = false;
};

#endif