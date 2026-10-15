# ESP Asynchronous Web Server Real Time Servo Controller

<div align="center">

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/ESP-Asynchronous-Web-Server-Real-Time-Servo-Controller)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![Portfolio](https://img.shields.io/badge/Portfolio-alwintr.github.io-00f0ff?style=for-the-badge&logo=googlechrome&logoColor=black)](https://alwintr.github.io)
[![License](https://img.shields.io/badge/License-MIT-10b981?style=for-the-badge)](LICENSE)

</div>

> Embedded asynchronous HTTP web server hosted directly on ESP microcontrollers delivering an interactive browser slider UI for multi-angle servo motor telemetry and PWM calibration.

---

## 📌 Executive Overview

Embedded asynchronous HTTP web server hosted directly on ESP microcontrollers delivering an interactive browser slider UI for multi-angle servo motor telemetry and PWM calibration. This repository contains production-ready firmware implementations, hardware wiring pinouts, signal conditioning routines, and real-time telemetry pipelines engineered for reliable physical operation.

- **Primary Domain**: IoT & Telemetry
- **Microcontroller & Hardware Core**: ESP8266 / Async
- **Specialization**: Web Telemetry
- **Live Specs & BOM Viewer**: [alwintr.github.io](https://alwintr.github.io)

---

## 📐 System Architecture & Signal Flow

```
+--------------------------------------------------------------+
|        Client Web Browser (Desktop / Mobile Device)          |
|    - HTML5 Glassmorphism UI   - Real-Time Angle Slider HUD   |
+--------------------------------------------------------------+
        |
        | Asynchronous HTTP GET / POST (/set-angle?val=X)
        v
+--------------------------------------------------------------+
|                   ESP8266 / ESP32 Microcontroller            |
|  - ESPAsyncWebServer Library  - Zero-Downtime Event Loop     |
|  - SPIFFS Static File Hosting - Non-Blocking PWM Scheduler   |
+--------------------------------------------------------------+
                                |
                                v Hardware PWM Pulse (500us - 2500us)
                   +--------------------------+
                   |   TowerPro SG90 Servo    |
                   +--------------------------+
```

---

## 📋 Hardware Bill of Materials (BOM)

| Component Name | Operating Voltage | Interface / Functionality |
| :--- | :--- | :--- |
| **NodeMCU ESP8266 / ESP32** | `3.3V / 5V` | Wi-Fi 802.11 b/g/n SoC |
| **TowerPro SG90 Servo** | `5V DC` | 180-degree angular actuator |
| **AMS1117-3.3 Voltage Regulator** | `5V -> 3.3V` | Microcontroller power rail |
| **1000uF Electrolytic Capacitor** | `6.3V` | Servo power rail decoupling |

---

## 🔌 Circuit Pinout & Microcontroller Interconnect

| MCU Pin / Channel | Peripheral Pin | Signal Function / Bus |
| :--- | :--- | :--- |
| `ESP8266 GPIO 4 (D2)` | `SG90 Servo Signal` | Hardware PWM Output |
| `ESP8266 5V (VIN)` | `Servo VCC` | Decoupled with 1000uF capacitor |
| `ESP8266 GND` | `Servo Ground` | Common Ground Rail |

---

## ⚙️ Firmware Architecture & Control Logic

Asynchronous event-driven HTTP request parser handling concurrent clients without blocking the main microcontroller execution loop or interrupting PWM timers.

### Key Firmware Capabilities:
- **Zero-Blocking Architecture**: Real-time non-blocking scheduling eliminating delay() deadlocks.
- **Hardware Interrupt Servicing**: Microsecond-precision edge-triggered pulse detection and safety shutoffs.
- **Diagnostic Telemetry**: Continuous serial datastreaming and state-machine transition logging.

---

## 📁 Repository Structure

```
ESP-Asynchronous-Web-Server-Real-Time-Servo-Controller/
├── .gitignore
├── esp_webserver_servo.ino
├── LICENSE
└── README.md
```

---

## 🚀 Build & Deployment Instructions

### 1. Hardware Assembly
- Verify common system ground across all microcontrollers, drivers, and peripheral sensor boards.
- Ensure dedicated power supply rails match the operating voltage specified in the Hardware Bill of Materials.

### 2. Firmware Compilation & Flashing
```bash
# Clone the repository
git clone https://github.com/ALWINTR/ESP-Asynchronous-Web-Server-Real-Time-Servo-Controller.git

# Navigate to the project directory
cd ESP-Asynchronous-Web-Server-Real-Time-Servo-Controller
```

- Open the project in **Arduino IDE**, **PlatformIO**, or **ESP-IDF**.
- Select the target board configuration and COM port.
- Compile and upload firmware directly to the microcontroller.

---

## 👨‍💻 Author

**Alwin T R** — Robotics & Automation Engineer  
- 💼 **LinkedIn**: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- 🌐 **Interactive Portfolio**: [alwintr.github.io](https://alwintr.github.io)  
- 🐙 **GitHub**: [github.com/ALWINTR](https://github.com/ALWINTR)  
- ✉️ **Direct Email**: [alwintr2003@gmail.com](mailto:alwintr2003@gmail.com)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
