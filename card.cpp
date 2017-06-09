#include "card.h"
#include "game.h"

Card::Card(int sum, QWidget *parent) : QLabel(parent), orderNumber(sum)
{

}

void Card::mousePressEvent(QMouseEvent *event)
{
    if (this == Game::pointerToFirstCard || Game::cardsGuessed[orderNumber]) {
        return;
    }
    Game::numberOfRevealedCards++;

    if (Game::numberOfRevealedCards == 1) {
//        Game::indexOfLastRevealedCard = orderNumber;
        Game::pointerToFirstCard = this;
    }

    QString fileName = ":/images/face0" + QString::number(Game::positionOfCards[orderNumber] + 1) + ".png";
    qDebug() << fileName;
    QPixmap * pixmap = new QPixmap(fileName);
    setPixmap(pixmap->scaled(200,200,Qt::KeepAspectRatio));

    if (Game::numberOfRevealedCards == 2) {
        QCoreApplication::processEvents();
        QThread::sleep(1);
        if (Game::positionOfCards[orderNumber] == Game::positionOfCards[Game::pointerToFirstCard->getOrderNumber()]) {
            Game::cardsGuessed[orderNumber] = true;
            Game::cardsGuessed[Game::pointerToFirstCard->getOrderNumber()] = true;
            Game::pointerToFirstCard->setVisible(false);
            this->setVisible(false);
            Game::score->increase();
        }
        else {
            setPixmap(Game::cardReverse->scaled(200,200,Qt::KeepAspectRatio));
            Game::pointerToFirstCard->setPixmap(Game::cardReverse->scaled(200,200,Qt::KeepAspectRatio));
        }
        Game::numberOfRevealedCards = 0;
        Game::pointerToFirstCard = nullptr;
    }
}

int Card::getOrderNumber()
{
    return orderNumber;
}
