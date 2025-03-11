#include "HoraryAngle.h"
#include "MyRTCLibrary.h"

HoraryAngle::HoraryAngle(float lon) {
    longitude = lon;
}

// Fonction pour calculer l'angle horaire (H)
float HoraryAngle::calculate(DateTime now, uint16_t Daynum) {
    float localTime = now.hour() + now.minute() / 60.0 + now.second() / 3600.0;
    float loc = (Daynum - 81) * 360 / 365.0;  // Position approximative de la Terre dans son orbite
    float equationOfTime = 9.87 * sin(2 * radians(loc)) - 7.53 * cos(radians(loc)) - 1.5 * sin(radians(loc));
    
    float eqTimeHours = equationOfTime / 60.0;
    float longitudeCorrection = longitude / 15.0;
    float HSL = localTime + longitudeCorrection + eqTimeHours;

    return (15 * (HSL - 12));
}

float HoraryAngle::getAngle() {
    Myrtc.begin();
    DateTime now = rtc.now();
    uint16_t Daynum = Myrtc.getDayOfYear();  
    return calculate(now,Daynum);
}

void HoraryAngle::printHoraryAngle() {
    float horary_angle = getAngle();
    Serial.print("Angle Horaire (float): ");
    Serial.println(horary_angle);
}

