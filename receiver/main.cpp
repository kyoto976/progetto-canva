#include <RadioLib.h>
#include "HT_SSD1306Wire.h"

// Pin SX1262 Heltec V3
#define LORA_CS   8
#define LORA_RST  12
#define LORA_BUSY 13
#define LORA_DIO1 14

SX1262 lora = new Module(LORA_CS, LORA_DIO1, LORA_RST, LORA_BUSY);

// OLED Heltec
SSD1306Wire display(0x3C, 400000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED);

void setup() {
  Serial.begin(115200);

  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW);
  delay(100);

  display.init();
  display.setFont(ArialMT_Plain_10);
  display.clear();
  display.drawString(0, 0, "LoRa Receiver...");
  display.display();

  int state = lora.begin();
  if (state != RADIOLIB_ERR_NONE) {
    Serial.print("Errore LoRa: ");
    Serial.println(state);
    display.drawString(0, 20, "Errore LoRa");
    display.display();
    while (true);
  }

  display.drawString(0, 20, "In ascolto...");
  display.display();
}

void loop() {
  String msg;
  int state = lora.receive(msg);

  // Se è stato ricevuto correttamente
  if (state == RADIOLIB_ERR_NONE) {
    Serial.print("[Ricevuto] ");
    Serial.println(msg);
    display.clear();
    display.drawString(0, 0, "Ricevuto:");
    display.drawString(0, 10, msg);
    display.display();
  } 
  // Se timeout, prova di nuovo
  else if (state == RADIOLIB_ERR_RX_TIMEOUT) {
    // Aggiungi eventuale codice per il timeout
  }
  else {
    Serial.println("Errore ricezione");
  }

  // Ricezione continua (in caso di timeout, si riprova senza bloccare)
  delay(10);  // Aggiungi un piccolo delay per migliorare la stabilità
}
