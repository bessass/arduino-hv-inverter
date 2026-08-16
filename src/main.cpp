#include <Arduino.h>

// Pino digital do Arduino conectado ao Gate do MOSFET
const int pinMOSFET = 3; 

void setup() {
  // Configura o pino como saída
  pinMode(pinMOSFET, OUTPUT);
  
  // Garante que o MOSFET inicie desligado por segurança
  digitalWrite(pinMOSFET, LOW); 
}

void loop() {
  // Frequência de chaveamento de aproximadamente 500 Hz a 1 kHz
  // Mantém o MOSFET acionado e cortado em pulsos rápidos
  
  digitalWrite(pinMOSFET, HIGH); // Liga o MOSFET (corrente no primário do trafo)
  delayMicroseconds(1000);       // Tempo ligado (1 ms)

  digitalWrite(pinMOSFET, LOW);  // Desliga o MOSFET
  delayMicroseconds(1000);       // Tempo desligado (1 ms)
}
