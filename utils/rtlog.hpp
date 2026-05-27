/*************************************************************
* RTLog++ v0.0.4a - Amackata's Codes
* https://github.com/amackata/RTLog
* Copyright (c) 2026 amackata - Garbanzo.com.ar
* SPDX-License-Identifier: MIT
*************************************************************/

// TODO: [CRITICAL - STACK ONLY] RTLog++ internally uses heap via std::string, std::ofstream
//       and std::format. Not suitable for certified systems (IEC 62304, DO-178C) or environments
//       where heap is prohibited or restricted (medical, aerospace, hard real-time).
//       For stack-only replace: std::ofstream → write() + fixed static buffer,
//       std::format → snprintf() over char[], std::string → std::string_view / const char*,
//       exceptions → compile with -fno-exceptions and use error codes instead.
//       In its current state RTLog++ is suitable only as a development and testing logger.
//
//       [CRÍTICO - STACK ONLY] RTLog++ usa heap internamente via std::string, std::ofstream
//       y std::format. No apto para sistemas certificados (IEC 62304, DO-178C) ni entornos
//       donde el heap está prohibido o restringido (médico, aeroespacial, tiempo real crítico).
//       Para stack-only reemplazar: std::ofstream → write() + buffer estático fijo,
//       std::format → snprintf() sobre char[], std::string → std::string_view / const char*,
//       excepciones → compilar con -fno-exceptions y usar códigos de error.
//       En su estado actual RTLog++ es apto únicamente como logger de desarrollo y testing.

// TODO: [PORTABILIDAD] current_zone() requiere IANA timezone database.
//       Disponible en GCC 13+ / Linux. Verificar soporte en otras plataformas.

#pragma once
#include <fstream>
#include <string>

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
    static std::string currentTimestamp();
    RTLog(const std::string& filename);
    ~RTLog();
};