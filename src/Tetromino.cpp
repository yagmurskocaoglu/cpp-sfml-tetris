#include "Tetromino.h"
#include <cstdlib>

Tetromino::Tetromino(int size) {
    cellSize = size;
    posX = 4;
    posY = 0;

   int type = std::rand() % 7;

    if (type == 0) { 
        // I parçası
        colorId = 1;
        blocks = {
            sf::Vector2i(0, 1),
            sf::Vector2i(1, 1),
            sf::Vector2i(2, 1),
            sf::Vector2i(3, 1)
        };
    } 
    else if (type == 1) { 
        // O parçası
        colorId = 2;
        blocks = {
            sf::Vector2i(0, 0),
            sf::Vector2i(1, 0),
            sf::Vector2i(0, 1),
            sf::Vector2i(1, 1)
        };
    } 
    else if (type == 2) { 
        // T parçası
        colorId = 3;
        blocks = {
            sf::Vector2i(1, 0),
            sf::Vector2i(0, 1),
            sf::Vector2i(1, 1),
            sf::Vector2i(2, 1)
        };
    } 
    else if (type == 3) { 
        // L parçası
        colorId = 4;
        blocks = {
            sf::Vector2i(0, 0),
            sf::Vector2i(0, 1),
            sf::Vector2i(1, 1),
            sf::Vector2i(2, 1)
        };
    } 
    else if (type == 4) { 
        // J parçası
        colorId = 5;
        blocks = {
            sf::Vector2i(2, 0),
            sf::Vector2i(0, 1),
            sf::Vector2i(1, 1),
            sf::Vector2i(2, 1)
        };
    } 
    else if (type == 5) { 
        // S parçası
        colorId = 6;
        blocks = {
            sf::Vector2i(1, 0),
            sf::Vector2i(2, 0),
            sf::Vector2i(0, 1),
            sf::Vector2i(1, 1)
        };
    } 
    else { 
        // Z parçası
        colorId = 7;
        blocks = {
            sf::Vector2i(0, 0),
            sf::Vector2i(1, 0),
            sf::Vector2i(1, 1),
            sf::Vector2i(2, 1)
        };
    }
}
bool Tetromino::canMove(int dx, int dy, const Board& board) const {
    for (const auto& b : blocks) {
        int newX = posX + b.x + dx;
        int newY = posY + b.y + dy;

        if (!board.isCellEmpty(newX, newY)) {
            return false;
        }
    }

    return true;
}

bool Tetromino::move(int dx, int dy, const Board& board) {
    if (canMove(dx, dy, board)) {
        posX += dx;
        posY += dy;
        return true;
    }

    return false;
}

void Tetromino::rotate(const Board& board) {
    std::vector<sf::Vector2i> rotatedBlocks;

    for (const auto& b : blocks) {
        rotatedBlocks.push_back(sf::Vector2i(-b.y, b.x));
    }

    for (const auto& b : rotatedBlocks) {
        int newX = posX + b.x;
        int newY = posY + b.y;

        if (!board.isCellEmpty(newX, newY)) {
            return;
        }
    }

    blocks = rotatedBlocks;
}

std::vector<sf::Vector2i> Tetromino::getBlocks() const {
    std::vector<sf::Vector2i> result;

    for (const auto& b : blocks) {
        result.push_back(sf::Vector2i(posX + b.x, posY + b.y));
    }

    return result;
}

int Tetromino::getColorId() const {
    return colorId;
}

void Tetromino::draw(sf::RenderWindow& window) {
    sf::RectangleShape block(sf::Vector2f(cellSize - 1, cellSize - 1));
   if (colorId == 1) {
    block.setFillColor(sf::Color::Cyan);
}
else if (colorId == 2) {
    block.setFillColor(sf::Color::Yellow);
}
else if (colorId == 3) {
    block.setFillColor(sf::Color::Magenta);
}
else if (colorId == 4) {
    block.setFillColor(sf::Color(255, 140, 0));
}
else if (colorId == 5) {
    block.setFillColor(sf::Color::Blue);
}
else if (colorId == 6) {
    block.setFillColor(sf::Color::Green);
}
else if (colorId == 7) {
    block.setFillColor(sf::Color::Red);
}

    for (const auto& b : blocks) {
        block.setPosition(sf::Vector2f(
            (posX + b.x) * cellSize,
            (posY + b.y) * cellSize
        ));

        window.draw(block);
    }
}