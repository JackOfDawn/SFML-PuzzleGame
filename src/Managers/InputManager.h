#ifndef INPUTMANAGER
#define INPUTMANAGER

#include "ManagerBase.h"

class InputManager : public ManagerBase
{
public:
    InputManager();
    ~InputManager();

    virtual int startUp();
    virtual int shutDown();
    virtual void update();
};


#endif