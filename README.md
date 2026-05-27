# RTLog++
Runtime User-Space Log File — v0.0.4a

![C++](https://img.shields.io/badge/language-C++-blue)
![CMake](https://img.shields.io/badge/build-CMake-green)
![SDL3](https://img.shields.io/badge/SDL-3-orange)
![Platforms](https://img.shields.io/badge/platforms-Linux%20%7C%20Windows%20%7C%20Android-lightgrey)
![Status](https://img.shields.io/badge/status-in%20development-yellow)


![Logo](logo.png) \
\
**RTLog++** is a lightweight, cross-platform C++ logging system for developers
who need structured, timestamped runtime `output.log`. It integrates easily
into any C++ project with minimal dependencies.

## 📦 Architecture

```
MyProject
│
├── log/
│    └── output.log
│
├── examples/
│      ├── CMakelists.txt
│      └── sdl3_demo.cpp
│
├── utils/   # RTLog++ 
│     ├── CMakelists.txt
│     ├── rtlog.hpp
│     └── rtlog.cpp
│
└── CMakeLists.txt
```

# SETUP GUIDE
## 🐧 Linux Setup

```bash
git clone https://github.com/amackata/RTLog.git
cd RTLog
cmake -S . -B build
cmake --build build
./build/bin/sdl3_demo
```
## Usage

RTLog++ uses a **Meyers' Singleton** pattern, ensuring a single instance
per process.

### Basic initialization

```cpp
#include "rtLog.hpp"

    RTLog& log = RTLog::get();
    log.runLogger();  
```
### Use Mode
```cpp
//Basic Mode:
log.info("Application started");
log.debug("Debug information");
log.warning("Something looks odd");
log.error("Operation failed");
log.fatal("Forcing shutdown");

// Two-parameter Mode (message + detail): 
log.debug("Renderer backend", SDL_GetRendererName(renderer));
log.warning("Adaptive vsync not supported", SDL_GetError());
log.error("Required asset not found", SDL_GetError());
log.fatal("Renderer creation failed", SDL_GetError());
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

## 🗺️ Roadmap

### ✅ v0.0.x Alpha — Current
- [x] Singleton logger with file output
- [x] Five log levels: DEBUG, INFO, WARNING, ERROR, FATAL
- [x] ISO 8601 timestamps via `std::chrono` (C++20)
- [x] Two-parameter API: `log.error("msg", detail)`
- [x] SDL3 integration example

### 🔲 v0.1.0 — Library Release
- [ ] CMake `install()` rules
- [ ] Installable via `sudo cmake --install build`
- [ ] System-wide header: `#include <RTLog/rtlog.hpp>`
- [ ] Remove heap usage: replace std::string, std::ofstream and std::format before release
- [x] Fix singleton debt: `RTLog() = default` + `get()` refactor
- [x] Move `currentTimestamp()` from header to `.cpp`
- [x] `const std::string&` parameters across all methods

### 🔲 v1.0.0 — Stable
- [ ] `#include <RTLog>` convenience header
- [ ] Big Debt `CRITICAL - STACK ONLY`
- [ ] Windows support
- [ ] Android support
- [ ] Thread-safe file writing
- [ ] Log rotation

🚧 Still in development 🚧
