#ifndef SHOWMAINGAME_H
#define SHOWMAINGAME_H
#include "abstractshow.h"
#include <vector>
using std::vector;
class ShowMainGame : public AbstractShow
{
    Q_OBJECT
public:
    ShowMainGame(QMainWindow *mainwindow);
    void clear();
    void setCenter();
    vector<QPushButton*>& getECardButton();
    vector<QPushButton*>& getMCardButton();
    vector<QPushButton*>& getFieldCardButton(int num);
    QPushButton** getFieldFlagButton();
    QPushButton* getPassButton();
private:
    QMainWindow *mainWindow;
    QWidget *centerWidget;
    QPixmap CardImage[34];
    QPixmap FieldFlag[3];
    QPixmap CardBack;
    //main layout
    QVBoxLayout *MainLayout;
    QHBoxLayout *ECardHandLayout;
    QHBoxLayout *MiddleLayout;
    QVBoxLayout *FightBattleField;
    QHBoxLayout *MCardHandLayout;
    QVBoxLayout *PlayerDetailLayout;
    QVBoxLayout *CardDetailLayout;
    //field
    QHBoxLayout *FieldCardLayout[6];
//********Layout SpacingItem********//
    QSpacerItem *ECardInHandSpace;
    QSpacerItem *FightMiddleLayoutSpace;
    QSpacerItem *FightBattleFieldSpace;
    QSpacerItem *MCardInHandSpace;
    QSpacerItem *FightDetailLayoutSpace;
    QSpacerItem *CardDetailLayoutSpace;
    //field
    QSpacerItem *FieldSpace[6];
//*****button*****//
    vector<QPushButton*> ECardHandButton;
    vector<QPushButton*> MCardHandButton;
    vector<QPushButton*> FieldCardButton[6];
    QPushButton *PowerLabel[2];
    QPushButton* FieldFlagButton[6];
    QPushButton* PassButton;

    QPushButton* infoLabel;
signals:
    void buttonChange();
public slots:
    void show(int turn,vector<int>&MCardID,vector<int>&FieldCardID0,vector<int>&FieldCardID1,vector<int>&FieldCardID2,vector<int>&FieldCardID3,vector<int>&FieldCardID4,vector<int>&FieldCardID5,vector<int>&ECardID,
              vector<int>&MCardPower,vector<int>&FieldCardPower0,vector<int>&FieldCardPower1,vector<int>&FieldCardPower2,vector<int>&FieldCardPower3,vector<int>&FieldCardPower4,vector<int>&FieldCardPower5,vector<int>&ECardPower);
};

#endif // SHOWMAINGAME_H
