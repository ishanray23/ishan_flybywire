# ishan_flybywire
May 31, Nov 6 2024 Modeling an aircraft flybywire system through arduino

Fly-By-Wire Servo Control System (Arduino + OLED + Wi-Fi)
Overview

This project simulates a basic fly-by-wire control system using an Arduino (or ESP8266), a servo motor, a potentiometer, and an OLED display.
It demonstrates how aircraft control surfaces (like an aileron or rudder) can be controlled electronically — without a direct mechanical link between the control stick and the actuator.

The servo angle is controlled by a potentiometer, representing a pilot’s control input. The current servo angle is displayed in real time on an OLED screen, and can also be viewed through a simple Wi-Fi web interface.

Features
Real-time servo control using a potentiometer input
Live angle feedback displayed on an OLED (128×64) display
Web server interface hosted by the ESP8266, showing the servo’s current angle
Compact and educational model of fly-by-wire control logic

Components Used
Component	Description
Arduino Uno , ESP8266	Main microcontroller board
SG90 Servo Motor	Represents the aircraft control surface
10kΩ Potentiometer	Acts as the pilot’s control stick
0.96” OLED Display (SSD1306, I2C)	Displays the servo angle
Breadboard + Jumper Wires	For connections
Wi-Fi Network	For web monitoring

Circuit Connections
Servo Motor
Servo Pin	Arduino Pin
Signal	D9
VCC	5V
GND	GND
Potentiometer
Pot Pin	Arduino Pin
Middle (Output)	A0
Side 1	5V
Side 2	GND
OLED Display (I2C)
OLED Pin	Arduino Pin
GND	GND
VCC	5V
SCL	A5 (or D1 for ESP8266)
SDA	A4 (or D2 for ESP8266)


How It Works
Input (Potentiometer):
The potentiometer converts analog rotation into a voltage signal (0–1023).
This value represents the pilot’s command.
Processing (Arduino/ESP8266):
The analog input is mapped to a servo angle between 0° and 180°.
The Arduino sends the corresponding PWM signal to the servo.
Output (Servo Motor):
The servo rotates to the commanded angle, simulating a control surface’s movement.
Feedback (OLED Display):
The OLED screen displays the current servo angle in real time.
Web Interface (ESP8266):
The ESP8266 hosts a simple web page.
When accessed from a browser (via the printed IP address), the current servo angle is displayed.

Usage Instructions:
Install Libraries
Servo.h
Wire.h
Adafruit_GFX.h
Adafruit_SSD1306.h
ESP8266WiFi.h

These can be installed via the Arduino Library Manager.

Upload Code
Open the .ino file in Arduino IDE.
Replace your_SSID and your_PASSWORD with your Wi-Fi credentials.
Upload the code to your board.
Run
Open the Serial Monitor at 115200 baud.

Wait for “Server started” and note the printed IP address.

Visit the shown IP (e.g., http://192.168.1.100) in a browser to view the servo angle.

Adjust Potentiometer
Rotating the potentiometer will move the servo and update the OLED and web display simultaneously.

Demonstration (Conceptually)

Input: Potentiometer rotation
Flight Computer: Arduino/ESP8266 processes and maps control input
Actuator: Servo motor adjusts position accordingly
Feedback Display: OLED and Web Interface show real-time angle

This mimics the fundamental loop of a fly-by-wire system: pilot → computer → actuator → feedback.

Troubleshooting

If the OLED screen remains blank:
Check I2C address (usually 0x3C).
Ensure SDA and SCL pins are correctly connected.
If Wi-Fi doesn’t connect:
Double-check your SSID and password.
Make sure your board supports Wi-Fi (ESP8266-based).
If servo jitters:
Use an external 5V power supply with a common ground.
