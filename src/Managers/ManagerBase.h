#ifndef MANAGER_BASE
#define MANAGER_BASE

class ManagerBase
{
public:
    virtual int startUp() = 0;
    virtual int shutDown() = 0;
    virtual void update() = 0;
};

#endif
