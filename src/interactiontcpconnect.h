#ifndef INTERACTIONTCPCONNECT_H
#define INTERACTIONTCPCONNECT_H
#include "abstractinteraction.h"
#include "logictcpconnect.h"
#include "showtcpconnect.h"
#include "logicchoosecardgroup.h"
class InteractionTcpConnect : public AbstractInteraction
{
    Q_OBJECT
public:
    InteractionTcpConnect(LogicTCPConnect *logic,ShowTCPConnect *show,LogicChooseCardGroup *choose);

signals:

public slots:
};

#endif // INTERACTIONTCPCONNECT_H
