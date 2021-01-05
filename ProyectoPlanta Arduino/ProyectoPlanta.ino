/* 
  Programa que permite encender un modulo de rele mediante el sensor de movimiento
  PIR.
*/

int PIR = 2;      // señal de PIR a pin 2
int RELE = 3;     // IN de rele a pin 3
int ESTADO = 0;     // almacena estado de señal

void setup(){
  pinMode(PIR, INPUT);    // pin 2 como entrada
  pinMode(RELE, OUTPUT);  // pin 3 como salida
  delay(20000);     // demora para estabilizar el sensor
}

void loop(){

  ESTADO = digitalRead(PIR);  // lectura de estado de señal
  if (ESTADO == HIGH){    // si la señal esta en alto indicando movimiento
    digitalWrite(RELE, LOW);  // activa modulo de rele con nivel bajo
    delay(4000);    // demora de 4 segundos
  } else {
    digitalWrite(RELE, HIGH); // apaga modulo rele
  }
}
