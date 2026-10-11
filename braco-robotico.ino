/*
  PROJETO: BRAÇO ROBÓTICO COM ARDUINO
  Movimentos:
    - Base: direita e esquerda
    - Ombro: mão pra cima
    - Cotovelo: outra parte da mão pra baixo
    - Garra: abre e fecha
*/

#include <Servo.h>

Servo servoBase;      // Pino 3 - gira direita/esquerda
Servo servoOmbro;     // Pino 5 - mão pra cima
Servo servoCotovelo;  // Pino 6 - outra parte pra baixo
Servo servoGarra;     // Pino 9 - garras

void setup() {
  servoBase.attach(3);
  servoOmbro.attach(5);
  servoCotovelo.attach(6);
  servoGarra.attach(9);

  // Posição inicial - tudo no meio
  servoBase.write(90);
  servoOmbro.write(90);
  servoCotovelo.write(90);
  servoGarra.write(0); // Garra aberta
  delay(1000);
}

void loop() {
  // 1. BASE PRA DIREITA E ESQUERDA
  servoBase.write(0);   // direita
  delay(1000);
  servoBase.write(180); // esquerda
  delay(1000);
  servoBase.write(90);  // volta pro meio
  delay(500);

  // 2. MÃO PRA CIMA (OMBRO)
  servoOmbro.write(30);  // sobe
  delay(1000);
  servoOmbro.write(120); // desce
  delay(1000);

  // 3. OUTRA PARTE DA MÃO PRA BAIXO (COTOVELO)
  servoCotovelo.write(30);  // desce
  delay(1000);
  servoCotovelo.write(120); // sobe
  delay(1000);

  // 4. GARRAS - ABRE E FECHA
  servoGarra.write(90); // fecha
  delay(1000);
  servoGarra.write(0);  // abre
  delay(1000);
}