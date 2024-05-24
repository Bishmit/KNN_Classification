#ifndef CREATEDOT_H
#define CREATEDOT_H

#include <SFML/Graphics.hpp>

class CreateDot {
public:
    CreateDot(int x, int y);
    void update();
    void render(sf::RenderWindow& window);
    sf::Vector2f getposition();
    sf::Color getcolor();
    void setColor(const sf::Color& color);

private:
    sf::CircleShape circle;
};

#endif // CREATEDOT_H