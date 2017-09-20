#include "battlefield.h"

BattleField::BattleField(int id)
{
    FieldID = id;
    weather = SUN;

    IcePower = 2;
    RainPower = 1;
    FogPower = 2;
}

BattleField::BattleField()
{

}

int BattleField::getFieldID()
{
    return FieldID;
}

int BattleField::getWeather()
{
    return weather;
}

void BattleField::IcePowerAdd()
{
    if(weather==ICE) IcePower++;
}

void BattleField::IcePowerLost()
{
    if(weather==ICE) IcePower--;
}

void BattleField::clear()
{
    weather = SUN;
    IcePower = 2;
    RainPower = 1;
    FogPower = 2;
}

void BattleField::setWeather(int newWeather)
{
    weather = newWeather;
}

void BattleField::WeatherAction()
{
    if(!weather) return;
    emit WeatherHarm(FieldID,weather);
}

void BattleField::setID(int i)
{
    FieldID = i;
}

int BattleField::getIcePower()
{
    return IcePower;
}

int BattleField::getRainPower()
{
    return RainPower;
}

int BattleField::getFogPower()
{
    return FogPower;
}
