/*
Programa para simular a función dunha ventana de un automovil, da maneira 
simplificada. O pulsador acciona o motor de subida o ser premido. unha 
segunda pulsación para o motor e unha terceira fai que se accione o motor de baixada.
Añádense 2 finais de carreira (pin 5,pin 6), un para subida e outro para baixada.

Entradas: Pulsador,finais de carreira (3x dixital)
Saídas: Relé (2x dixital)

Autor: Marcos Antonio Mariño Mota
Data: Febreiro de 2023
*/

#define motorArriba 11
#define motorAbaixo 12
#define pulsador     7
#define fcArriba     6
#define fcAbaixo     5

int estado = 1;    //valores: 0(arriba) , 1(paro) , 2(abixo) , 3(para)
int contador = 0; // Contador para o número de impulsos ao motor

void setup() {
  pinMode(motorArriba, OUTPUT);
  pinMode(motorAbaixo, OUTPUT);
  pinMode(pulsador, INPUT);
  pinMode(fcArriba, INPUT);
  pinMode(fcAbaixo, INPUT);
  
  Serial.begin(9600);
  int estado;
  
  Serial.println(estado);
}

void loop() {
  // Lectura do pulsador
  if(digitalRead(pulsador)) {
    estado++; 
    if(estado > 3) {
      estado = 0;
    }
    
    contador = 100;
    while(digitalRead(pulsador)) {
      delay(20);
    }
  }
  
  if(digitalRead(fcArriba)) {
    if(estado != 2) {
      estado = 1;
    }
    delay(20);
  }
  
  if(digitalRead(fcAbaixo)) {
   if(estado != 0) {
      estado = 3;
   }
    delay(20);
  }
  // Fin da lectura do pulador
  
  Serial.print("valor do contador: ");
  Serial.println(contador);
  Serial.print("estado: ");
  Serial.println(estado);
  
  // Accionamiento dos motores
  if(contador > 0) {
    if(estado == 0) {
      digitalWrite(motorArriba, HIGH);
      digitalWrite(motorAbaixo, LOW);
      delay(70);
    }
    else if(estado == 2) {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, HIGH);
      delay(70);
    }
    else {
      digitalWrite(motorArriba, LOW);
      digitalWrite(motorAbaixo, LOW);
    }
  }
}
