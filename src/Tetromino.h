#ifndef TETROMINO_H
#define TETROMINO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Board.h"

class Tetromino {
private:
    std::vector<sf::Vector2i> blocks;
    int cellSize;
    int posX;
    int posY;

    bool canMove(int dx, int dy, const Board& board) const;

public:
    Tetromino(int size);

    bool move(int dx, int dy, const Board& board);
    void rotate(const Board& board);
    std::vector<sf::Vector2i> getBlocks() const;
    void draw(sf::RenderWindow& window);
};

#endif