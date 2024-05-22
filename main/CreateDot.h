#ifndef CREATEDOT_H
#define CREATEDOT_H

#include <SFML/Graphics.hpp>

class CreateDot {
public:
    CreateDot(int x, int y);
    void update();
    void render(sf::RenderWindow& window);

private:
    sf::CircleShape circle;
};

#endif // CREATEDOT_H
