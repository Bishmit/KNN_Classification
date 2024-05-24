#include "CreateDot.h"

CreateDot::CreateDot(int x, int y) {
    circle.setRadius(5.f);
    sf::Color rgb;
    int colorIndex = (std::rand() % 2);
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

void CreateDot::update() {
   
}

void CreateDot::render(sf::RenderWindow& window) {
    window.draw(circle);
}

sf::Vector2f CreateDot::getposition()
{
    return circle.getPosition();
}

sf::Color CreateDot::getcolor()
{
    return circle.getFillColor();
}

void CreateDot::setColor(const sf::Color& color) { 
    circle.setFillColor(color);
}