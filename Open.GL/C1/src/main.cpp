#define SFML_STATIC
#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800,600), "Welcome to the wonder of OpenGL :)", sf::Style::Close);
    bool running = true;
    while (running) {
        sf::Event windowEvent;
        while (window.pollEvent(windowEvent)) {
            switch(windowEvent.type) {
                case sf::Event::Closed:
                    running = false;
                    break;
                case sf::Event::KeyPressed:
                    if (windowEvent.key.code == sf::Keyboard::Escape)
                        running = false;
                    break;
            }
        }
    }
    return 0;
}