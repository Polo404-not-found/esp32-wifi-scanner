# ESP32 WiFi Spectrum Scanner

An educational, passive WiFi reconnaissance tool built with an ESP32.

## What it does

Scans the WiFi spectrum and lists nearby networks with:

- SSID
- Signal strength (RSSI in dBm)
- Encryption type (Open, WEP, WPA, WPA2, WPA3)

**It does not attack, inject, or capture traffic.** It only listens.

## Why this exists

This project was built to:

- Learn about WiFi protocols and encryption types.
- Audit my own environment (detect open or WEP-protected networks).
- Practice embedded programming with the ESP32.
- Understand how passive reconnaissance works at the hardware level.

## Hardware

- ESP32 (any variant with WiFi)
- USB cable
- Serial monitor at 115200 baud

## How to use

### With Arduino IDE

1. Install the ESP32 board support in Arduino IDE.
2. Open `src/main.cpp`.
3. Select your ESP32 board and the correct port.
4. Upload the sketch.
5. Open the Serial Monitor at `115200` baud.

### With PlatformIO

1. Create a new PlatformIO project for ESP32.
2. Replace `src/main.cpp` with the file from this repo.
3. Build and upload:

```bash
pio run --target upload
pio device monitor --baud 115200
```
## Add OLED/LCD display support.
□ Add async scanning to avoid blocking.
□ Add CSV export over serial.
□ Add support for ESP32-C5 (5 GHz scanning).
Legal notice

This directory is intended for PlatformIO Test Runner and project tests.

Unit Testing is a software testing method by which individual units of
source code, sets of one or more MCU program modules together with associated
control data, usage procedures, and operating procedures, are tested to
determine whether they are fit for use. Unit testing finds problems early
in the development cycle.

More information about PlatformIO Unit Testing:
- https://docs.platformio.org/en/latest/advanced/unit-testing/index.html
