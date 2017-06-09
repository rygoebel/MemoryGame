#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGridLayout>
#include <QLabel>
#include <QTimer>

#include "constants.h"
#include "board.h"
#include "card.h"
#include "score.h"
#include "time.h"

class Game : public QObject{
    Q_OBJECT
private:
    GameLevel level;
    static Time * time;
    static Score * score;
    Board * gameBoard;
    static QGridLayout * layout;
    QGraphicsScene * gameScene;
    QVector<Card*> * cards;
    static QPixmap * cardReverse;
    static int * positionOfCards;
    static bool * cardsGuessed;
    static int numberOfRevealedCards;
//    static int indexOfLastRevealedCard;
    static Card * pointerToFirstCard;
public:
    friend class Card;
    Game();
    void setLevel(GameLevel newLevel);
    GameLevel getLevel();
    void createNewGame();
    void endGame();
public slots:
    void updateTimer();
};

#endif // GAME_H
