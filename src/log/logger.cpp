#include <iostream>
#include "logger.hpp"

Logger* Logger::getInstance() {
    static auto *logger = new Logger(cout, INFO);
    return logger;
}

Logger::Logger(ostream &logStream, LogLevel level) : d_logStream(logStream), d_level(level) {}

void Logger::setLogLevel(LogLevel level) {
    d_level = level;
}

string Logger::levelToString(LogLevel level) {
    string message;
    switch (level) {
        case INFO:
            message = message + WHITE + "[INFO]";
            break;
        case WARN:
            message = message + YELLOW + "[WARN]";
            break;
        case ERROR:
            message = message + RED + "[ERROR]";
            break;
    }
    return message;
}

void Logger::log(LogLevel level, const string &message) {
    if (level < d_level)
        return;
    d_logStream << levelToString(level) << " - " << message << RESET << endl;
}

void Logger::operator() (LogLevel level, const string &message) {
    log(level, message);
};