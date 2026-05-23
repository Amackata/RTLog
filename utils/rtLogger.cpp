/*************************************************************
* RTLog++ - Amackata's Codes version 0.0.1a
* Garbanzo.com.ar/download
*
* All rights reserved.
* Project license: MIT
* Copyright (c) 2026 amackata *gmail.com
*************************************************************/

#include "rtLogger.hpp"

rtLogger::rtLogger(const std::string& filename)
{
    logFile.open(filename, std::ios::app);
    if (!logFile.is_open())
    {
        throw std::runtime_error("Could not open log file: " + filename);
    }
}

rtLogger::~rtLogger()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

rtLogger& rtLogger::get() {
    static rtLogger instance;   // ← esto es clave: thread-safe desde C++11, se crea solo una vez
    return instance;
}

void rtLogger::log(Level level, const std::string& message)
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

void rtLogger::runLogger()
{
    try
    {
        rtLogger logger("hummus.log");
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void rtLogger::debugLog(std::string debuglogStr)
{
    rtLogger logger("hummus.log");
    logger.log(rtLogger::DEBUG, debuglogStr);
}

void rtLogger::infoLog(std::string infologStr)
{
    rtLogger logger("hummus.log");
    logger.log(rtLogger::INFO, infologStr);

}

void rtLogger::warningLog(std::string warninglogStr)
{
    rtLogger logger("hummus.log");
    logger.log(rtLogger::WARNING, warninglogStr);
}

void rtLogger::errorLog(std::string errorlogStr)
{
    rtLogger logger("hummus.log");
    logger.log(rtLogger::ERROR, errorlogStr);
}

void rtLogger::fatalLog(std::string fatallogStr)
{
    rtLogger logger("hummus.log");
    logger.log(rtLogger::FATAL, fatallogStr);
}
