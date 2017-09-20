#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <QObject>

#define SUN 0
#define RAIN 1
#define ICE 2
#define FOG 3
class BattleField : public QObject
{
    Q_OBJECT
public:
    BattleField();
    BattleField(int id);
    void clear();
    int getFieldID();
    int getWeather();
    void setID(int i);
    int getRainPower();
    int getIcePower();
    int getFogPower();
private:
    int weather;
    int RainPower;
    int IcePower;
    int FogPower;
    int FieldID;
signals:
    void FogSet();
    void FogLose();
    void WeatherHarm(int,int);
public slots:
    void WeatherAction();
    void IcePowerAdd();
    void IcePowerLost();
    void setWeather(int newWeather);
};

#endif // BATTLEFIELD_H
