/*************************************************************
* RTLog++ v0.0.3a - Amackata's Codes
* https://github.com/amackata/RTLog
* Copyright (c) 2026 amackata - Garbanzo.com.ar
* SPDX-License-Identifier: MIT
*************************************************************/
// TODO: [DEUDA] currentTimestamp() definido en header (.hpp) → se compila en cada .cpp
//       que incluya el header. Mover implementación a rtLog.cpp.
// TODO: [MEJORA] Parámetros de debug/info/warning/error/fatal reciben std::string por valor.
//       Cambiar a const std::string& para evitar copias.
// TODO: [PORTABILIDAD] current_zone() requiere IANA timezone database.
//       Disponible en GCC 13+ / Linux. Verificar soporte en otras plataformas.
#pragma once
#include <fstream>
#include <string>
#include <chrono>
#include <format>

class RTLog
{
public:

    // Global Access (Meyers' Singleton)
    static RTLog& get();

    // =========================
    // LEVEL TYPES
    // =========================
    enum Level
    {
        // RULES -> Standard Rules...
        DEBUG,   // Diagnostic info helpful to developers and sysadmins (e.g. SDL_GetError())
        INFO,    // Generally useful: service start/stop, configuration assumptions
        WARNING, // Anything that can potentially cause application oddities
        ERROR,   // Fatal to the operation, but not the service or application
        FATAL    // Forces shutdown to prevent data loss
    };
    //void runLogger();
    void log(Level level, const std::string& message);

    // Single parameter
    void debug(const std::string& msg);
    void info(const std::string& msg);
    void warning(const std::string& msg);
    void error(const std::string& msg);
    void fatal(const std::string& msg);

    // Two parameters: message + detail (e.g. SDL_GetError())
    void debug(const std::string& msg, const std::string& detail);
    void info(const std::string& msg, const std::string& detail);
    void warning(const std::string& msg, const std::string& detail);
    void error(const std::string& msg, const std::string& detail);
    void fatal(const std::string& msg, const std::string& detail);
    // Prohibir copiar o mover (buena práctica)
    RTLog(const RTLog&) = delete;
    RTLog& operator=(const RTLog&) = delete;

private:
    std::ofstream logFile;
    std::string currentTimestamp()
    {
        auto now   = std::chrono::system_clock::now();
        auto zone  = std::chrono::current_zone();
        auto local = zone->to_local(now);
        /////////////////////////////////////////////////////////////////////////
        // EN: ISO 8601 format → {:%Y-%m-%d %H:%M:%S} → 2026-05-24 14:30:00
        // ES: Spanish format  → {:%d-%m-%Y %H:%M:%S} → 24-05-2026 14:30:00
        /////////////////////////////////////////////////////////////////////////
        return std::format("{:%Y-%m-%d %H:%M:%S}", local);
    }
    RTLog(const std::string& filename);
    ~RTLog();
};