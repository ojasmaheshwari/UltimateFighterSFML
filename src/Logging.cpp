#include "include/utils/Logging.h"
#include "include/utils/AsciiColor.h"

#include <format>


Logging::Logging()
  :m_LoggingLevel(LoggingLevel::LogLevelInfo), m_ClassName("Undefined")
{}
Logging::~Logging() {}

Logging::Logging(LoggingLevel loggingLevel, const std::string &className)
  : m_LoggingLevel(loggingLevel), m_ClassName(className)
{}

void Logging::setLoggingLevel(LoggingLevel loggingLevel) {
  m_LoggingLevel = loggingLevel;
}

LoggingLevel Logging::getLoggingLevel() const {
  return m_LoggingLevel;
}

void Logging::log(const std::string &message, LoggingLevel loggingLevel) {
  switch(loggingLevel) {
    case LoggingLevel::LogLevelInfo:
      info(message);
      break;
    case LoggingLevel::LogLevelWarning:
      warn(message);
      break;
    case LoggingLevel::LogLevelError:
      error(message);
      break;
    default:
      break;
  }
}

void Logging::log(const std::string &message) {
  log(message, getLoggingLevel());
}

void Logging::info(const std::string &message) {
  std::cout << "[INFO] " << message << " [From " << m_ClassName << ']' << '\n';
}

void Logging::warn(const std::string &message) {
  std::cout << AsciiColor::colorized(std::format("{} {} [From {}]", "[WARNING]", message, m_ClassName), Ascii::Color::Yellow);
}

void Logging::error(const std::string &message) {
  std::cout << AsciiColor::colorized(std::format("{} {} [From {}]", "[ERROR]", message, m_ClassName), Ascii::Color::Red);
}
