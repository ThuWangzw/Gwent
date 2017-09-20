#ifndef INTERACTIONCHOOSECARDGROUP_H
#define INTERACTIONCHOOSECARDGROUP_H
#include "abstractinteraction.h"
#include "logicchoosecardgroup.h"
#include "showchoosecardgroup.h"
#include "logicdispatchcards.h"

class InteractionChooseCardGroup:public AbstractInteraction
{
    Q_OBJECT
public:
    InteractionChooseCardGroup(ShowChooseCardGroup *show,LogicChooseCardGroup *logic,LogicDispatchCards *dispatch);
public slots:
    void ButtonConnected();
private:
    ShowChooseCardGroup *Show;
    LogicChooseCardGroup *Logic;
    LogicDispatchCards *Dispatch;
};

#endif // INTERACTIONCHOOSECARDGROUP_H
