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

public:
    Tetromino(int size);

    void draw(sf::RenderWindow& window);
};

#endif