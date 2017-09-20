#ifndef INTERACTIONBETWEENGAME_H
#define INTERACTIONBETWEENGAME_H
#include "abstractinteraction.h"
#include "logicbetweengame.h"
#include "showbetweengame.h"
#include "logicmaingame.h"
class InteractionBetweenGame : public AbstractInteraction
{
    Q_OBJECT
public:
    InteractionBetweenGame(LogicBetweenGame *logic,ShowBetweenGame *show,LogicMainGame *maingame);
private:
    LogicBetweenGame *Logic;
    ShowBetweenGame *Show;
    LogicMainGame *Maingame;
signals:

public slots:
    void buttonConnect();
};

#endif // INTERACTIONBETWEENGAME_H
