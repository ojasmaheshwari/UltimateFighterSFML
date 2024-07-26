#pragma once

#include <iostream>

enum class LoggingLevel {
  LogLevelInfo = 0, LogLevelWarning, LogLevelError
};

class Logging {
public:
  Logging();
  ~Logging();
  Logging(LoggingLevel loggingLevel, const std::string &className);
  LoggingLevel getLoggingLevel() const;
  void setLoggingLevel(LoggingLevel loggingLevel);
  void log(const std::string &message);
  void log(const std::string &message, LoggingLevel loggingLevel);
private:
  LoggingLevel m_LoggingLevel;
  const std::string m_ClassName;
};
