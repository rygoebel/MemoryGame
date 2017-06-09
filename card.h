#ifndef CARD_H
#define CARD_H

#include <QLabel>
#include <QString>
#include <QDebug>
#include <QThread>
#include <QCoreApplication>

class Card : public QLabel {
private:
    int orderNumber;
public:
    Card(int sum, QWidget * parent = 0);
    void mousePressEvent(QMouseEvent * event);
    int getOrderNumber();
};

#endif // CARD_H
