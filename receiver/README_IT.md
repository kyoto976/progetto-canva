# 📥 ESP32 LoRa - Receiver (Heltec V3)

Questo sketch utilizza un **ESP32 Heltec LoRa V3** per ricevere messaggi via LoRa da un nodo trasmettitore.  
I messaggi vengono mostrati sul **Serial Monitor** e su un **display OLED** integrato.

---

## 📦 Librerie utilizzate

- [`RadioLib`](https://github.com/jgromes/RadioLib) – per ricezione via SX1262
- `HT_SSD1306Wire` – per il display OLED Heltec integrato

---

## ⚙️ Componenti utilizzati

| Componente        | Descrizione                      |
|-------------------|----------------------------------|
| ESP32 Heltec V3   | Con chip LoRa SX1262 + OLED      |
| Antenna           | 868 MHz o 433 MHz                |
| PC + cavo USB     | Per alimentazione e monitoraggio |

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

| Segnale | ESP32 Pin         |
|---------|-------------------|
| SDA     | SDA_OLED (board)  |
| SCL     | SCL_OLED (board)  |
| RST     | RST_OLED (board)  |

ℹ️ I pin OLED sono già gestiti dalla libreria `HT_SSD1306Wire` su Heltec V3.

---

## ▶️ Funzionamento

1. All'avvio, il display mostra:
   - `"LoRa Receiver..."`  
   - `"In ascolto..."`
2. Il modulo resta in ascolto LoRa.
3. Quando riceve un messaggio:
   - Lo stampa sul **Serial Monitor**
   - Lo visualizza su **display OLED**

⚠️ Se il messaggio non arriva o va in timeout, il loop riprova automaticamente.

---

## 🧪 Output esempio

**Serial Monitor:**
   [Ricevuto] Messaggio #3
   [Ricevuto] Messaggio #4

**Display OLED:**
  Ricevuto:
  Messaggio #3

---

## 💡 Note tecniche

- Il codice usa `lora.receive(msg)` per ricezione non bloccante
- In caso di `RADIOLIB_ERR_RX_TIMEOUT`, la ricezione si riavvia senza interrompere il loop
- Delay minimo di 10 ms per migliorare la stabilità del loop

---

## 📁 File inclusi
/receiver
├── main.cpp ← Codice completo ricevitore
└── README.md ← Questo file

---

## 🛠️ Idee per evoluzione

- Aggiungere buzzer/LED al ricevimento messaggi
- Visualizzare il numero totale dei messaggi ricevuti
- Salvare i dati in SD o inviarli a una dashboard

---

## 👤 Autore

**Giuseppe Cialdella**  
📧 giuseppecialdella97@gmail.com  
🔗 [LinkedIn](https://www.linkedin.com/in/giuseppe-cialdella-2b582a295)

---

## 🛡️ Licenza

Progetto open source a scopo didattico.
