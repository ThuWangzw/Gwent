#include "cardinfo.h"
#include <QDebug>
CardInfo::CardInfo()
{

}

void CardInfo::InitCardInfo(int cardID)
{
    QString m_String(":/json/json");
    m_String.append(QString::number(cardID));
    //open json
    QFile m_File(m_String);
    m_File.open(QIODevice::ReadOnly);

    QByteArray m_byte = m_File.readAll();
    m_File.close();
    QJsonDocument m_json = QJsonDocument::fromJson(m_byte);
    QJsonObject CardJson = m_json.object();
    name = CardJson.value("name").toString();
    CardID = CardJson.value("CardID").toInt();
    quality = CardJson.value("quality").toString();
    power = CardJson.value("power").toString().toInt();
    position = CardJson.value("position").toString().toInt();
    ability = CardJson.value("ability").toString();
    QJsonArray m_property = CardJson.value("property").toArray();
    QJsonArray::Iterator iter = m_property.begin();
    for(;iter!=m_property.end();iter++)
    {
        property.push_back((*iter).toString());
    }
}

QString CardInfo::getName()
{
    return name;
}

void CardInfo::setName(const QString &newName)
{
    name.clear();
    name.append(newName);
}

int CardInfo::getID()
{
    return CardID;
}

void CardInfo::setID(const int newID)
{
    CardID = newID;
}

QString CardInfo::getQuality()
{
    return quality;
}

void CardInfo::setQuality(const QString &newQuality)
{
    quality.clear();
    quality.append(newQuality);
}

int CardInfo::getPower()
{
    return power;
}

void CardInfo::setPower(const int newPower)
{
    power = newPower;
}

int CardInfo::getPosition()
{
    return position;
}

void CardInfo::setPosition(const int newPosition)
{
    position = newPosition;
}

QString CardInfo::getAbility()
{
    return ability;
}

void CardInfo::setAbility(const QString newAbility)
{
    ability.clear();
    ability.append(newAbility);
}

std::vector<QString>::iterator CardInfo::getPropertyIter()
{
    return property.begin();
}

int CardInfo::getPropertySize()
{
    return property.size();
}

void CardInfo::setProperty(QJsonArray &newProperty)
{
    property.clear();
    QJsonArray::Iterator iter = newProperty.begin();
    for(;iter!=newProperty.end();iter++)
    {
        property.push_back((*iter).toString());
    }
}

void CardInfo::BeginMTurn()
{

}

void CardInfo::BeginETurn()
{

}

void CardInfo::Deploy(int place,vector<CardInfo*> FieldCard[],BattleField Field[],vector<CardInfo*>& MCardGroup,int flag)
{
    int i = place%10;
    int n = place/10;
}

void CardInfo::DeadWish()
{

}
