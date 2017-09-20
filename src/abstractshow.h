#ifndef ABSTRACTSHOW_H
#define ABSTRACTSHOW_H

#include <QObject>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QPixmap>
#include <QSize>
#include <QLayoutItem>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QPropertyAnimation>
class AbstractShow : public QObject
{
    Q_OBJECT
public:
    explicit AbstractShow(QObject *parent = nullptr);
    QString getStyleReady();
    QString getStyleGame();
    QString getstyleRedText();
private:
    QString style_ready;
    QString style_game;
    QString style_redtext;
signals:

public slots:
};

#endif // ABSTRACTSHOW_H
