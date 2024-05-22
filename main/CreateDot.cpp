#include "CreateDot.h"

CreateDot::CreateDot(int x, int y) {
    circle.setRadius(5.f);
    sf::Color rgb;
    int colorIndex = (std::rand() % 4 ) + 1;
    switch (colorIndex) {
    case 0: 
        rgb = sf::Color::Red;
        break;
    case 1: 
        rgb = sf::Color::Magenta;
        break;
    case 3: 
        rgb = sf::Color(75, 0, 130);
        break;
    case 4: 
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
