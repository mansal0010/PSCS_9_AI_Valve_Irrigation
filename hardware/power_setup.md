# Power Setup for Smart Irrigation System

This document explains the powering options for the **Automatic Irrigation Valve Control System using AI & IoT**.

---

## 1. ESP32 Board
- The ESP32 can be powered in two ways:
  - **USB 5V Supply** → via laptop or 5V adapter (for lab testing).  
  - **Battery Pack (Li-ion 3.7V with Boost Converter to 5V)** → for standalone field deployment.  

---

## 2. Soil Moisture Sensor
- Powered directly from **ESP32 3.3V/5V pin**.  
- Current requirement is very low (a few mA).  

---

## 3. Relay Module
- Relay requires **5V supply** (provided by ESP32 5V pin or external 5V adapter).  
- Controlled via digital GPIO pin of ESP32.  

---

## 4. Solenoid Valve
- Requires **12V DC power** for operation.  
- Controlled indirectly via the relay module.  
- **Important:** ESP32 cannot supply this power directly. A separate 12V adapter or battery is required.  

---

## 5. Recommended Power Configurations

### ⚡ Lab Testing (Simple)
- ESP32 powered via **USB (5V adapter/laptop)**.  
- Relay powered from ESP32 5V.  
- Solenoid valve powered from **12V DC adapter**.  

### ☀ Field Deployment (Solar)
- ESP32 powered via **5V regulator connected to solar battery**.  
- Relay powered from same 5V line.  
- Solenoid valve powered via **12V battery charged by solar panel**.  

---

## 6. Safety Notes
- Always use a **common ground** between ESP32, relay, and valve power.  
- Ensure the relay is rated for 12V DC loads.  
- Protect electronics with waterproof casing for field deployment.  
