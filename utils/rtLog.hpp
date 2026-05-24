/*************************************************************
* RTLog++ v0.0.1a - Amackata's Codes
* https://github.com/amackata/RTLog
*
* Copyright (c) 2026 amackata - Garbanzo.com.ar
* SPDX-License-Identifier: MIT
*************************************************************/

// TODO: [DEUDA] RTLog() = default público coexiste con RTLog(const std::string&) privado.
//       El singleton get() llama al default pero logFile nunca se abre → log() es no-op silencioso.
//       Solución: eliminar RTLog() = default, inicializar el singleton con filename fijo en get().

// TODO: [DEUDA] _CRT_SECURE_NO_WARNINGS definido en header → contamina todas las unidades
//       que incluyan logger.hpp. Mover al CMakeLists de utils como add_compile_definitions()
//       solo para Windows, o usar strftime() directamente.

// TODO: [DEUDA] currentTimestamp() definido en header (.hpp) → se compila en cada .cpp
//       que incluya el header. Mover implementación a logger.cpp.

// TODO: [MEJORA] Parámetros de debugLog/infoLog/warningLog/errorLog/fatalLog
//       reciben std::string por valor. Cambiar a const std::string& para evitar copias.

#pragma once

#define _CRT_SECURE_NO_WARNINGS  // TODO: Warning on Windows: Try to use strftime instead 'ctime': This function or variable may be unsafe. Consider using ctime_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS.

#include <fstream>
#include <iostream>
#include <string>
#include <ctime> // Only for show local time system in log

//Trying to get work with this libraries
#include <sstream> // Include this library because error: el agregado ‘std::ostringstream oss’ tiene un tipo incompleto y no se puede definir
#include <iomanip> // This library defines std::put_time, otherway get error y no se puede definir


class RTLog
{
public:
    RTLog() = default; // this -> Breaks the singleton

    // Global Access (Meyers' Singleton)
    static RTLog& get();

    // =========================
    // LEVEL TYPES
    // =========================
    enum Level
    {
        // RULES -> Standard Rules...
        DEBUG, // FOR EXAMPLE DEBUG USE IN SDL3 = logger + SDL_GetError () ->Information that is diagnostically helpful to people more than just developers (IT, sysadmins, etc.).
        INFO, // Generally useful information to log (service start/stop, configuration assumptions, etc). Info I want to always have available but usually don't care about under normal circumstances. This is my out-of-the-box config level.
        WARNING, // Anything that can potentially cause application oddities,
        ERROR, // Any error which is fatal to the operation, but not the service or application...
        FATAL // Any error that is forcing a shutdown of the service or application to prevent data loss...

    };

    void runLogger();
    void log(Level level, const std::string& message);

    void debugLog(std::string debuglogStr);
    void infoLog(std::string infologStr);
    void warningLog(std::string warninglogStr);
    void errorLog(std::string errorlogStr);
    void fatalLog(std::string fatallogStr);

    // Prohibir copiar o mover (buena práctica)
    RTLog(const RTLog&) = delete;
    RTLog& operator=(const RTLog&) = delete;


private:
    std::ofstream logFile;
    std::string currentTimestamp()
    {
        auto now = std::time(nullptr);
        auto tm = *std::localtime(&now);
        std::ostringstream osLog; // osPanel = Output String Panel and osLog = Output String Log
        osLog << std::put_time(&tm, "%d-%m-%Y %H:%M:%S"); // For Log propuse
        return osLog.str();
    }

    RTLog(const std::string& filename);
    ~RTLog();
};