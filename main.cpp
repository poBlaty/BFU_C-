#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape circle_shape(100.f);
    sf::Font font;
    sf::Music ambient;
    ambient.openFromFile("real_matan.flac");
    ambient.setLoop(true);
    ambient.setVolume(50);
    ambient.play();
    font.loadFromFile("Comic Sans MS.ttf");
    sf::Text text("\n\n\n\n\t\t\tDFM 2025", font);
    text.setCharacterSize(14);
    text.setStyle(sf::Text::Bold);
    circle_shape.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(circle_shape);
        window.draw(text);
        window.display();
    }

    return 0;
}