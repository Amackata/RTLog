# RTLog++
Runtime User-Space Log File

![C++](https://img.shields.io/badge/language-C++-blue)
![CMake](https://img.shields.io/badge/build-CMake-green)
![SDL3](https://img.shields.io/badge/SDL-3-orange)
![Platforms](https://img.shields.io/badge/platforms-Linux%20%7C%20Windows%20%7C%20Android-lightgrey)
![Status](https://img.shields.io/badge/status-in%20development-yellow)

___
![Logo](logo.png) \
**RTLog++** is a modular runtime userspace log file, cross-platform C++ project with a strong separation of concerns:

* `core` → independent logic
* `platforms` → SDL3 + OS implementations
* `third_party` → You can use with others external dependencies

___
## 🧱 Architecture

```
ProjectX/
│
├── log/...
│
├── examples
│      ├── CMakelists.txt
│      └── SDL3.cpp
│
├── utils -> RTLog++ 
│   ├── CMakelists.txt
│   ├── rtLogger.hpp
│   └── rtLogger.cpp
│
└── CMakeLists.txt
```
---
# Setup Guide
## 🐧 Linux Setup

### Install (required)

```bash
git clone https://github.com/Amackata/RTLog.git
cd rtLog
cmake -S . -B build
cmake --build build
sudo cmake --install build
```

## 📊 Platform Strategy Progress Comparison

|OS     | Technical Debt         |
|---------|------------------------|
| Linux   | Todo: Systemd(`apt`) ? |
| Windows | Todo:    ??            |
| Android | Precompiled `.a`       |

---
# 📄 MIT License

See License File

---

# 👨‍💻 Garbanzo.com.ar

Still in development 🚧
