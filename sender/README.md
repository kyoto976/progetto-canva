
# 📤 ESP32 LoRa - Sender (Heltec V3)

Questo sketch utilizza un **ESP32 Heltec LoRa V3** con chip **SX1262** per inviare messaggi LoRa a un ricevitore.  
Include un display OLED I2C integrato per feedback visivo locale e supporta comandi da serial monitor (`start` / `stop`).

---

## 📦 Librerie utilizzate

- [`RadioLib`](https://github.com/jgromes/RadioLib) → per la gestione del modulo LoRa SX1262
- `HT_SSD1306Wire` → per il display OLED Heltec

---

## ⚙️ Hardware richiesto

| Componente        | Descrizione                     |
|-------------------|---------------------------------|
| ESP32 Heltec V3   | Con LoRa SX1262 + OLED integrato |
| Antenna           | 868 MHz o 433 MHz               |
| PC + cavo USB     | Per alimentazione e debug seriale

---

## 🔌 Pinout LoRa SX1262 (Heltec V3)

| Segnale LoRa | ESP32 Pin |
|--------------|-----------|
| CS           | GPIO 8    |
| RST          | GPIO 12   |
| BUSY         | GPIO 13   |
| DIO1         | GPIO 14   |

---

## 📟 OLED Display (I2C integrato)

| Segnale | ESP32 Pin |
|---------|-----------|
| SDA     | SDA_OLED (definito dalla board) |
| SCL     | SCL_OLED                       |
| RST     | RST_OLED                       |

ℹ️ Questi pin sono gestiti automaticamente dalla libreria **HT_SSD1306Wire** su Heltec V3.

---

## ▶️ Funzionamento

1. All’avvio, il display mostra **"LoRa Sender..."** e **"LoRa inizializzato!"**
2. Ogni **5 secondi** viene inviato un messaggio testuale via LoRa:
