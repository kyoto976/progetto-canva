# 📥 ESP32 LoRa - Receiver (Heltec V3)

This sketch uses an **ESP32 Heltec LoRa V3** board to receive messages via LoRa from a transmitter node.  
Received messages are shown on the **Serial Monitor** and on the integrated **OLED display**.

---

## 📦 Libraries used

- [`RadioLib`](https://github.com/jgromes/RadioLib) – for receiving via SX1262
- `HT_SSD1306Wire` – for integrated Heltec OLED display

---

## ⚙️ Components used

| Component         | Description                      |
|-------------------|----------------------------------|
| ESP32 Heltec V3   | With LoRa SX1262 + OLED display  |
| Antenna           | 868 MHz or 433 MHz               |
| USB cable + PC    | For power and serial monitoring  |

---

## 🔌 LoRa SX1262 Pinout (Heltec V3)

| LoRa Signal | ESP32 GPIO |
|-------------|------------|
| CS          | GPIO 8     |
| RST         | GPIO 12    |
| BUSY        | GPIO 13    |
| DIO1        | GPIO 14    |

---

## 📟 OLED Display (Integrated I2C)

| Signal | ESP32 Pin       |
|--------|-----------------|
| SDA    | SDA_OLED        |
| SCL    | SCL_OLED        |
| RST    | RST_OLED        |

ℹ️ The OLED pins are automatically handled by the `HT_SSD1306Wire` library for Heltec V3.

---

## ▶️ How it works

1. On startup, the OLED shows:
   - `"LoRa Receiver..."`
   - `"Listening..."`
2. The module continuously listens for incoming LoRa messages.
3. When a message is received:
   - It prints to the **Serial Monitor**
   - It is displayed on the **OLED**

⚠️ If no message is received (timeout), the loop retries automatically.

---

## 🧪 Example Output

**Serial Monitor:**
  [Received] Message #3
  [Received] Message #4

**OLED Display:**
Received: Message #3

---

## 💡 Technical Notes

- The code uses `lora.receive(msg)` with non-blocking mode
- If `RADIOLIB_ERR_RX_TIMEOUT` occurs, the receiver retries without freezing
- A small delay of 10 ms helps stabilize the loop

---

## 📁 Included files

/receiver
├── main.cpp ← Full receiver code
└── README.md ← This file

---

## 🛠️ Ideas for improvement

- Add buzzer or LED to indicate reception
- Display a message counter
- Save data to SD card or send to a web dashboard

---

## 👤 Author

**Giuseppe Cialdella**  
📧 giuseppecialdella97@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/giuseppe-cialdella-2b582a295)

---

## 🛡️ License

Open source project for educational purposes.

