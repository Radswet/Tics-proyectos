#include "HX711.h" 

#define LOADCELL_DOUT_PIN  A0 
#define LOADCELL_SCK_PIN  A1  

HX711 scale;

float calibration_factor = 0;

void setup() {
  Serial.begin(9600);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale();
  scale.tare();  //Reset the scale to 0

  long zero_factor = scale.read_average();
}

void loop() {

  scale.set_scale(calibration_factor); 

  Serial.print("Lectura: ");
  Serial.print(scale.get_units(), 1);
  Serial.print(" Gramos"); 
  Serial.print(" calibration_factor: ");
  Serial.print(calibration_factor);
  Serial.println();

  if(Serial.available())
  {
    int temp = Serial.read();
    calibration_factor = temp;
  }
}