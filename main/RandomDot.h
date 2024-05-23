#ifndef RANDOMDOT_H
#define RANDOMDOT_H

#include<SFML/Graphics.hpp>
class RandomDot
{
public:
    RandomDot(int x, int y);
    void update();
    void render(sf::RenderWindow& window);
    sf::Vector2f getposition(); 
    sf::Color getcolor(); 

private:
    sf::CircleShape circle;
};

#endif 

