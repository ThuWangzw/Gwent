#include "interactiondispatchcards.h"
#include <QDebug>
#include <QPushButton>
InteractionDispatchCards::InteractionDispatchCards(ShowDispatchCards *show,LogicDispatchCards *logic,LogicMainGame *maingame)
{
    Show = show;
    Logic = logic;
    connect(Logic,SIGNAL(cardChange(std::vector<int>&,std::vector<int>&,std::vector<int>&)),
            Show,SLOT(show(std::vector<int>&,std::vector<int>&,std::vector<int>&)));

    connect(show,SIGNAL(dispatchInitDone()),this,SLOT(buttonConnect()));
    connect(logic,SIGNAL(ChooseAllDone(std::vector<int>&,std::vector<int>&,std::vector<int>&,std::vector<int>&,QTcpServer *,QTcpSocket *,int)),
            maingame,SLOT(Init(std::vector<int>&,std::vector<int>&,std::vector<int>&,std::vector<int>&,QTcpServer *,QTcpSocket *,int)));
}

void InteractionDispatchCards::buttonConnect()
{
    QSignalMapper *m_map = new QSignalMapper;
    int sum = Logic->getChooseCardNum();
    std::vector<QPushButton*> button = Show->getChooseButton();
    for(int i = 0;i<sum;i++)
    {
        connect(button[i],SIGNAL(clicked(bool)),m_map,SLOT(map()));
        m_map->setMapping(button[i],i);
    }
    connect(m_map,SIGNAL(mapped(int)),Logic,SLOT(ChooseNewCard(int)));

    connect(Show->getButton(),SIGNAL(clicked(bool)),Logic,SLOT(MDone()));
}
