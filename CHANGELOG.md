# 📦 Changelog

All notable changes to this project will be documented in this file.

---

## [1.0.0] - 2026-04-30

### ✨ Added

* Initial release of WERA Sharp IR Library
* Support for Sharp GP2Y0A21YK0F sensor
* Power regression model implementation
* Inverse regression model implementation
* Median filtering (25 samples)
* ESP32 ADC optimization (12-bit + attenuation)

### 📊 Performance

* R² ≈ 0.9997 (high accuracy)
* MAE (Power): ~0.0745
* MAE (Inverse): ~0.1536

### 📁 Structure

* Standard Arduino library structure
* Example usage included
* Documentation with regression model
