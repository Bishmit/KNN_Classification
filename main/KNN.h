#ifndef KNN_H
#define KNN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include<climits>
#include<iostream>
#include "CreateDot.h"
#include "RandomDot.h"

struct S {
    float x1, y1, x2, y2, d;

    S() : x1(0.0f), y1(0.0f), x2(0.0f), y2(0.0f), d(0.0f) {}

    S(float x1, float y1, float x2, float y2, float d) : x1(x1), y1(y1), x2(x2), y2(y2), d(d) {}
};
class KNN {
public:
    KNN();
    void run();

private:
    float min_; 
    bool clickDetected, clickDetected2;
    float nearestDistance;
    //std::vector<sf::Vertex> line;
    sf::Vertex line[2]; 
    std::vector<S> nearestDistances;
    void processEvents();
    float euclideanDistance(float x1, float y1, float x2, float y2); 
    void update();
    void initRandomDotsOverScreen();
    void render();

    sf::RenderWindow window;
    std::vector<CreateDot> dotvector;
    std::vector<RandomDot> randomdot;
    std::vector<float> distances;

};

#endif // KNN_H
