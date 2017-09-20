#ifndef INTERACTIONMAINMENU_H
#define INTERACTIONMAINMENU_H
#include "abstractinteraction.h"
#include "showmainmenu.h"
#include "logictcpconnect.h"
class InteractionMainMenu : public AbstractInteraction
{
    Q_OBJECT
public:
    InteractionMainMenu(ShowMainMenu *menu,LogicTCPConnect *tcp);
private:
    ShowMainMenu *Menu;
    LogicTCPConnect *Tcp;
signals:

public slots:
    void buttonReConnect();
};

#endif // INTERACTIONMAINMENU_H
