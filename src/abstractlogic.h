#ifndef ABSTRACTLOGIC_H
#define ABSTRACTLOGIC_H

#include <QObject>
#include <QEventLoop>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#include <ctime>
#include "cardinfo.h"
#include "card.h"
class AbstractLogic : public QObject
{
    Q_OBJECT
public:
    explicit AbstractLogic(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ABSTRACTLOGIC_H
