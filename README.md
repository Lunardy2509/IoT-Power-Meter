<details>
<summary>Click to view Documentation Images</summary>

| | | |
|---|---|---|
| ![1](https://github.com/Lunardy2509/IoT_esp8266_Ampmeter_Tempmeter/blob/main/documentation/IMG-20240329-WA0028.jpg) | ![2](https://github.com/Lunardy2509/IoT_esp8266_Ampmeter_Tempmeter/blob/main/documentation/IMG-20240329-WA0024.jpg) | ![3](https://github.com/Lunardy2509/IoT_esp8266_Ampmeter_Tempmeter/blob/main/documentation/IMG-20240329-WA0029.jpg) |

</details>

# 🌐 IoT ESP8266-Based Ampmeter & Temperature Meter

This project is an IoT-enabled ammeter and temperature monitoring system using **ESP8266**, implemented in a school environment in **Depok, West Java, Indonesia**. It aims to monitor energy usage in various electronic devices by sending real-time data to a dashboard from over 60+ ESP8266 nodes installed in classrooms.

---

## 🧭 Project Goal

The primary purpose is to:

- 📡 Monitor **electric current** (via ammeter sensors)
- 🌡️ Monitor **temperature** in real-time
- 🧠 Transmit sensor data using **ESP8266 (WiFi)** to a central dashboard
- 🏫 Deploy **60+ ESP nodes**, each sending hourly usage data from classrooms

---

## ⚙️ Features

- ✅ Measures **current consumption** using analog sensors (e.g., ACS712)
- ✅ Monitors **ambient temperature** using digital sensors (e.g., DHT11/DHT22)
- ✅ Sends data via WiFi using **ESP8266 (NodeMCU)**
- ✅ Supports MQTT/HTTP-based data pushing (configurable)
- ✅ Scalable to 50+ classroom nodes
- ✅ Easy dashboard integration (e.g., ThingsBoard, Firebase, or custom)

---

## 🧰 Components Used

| Component               | Quantity | Description                            |
|------------------------|----------|----------------------------------------|
| ESP8266 (NodeMCU)      | 1 per node | WiFi microcontroller                   |
| ACS712 Current Sensor  | 1        | To measure current (0–5A)              |
| DHT11 / DHT22 Sensor   | 1        | For temperature monitoring             |
| 10kΩ Resistor          | 1        | Pull-up for DHT sensor                 |
| WiFi Connection        | -        | Required for data transmission         |
| Power Supply (5V)      | 1        | For NodeMCU and sensors                |

---

## 🗂️ Folder Structure

```bash
IoT_esp8266_Ampmeter_Tempmeter/
├── circuit_schematics/        # Fritzing diagrams or circuit PDFs
├── code/                      # Arduino sketches (.ino)
│   └── main_node.ino
├── documentation/             # Any research, report, or guides
├── List of Components.xlsx    # Bill of materials
└── README.md
```

## 🚀 How to Deploy
### 1. Clone the Repository
```bash
git clone https://github.com/Lunardy2509/IoT_esp8266_Ampmeter_Tempmeter.git
cd IoT_esp8266_Ampmeter_Tempmeter/code
```

### 2. Install Required Arduino Libraries
- `ESP8266WiFi.h`
- `DHT.h`
- `Adafruit_Sensor.h`
- `PubSubClient.h` (for MQTT)
Install via **Arduino IDE** → **Sketch** → **Include Library** → **Manage Libraries**

### 3. Connect the Circuit
- Follow the diagrams in `circuit_schematics/`
- Connect ACS712 to analog pin
- Connect DHT11 to digital pin (with 10kΩ pull-up)

### 4. Configure Your WiFi Credentials
In `main_node.ino`, replace:
```cpp
const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";
const char* mqtt_server = "broker.example.com";
```

### 5. Upload & Monitor
- Select `NodeMCU 1.0` as your board
- Upload the sketch
- Open Serial Monitor to debug or view transmissions

## 🌐 Integration Options
You can integrate this system with:
- 📊 ThingsBoard.io
- 🔥 Firebase Realtime DB
- 📈 Custom MQTT Dashboard (Node-RED, Grafana, etc.)
- 🧪 Classroom-level energy consumption analysis

## ⚠️ Disclaimer
This project is adapted from various IoT community examples. Hardware assembly and deployment logic were done by me. Credit goes to original authors for core sensor libraries and firmware references.

## 📬 Contact
- GitHub: [@Lunardy2509](https://github.com/Lunardy2509)
- Email: ferdilunardy@gmail.com

If this project inspires your smart classroom ideas, consider giving it a ⭐️ or forking it to enhance it further!

---

Would you like me to:
- Translate it to **Bahasa Indonesia**?
- Add a **diagram or system flow** section?
- Help you generate a `LICENSE` or `requirements.txt` for libraries?

Let me know!
