#include "interactionmainmenu.h"

InteractionMainMenu::InteractionMainMenu(ShowMainMenu *menu,LogicTCPConnect *tcp)
{
    Menu = menu;
    Tcp = tcp;
    connect(Menu,SIGNAL(buttonChange()),this,SLOT(buttonReConnect()));
}

void InteractionMainMenu::buttonReConnect()
{
    connect(Menu->getButton(),SIGNAL(clicked(bool)),Tcp,SLOT(Init()));
}
