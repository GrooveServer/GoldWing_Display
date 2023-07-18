#include <dht.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

/*
  GoldWing Display

  This code is written in C++ for an Arduino-based GoldWing Display. It utilizes the DHT library for temperature sensing,
  the U8g2 library for the OLED display, and the Wire library for I2C communication.

  The code displays the outside temperature, voltage, and gear indicator on the OLED display.

  Author: Matthew Neadow
  Date: July 11, 2023

  Library References:
  - DHT library
  - U8g2 library
  - Wire library
*/

// VARIABLES
// For Temperature
dht DHT;
#define DHT11_PIN 7

// For OLED Display
U8G2_SH1106_128X64_NONAME_F_SW_I2C display(U8G2_R0, SCL, SDA, U8X8_PIN_NONE);
#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_ADDR 0x3C

// For Voltage
double voltage = 0.0;

// For Gear Indicator
String currentGear = "";
int delayCount = 0;

/**
   Displays the outside temperature on the OLED display.
*/
void displayOutsideTemperature() {
  const char DEGREE_SYMBOL[] = { 0xB0, '\0' };
  int chk = DHT.read11(DHT11_PIN);
  display.setCursor(10, 20);
  int displayTemp = DHT.temperature;
  display.println(String("TEMP:  ") + String(displayTemp) + String(DEGREE_SYMBOL) + String("C"));
}

/**
   Displays the voltage on the OLED display.
*/
void displayVoltage() {
  voltage = (analogRead(A1) * 0.0293255);
  display.setCursor(10, 40);
  if (voltage < 10.00){
    display.println(String("VOLT:  ") + String(voltage));
  } else {
    display.println(String("VOLT:  ") + String(voltage,1));
  }
  
}

/**
   Displays the gear indicator on the OLED display.
*/
void displayGearIndicator() {
  int sensorValueN = digitalRead(2);
  int sensorValue2 = digitalRead(3);
  int sensorValue3 = digitalRead(4);
  int sensorValue4 = digitalRead(5);
  int sensorValue5 = digitalRead(6);

  display.setCursor(10, 60);

  if (sensorValueN == 0) {
    currentGear=" N";
  } else if (sensorValue2 == 0) {
    currentGear=" 2";
  } else if (sensorValue3 == 0) {
    currentGear=" 3";
  } else if (sensorValue4 == 0) {
    currentGear=" 4";
  } else if (sensorValue5 == 0) {
    currentGear="OD";
  } else {
        currentGear=" 1"; 
  }

  // This code is to avoid 1 showing while swithcing gears
  if (currentGear!=" 1"){
  display.print(String("GEAR:    " + currentGear));
  delayCount=0;
  } else if ((currentGear==" 1") && (delayCount==1)){
  display.print(String("GEAR:    " + currentGear));
  } else {
    display.print(String("GEAR:    "));
    delayCount++;
  }

 
}

void setup() {
  // Initializations
  // Initialize OLED
  display.begin();
  display.setFont(u8g2_font_10x20_tf);

  // Initialize Volt Meter
  pinMode(A1, INPUT);

  // Gear Indicator
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
}

void loop() {
  // Picture loop
  display.firstPage();
  do {
    displayOutsideTemperature();
    displayVoltage();
    displayGearIndicator();

    delay(500);
  } while (display.nextPage());
}
