> 🇮🇹 Questo progetto è disponibile anche in italiano: [README_IT.md](./README_IT.md)

# 📡 ESP32 LoRa – Point-to-Point Communication (Sender ↔ Receiver)

This project uses two **ESP32 Heltec LoRa V3 boards** (with SX1262 chip and integrated OLED display) to create a **point-to-point communication system** over LoRa, with local feedback via display and serial monitor.  
It consists of a **sender** that transmits LoRa messages every 5 seconds and a **receiver** that listens and displays the messages.  
Project developed by **Giuseppe Cialdella** for educational purposes and experimentation in long-range wireless communications.

**ESP32 Heltec V3 (Sender)** → LoRa 868 MHz → **ESP32 Heltec V3 (Receiver)**

- Peer-to-peer communication over LoRa
- OLED display output (onboard)
- Control via Serial Monitor (`start` / `stop`)
- Code split into two modules: `sender` and `receiver`

### 📁 Repository structure
  progetto_LoRa32/
├── sender/ ← sender node code
├── receiver/ ← receiver node code
└── README.md ← this file

---

## 🧰 Libraries used

- **RadioLib** – LoRa SX1262 communication
- **HT_SSD1306Wire** – Heltec OLED display

You can install them via **Arduino Library Manager** or **PlatformIO**.

---

## 📤 What the Sender does

- Sends a message `"Message #X"` every 5 seconds via LoRa
- Displays status on the OLED
- Accepts commands from the Serial Monitor:
  - `start` → enable transmission
  - `stop` → disable transmission
- OLED example:
  Sent:
  Message #3

---

## 📥 What the Receiver does

- Receives messages from the sender node
- Displays them on OLED and Serial Monitor
- Uses a non-blocking receive loop
- OLED example:
  Received:
  Message #3

---

## 🔌 Pinout (LoRa SX1262 on Heltec V3)

| Function     | GPIO Pin       |
|--------------|----------------|
| LoRa CS      | GPIO 8         |
| LoRa RST     | GPIO 12        |
| LoRa BUSY    | GPIO 13        |
| LoRa DIO1    | GPIO 14        |
| OLED SDA     | `SDA_OLED`     |
| OLED SCL     | `SCL_OLED`     |

> ℹ️ Note: OLED and LoRa are integrated and managed via `Vext`.

---

## 🚀 How to use it

1. Upload `sender/main.cpp` to one Heltec board
2. Upload `receiver/main.cpp` to another
3. Attach antennas to both boards
4. Open Serial Monitor to view logs
5. Observe the messages displayed on the OLEDs

---

## 🧪 Example output

**Sender – Serial Monitor:**
  [Sending] Message #4

**Receiver – Serial Monitor:**
  [Received] Message #4

---

## 💡 Possible extensions

- Add environmental sensors (temperature, gas, light…)
- Trigger buzzer/LED on message reception
- Send data via Wi-Fi to a dashboard or Blynk
- Reduce power usage with deepSleep mode
- Log data to SD card or Google Sheets

---

## 👤 Author

**Giuseppe Cialdella**  
📧 giuseppecialdella97@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/giuseppe-cialdella-2b582a295)

---

## 📄 License

Open source project for educational purposes.  
Free to use and adapt with attribution.

---

## 🌍 Languages

> 🇮🇹 This README is also available in Italian: [README_IT.md](./README_IT.md)

