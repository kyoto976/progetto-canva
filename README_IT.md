> 🇬🇧 This project is also available in English: [README.md](./README.md)


# 📡 ESP32 LoRa – Comunicazione Punto-Punto (Sender ↔ Receiver)

Questo progetto utilizza due schede ESP32 Heltec LoRa V3 (con chip SX1262 e display OLED integrato) per realizzare una comunicazione punto-punto via LoRa, con visualizzazione locale su display e su serial monitor.  
È composto da un sender che invia messaggi LoRa ogni 5 secondi e un receiver che riceve e mostra i messaggi.  
Progetto sviluppato da Giuseppe Cialdella per scopi didattici ed esplorativi nel campo delle comunicazioni wireless a lungo raggio.

ESP32 Heltec V3 (Sender) → LoRa 868 MHz → ESP32 Heltec V3 (Receiver)

Comunicazione peer-to-peer su frequenze LoRa  
Visualizzazione su display OLED integrato  
Controllo da serial monitor (start / stop)  
Codice separato in due moduli: sender e receiver

progetto_LoRa32/
├── sender/     ← codice del nodo trasmettitore
├── receiver/   ← codice del nodo ricevente
└── README.md   ← questo file

Librerie utilizzate:
- RadioLib – gestione SX1262 LoRa
- HT_SSD1306Wire – display OLED Heltec

Tutte disponibili da Library Manager in Arduino IDE o su PlatformIO.

Sender – cosa fa:
- Invia messaggi "Messaggio #X" ogni 5 secondi via LoRa
- Mostra stato sul display OLED
- Accetta comandi da serial monitor: start per abilitare, stop per disabilitare
- OLED mostra: "Inviato: Messaggio #3"

Receiver – cosa fa:
- Riceve i messaggi dal nodo sender
- Li mostra sul display OLED e nel serial monitor
- Ricezione continua, non bloccante
- OLED mostra: "Ricevuto: Messaggio #3"

Pinout LoRa SX1262 (Heltec V3):
- CS → GPIO 8
- RST → GPIO 12
- BUSY → GPIO 13
- DIO1 → GPIO 14
- SDA OLED → SDA_OLED (predefinito Heltec)
- SCL OLED → SCL_OLED (predefinito Heltec)

Come usare:
1. Carica sender/main.cpp su una board Heltec
2. Carica receiver/main.cpp su un’altra
3. Collega antenna a entrambe le schede
4. Apri il serial monitor per visualizzare i dati
5. Guarda i messaggi anche sul display OLED

Output previsto:
Sender – Serial Monitor:
Invio: Messaggio #4

Receiver – Serial Monitor:
[Ricevuto] Messaggio #4

Idee per estensioni:
- Integrazione con sensori (temperatura, gas, luce…)
- Aggiunta di buzzer/LED alla ricezione
- Invio dati via Wi-Fi a dashboard o Blynk
- Riduzione consumo energetico con deepSleep
- Logging dati su SD card o Google Sheets

Autore:
Giuseppe Cialdella  
giuseppecialdella97@gmail.com  
LinkedIn: https://www.linkedin.com/in/giuseppe-cialdella-2b582a295

Licenza:
Progetto open source a scopo formativo. Libero utilizzo con attribuzione.

Repository layout:
progetto_LoRa32/
├── sender/
│   ├── main.cpp
│   └── README.md
├── receiver/
│   ├── main.cpp
│   └── README.md
└── README.md     ← descrizione generale (questo file)
