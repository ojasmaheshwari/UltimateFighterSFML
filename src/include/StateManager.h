#pragma once

#include "BaseState.h"
#include "utils/Logging.h"

class StateManager {
  public:
    StateManager();
    StateManager(BaseState *baseState);
    ~StateManager();
    void switchState(BaseState *state);
    BaseState* getCurrentState() const;
  private:
    BaseState* m_CurrentState;
    Logging m_Logger;
};
