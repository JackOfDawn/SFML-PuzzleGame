#include <SFML/Graphics.hpp>
#include <iostream>
#include "Managers/InputManager.h"

int main()
{
    ManagerBase* input = new InputManager();
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sprite(texture);

    input->startUp();

    while (app.isOpen())
    {
        input->update();

        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear();
        app.draw(sprite);
        app.display();
    }

    input->shutDown();
    delete input;

    return EXIT_SUCCESS;
}
