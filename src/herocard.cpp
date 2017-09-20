#include "herocard.h"
#include <QDebug>
UnseenElder::UnseenElder()
{
    InitCard(31);
}

Arachas::Arachas()
{
    InitCard(1);
}
void Arachas::Deploy(int place, vector<CardInfo *> FieldCard[], BattleField Field[], vector<CardInfo *> &MCardGroup,int flag)
{
    qDebug()<<"success!";
    int i = place%10;
    int n = place/10;
    for(vector<CardInfo*>::iterator iter = MCardGroup.begin();iter != MCardGroup.end();iter++)
    {
        CardInfo* now = *iter;
        if(now->getID()==1) FieldCard[i].push_back(*iter);
    }
    for(vector<CardInfo*>::iterator iter = MCardGroup.begin();iter != MCardGroup.end();)
    {
        CardInfo* now = *iter;
        if(now->getID()==1)
        {
            MCardGroup.erase(iter);
        }
        else    iter++;
    }
}

ArachasBehemoth::ArachasBehemoth()
{
    InitCard(2);
}

ArachasLarva::ArachasLarva()
{
    InitCard(3);
}

Archgriffin::Archgriffin()
{
    InitCard(4);
}

Caranthir::Caranthir()
{
    InitCard(7);
}

CelaenoHarpy::CelaenoHarpy()
{
    InitCard(8);
}

CroneBrewess::CroneBrewess()
{
    InitCard(10);
}

CroneWeavess::CroneWeavess()
{
    InitCard(11);
}

CroneWhispess::CroneWhispess()
{
    InitCard(12);
}

Dagon::Dagon()
{
    InitCard(13);
}

EarthElemental::EarthElemental()
{
    InitCard(14);
}

Foglet::Foglet()
{
    InitCard(16);
}

Frightener::Frightener()
{
    InitCard(17);
}

Geels::Geels()
{
    InitCard(18);
}

GeraltIgni::GeraltIgni()
{
    InitCard(19);
}

HarpyBaby::HarpyBaby()
{
    InitCard(20);
}

HarpyEgg::HarpyEgg()
{
    InitCard(21);
}

LesserEarthElemental::LesserEarthElemental()
{
    InitCard(24);
}

RabidWolf::RabidWolf()
{
    InitCard(25);
}

Roach::Roach()
{
    InitCard(27);
}

VranWarrior::VranWarrior()
{
    InitCard(32);
}

WildHuntRider::WildHuntRider()
{
    InitCard(33);
}

WoodlandSpirit::WoodlandSpirit()
{
    InitCard(34);
}
