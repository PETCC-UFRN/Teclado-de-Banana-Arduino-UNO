#include <movingAvg.h>

uint8_t buf[8] = { 0 };

#define PIN_0 A0 
#define PIN_1 A1 
#define PIN_2 A2 
#define PIN_3 A3 
#define PIN_4 A4 
#define PIN_5 A5

const int limiarPressionado = 650; // Mais alto = mais sensível ao toque & menos preciso
const int limiarSolto = 750;       // Mais alto para histerese maior

// Arrays para cada propriedade
byte pinos[6] = {PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5};
byte keycodes[6] = {21, 23, 28, 24, 18, 19}; // R, T, Y, U, O, P
boolean pressionado[6] = {false, false, false, false, false, false};

// Filtros de média móvel para estabilizar o sinal
movingAvg filtro0(50); 
movingAvg filtro1(50);
movingAvg filtro2(50);
movingAvg filtro3(50);
movingAvg filtro4(50);
movingAvg filtro5(50);

movingAvg* filtros[6] = {&filtro0, &filtro1, &filtro2, &filtro3, &filtro4, &filtro5};

void setup() {
  Serial.begin(9600); 
  
  // Inicializando os filtros
  for (int i = 0; i < 6; i++) {
    filtros[i]->begin();
  }
}

void loop() {
  // Processar cada tecla
  for (int i = 0; i < 6; i++) {
    // Calcular média móvel da leitura analógica
    float mediaAtual = filtros[i]->reading(analogRead(pinos[i]));
    
    boolean estadoAnterior = pressionado[i];
    boolean estadoAtual = estadoAnterior;
    
    // Verificar se passou dos limiares
    if (mediaAtual < limiarPressionado) {
      estadoAtual = true;  // Tecla pressionada
    }
    else if (mediaAtual > limiarSolto) {
      estadoAtual = false; // Tecla solta
    }
    
    // Se o estado mudou, envia o comando
    if (estadoAtual != estadoAnterior) {
      if (estadoAtual) {
        // Pressionar tecla
        buf[2] = keycodes[i];
        Serial.write(buf, 8);
      } else {
        // Soltar tecla
        releaseKey();
      }
    }
    
    // Atualizar estado
    pressionado[i] = estadoAtual;
  }
}

void releaseKey() {
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);
}