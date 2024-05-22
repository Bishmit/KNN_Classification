#ifndef KNN_H
#define KNN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "CreateDot.h"

class KNN {
public:
    KNN();
    void run();

private:
    void processEvents();
    void update();
    void initRandomDotsOverScreen();
    void render();

    sf::RenderWindow window;
    std::vector<CreateDot> dotvector;
};

#endif // KNN_H
