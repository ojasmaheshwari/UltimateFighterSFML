#pragma once


class BaseState {
  public:
    virtual ~BaseState();
    virtual void processEvents() = 0;
    virtual void draw() = 0;
    virtual void update() = 0;
};
