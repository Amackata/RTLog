/*************************************************************
* RTLog++ v0.0.2a - Amackata's Codes
* https://github.com/amackata/RTLog
* Copyright (c) 2026 amackata - Garbanzo.com.ar
* SPDX-License-Identifier: MIT
*************************************************************/

// TODO: [DEUDA] RTLog() = default público coexiste con RTLog(const std::string&) privado.
//       El singleton get() llama al default pero logFile nunca se abre → log() es no-op silencioso.
//       Solución: eliminar RTLog() = default, inicializar el singleton con filename fijo en get().
// TODO: [DEUDA] currentTimestamp() definido en header (.hpp) → se compila en cada .cpp
//       que incluya el header. Mover implementación a rtLog.cpp.
// TODO: [MEJORA] Parámetros de debugLog/infoLog/warningLog/errorLog/fatalLog
//       reciben std::string por valor. Cambiar a const std::string& para evitar copias.
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
        auto now       = std::chrono::system_clock::now();
        auto zone      = std::chrono::current_zone();
        auto local     = zone->to_local(now);

        /////////////////////////////////////////////////////////////////////////
        // EN: ISO 8601 format → {:%Y-%m-%d %H:%M:%S} → 2026-05-24 14:30:00
        // ES: Spanish format  → {:%d-%m-%Y %H:%M:%S} → 24-05-2026 14:30:00
        /////////////////////////////////////////////////////////////////////////
        return std::format("{:%Y-%m-%d %H:%M:%S}", local);
    }

    RTLog(const std::string& filename);
    ~RTLog();
};