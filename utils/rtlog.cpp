/*************************************************************
* RTLog++ v0.0.4a - Amackata's Codes
* https://github.com/amackata/RTLog
* Copyright (c) 2026 amackata - Garbanzo.com.ar
* SPDX-License-Identifier: MIT
*************************************************************/
// Standard library dependencies
#include <iomanip>   // std::setw, std::left
#include <iostream>  // std::cerr
#include <stdexcept> // std::runtime_error
#include <chrono> // For currentTimestamp()
#include <format> // For currentTimestamp()
#include "rtlog.hpp"

RTLog::RTLog(const std::string& filename)
{
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open())
    {
        throw std::runtime_error("Could not open log file: " + filename);
    }
}

RTLog::~RTLog()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

std::string RTLog::currentTimestamp()
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

RTLog& RTLog::get()
{
    static RTLog instance(RTLOG_LOG_PATH); // ← thread-safe desde C++11, se crea solo una vez
    return instance;
}

void RTLog::log(Level level, const std::string& message)
{
    if (!logFile.is_open()) return;
    std::string levelStr;
    switch (level)
    {
        case DEBUG:   levelStr = "DEBUG";   break;
        case INFO:    levelStr = "INFO";    break;
        case WARNING: levelStr = "WARNING"; break;
        case ERROR:   levelStr = "ERROR";   break;
        case FATAL:   levelStr = "FATAL";   break;
    }
    logFile << "[" << currentTimestamp() << "] "
            << std::setw(7) << std::left << levelStr << " : "
            << message << std::endl;
}

// =========================
// SINGLE PARAMETER
// =========================
void RTLog::debug(const std::string& msg)   { get().log(DEBUG, msg); }
void RTLog::info(const std::string& msg)    { get().log(INFO, msg); }
void RTLog::warning(const std::string& msg) { get().log(WARNING, msg); }
void RTLog::error(const std::string& msg)   { get().log(ERROR, msg); }
void RTLog::fatal(const std::string& msg)   { get().log(FATAL, msg); }

// =========================
// TWO PARAMETERS
// =========================
void RTLog::debug(const std::string& msg, const std::string& detail)   { get().log(DEBUG, std::format("{}: {}", msg, detail)); }
void RTLog::info(const std::string& msg, const std::string& detail)    { get().log(INFO, std::format("{}: {}", msg, detail)); }
void RTLog::warning(const std::string& msg, const std::string& detail) { get().log(WARNING, std::format("{}: {}", msg, detail)); }
void RTLog::error(const std::string& msg, const std::string& detail)   { get().log(ERROR, std::format("{}: {}", msg, detail)); }
void RTLog::fatal(const std::string& msg, const std::string& detail)   { get().log(FATAL, std::format("{}: {}", msg, detail)); }