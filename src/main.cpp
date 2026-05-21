#include <SFML/Graphics.hpp>
#include <optional>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"
#include "Tetromino.h"

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tetris");

    Board board(20, 10, 30);
    Tetromino currentPiece(30);
    int score=0;

    sf::Clock clock;
    float fallInterval = 0.5f;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::Left) {
                    currentPiece.move(-1, 0,board);
                }

                if (keyPressed->code == sf::Keyboard::Key::Right) {
                    currentPiece.move(1, 0,board);
                }

                if (keyPressed->code == sf::Keyboard::Key::Down) {
                    currentPiece.move(0, 1,board);
                }
                if (keyPressed->code == sf::Keyboard::Key::Up) {
    currentPiece.rotate(board);
}
            }
        }
        if (clock.getElapsedTime().asSeconds() >= fallInterval) {
    bool moved = currentPiece.move(0, 1, board);

    if (!moved) {
    board.placeBlocks(currentPiece.getBlocks());

    int clearedRows = board.clearFullRows();

    if (clearedRows > 0) {
        score += clearedRows * 100;
        std::cout << "Skor: " << score << std::endl;
    }

    currentPiece = Tetromino(30);
}

    clock.restart();
}

        window.clear(sf::Color::Black);

        board.draw(window);
        currentPiece.draw(window);

        window.display();
    }

    return 0;
}