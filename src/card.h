#ifndef CARD_H
#define CARD_H

#include <QObject>
#include "cardimage.h"
#include "cardinfo.h"

class Card:public QObject
{
    Q_OBJECT
public:
    Card();
    CardInfo *getInfo();
    CardImage *getiamge();
private:
    CardInfo *info;
    CardImage *image;
protected:
    void InitCard(int cardID);
};

#endif // CARD_H
