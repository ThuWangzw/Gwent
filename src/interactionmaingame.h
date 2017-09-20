#ifndef INTERACTIONMAINGAME_H
#define INTERACTIONMAINGAME_H
#include "abstractinteraction.h"
#include "logicmaingame.h"
#include "showmaingame.h"
#include "logicbetweengame.h"
class InteractionMainGame : public AbstractInteraction
{
    Q_OBJECT
public:
    InteractionMainGame(LogicMainGame *logic,ShowMainGame *show,LogicBetweenGame *between);
private:
    LogicMainGame *Logic;
    ShowMainGame *Show;
    LogicBetweenGame *Between;
signals:

public slots:
    void buttonReConnect();
};

#endif // INTERACTIONMAINGAME_H
