#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include <vector>

class Board {
private:
    int rows;
    int cols;
    int cellSize;
    std::vector<std::vector<int>> grid;

public:
    Board(int r, int c, int size);

    bool isCellEmpty(int x, int y) const;
    bool canPlaceBlocks(const std::vector<sf::Vector2i>& blocks) const;
    void placeBlocks(const std::vector<sf::Vector2i>& blocks);
    int clearFullRows();
    void draw(sf::RenderWindow& window);
};

#endif