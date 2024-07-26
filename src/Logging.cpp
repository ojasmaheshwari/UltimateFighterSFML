#include "include/utils/Logging.h"


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
      std::cout << "[INFO]" << message << " [From " << m_ClassName << ']' << '\n';
      break;
    case LoggingLevel::LogLevelWarning:
      std::cout << "[WARNING]" << message << '[' << m_ClassName << ']' << '\n';
      break;
    case LoggingLevel::LogLevelError:
      std::cout << "[ERROR]" << message << '[' << m_ClassName << ']' << '\n';
      break;
    default:
      break;
  }
}

void Logging::log(const std::string &message) {
  log(message, getLoggingLevel());
}
