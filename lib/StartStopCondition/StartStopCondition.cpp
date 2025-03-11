#include "StartStopCondition.h"


StartStopCondition::StartStopCondition(){

}

void StartStopCondition::ConditionMotorWithHeight(int height, DateTime now) {
    Myrtc.begin();
    if (height == 0 && now.hour() <= 10 && !activationSyncHeight) {
        activationSyncHeight = true;
    } else if (height == 0 && now.hour() > 16 && activationSyncHeight) {
        activationSyncHeight = false;
    } else {
        // Mettre la fonction Sync
        Serial.print("Synchronisation moteur avec Angle hauteur: ");
        Serial.println(height);
    }
}

void StartStopCondition::ConditionMotorWithAzimut(int azimut, DateTime now) {
}