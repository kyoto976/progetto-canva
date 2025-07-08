#include <RadioLib.h>
#include "HT_SSD1306Wire.h"

// Pin SX1262 Heltec V3
#define LORA_CS   8
#define LORA_RST  12
#define LORA_BUSY 13
#define LORA_DIO1 14

SX1262 lora = new Module(LORA_CS, LORA_DIO1, LORA_RST, LORA_BUSY);

// OLED Heltec 
SSD1306Wire mydisplay(0x3C, 400000, SDA_OLED, SCL_OLED, GEOMETRY_128_64, RST_OLED);

int counter = 0;
unsigned long lastSend = 0;
bool sendingEnabled = true;

void setup() {
  Serial.begin(115200);

  pinMode(Vext, OUTPUT);
  digitalWrite(Vext, LOW);  // Accende LoRa + OLED
  delay(100);

  mydisplay.init();
  mydisplay.setFont(ArialMT_Plain_10);
  mydisplay.clear();
  mydisplay.drawString(0, 0, "LoRa Sender...");
  mydisplay.display();

  int state = lora.begin();
  if (state != RADIOLIB_ERR_NONE) {
    Serial.print("Errore LoRa: ");
    Serial.println(state);
    while (true);
  }

  mydisplay.drawString(0, 20, "LoRa inizializzato!");
  mydisplay.display();

  Serial.println("Digita 'stop' per fermare l'invio o 'start' per riattivarlo.");
}

void loop() {
  // Lettura comandi da Serial Monitor
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();  // Rimuove spazi e newline

    if (cmd.equalsIgnoreCase("start")) {
      sendingEnabled = true;
      Serial.println("Invio abilitato.");
      mydisplay.clear();
      mydisplay.drawString(0, 0, "Invio ON");
      mydisplay.display();
    } else if (cmd.equalsIgnoreCase("stop")) {
      sendingEnabled = false;
      Serial.println("Invio disabilitato.");
      mydisplay.clear();
      mydisplay.drawString(0, 0, "Invio OFF");
      mydisplay.display();
    } else {
      Serial.println("Comando non riconosciuto. Usa 'start' o 'stop'.");
    }
  }

  // Invio LoRa solo se abilitato
  if (sendingEnabled && (millis() - lastSend > 5000)) {
    lastSend = millis();
    String msg = "Messaggio #" + String(counter++);
    Serial.print("Invio: ");
    Serial.println(msg);

    int state = lora.transmit(msg);
    mydisplay.clear();
    if (state == RADIOLIB_ERR_NONE) {
      mydisplay.drawString(0, 0, "Inviato:");
      mydisplay.drawString(0, 10, msg);
    } else {
      mydisplay.drawString(0, 0, "Errore TX!");
    }
    mydisplay.display();
  }
}
