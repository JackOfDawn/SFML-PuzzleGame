#ifndef GRAPHICS_MANAGER
#define GRAPHICS_MANAGER

#include "ManagerBase.h"
#include "../Utils/VectorMath.h"

class GraphicsManager : public ManagerBase
{
public:
    GraphicsManager(std::string name);

    //Base functions
    virtual void update();
    virtual int startUp();
    virtual int shutDown();

    bool isWindowOpen() {return mWindow.isOpen();}
    sf::RenderWindow& getWindow() {return mWindow;}
    void Display() {mWindow.display();}
    void ClearDisplay() {mWindow.clear(clearColor);}

    //Basic Shape Functions

private:
    //The most important function
    void cameraShake();

    sf::RenderWindow mWindow;
    sf::View    mView;
    sf::View    mOrgView;
    sf::Clock   mShakeTimer;

    //Colors
    sf::Color clearColor = sf::Color(41, 79, 109, 255);
};

#endif
