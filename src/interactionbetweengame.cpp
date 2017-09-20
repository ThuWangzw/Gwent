#include "interactionbetweengame.h"

InteractionBetweenGame::InteractionBetweenGame(LogicBetweenGame *logic,ShowBetweenGame *show,LogicMainGame *maingame)
{
    Logic = logic;
    Show = show;
    Maingame = maingame;
    //
    connect(Logic,SIGNAL(cardChange(int,vector<int>&,vector<int>&,vector<int>&,int)),Show,SLOT(show(int,vector<int>&,vector<int>&,vector<int>&,int)));
    connect(Logic,SIGNAL(AllDone(vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&)),
            Maingame,SLOT(nextGameBegin(vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&,vector<CardInfo*>&)));
    connect(Show,SIGNAL(InitDone()),this,SLOT(buttonConnect()));
}

void InteractionBetweenGame::buttonConnect()
{
    QSignalMapper *m_map = new QSignalMapper;
    int sum = Show->getChooseButtonSIze();
    std::vector<QPushButton*> button = Show->getChooseButton();
    for(int i = 0;i<sum;i++)
    {
        connect(button[i],SIGNAL(clicked(bool)),m_map,SLOT(map()));
        m_map->setMapping(button[i],i);
    }
    connect(m_map,SIGNAL(mapped(int)),Logic,SLOT(ChooseNewCard(int)));

    connect(Show->getButton(),SIGNAL(clicked(bool)),Logic,SLOT(MDone()));
}
