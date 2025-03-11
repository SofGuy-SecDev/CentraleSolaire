#include "HeightAngle.h"

ElevationAngle::ElevationAngle(float lat) {
    latitude = lat;
}


ElevationResult ElevationAngle::calculate(float horaryAngle, uint16_t Daynum) {
    ElevationResult h_result;

    // Calcul de la déclinaison solaire
    float D_degrees = 23.45 * sin(radians((360.0 / 365.0) * (Daynum - 81)));
    float D_radians = radians(D_degrees);

    // Conversion de H en radians
    float H_radians = radians(horaryAngle);

    // Calcul de l'angle hauteur
    float sin_h = sin(latitude) * sin(D_radians) + cos(latitude) * cos(D_radians) * cos(H_radians);
    
    if (sin_h > 1.0 || sin_h < -1.0) {
        Serial.println("ERREUR DE CALCUL DU sin_h");
    }

    float rad_h = asin(sin_h); // Convertit en radians
    h_result.h_float = degrees(rad_h); // Convertit en degrés
    h_result.h_int = round(h_result.h_float);

    return h_result;
}

ElevationResult ElevationAngle::getAngle(){
    HoraryAngle horaryAngle(3.26);
    float H = horaryAngle.getAngle();
    uint16_t Daynum = Myrtc.getDayOfYear();
    return calculate(H,Daynum);
}

void ElevationAngle::printElevationAngle(){
    ElevationResult elevation_result = getAngle();
    Serial.print("Angle d'élévation (int): ");
    Serial.print(elevation_result.h_int);
    Serial.print("Angle d'élévation (float): ");
    Serial.println(elevation_result.h_float);
}
