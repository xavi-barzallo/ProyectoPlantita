/* 
  Programa que permite encender un modulo de rele mediante el sensor de movimiento
  PIR.
*/

int PIR = 2;      // señal de PIR a pin 2
int RELE = 3;     // IN de rele a pin 3
int ESTADO = 0;     // almacena estado de señal
int cont = 0;

void setup(){
  Serial.begin(9600);
  pinMode(PIR, INPUT);    // pin 2 como entrada
  pinMode(RELE, OUTPUT);  // pin 3 como salida
  //delay(1000);     // demora para estabilizar el sensor
}

void loop(){
  ESTADO = digitalRead(PIR);  // lectura de estado de señal
  if (ESTADO == HIGH){    // si la señal esta en alto indicando movimiento
     // activa modulo de rele con nivel bajo
      digitalWrite(RELE, HIGH);
      cont++;
      Serial.println(cont);
      delay(5000);
        // demora de 4 segundos
  } else {
      if(cont==3){
        cont=0; 
        digitalWrite(RELE, LOW);  // apaga modulo rele
        delay(20000);
         Serial.println("Habilitar");   
      }else{
        digitalWrite(RELE, LOW);
      }
      
     
     
  }
}
