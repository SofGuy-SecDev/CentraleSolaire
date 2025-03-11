
#include <Arduino.h>
#include <Wire.h>
#include <RTClib.h>
#include <AccelStepper.h>
#include <SPI.h>
#include <MyRTCLibrary.h>
#include <HoraryAngle.h>
#include <HeightAngle.h>
#include <AzimutAngle.h>


// Définir les broches de commande du moteur
#define IN1 16
#define IN2 17
#define IN3 26
#define IN4 27  

MyRTCLibrary Myrtc;
HoraryAngle horaryAngle(3.26);
ElevationAngle heightAngle(48.43);
AzimutAngle azimutAngle(48.85);

// Créer une instance d'AccelStepper avec le mode FULL4WIRE pour les moteurs avec 4 fils
AccelStepper stepper(AccelStepper::FULL4WIRE, IN1, IN2, IN3, IN4);

int h_max = 0;
bool Activation_sync_hauteur = false; 

//######################################################################## fichier Motor_SYNC_ANGL #######################################################################################

void motor_sync_height_angl(int h)
{
  if(h == 0){
    h_max = 0;    
    return;
  }
  //le moteur fais 360° en 2048 pas donc pour faire 1° on doit faire 5.6 pas
  else if (h > 0 && h > h_max ) {
    stepper.moveTo(5.6);  
    stepper.runToPosition();
    h_max = h;
    return;
  }

  else if (h > 0 && h < h_max ) {
    stepper.moveTo(-5.6);  
    stepper.runToPosition();
    h_max = h;
    return;
  }
    
  else {
    Serial.print("ERREUR AUCUNE CONDITION PASSÉE POUR LA SYNC_ANGL_HORARY");
    return;  
  }  

}

void setup() {
  Serial.begin(115200);

  // Initialisation du moteur 
  stepper.setMaxSpeed(100);  // Vitesse maximale (pas par seconde)
  stepper.setAcceleration(50);  // Accélération maximale (pas par seconde^2)

}

void loop() {

  //appelle des fonction
  uint16_t Day_Num = Myrtc.getDayOfYear(); //nueros du jour dans l'année
  float Horrary_Angle = horaryAngle.getAngle();// Angles Horraire nécessaire pour calculer l'angle Hauteur
  ElevationResult Height_Angle = heightAngle.getAngle(); // Angles hauteur
  AzimutResult Azimut_Angle = azimutAngle.getAngle();

  //condition de démarrage de la sync du motor sur l'angle Hauteur en début de journer
  if (Height_Angle.h_int == 0 && now.hour() <= 10 && Activation_sync_hauteur == false){
    Activation_sync_hauteur = true; 
  }

  if(Activation_sync_hauteur == true){
    motor_sync_height_angl(Height_Angle.h_int);
  }

  //condition de l'arrêt de la sync du motor sur l'angle Hauteur en fin de journer
  if (Height_Angle.h_int == 0 && now.hour() > 16 && Activation_sync_hauteur == true){
    Activation_sync_hauteur = false; 
  }

  //Affichage des résultats : JDA | Angle H | Angle h | Angle A
  Myrtc.printDayOfYear();
  horaryAngle.printHoraryAngle();
  heightAngle.printElevationAngle();
  azimutAngle.printAzimutAngle();
  Serial.println("");

  delay(4000);

}
