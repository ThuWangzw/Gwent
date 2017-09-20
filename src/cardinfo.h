#ifndef CARDINFO_H
#define CARDINFO_H

#include <QObject>
#include <QString>
#include <vector>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <vector>
#include <battlefield.h>
using std::vector;
#include "battlefield.h"
class CardInfo:public QObject
{
    Q_OBJECT
public:
    CardInfo();
private:
    QString name;
    int CardID;
    QString quality;
    int power;
    int position;
    QString ability;
    std::vector<QString> property;
public:
    QString getName();
    void setName(const QString &newName);
    int getID();
    void setID(const int newID);
    QString getQuality();
    void setQuality(const QString &newQuality);
    int getPower();
    void setPower(const int newPower);
    int getPosition();
    void setPosition(const int newPosition);
    QString getAbility();
    void setAbility(const QString newAbility);
    std::vector<QString>::iterator getPropertyIter();
    int getPropertySize();
    void setProperty(QJsonArray &newProperty);

    void InitCardInfo(int cardID);
    virtual void BeginMTurn();
    virtual void BeginETurn();
    virtual void Deploy(int place,vector<CardInfo*> FieldCard[],BattleField Field[],vector<CardInfo*>& MCardGroup,int flag);
    virtual void DeadWish();
};

#endif // CARDINFO_H
