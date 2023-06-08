#pragma once
#include "settings.h"

class StopWatch {
private:
    sf::Clock clock;
    sf::Time elapsed;
    sf::Font font;
    sf::Text text;

public:
    StopWatch() {
        font.loadFromFile("arial.ttf");
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(sf::Color::White);
        text.setPosition(10, 10);
    }

    void update() {
        elapsed = clock.getElapsedTime();
        std::ostringstream ss;
        ss << "Survival time: " << elapsed.asSeconds() << "s";
        text.setString(ss.str());
    }

    void draw(sf::RenderWindow& window) {
        window.draw(text);
    }
};

void mai() {
    sf::RenderWindow window(sf::VideoMode(400, 300), "Stopwatch");
    StopWatch stopwatch;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        stopwatch.update();
        window.clear();
        stopwatch.draw(window);
        window.display();
    }
}