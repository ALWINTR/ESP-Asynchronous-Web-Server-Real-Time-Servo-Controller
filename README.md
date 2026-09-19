# ESP Asynchronous Web Server Real Time Servo Controller

[![GitHub Repository](https://img.shields.io/badge/GitHub-Repository-00f0ff?style=for-the-badge&logo=github&logoColor=white)](https://github.com/ALWINTR/esp-webserver-servo)
[![Developer](https://img.shields.io/badge/Developer-Alwin_T_R-0284c7?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/alwintr)
[![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)](LICENSE)

An embedded asynchronous HTTP web server hosted directly on ESP8266 and ESP32 microcontrollers delivering a responsive web UI with AJAX sliders for real-time 0 to 180 degree servo motor position control, angle feedback, and REST endpoint integration.

---

## Network Architecture and RESTful Endpoints

- **Station Mode (STA)**: Connects to existing Wi-Fi LAN with mDNS hostname discovery.
- **Soft Access Point Mode (SoftAP)**: Self-hosts a dedicated standalone Wi-Fi network for field operations.
- **Asynchronous Architecture**: Handles concurrent HTTP GET requests without blocking PWM timer pulse generation.

| Endpoint | Method | Parameters | Description |
| :--- | :--- | :--- | :--- |
| `/` | `GET` | None | Serves the compressed HTML5 / CSS3 / JS control interface |
| `/set_angle` | `GET` | `value=[0-180]` | Updates servo motor PWM angle and returns JSON status |
| `/status` | `GET` | None | Returns current angle, Wi-Fi RSSI signal strength, and uptime |

---

## Circuit Pinout Table

| Module / Pin | ESP8266 Pin | ESP32 Pin | Description |
| :--- | :--- | :--- | :--- |
| **Servo Signal** | GPIO 2 (D4) | GPIO 18 | 50Hz PWM output signal |
| **Servo Power (VCC)** | External 5V Rail | External 5V Rail | Regulated power supply (100uF capacitor) |
| **Ground (GND)** | Common GND | Common GND | Shared system ground |

---

## Author

**Alwin T R** - Robotics and Automation Engineer  
- LinkedIn: [linkedin.com/in/alwintr](https://www.linkedin.com/in/alwintr)  
- Portfolio: [alwintr.github.io](https://alwintr.github.io)  
- GitHub: [github.com/ALWINTR](https://github.com/ALWINTR)

---

## License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.
