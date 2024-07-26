#include "include/StateManager.h"
#include "include/BaseState.h"

#include <iostream>

StateManager::StateManager()
  : m_CurrentState(nullptr)
{}

StateManager::StateManager(BaseState *baseState)
{
  if (baseState != nullptr) {
    m_CurrentState = baseState;
  }
  else {
    std::cout << "StateManager->Constructor: baseState is null" << '\n';
  }
}

StateManager::~StateManager()
{
  if (m_CurrentState != nullptr)
    delete m_CurrentState;
  else
    std::cout << "StateManager->Destructor: m_CurrentState is null" << '\n';
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
    std::cout << "StateManager->switchState: state is null" << '\n';
  }
}
