#include <SFML/Graphics.hpp>
#include <optional>
#include "Board.h"
#include "Tetromino.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tetris");

    Board board(20, 10, 30);
    Tetromino currentPiece(30);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Left) {
                    currentPiece.move(-1, 0,10,20);
                }

                if (keyPressed->code == sf::Keyboard::Key::Right) {
                    currentPiece.move(1, 0,10,20);
                }

                if (keyPressed->code == sf::Keyboard::Key::Down) {
                    currentPiece.move(0, 1,10,20);
                }
            }
        }

        window.clear(sf::Color::Black);

        board.draw(window);
        currentPiece.draw(window);

        window.display();
    }

    return 0;
}