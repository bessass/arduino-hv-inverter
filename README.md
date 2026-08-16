# ⚡ Arduino HV Inverter (MOSFET & Trafo Driver)

Este projeto consiste em um circuito inversor / driver de alta tensão controlado por Arduino, utilizando um transistor MOSFET para o chaveamento de alta frequência em um transformador elevador. 

O sistema permite gerar pulsos de alta frequência (1 kHz) para aplicações como acionamento de lâmpadas neon/fluorescentes, testes de ionização de gases e pequenos arcos elétricos.

---

## 🛠️ Componentes Utilizados

* **Microcontrolador:** Arduino (Uno, Nano ou equivalente)
* **Chaveamento:** Transistor MOSFET N-Channel (SIF7N65F ou similar)
* **Transformador:** Transformador Elevador (Trafo)
* **Alimentação:** Fonte Externa (5V / 3A) para o primário do trafo
* **Acessórios:** Protoboard, jumpers e dissipador de calor para o MOSFET

---

## 📌 Esquemático de Ligação

| Componente | Conexão Arduino | Descrição |
| :--- | :--- | :--- |
| **MOSFET Gate** | Pino Digital 3 | Sinal PWM / Pulso de disparo |
| **MOSFET Source** | GND | Terra comum (Arduino + Fonte Externa) |
| **MOSFET Drain** | Primário do Trafo (-) | Entrada negativa do primário |
| **Primário (+)** | Fonte 5V Externa | Entrada positiva de alimentação do trafo |

> ⚠️ **Importante:** O GND da fonte externa DEVE estar conectado ao GND do Arduino para garantir a referência de terra do MOSFET.

---

## 💻 Funcionamento do Código

O código em C++ (desenvolvido para o **PlatformIO**) gera um pulso de frequência fixa de aproximadamente 1 kHz ajustando os tempos de disparo (`delayMicroseconds`).

```cpp
#include <Arduino.h>

const int pinMOSFET = 3; 

void setup() {
  pinMode(pinMOSFET, OUTPUT);
  digitalWrite(pinMOSFET, LOW); 
}

void loop() {
  digitalWrite(pinMOSFET, HIGH); // Chaveia corrente no primário
  delayMicroseconds(1000);       // 1 ms ligado

  digitalWrite(pinMOSFET, LOW);  // Corta a corrente
  delayMicroseconds(1000);       // 1 ms desligado
}
```

---

## 🚀 Como Executar

1. Abra a pasta do projeto no **VS Code** com a extensão **PlatformIO**.
2. Conecte o Arduino ao computador via USB.
3. Clique no botão **Upload** → do PlatformIO para gravar o código na placa.
4. Conecte a fonte externa de 5V no circuito com a carga/trafo conectada ao MOSFET.

---

## ⚠️ Precauções de Segurança

* **Tensão Elevada:** A saída do transformador gera alta tensão capaz de causar choques dolorosos ou danificar equipamentos eletrônicos sensíveis.
* **Aquecimento:** O MOSFET e o transformador podem aquecer durante operações contínuas; utilize um dissipador no MOSFET.
* **Proteção contra Flyback:** Certifique-se de utilizar circuitos de proteção/snubber para absorver os picos indutivos e proteger o transistor.
