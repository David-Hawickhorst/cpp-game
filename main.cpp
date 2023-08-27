#include "Game.h"
#include <SFML/Graphics.hpp>

void temp() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(100, 200);

    sf::CircleShape triangle(50.f, 3);
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(475, 375);

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close window: exit
            if (event.type == sf::Event::Closed) { window.close(); }
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(circle);
        window.draw(triangle);

        // Update the window
        window.display();
    }
}


int main() {
    Game game;
    game.run();
    return 0;
}
