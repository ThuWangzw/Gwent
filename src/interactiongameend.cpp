#include "interactiongameend.h"

InteractionGameEnd::InteractionGameEnd(ShowGameEnd *end, LogicMainGame *logic,ShowMainMenu *menu)
{
    End = end;
    Logic = logic;
    Menu = menu;

    connect(End,SIGNAL(buttonChange()),this,SLOT(buttonReConnect()));
    connect(logic,SIGNAL(AllEnd(int,int,vector<int>&,vector<int>&)),End,SLOT(show(int,int,vector<int>&,vector<int>&)));
}

void InteractionGameEnd::buttonReConnect()
{
    connect(End->getButton(),SIGNAL(clicked(bool)),Menu,SLOT(show()));
}
