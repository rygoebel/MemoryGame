#ifndef BOARD_H
#define BOARD_H

#include <QgraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Board : public QGraphicsView {
private:
    //QgraphicsScene * scene;
public:
    Board(QGraphicsScene scene);
};

#endif // BOARD_H
