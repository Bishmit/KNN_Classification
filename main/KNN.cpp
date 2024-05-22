#include "KNN.h"

KNN::KNN() : window(sf::VideoMode(1000, 600), "KNN Classification") {
    initRandomDotsOverScreen();
}

void KNN::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
            window.close();

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                int X = mousePos.x;
                int Y = mousePos.y;
                dotvector.emplace_back(X, Y);
            }
        }
    }
}

void KNN::update() {
    
}

void KNN::initRandomDotsOverScreen() {
    for (int i = 0; i < 100; i++) {
        int x = std::rand() % window.getSize().x;
        int y = std::rand() % window.getSize().y;
        dotvector.emplace_back(x, y);
    }
}

void KNN::render() {
    sf::Color silverColor(192, 192, 192);
    window.clear(silverColor);
    for (auto& dot : dotvector) {
        dot.render(window);
    }
    window.display();
}

void KNN::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}
