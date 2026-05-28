# Tetris Project

Bu proje, C++ ve SFML kullanilarak gelistirilen basit bir Tetris oyunudur. Projede oyun tahtasi, farkli tetromino sekilleri, hareket, dondurme, skor, high score, game over ve yeniden baslatma sistemleri bulunmaktadir.

## Kullanilan Teknolojiler

- C++
- SFML 3
- CMake
- Visual Studio Code
- Git / GitHub

## Ozellikler

- 20x10 Tetris oyun tahtasi
- Farkli tetromino sekilleri
- Rastgele parca uretimi
- Parca hareketleri
- Parca dondurme sistemi
- Otomatik dusme sistemi
- Sabit bloklarla carpisma kontrolu
- Satir silme sistemi
- Skor sistemi
- High score kaydetme sistemi
- Game over sistemi
- R tusu ile yeniden baslatma
- Sag bilgi paneli
- Sonraki tetromino gostergesi

## Kontroller

| Tus | Gorev |
|---|---|
| Sol Ok | Parcayi sola hareket ettirir |
| Sag Ok | Parcayi saga hareket ettirir |
| Asagi Ok | Parcayi hizli asagi indirir |
| Yukari Ok | Parcayi dondurur |
| R | Game over durumunda oyunu yeniden baslatir |

## Proje Yapisi

TetrisProject/
├── assets/
│   └── arial.ttf
├── src/
│   ├── main.cpp
│   ├── Board.h
│   ├── Board.cpp
│   ├── Tetromino.h
│   └── Tetromino.cpp
├── CMakeLists.txt
├── README.md
└── highscore.txt

## Derleme ve Calistirma

Projeyi derlemek icin:

cmake -S . -B build
cmake --build build

Projeyi calistirmak icin:

.\build\TetrisProject.exe

## Notlar

- Oyun SFML penceresi uzerinden calisir.
- High score bilgisi highscore.txt dosyasinda saklanir.
- Yazi gostermek icin assets/arial.ttf font dosyasi kullanilmistir.