#ifndef TETROMINO_H
#define TETROMINO_H

#include <SFML/Graphics.hpp>
#include <vector>

class Tetromino {
private:
    std::vector<sf::Vector2i> blocks;
    int cellSize;
    int posX;
    int posY;

    bool canMove(int dx, int dy, int boardCols, int boardRows) const;

public:
    Tetromino(int size);

    void move(int dx, int dy, int boardCols, int boardRows);
    void draw(sf::RenderWindow& window);
};

#endif