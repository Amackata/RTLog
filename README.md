# RTLog++
Runtime User-Space Log File - v0.0.1a

![C++](https://img.shields.io/badge/language-C++-blue)
![CMake](https://img.shields.io/badge/build-CMake-green)
![SDL3](https://img.shields.io/badge/SDL-3-orange)
![Platforms](https://img.shields.io/badge/platforms-Linux%20%7C%20Windows%20%7C%20Android-lightgrey)
![Status](https://img.shields.io/badge/status-in%20development-yellow)


![Logo](logo.png) \
**RTLog++** is a modular runtime userspace log file, cross-platform C++ project with a strong separation of concerns:

* `core` → independent logic
* `platforms` → SDL3 + OS implementations
* `third_party` → You can use with others external dependencies


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

# SETUP GUIDE
## 🐧 Linux Setup
```bash
git clone https://github.com/Amackata/RTLog.git
cd RTLog
cmake -S . -B build
cmake --build build
./build/bin/RTLog
```
## Usage

RTLog++ uses a **Meyers' Singleton** pattern, ensuring a single instance
per process.

### Basic initialization

```cpp
#include "rtLog.hpp"

    RTLog& log = RTLog::get();
    log.runLogger();
    
    //Use mode:
    log.infoLog("Application started");
    log.debugLog("Debug information");
    log.warningLog("Something looks odd");
    log.errorLog("Operation failed");
    log.fatalLog("Forcing shutdown");

```

### Log levels

| Level     | Use case                                              |
|-----------|-------------------------------------------------------|
| `DEBUG`   | Diagnostic info for developers and sysadmins          |
| `INFO`    | General events: start, stop, configuration            |
| `WARNING` | Anything that could cause application oddities        |
| `ERROR`   | Fatal to the operation, but not the application       |
| `FATAL`   | Forces shutdown to prevent data loss                  |

### One instance per process

`RTLog::get()` always returns the same instance within a process.
Multiple references across your codebase all point to the same object:

```cpp
RTLog& logA = RTLog::get(); // same instance
RTLog& logB = RTLog::get(); // same instance
```

If RTLog++ is used across separate processes (e.g. a launcher that
spawns child processes), each process maintains its own independent
singleton — which is the expected behavior.


🚧 Still in development 🚧
