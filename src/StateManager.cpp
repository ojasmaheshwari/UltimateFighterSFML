#include "include/StateManager.h"
#include "include/BaseState.h"
#include "include/utils/Logging.h"

#include <iostream>

StateManager::StateManager()
  : m_CurrentState(nullptr), m_Logger(LoggingLevel::LogLevelInfo, "StateManager")
{}

StateManager::StateManager(BaseState *baseState)
{
  if (baseState != nullptr) {
    m_CurrentState = baseState;
  }
  else {
    m_Logger.log("Base state of StateManager constructor is nullptr", LoggingLevel::LogLevelError);
  }
}

StateManager::~StateManager()
{
  if (m_CurrentState != nullptr)
    delete m_CurrentState;
  else
    m_Logger.log("Current state of State Manager is nullptr, ignoring destruction", LoggingLevel::LogLevelWarning);
}

BaseState* StateManager::getCurrentState() const {
  return m_CurrentState;
}
 
void StateManager::switchState(BaseState *state) {
  if (state != nullptr) {
    if (m_CurrentState != nullptr) {
      delete m_CurrentState;
    }
    m_CurrentState = state;
  }
  else {
    m_Logger.log("Tried to switch to a state that is nullptr, ignoring state switch, retaining previous state", LoggingLevel::LogLevelWarning);
  }
}
