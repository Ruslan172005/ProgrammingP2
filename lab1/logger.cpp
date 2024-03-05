#include "logger.hpp"
#include <iostream>

int main() {
    Logger logger(std::cout);

    logger.SetLogLine(true);
    logger.SetLogFile(true);

    LOG(logger, "Hello, world!");

    return 0;
}
