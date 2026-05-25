/*************************************************************
* RTLog++ v0.0.3a - Amackata's Codes
* https://github.com/amackata/RTLog
* Copyright (c) 2026 amackata - Garbanzo.com.ar
* SPDX-License-Identifier: MIT
*************************************************************/
// Standard library dependencies
#include <iomanip>   // std::setw, std::left
#include <iostream>  // std::cerr
#include <stdexcept> // std::runtime_error
#include "rtLog.hpp"

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

RTLog& RTLog::get()
{
    static RTLog instance; // ← thread-safe desde C++11, se crea solo una vez
    return instance;
}

/*
 * TODO
 * #include <filesystem>
RTLog& RTLog::get()
{
    // Crear directorio log/ si no existe
    std::filesystem::create_directories("log");
    static RTLog instance("log/output.log"); // usa el constructor privado correcto
    return instance;
}
*/

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

void RTLog::runLogger()
{
    try { RTLog logger(RTLOG_LOG_PATH); }
    catch (const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
}

// =========================
// SINGLE PARAMETER
// =========================
void RTLog::debug(const std::string& msg)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::DEBUG, msg);
}

void RTLog::info(const std::string& msg)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::INFO, msg);
}

void RTLog::warning(const std::string& msg)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::WARNING, msg);
}

void RTLog::error(const std::string& msg)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::ERROR, msg);
}

void RTLog::fatal(const std::string& msg)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::FATAL, msg);
}

// =========================
// TWO PARAMETERS
// =========================
void RTLog::debug(const std::string& msg, const std::string& detail)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::DEBUG, std::format("{}: {}", msg, detail));
}

void RTLog::info(const std::string& msg, const std::string& detail)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::INFO, std::format("{}: {}", msg, detail));
}

void RTLog::warning(const std::string& msg, const std::string& detail)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::WARNING, std::format("{}: {}", msg, detail));
}

void RTLog::error(const std::string& msg, const std::string& detail)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::ERROR, std::format("{}: {}", msg, detail));
}

void RTLog::fatal(const std::string& msg, const std::string& detail)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::FATAL, std::format("{}: {}", msg, detail));
}