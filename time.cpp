#include "time.h"
#include "constants.h"
#include <QDebug>
Time::Time(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    timeLeft = START_TIME;
    setPlainText(QString("Time: " + QString::number(timeLeft)));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
    setPos(980, 100);
}

void Time::decrease()
{
    qDebug() << "Hello one";
    timeLeft--;
    setPlainText(QString("Time: " + QString::number(timeLeft)));
}

int Time::getTime()
{
    return timeLeft;
}
