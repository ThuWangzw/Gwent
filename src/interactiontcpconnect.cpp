#include "interactiontcpconnect.h"

InteractionTcpConnect::InteractionTcpConnect(LogicTCPConnect *logic,ShowTCPConnect *show,LogicChooseCardGroup *choose)
{
    connect(logic,SIGNAL(paint()),show,SLOT(show()));
    connect(show,SIGNAL(submitString(QString)),logic,SLOT(ClientConnect(QString)));
    connect(logic,SIGNAL(tcpconnected(QTcpServer*,QTcpSocket*,int)),choose,SLOT(loadCardGroupLeader(QTcpServer*,QTcpSocket*,int)));
}
