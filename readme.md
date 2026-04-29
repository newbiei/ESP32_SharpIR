# 🚀 WERA Sharp IR Library (ESP32)

Library Arduino untuk membaca sensor **Sharp IR GP2Y0A21YK0F** menggunakan **ESP32** dengan pendekatan **regresi matematis berbasis data eksperimen (Power & Inverse)** + **median filtering** untuk hasil yang stabil dan akurat.

---

## ✨ Features

* 📏 Output jarak dalam satuan cm
* 📊 Regresi **Power Model** (best fit dari eksperimen)
* 📈 Regresi **Inverse Model** (sesuai karakter sensor IR)
* 🔇 Median filtering (25 sampel) untuk reduksi noise
* ⚡ Optimized untuk ESP32 (ADC 12-bit + attenuation)
* 🎯 Akurasi tinggi (R² ≈ 0.9997)

---

## 📦 Installation

### Manual Install

```bash
git clone https://github.com/newbiei/ESP32_SharpIR.git
```

Pindahkan ke:

```
Documents/Arduino/libraries/
```

Lalu restart Arduino IDE.

---

## 🧪 Usage Example

```cpp
#include <WERA_SharpIR.h>

WERASharpIR sensor(35);

void setup() {
  Serial.begin(115200);
}

void loop() {
  float d_power   = sensor.readCM();    // Regresi Power
  float d_inverse = sensor.readCMv2();  // Regresi Inverse

  Serial.print("Power: ");
  Serial.print(d_power);

  Serial.print(" | Inverse: ");
  Serial.println(d_inverse);

  delay(500);
}
```

📌 Di folder `examples/` tersedia:

* mode **Regresi Power**
* mode **Regresi Inverse**
* contoh **switching mode via Serial**

---

## 📊 Model Regresi

### 🔹 Regresi Pangkat (Power)

```
ADC = 22581.6 × jarak^(-0.9184)
```

Inverse:

```
jarak = (ADC / 22581.6)^(1 / -0.9184)
```

---

### 🔹 Regresi Inverse

```
ADC = 29103.3 / (jarak + 0.89) + 49.57
```

Inverse:

```
jarak = 29103.3 / (ADC - 49.57) - 0.89
```

---

## 📈 Performance

| Model   | MAE     | RMSE    | MAPE   |
| ------- | ------- | ------- | ------ |
| Power   | ~0.0745 | ~0.0745 | ~0.31% |
| Inverse | ~0.1536 | ~0.1536 | ~0.64% |

📌 Kedua model memiliki akurasi sangat tinggi (R² ≈ 0.9997)

📌 Pada dataset eksperimen, **Regresi Power memberikan error lebih kecil**

---

## ⚙️ Hardware

* ESP32
* Sharp IR GP2Y0A21YK0F
* Supply sensor: **5V**
* Output analog ke ESP32 (ADC 12-bit)

---

## 🧠 How It Works

1. Sensor membaca nilai analog (ADC 0–4095)
2. Dilakukan **median filtering (25 sampel)**
3. Nilai dikonversi ke jarak menggunakan model regresi
4. Output dibatasi pada range **10–80 cm**

---

## ⚠️ Notes

* Nilai di bawah ~10 cm dan di atas ~80 cm kurang stabil
* Pastikan pembacaan ADC stabil (hindari noise supply)
* Gunakan model sesuai kebutuhan:

  * Power → akurasi terbaik (hasil eksperimen)
  * Inverse → representasi karakter sensor

---

## 🔥 Use Case

* 🤖 Robot navigasi
* 🚧 Obstacle detection
* 🧠 Smart sensing system
* 📡 IoT monitoring

---

## 📸 Preview

Tambahkan grafik hasil regresi atau foto perangkat:

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

MIT License — bebas digunakan & dikembangkan.

---

## ⭐ Support

Kalau project ini membantu:

* ⭐ Star repo
* 🍴 Fork
* 🐛 Open issue jika ada bug

---

## 🚀 Future Development

* [ ] Auto calibration
* [ ] Multi-sensor support
* [ ] Adaptive filtering
* [ ] IoT integration (Firebase)

---
