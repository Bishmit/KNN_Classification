#include "RandomDot.h"

RandomDot::RandomDot(int x, int y)
{
    circle.setRadius(5.f);
    sf::Color rgb;
    int colorIndex = (std::rand() % 3);
    switch (colorIndex) {
    case 0:
        rgb = sf::Color::Red;
        break;
    case 1: 
        rgb = sf::Color::Green; 
        break;
    case 2:
        rgb = sf::Color::Blue;
        break;
    default:
        rgb = sf::Color::Black;
        break;
    }

    circle.setFillColor(rgb);
    circle.setPosition(x, y);
}

void RandomDot::update()
{
    
}

void RandomDot::render(sf::RenderWindow& window)
{
    window.draw(circle);
}

sf::Vector2f RandomDot::getposition()
{
    return circle.getPosition(); 
}

sf::Color RandomDot::getcolor()
{
    return circle.getFillColor(); 
}
