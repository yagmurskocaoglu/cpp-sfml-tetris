#include <SFML/Graphics.hpp>
#include <fstream>
#include <optional>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Board.h"
#include "Tetromino.h"


int loadHighScore() {
    std::ifstream file("highscore.txt");

    int highScore = 0;

    if (file.is_open()) {
        file >> highScore;
        file.close();
    }

    return highScore;
}

void saveHighScore(int highScore) {
    std::ofstream file("highscore.txt");

    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}





int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Tetris");

    Board board(20, 10, 30);
    Tetromino currentPiece(30);
    Tetromino nextPiece(30);

    int score = 0;
    int highScore = loadHighScore();
    bool gameOver = false;

    sf::RectangleShape sidePanel(sf::Vector2f(500, 600));
   sidePanel.setPosition(sf::Vector2f(300, 0));
    sidePanel.setFillColor(sf::Color(15, 15, 15));

    sf::RectangleShape separator(sf::Vector2f(2, 600));
   separator.setPosition(sf::Vector2f(300, 0));
   separator.setFillColor(sf::Color(80, 80, 80));

   sf::Font font;
if (!font.openFromFile("assets/arial.ttf")) {
    std::cout << "Font dosyasi yuklenemedi!" << std::endl;
}

sf::Text titleText(font, "TETRIS", 36);
titleText.setPosition(sf::Vector2f(380, 80));
titleText.setFillColor(sf::Color::White);

sf::Text scoreText(font, "Skor: 0", 24);
scoreText.setPosition(sf::Vector2f(380, 160));
scoreText.setFillColor(sf::Color::White);

sf::Text nextText(font, "Sonraki:", 24);
nextText.setPosition(sf::Vector2f(380, 230));
nextText.setFillColor(sf::Color::White);

sf::Text highScoreText(font, "En Yuksek: " + std::to_string(highScore), 24);
highScoreText.setPosition(sf::Vector2f(380, 190));
highScoreText.setFillColor(sf::Color::White);

sf::Text gameOverText(font, "", 28);
gameOverText.setPosition(sf::Vector2f(360, 260));
gameOverText.setFillColor(sf::Color::Red);

sf::Text restartText(font, "", 20);
restartText.setPosition(sf::Vector2f(350, 400));
restartText.setFillColor(sf::Color::White);

sf::Text controlsText(font, "Kontroller:\nSol/Sag: Hareket\nAsagi: Hizli dusur\nYukari: Dondur\nR: Yeniden baslat", 18);
controlsText.setPosition(sf::Vector2f(350, 460));
controlsText.setFillColor(sf::Color::White);


    window.setTitle("Tetris | Skor: " + std::to_string(score));

    sf::Clock clock;
    float fallInterval = 0.5f;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
    if (gameOver && keyPressed->code == sf::Keyboard::Key::R) {
        board.reset();
        currentPiece = Tetromino(30);
        nextPiece = Tetromino(30);

        score = 0;
        gameOver = false;

        scoreText.setString("Skor: 0");
        gameOverText.setString("");
        restartText.setString("");
        window.setTitle("Tetris | Skor: 0");
    }

    if (!gameOver) {
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
                board.placeBlocks(currentPiece.getBlocks(),currentPiece.getColorId());

                int clearedRows = board.clearFullRows();

                if (clearedRows > 0) {
                    score += clearedRows * 100;
                    std::cout << "Skor: " << score << std::endl;
                     scoreText.setString("Skor: " + std::to_string(score));
                    window.setTitle("Tetris | Skor: " + std::to_string(score));
                }

                currentPiece = nextPiece;
                nextPiece = Tetromino(30);


                if (!board.canPlaceBlocks(currentPiece.getBlocks())) {
                    gameOver = true;
                    std::cout << "Oyun bitti! Final skor: " << score << std::endl;

                    if (score > highScore) {
        highScore = score;
        saveHighScore(highScore);
        highScoreText.setString("En Yuksek: " + std::to_string(highScore));
    }

                     gameOverText.setString("GAME OVER");
                     restartText.setString("R ile yeniden basla");
                    window.setTitle("GAME OVER | Final skor: " + std::to_string(score));
                }
            }

            clock.restart();
        }

        window.clear(sf::Color::Black);

        board.draw(window);

        window.draw(sidePanel);
        window.draw(separator);
        window.draw(titleText);

        window.draw(scoreText);
        if (!gameOver) {
    window.draw(nextText);
    nextPiece.drawPreview(window, 400, 280);
}
        window.draw(gameOverText);
        window.draw(restartText);
        window.draw(controlsText);
        window.draw(highScoreText);


        if (!gameOver) {
            currentPiece.draw(window);
        }

        window.display();
    }

    return 0;
}