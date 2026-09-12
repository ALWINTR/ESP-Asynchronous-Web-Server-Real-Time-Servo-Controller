# 🌐 ESP Webserver Real-Time Servo Angle Controller

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/esp-webserver-servo)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![Platform](https://img.shields.io/badge/Platform-ESP8266_%26_ESP32-38bdf8?style=for-the-badge&logo=espressif&logoColor=white)](https://github.com/ALWINTR)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

An embedded asynchronous HTTP web server hosted directly on ESP8266 / ESP32 microcontrollers delivering a responsive web UI with AJAX sliders for real-time 0°-180° servo motor position control, angle feedback, and REST endpoint integration.

---

## 📌 Network Modes & Architecture

- **Station Mode (STA)**: Connects to existing Wi-Fi network with mDNS hostname discovery (`http://esp-servo.local`).
- **Soft Access Point Mode (SoftAP)**: Self-hosts a dedicated standalone Wi-Fi network for off-grid field operations.
- **Asynchronous HTTP Server**: Handles concurrent HTTP GET requests without blocking servo PWM generation.

---

## 🔌 RESTful API Endpoints

| Endpoint | Method | Parameters | Description |
| :--- | :--- | :--- | :--- |
| `/` | `GET` | None | Serves the compressed HTML5 / CSS3 / JS control interface |
| `/set_angle` | `GET` | `value=[0-180]` | Updates servo motor PWM angle and returns JSON status |
| `/status` | `GET` | None | Returns current angle, Wi-Fi RSSI signal strength, and uptime |

---

## ⚙️ Hardware BOM & Pinout

| Module / Pin | ESP8266 Pin | ESP32 Pin | Description |
| :--- | :--- | :--- | :--- |
| **Servo Signal** | GPIO 2 (D4) | GPIO 18 | 50Hz PWM output signal |
| **Servo VCC** | External 5V Rail | External 5V Rail | Power rail (100µF capacitor recommended) |
| **Servo GND** | Common GND | Common GND | System ground reference |

---

## 🚀 Getting Started

1. Clone repository:
   ```bash
   git clone https://github.com/ALWINTR/esp-webserver-servo.git
   ```
2. Open `esp_webserver_servo.ino` in Arduino IDE or VS Code PlatformIO.
3. Configure your Wi-Fi credentials:
   ```cpp
   const char* ssid = "YOUR_WIFI_SSID";
   const char* password = "YOUR_WIFI_PASSWORD";
   ```
4. Upload firmware, open Serial Monitor at **115200 baud** to retrieve the IP address, and access the web UI in any browser.

---

## 👨‍💻 Author

**Alwin T R** — Robotics & Automation Engineer  
- 💼 LinkedIn: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- 🌌 Portfolio: [alwintr.github.io](https://alwintr.github.io)  
- 💻 GitHub: [github.com/ALWINTR](https://github.com/ALWINTR)

---

## 📄 License

This project is licensed under the **MIT License** — see the [LICENSE](LICENSE) file for details.
