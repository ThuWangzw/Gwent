#ifndef INTERACTIONDISPATCHCARDS_H
#define INTERACTIONDISPATCHCARDS_H

#include "abstractinteraction.h"
#include "logicdispatchcards.h"
#include "showdispatchcards.h"
#include "logicmaingame.h"
class InteractionDispatchCards : public AbstractInteraction
{
    Q_OBJECT
public:
    InteractionDispatchCards(ShowDispatchCards *show,LogicDispatchCards *logic,LogicMainGame *maingame);
private:
    ShowDispatchCards *Show;
    LogicDispatchCards *Logic;
signals:

public slots:
    void buttonConnect();
};

#endif // INTERACTIONDISPATCHCARDS_H
