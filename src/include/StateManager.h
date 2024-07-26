#pragma once

#include "BaseState.h"

class StateManager {
  public:
    StateManager();
    StateManager(BaseState *baseState);
    ~StateManager();
    void switchState(BaseState *state);
    void processEvents();
    void draw();
    void update();
  private:
    BaseState *m_CurrentState;
};
