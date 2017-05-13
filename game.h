#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "constants.h"
#include "board.h"

class Game {
private:
    GameLevel level;
    Board * gameBoard;
    QGraphicsScene * gameScene;
public:
    Game();
    void setLevel(GameLevel newLevel);
    GameLevel getLevel();
    void createNewGame();
    void endGame();
};

#endif // GAME_H
