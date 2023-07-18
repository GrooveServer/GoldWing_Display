# GoldWing Display

This Arduino sketch displays the outside temperature, voltage, and gear indicator on an OLED display using an Arduino-based GoldWing Display. It utilizes the DHT library for temperature sensing, the U8g2 library for the OLED display, and the Wire library for I2C communication.

## Hardware Requirements

To use this code, you will need the following hardware components:

- Arduino board (e.g., Arduino Nano)
- DHT11 temperature and humidity sensor
- OLED display (128x64 resolution, SH1106 controller)
- 15kΩ and 3kΩ resister for the voltage
- Gear indicator (five switches for N, 2, 3, 4, and OD)

Make sure to connect the components to the appropriate pins on the Arduino board as specified in the code. Modify the pin assignments in the code if necessary.

## Libraries

The following libraries are required and should be installed in your Arduino IDE:

- DHT library: Allows reading temperature and humidity from the DHT11 sensor.
- U8g2 library: Provides support for monochrome OLED displays.
- Wire library: Required for I2C communication with the OLED display.

Install these libraries using the Library Manager in the Arduino IDE.

## Usage

1. Connect the hardware components as per the pin assignments specified in the code.

2. Open the Arduino IDE and create a new sketch.

3. Copy and paste the code into the new sketch.

4. Make sure to install the required libraries if not already installed.

5. Select the correct board and port under the "Tools" menu in the Arduino IDE.

6. Upload the sketch to your Arduino board.

7. Once the sketch is uploaded, you should see the temperature, voltage, and gear indicator displayed on the OLED screen.

## Customization

Feel free to customize the code according to your specific requirements. You can modify the display layout, add additional features, or integrate other sensors or indicators.

Make sure to refer to the documentation of the libraries used (DHT library, U8g2 library) for more information on available functions and customization options.

## Author

This code was written by Matthew Neadow on July 11, 2023.

## License

This code is licensed under the GNU General Public License v3.0. You are free to use, modify, and distribute it under the terms of this license. See the [LICENSE](LICENSE) file for more details.
