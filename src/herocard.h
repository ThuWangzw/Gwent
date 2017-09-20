#ifndef HEROCARD_H
#define HEROCARD_H
#include "card.h"

class UnseenElder:public Card
{
public:
    UnseenElder();
    ~UnseenElder(){}
};

class Arachas:public Card
{
public:
    Arachas();
    ~Arachas(){}
    virtual void Deploy(int place,vector<CardInfo*> FieldCard[],BattleField Field[],vector<CardInfo*>& MCardGroup,int flag);
};

class ArachasBehemoth:public Card
{
public:
    ArachasBehemoth();
    ~ArachasBehemoth(){}
};

class ArachasLarva:public Card
{
public:
    ArachasLarva();
    ~ArachasLarva(){}
};

class Archgriffin:public Card
{
public:
    Archgriffin();
    ~Archgriffin(){}
};

class Caranthir:public Card
{
public:
    Caranthir();
    ~Caranthir(){}
};

class CelaenoHarpy:public Card
{
public:
    CelaenoHarpy();
    ~CelaenoHarpy(){}
};

class CroneBrewess:public Card
{
public:
    CroneBrewess();
    ~CroneBrewess(){}
};

class CroneWeavess:public Card
{
public:
    CroneWeavess();
    ~CroneWeavess(){}
};

class CroneWhispess:public Card
{
public:
    CroneWhispess();
    ~CroneWhispess(){}
};

class Dagon:public Card
{
public:
    Dagon();
    ~Dagon(){}
};

class EarthElemental:public Card
{
public:
    EarthElemental();
    ~EarthElemental(){}
};

class Foglet:public Card
{
public:
    Foglet();
    ~Foglet(){}
};

class Frightener:public Card
{
public:
    Frightener();
    ~Frightener(){}
};

class Geels:public Card
{
public:
    Geels();
    ~Geels(){}
};

class GeraltIgni:public Card
{
public:
    GeraltIgni();
    ~GeraltIgni(){}
};

class HarpyBaby:public Card
{
public:
    HarpyBaby();
    ~HarpyBaby(){}
};

class HarpyEgg:public Card
{
public:
    HarpyEgg();
    ~HarpyEgg(){}
};

class LesserEarthElemental:public Card
{
public:
    LesserEarthElemental();
    ~LesserEarthElemental(){}
};

class RabidWolf:public Card
{
public:
    RabidWolf();
    ~RabidWolf(){}
};

class Roach:public Card
{
public:
    Roach();
    ~Roach(){}
};

class VranWarrior:public Card
{
public:
    VranWarrior();
    ~VranWarrior(){}
};

class WildHuntRider:public Card
{
public:
    WildHuntRider();
    ~WildHuntRider(){}
};

class WoodlandSpirit:public Card
{
public:
    WoodlandSpirit();
    ~WoodlandSpirit(){}
};

#endif // HEROCARD_H
