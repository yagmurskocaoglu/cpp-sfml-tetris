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
bool Tetromino::canMove(int dx, int dy, int boardCols, int boardRows) const {
    for (const auto& b : blocks) {
        int newX = posX + b.x + dx;
        int newY = posY + b.y + dy;

        if (newX < 0 || newX >= boardCols) {
            return false;
        }

        if (newY < 0 || newY >= boardRows) {
            return false;
        }
    }

    return true;
}

bool Tetromino::move(int dx, int dy, int boardCols, int boardRows) {
    if (canMove(dx, dy, boardCols, boardRows)) {
        posX += dx;
        posY += dy;
        return true;
    }
    return false;
}
std::vector<sf::Vector2i> Tetromino::getBlocks() const {
    std::vector<sf::Vector2i> result;

    for (const auto& b : blocks) {
        result.push_back(sf::Vector2i(posX + b.x, posY + b.y));
    }

    return result;
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