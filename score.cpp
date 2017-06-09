#include "Score.h"

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText(QString("Score: " + QString::number(score)));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
    setPos(980, 0);
}

void Score::increase()
{
    score++;
    setPlainText(QString("Score: " + QString::number(score)));
}

int Score::getScore()
{
    return score;
}
