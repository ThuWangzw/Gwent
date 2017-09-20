#ifndef INTERACTIONGAMEEND_H
#define INTERACTIONGAMEEND_H
#include "abstractinteraction.h"
#include "showgameend.h"
#include "logicmaingame.h"
#include "showmainmenu.h"

class InteractionGameEnd : public AbstractInteraction
{
    Q_OBJECT
public:
    InteractionGameEnd(ShowGameEnd *end, LogicMainGame *logic,ShowMainMenu *menu);
private:
    ShowGameEnd *End;
    LogicMainGame *Logic;
    ShowMainMenu *Menu;
signals:

public slots:
    void buttonReConnect();
};

#endif // INTERACTIONGAMEEND_H
