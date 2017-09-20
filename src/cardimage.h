#ifndef CARDIMAGE_H
#define CARDIMAGE_H

#include <QObject>
#include <QFile>
#include <QPushButton>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
class CardImage:public QObject
{
    Q_OBJECT
public:
    CardImage();
private:
    QPushButton *button;
    int imageID;
public:
    QPushButton *getButton();
    void setButton(QPushButton *newButton);
    int getimageID();
    void setimageID(int newID);
    void InitCardImage(int cardID);
};

#endif // CARDIMAGE_H
