/*************************************************************
  Zero-Account Wi-Fi Servo Controller (Web Server)
  Compatible with: ESP8266 (NodeMCU/D1 Mini) & ESP32 Dev Module
  
  NO BLYNK ACCOUNT REQUIRED!
  - Creates a beautiful web interface accessible from your phone/PC.
  - Has an ON/OFF toggle switch to move the servo between 0° and 180°.
  
  Libraries Required:
  - For ESP32: "ESP32Servo" by Kevin Harrington
  - For ESP8266: Built-in "Servo" and "ESP8266WebServer"
 *************************************************************/

#if defined(ESP8266)
  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>
  #include <Servo.h>
  ESP8266WebServer server(80);
  const int SERVO_PIN = D4; // GPIO 2
  Servo myServo;
#elif defined(ESP32)
  #include <WiFi.h>
  #include <WebServer.h>
  #include <ESP32Servo.h>
  WebServer server(80);
  const int SERVO_PIN = 18; // GPIO 18
  Servo myServo;
#else
  #error "Select ESP8266 or ESP32 board in your Arduino IDE"
#endif

// --- Wi-Fi Credentials ---
const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";

// --- Servo State ---
int currentPos = 0; // 0 or 180

// HTML Web Page
const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Servo 180 Control</title>
  <style>
    body { font-family: 'Segoe UI', Arial, sans-serif; text-align: center; background: #0f172a; color: #f8fafc; margin: 0; padding: 40px 15px; }
    .card { background: #1e293b; max-width: 400px; margin: 0 auto; padding: 30px 20px; border-radius: 20px; box-shadow: 0 10px 25px rgba(0,0,0,0.5); }
    h1 { font-size: 24px; margin-bottom: 5px; color: #38bdf8; }
    p { color: #94a3b8; font-size: 14px; margin-bottom: 25px; }
    .status { font-size: 18px; margin: 20px 0; font-weight: bold; }
    .status span { color: #38bdf8; }
    .switch-btn { display: inline-block; width: 140px; padding: 15px 0; margin: 10px; font-size: 18px; font-weight: bold; border-radius: 12px; border: none; cursor: pointer; transition: 0.2s; text-decoration: none; color: white; }
    .btn-on { background: #10b981; box-shadow: 0 4px 14px rgba(16, 185, 129, 0.4); }
    .btn-on:hover { background: #059669; }
    .btn-off { background: #ef4444; box-shadow: 0 4px 14px rgba(239, 68, 68, 0.4); }
    .btn-off:hover { background: #dc2626; }
  </style>
</head>
<body>
  <div class="card">
    <h1>🤖 Servo Motor Controller</h1>
    <p>Wi-Fi 0&deg; / 180&deg; Switch Control</p>
    <div class="status">Current Angle: <span>%ANGLE%&deg;</span></div>
    <div>
      <a href="/set?pos=180" class="switch-btn btn-on">ROTATE 180&deg;</a>
      <a href="/set?pos=0" class="switch-btn btn-off">RETURN 0&deg;</a>
    </div>
  </div>
</body>
</html>
)rawliteral";

void handleRoot() {
  String html = INDEX_HTML;
  html.replace("%ANGLE%", String(currentPos));
  server.send(200, "text/html", html);
}

void handleSet() {
  if (server.hasArg("pos")) {
    int target = server.arg("pos").toInt();
    target = constrain(target, 0, 180);
    myServo.write(target);
    currentPos = target;
    Serial.print("[SERVO] Moved to: ");
    Serial.print(target);
    Serial.println("°");
  }
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  delay(500);
  Serial.println("\n=== Wi-Fi Servo Web Server ===");

  #if defined(ESP32)
    ESP32PWM::allocateTimer(0);
    ESP32PWM::allocateTimer(1);
    ESP32PWM::allocateTimer(2);
    ESP32PWM::allocateTimer(3);
    myServo.setPeriodHertz(50);
    myServo.attach(SERVO_PIN, 500, 2400);
  #elif defined(ESP8266)
    myServo.attach(SERVO_PIN);
  #endif

  myServo.write(0);
  currentPos = 0;

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi: ");
  Serial.print(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\n[WIFI] Connected!");
  Serial.print("[WIFI] Open this URL in your browser: http://");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/set", handleSet);
  server.begin();
  Serial.println("[SERVER] Web server started.");
}

void loop() {
  server.handleClient();
}
