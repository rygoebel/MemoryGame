#include "Game.h"

#include <QDebug>
#include <algorithm>

Score * Game::score = 0;
Time * Game::time = nullptr;
QGridLayout * Game::layout = nullptr;
QPixmap * Game::cardReverse = nullptr;
int * Game::positionOfCards = nullptr;
bool * Game::cardsGuessed = nullptr;
int Game::numberOfRevealedCards = 0;
//int Game::indexOfLastRevealedCard = -1;
Card * Game::pointerToFirstCard;

Game::Game()
{
    level = GameLevel::Medium;
    if (cardReverse == nullptr) {
        cardReverse = new QPixmap(":/images/card.jpg");
    }
}

void Game::setLevel(GameLevel newLevel)
{
    level = newLevel;
}

GameLevel Game::getLevel()
{
    return level;
}

void Game::createNewGame()
{
    // Initialization of model
    positionOfCards = new int [NUMBER_OF_CARDS_FOR_MEDIUM_LEVEL];
    cardsGuessed = new bool [NUMBER_OF_CARDS_FOR_MEDIUM_LEVEL];
    for (int i = 0; i < NUMBER_OF_CARDS_FOR_MEDIUM_LEVEL / 2; ++i) {
        positionOfCards[i] = positionOfCards[i + NUMBER_OF_CARDS_FOR_MEDIUM_LEVEL / 2] = i;
    }
    std::random_shuffle(&positionOfCards[0], &positionOfCards[NUMBER_OF_CARDS_FOR_MEDIUM_LEVEL]);

    for (int i = 0; i < NUMBER_OF_CARDS_FOR_MEDIUM_LEVEL; ++i) {
        cardsGuessed[i] = false;
    }

    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0, GAME_WIDTH, GAME_HEIGHT);
    gameBoard = new Board(gameScene);
    gameBoard->setScene(gameScene);

    score = new Score();
    gameScene->addItem(score);

    QTimer * timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(updateTimer()));
    timer->start(1000);

    time = new Time();
    gameScene->addItem(time);
//    gameScene->setBackgroundBrush(QBrush(QImage(":/images/menuBackground.jpg")));
    QBrush brush(QColor(0x99, 0xFF, 0x33, 255));
    gameScene->setBackgroundBrush(brush);
    gameBoard->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameBoard->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gameBoard->setFixedSize(1200, 900);

    layout = new QGridLayout();
    cards = new QVector<Card*>();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            Card * card = new Card(i*4 + j);

            card->setPixmap(cardReverse->scaled(200,200,Qt::KeepAspectRatio));
//            label->setStyleSheet("background-image: ./card.jpg");
//            widget->setPalette(QPixmap(":/images/card.jpg"));

            cards->append(card);
            layout->addWidget(card, i, j);
        }
    }

    gameBoard->setLayout(layout);

    gameBoard->show();
}

void Game::endGame()
{
    delete gameScene;
    for(int i = 0; i < cards->size(); ++i) {
        delete cards->at(i);
    }
    delete cards;
}

void Game::updateTimer()
{
    time->decrease();
}
