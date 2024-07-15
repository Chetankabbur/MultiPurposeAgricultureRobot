# MultiPurposeAgricultureRobot
This project implements a multipurpose agriculture bot using an ESP8266 microcontroller, controlled via the RemoteXY application. The bot includes functionalities for movement, spraying, honking, and lighting, with feedback displayed on an LCD.

Hardware Requirements
ESP8266 microcontroller
L298N Motor Driver
LiquidCrystal_I2C LCD (16x2)
2 DC Motors for movement
Sprayer, horn, and lighting components
Breadboard and jumper wires
Software Requirements
Arduino IDE
RemoteXY Library
LiquidCrystal_I2C Library
Connection Diagram
Motors:

Motor 1: D2 and D3
Motor 2: D4 and D5
Sprayer:

Control pin: D8
Horn:

Control pin: D6
Light:

Control pin: D10
LCD:

SDA: A4
SCL: A5
RemoteXY Configuration
The RemoteXY interface is configured to control the bot via a WiFi connection. Here are the main components:

Push buttons to control movements, sprayer, horn, and ligh.
