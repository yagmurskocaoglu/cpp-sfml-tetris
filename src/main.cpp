#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Board.h"
#include "Tetromino.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tetris");

    Board board(20, 10, 30);
    Tetromino currentPiece(30);

    sf::RectangleShape sidePanel(sf::Vector2f(500, 600));
   sidePanel.setPosition(sf::Vector2f(300, 0));
    sidePanel.setFillColor(sf::Color(15, 15, 15));

    sf::RectangleShape separator(sf::Vector2f(2, 600));
   separator.setPosition(sf::Vector2f(300, 0));
   separator.setFillColor(sf::Color(80, 80, 80));


    int score = 0;
    bool gameOver = false;

    window.setTitle("Tetris | Skor: " + std::to_string(score));

    sf::Clock clock;
    float fallInterval = 0.5f;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (!gameOver) {
                if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                    if (keyPressed->code == sf::Keyboard::Key::Left) {
                        currentPiece.move(-1, 0, board);
                    }

                    if (keyPressed->code == sf::Keyboard::Key::Right) {
                        currentPiece.move(1, 0, board);
                    }

                    if (keyPressed->code == sf::Keyboard::Key::Down) {
                        currentPiece.move(0, 1, board);
                    }

                    if (keyPressed->code == sf::Keyboard::Key::Up) {
                        currentPiece.rotate(board);
                    }
                }
            }
        }

        if (!gameOver && clock.getElapsedTime().asSeconds() >= fallInterval) {
            bool moved = currentPiece.move(0, 1, board);

            if (!moved) {
                board.placeBlocks(currentPiece.getBlocks());

                int clearedRows = board.clearFullRows();

                if (clearedRows > 0) {
                    score += clearedRows * 100;
                    std::cout << "Skor: " << score << std::endl;
                    window.setTitle("Tetris | Skor: " + std::to_string(score));
                }

                currentPiece = Tetromino(30);

                if (!board.canPlaceBlocks(currentPiece.getBlocks())) {
                    gameOver = true;
                    std::cout << "Oyun bitti! Final skor: " << score << std::endl;
                    window.setTitle("GAME OVER | Final skor: " + std::to_string(score));
                }
            }

            clock.restart();
        }

        window.clear(sf::Color::Black);

        board.draw(window);

        window.draw(sidePanel);
        window.draw(separator);

        if (!gameOver) {
            currentPiece.draw(window);
        }

        window.display();
    }

    return 0;
}