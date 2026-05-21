#include "Board.h"

Board::Board(int r, int c, int size) {
    rows = r;
    cols = c;
    cellSize = size;

    grid = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
}
bool Board::isCellEmpty(int x, int y) const {
    if (x < 0 || x >= cols || y < 0 || y >= rows) {
        return false;
    }

    return grid[y][x] == 0;
}

bool Board::canPlaceBlocks(const std::vector<sf::Vector2i>& blocks) const {
    for (const auto& b : blocks) {
        if (!isCellEmpty(b.x, b.y)) {
            return false;
        }
    }

    return true;
}

void Board::placeBlocks(const std::vector<sf::Vector2i>& blocks) {
    for (const auto& b : blocks) {
        if (b.y >= 0 && b.y < rows && b.x >= 0 && b.x < cols) {
            grid[b.y][b.x] = 1;
        }
    }
}

int Board::clearFullRows() {
    int clearedRows = 0;

    for (int row = rows - 1; row >= 0; row--) {
        bool full = true;

        for (int col = 0; col < cols; col++) {
            if (grid[row][col] == 0) {
                full = false;
                break;
            }
        }

        if (full) {
            grid.erase(grid.begin() + row);
            grid.insert(grid.begin(), std::vector<int>(cols, 0));
            clearedRows++;

            row++;
        }
    }

    return clearedRows;
}

void Board::draw(sf::RenderWindow& window) {
    sf::RectangleShape cell(sf::Vector2f(cellSize - 1, cellSize - 1));

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            cell.setPosition(sf::Vector2f(col * cellSize, row * cellSize));

            if (grid[row][col] == 0) {
                cell.setFillColor(sf::Color(30, 30, 30));
            } else {
                cell.setFillColor(sf::Color::Cyan);
            }

            window.draw(cell);
        }
    }
}