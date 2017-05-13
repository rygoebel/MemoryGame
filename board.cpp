#include "board.h"
#include "constants.h"

Board::Board(QGraphicsScene)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(GAME_WIDTH, GAME_HEIGHT);
    //QGraphicsRectItem * view = new QGraphicsRectItem();
    //view->setRect(0,0, 100, 100);
    //scene->
}
