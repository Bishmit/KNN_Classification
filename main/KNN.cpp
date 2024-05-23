#include "KNN.h"

KNN::KNN() : window(sf::VideoMode(1000, 600), "KNN Classification"), min_(INT_MAX), clickDetected(false), clickDetected2(false){
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
                clickDetected = true;
                clickDetected2 = true;
                int X = mousePos.x;
                int Y = mousePos.y;
                dotvector.emplace_back(X, Y);
            }
        }

    }
}

float KNN::euclideanDistance(float x1, float y1, float x2, float y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

void KNN::update() {
    std::vector<S> distances; // Vector to store distances along with coordinates

    // Calculate distances and store them with coordinates
    for (auto& i : randomdot) {
        for (auto& j : dotvector) {
            float x1 = i.getposition().x;
            float y1 = i.getposition().y;
            float x2 = j.getposition().x;
            float y2 = j.getposition().y;
            float d = euclideanDistance(x1, y1, x2, y2);
            distances.push_back(S(x1, y1, x2, y2, d)); // Store distance and coordinates
        }
    }

    std::sort(distances.begin(), distances.end(), [](const S& a, const S& b) {
        return a.d < b.d;
        });

    nearestDistances.clear(); // Clear the nearestDistances vector before updating it
    nearestDistances.resize(std::min(static_cast<size_t>(5), distances.size())); // Resize the nearestDistances vector

    // Copy the nearest distances and coordinates to nearestDistances vector
    std::copy(distances.begin(), distances.begin() + nearestDistances.size(), nearestDistances.begin());
}

void KNN::initRandomDotsOverScreen() {
    for (int i = 0; i < 100; i++) {
        int x = std::rand() % window.getSize().x;
        int y = std::rand() % window.getSize().y;
        randomdot.emplace_back(x, y);
    }
}

void KNN::render() {
    window.clear();
    for (auto& dot : dotvector) {
        dot.render(window);
    }

    for (auto& dot : randomdot) {
        dot.render(window);
    }

    for (const auto& s : nearestDistances) {
        //std::cout << "Distance: " << s.d << ", Coordinates: (" << s.x1 << ", " << s.y1 << "), (" << s.x2 << ", " << s.y2 << ")" << std::endl;
        line[0] = sf::Vertex(sf::Vector2f(s.x1, s.y1), sf::Color::Cyan);
        line[1] = sf::Vertex(sf::Vector2f(s.x2, s.y2), sf::Color::Cyan);
        window.draw(line, 2, sf::Lines);
    }

    window.display();
}

void KNN::run() {
    while (window.isOpen()) {
        processEvents();
        if (clickDetected) {
            update();
            clickDetected = false;
        }
        render();
    }
}
