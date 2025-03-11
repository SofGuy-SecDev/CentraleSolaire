#include "HeightAngle.h"
#include "HoraryAngle.h"
#include "AzimutAngle.h"

AzimutAngle::AzimutAngle(float lat){
  latitude = lat;
}             


AzimutResult AzimutAngle::calculate(float H, float h, uint16_t Daynum){
  AzimutResult A_result;
  //Calcul de la déclinaison Solaire
  float D_degrees = 23.45*sin(360.0/365.0*(Daynum-81));
  float D_radians = radians(D_degrees); //conversion en radians car on l'utilise avec cos et sin
  //Conversion de H en radians car on vas l'utiliser avec sin et cos 
  float H_radians = radians(H);
  //Conversion de h en radians car on vas l'utiliser avec sin et cos 
  float h_radians = radians(h);

  //Calcul de sin(A)
  float sin_A = (cos(D_radians)*sin(H_radians))/cos(h_radians);
  //Calcul de cos(A)
  float cos_A = (sin(h_radians)*sin(latitude)-sin(D_radians) / (cos(h_radians)*cos(latitude)));

  // Calcul de A en utilisant atan2 qui tient compte du quadrant
  float A = atan2(sin_A, cos_A);
  A_result.A_float = degrees(A); // Convertir en degrés (c'est un float)
  A_result.A_int = round(A_result.A_float);

  return A_result;
}

AzimutResult AzimutAngle::getAngle(){
  HoraryAngle Horary(3.26); // j'appelle leur constructeur ici et pas dans le .h car je ne peux pas a cause de leur paramètre 
  ElevationAngle Height(48.85); // pareil que pour l'angle horaire
  uint16_t Daynum = Myrtc.getDayOfYear();
  float H = Horary.getAngle();
  ElevationResult h = Height.getAngle();
  return calculate(H, h.h_float, Daynum);
}

void AzimutAngle::printAzimutAngle(){
  AzimutResult azimut_result = getAngle();
  Serial.print("Angle azimut (int): ");
  Serial.print(azimut_result.A_int);
  Serial.print("  Angle azimut (float): ");
  Serial.println(azimut_result.A_float);
}
