#ifndef SCORE_H
#define SCORE_H

#include <QGRaphicsTextItem>
#include <QFont>
#include <QDebug>

class Score : public QGraphicsTextItem {
private:
    int score;
public:
    Score(QGraphicsItem * parent = 0);
    void increase();
    int getScore();
};

#endif // SCORE_H
