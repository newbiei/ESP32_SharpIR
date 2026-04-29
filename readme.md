# 🚀 WERA Sharp IR Library (ESP32)

Arduino library for reading the **Sharp IR distance sensor GP2Y0A21YK0F** using **ESP32**, with **data-driven regression models (Power & Inverse)** and **median filtering** for stable and accurate distance measurement.

---

## ✨ Features

* 📏 Distance output in centimeters (cm)
* 📊 **Power Regression Model** (best fit from experimental data)
* 📈 **Inverse Regression Model** (matches IR sensor characteristics)
* 🔇 Median filtering (25 samples) for noise reduction
* ⚡ Optimized for ESP32 (12-bit ADC + attenuation)
* 🎯 High accuracy (R² ≈ 0.9997)

---

## 📌 Sensor Used

This library is specifically designed and calibrated for:

> **Sharp GP2Y0A21YK0F Infrared Distance Sensor**

### Sensor Characteristics:

* Measurement range: **10 cm – 80 cm**
* Output: Analog voltage (non-linear)
* Highly sensitive to noise and surface reflectivity
* Requires calibration for accurate distance estimation

---

## 📦 Installation

### Manual Installation

```bash
git clone https://github.com/username/WERA_SharpIR.git
```

Move the folder to:

```
Documents/Arduino/libraries/
```

Restart Arduino IDE.

---

## 🧪 Usage Example

```cpp
#include <WERA_SharpIR.h>

WERASharpIR sensor(35);

void setup() {
  Serial.begin(115200);
}

void loop() {
  float d_power   = sensor.readCM();    // Power regression
  float d_inverse = sensor.readCMv2();  // Inverse regression

  Serial.print("Power: ");
  Serial.print(d_power);

  Serial.print(" | Inverse: ");
  Serial.println(d_inverse);

  delay(500);
}
```

📌 See the `examples/` folder for:

* Power regression usage
* Inverse regression usage
* Mode switching via Serial

---

## 📊 Regression Models

### 🔹 Power Regression

```
ADC = 22581.6 × distance^(-0.9184)
```

Inverse form:

```
distance = (ADC / 22581.6)^(1 / -0.9184)
```

---

### 🔹 Inverse Regression

```
ADC = 29103.3 / (distance + 0.89) + 49.57
```

Inverse form:

```
distance = 29103.3 / (ADC - 49.57) - 0.89
```

---

## 📈 Performance

| Model   | MAE     | RMSE    | MAPE   |
| ------- | ------- | ------- | ------ |
| Power   | ~0.0745 | ~0.0745 | ~0.31% |
| Inverse | ~0.1536 | ~0.1536 | ~0.64% |

📌 Both models achieve very high accuracy (R² ≈ 0.9997)
📌 The **Power model shows lower error** on the experimental dataset

---

## ⚙️ Hardware

* ESP32
* Sharp GP2Y0A21YK0F
* Sensor supply: **5V**
* ADC resolution: 12-bit (0–4095)

---

## 🧠 How It Works

1. Reads analog voltage from the IR sensor (ADC)
2. Applies **median filtering (25 samples)**
3. Converts ADC value into distance using regression models
4. Clamps output to valid range (**10–80 cm**)

---

## ⚠️ Notes

* Measurements below 10 cm and above 80 cm are less reliable
* Sensor output is non-linear → regression is required
* Noise may occur due to power supply or environment
* Choose model based on use case:

  * Power → best experimental accuracy
  * Inverse → physically representative model

---

## 🔥 Use Cases

* 🤖 Robotics navigation (WERA)
* 🚧 Obstacle detection
* 🧠 Smart sensing systems
* 📡 IoT monitoring

---

## 📸 Preview

Add regression graph or hardware setup image:

```
docs/graph.png
```

---

## 👨‍💻 Author

**Ramdesh Gustiar**
Electrical Engineering Student
Project: WERA (Whiteboard Eraser Automation)

---

## 📜 License

MIT License — free to use and modify.

---

## ⭐ Support

If this project helps you:

* ⭐ Star this repository
* 🍴 Fork it
* 🐛 Open an issue for bugs or suggestions

---

## 🚀 Future Development

* [ ] Auto calibration
* [ ] Multi-sensor support
* [ ] Adaptive filtering
* [ ] IoT integration (Firebase)

---
