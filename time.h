#ifndef TIME_H
#define TIME_H

#include <QGRaphicsTextItem>
#include <QFont>
#include <QDebug>

class Time : public QGraphicsTextItem {
private:
    int timeLeft;
public:
    Time(QGraphicsItem * parent = 0);
    void decrease();
    int getTime();
};

#endif // TIME_H
