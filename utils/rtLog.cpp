/*************************************************************
* RTLog++ - Amackata's Codes version 0.0.1a
* Garbanzo.com.ar/download
*
* All rights reserved.
* Project license: MIT
* Copyright (c) 2026 amackata *gmail.com
*************************************************************/

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


RTLog& RTLog::get() {
    static RTLog instance;   // ← esto es clave: thread-safe desde C++11, se crea solo una vez
    return instance;
}

/*
 *TODO
 * #include <filesystem>
RTLog& RTLog::get()
{
    // Crear directorio log/ si no existe
    std::filesystem::create_directories("log");
    static RTLog instance("log/rtLog.log"); // usa el constructor privado correcto
    return instance;
}
 */

void RTLog::log(Level level, const std::string& message)
{
    if (!logFile.is_open()) return;

    std::string levelStr;
    switch (level)
    {
    case DEBUG:
        levelStr = "DEBUG";
        break;

    case INFO:
        levelStr = "INFO";
        break;

    case WARNING:
        levelStr = "WARNING";
        break;

    case ERROR:
        levelStr = "ERROR";
        break;

    case FATAL:
        levelStr = "FATAL";
        break;
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

void RTLog::debugLog(std::string debuglogStr)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::DEBUG, debuglogStr);
}

void RTLog::infoLog(std::string infologStr)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::INFO, infologStr);
}

void RTLog::warningLog(std::string warninglogStr)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::WARNING, warninglogStr);
}

void RTLog::errorLog(std::string errorlogStr)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::ERROR, errorlogStr);
}

void RTLog::fatalLog(std::string fatallogStr)
{
    RTLog logger(RTLOG_LOG_PATH);
    logger.log(RTLog::FATAL, fatallogStr);
}

