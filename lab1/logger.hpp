#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <string>

class Logger {
public:
    explicit Logger(std::ostream& output_stream) : os(output_stream) {}

    void SetLogLine(bool value) { log_line = value; }
    void SetLogFile(bool value) { log_file = value; }
    void SetFile(const std::string& file) { file_name = file; }
    void SetLine(int line) { line_number = line; }

    void Log(const std::string& message);

private:
    std::ostream& os;
    bool log_line = false;
    bool log_file = false;
    std::string file_name;
    int line_number = 0;
};

void Logger::Log(const std::string& message) {
    if (log_file && log_line) {
        os << file_name << ":" << line_number << " - " << message << std::endl;
    }
    else if (log_file) {
        os << file_name << " - " << message << std::endl;
    }
    else if (log_line) {
        os << line_number << " - " << message << std::endl;
    }
    else {
        os << message << std::endl;
    }
}

#define LOG(logger, message) \
    logger.SetFile(__FILE__); \
    logger.SetLine(__LINE__); \
    logger.Log(message);

#endif // LOGGER_HPP
