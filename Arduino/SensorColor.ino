#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorSalida 8
#define led1 9
#define led2 10
int Rojo_Frec = 0, Verde_Frec = 0,Azul_Frec = 0;
void setup() {
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sensorSalida, INPUT);
  
                           // Configura la escala de Frecuencia en 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
}
void loop() {
                          // Configura el filtro ROJO para tomar lectura
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  delay(100);
  Rojo_Frec= pulseIn(sensorSalida, LOW);
  Serial.print(" R= "); Serial.print(Rojo_Frec);
  delay(100);
                            // Configura el filtro VERDE para tomar lectura
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  delay(100);
  Verde_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" V= "); Serial.print(Verde_Frec);
  delay(100);
                           // Configura el filtro AZUL para tomar lectura
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  delay(100);
  Azul_Frec = pulseIn(sensorSalida, LOW);
  Serial.print(" A= "); Serial.print(Azul_Frec);
  delay(100);

                  //Valores obtenidos en la calibracion del sensor, son propios de cada usuario 
                  
 
 if (Rojo_Frec < 40 && Verde_Frec < 60 && Azul_Frec < 60){  
    Serial.print(" . *** BLANCO **");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    
 }
 else if (Rojo_Frec < 50 && Verde_Frec < 80 && Azul_Frec < 80){  
  Serial.print(" . *** COLOR **");
  digitalWrite(led2, HIGH);
  digitalWrite(led1, LOW);
 }
 else{ 
  Serial.print(" . *** NINGUNO **");
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
 }
 Serial.println("*");
 delay(200);
}