#ifndef SHOWCHOOSECARDGROUP_H
#define SHOWCHOOSECARDGROUP_H
#include "abstractshow.h"
#include <vector>
class ShowChooseCardGroup : public AbstractShow
{
    Q_OBJECT
public:
    ShowChooseCardGroup(QMainWindow *m_mainwindow);
    void clear();
    void setCenter();
    std::vector<QPushButton*> &getButton();
private:
    QMainWindow *mainWindow;
    QHBoxLayout *mainLayout;
    QPixmap CardImage[2];
    std::vector<QPushButton*> button;
    QWidget *centerWidget;
signals:
    void initDone();
public slots:
        void Init(int sum,int leader);
};

#endif // SHOWCHOOSECARDGROUP_H
