#include "Tetromino.h"

Tetromino::Tetromino(int size) {
    cellSize = size;
    posX = 4;
    posY = 0;

    blocks = {
        sf::Vector2i(1, 0),
        sf::Vector2i(0, 1),
        sf::Vector2i(1, 1),
        sf::Vector2i(2, 1)
    };
}
void Tetromino::move(int dx, int dy) {
    posX += dx;
    posY += dy;
}

void Tetromino::draw(sf::RenderWindow& window) {
    sf::RectangleShape block(sf::Vector2f(cellSize - 1, cellSize - 1));
    block.setFillColor(sf::Color::Red);

    for (const auto& b : blocks) {
        block.setPosition(sf::Vector2f(
            (posX + b.x) * cellSize,
            (posY + b.y) * cellSize
        ));

        window.draw(block);
    }
}