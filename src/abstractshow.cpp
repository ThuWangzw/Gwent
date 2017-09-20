#include "abstractshow.h"

AbstractShow::AbstractShow(QObject *parent) : QObject(parent)
{
    style_ready = "QMainWindow{border-image:url(:image/background);}";
    style_game = "QMainWindow{border-image:url(:image/gamefield);}";
    style_redtext = "QLabel{font:red}";
}

QString AbstractShow::getStyleGame()
{
    return style_game;
}

QString AbstractShow::getStyleReady()
{
    return style_ready;
}

QString AbstractShow::getstyleRedText()
{
    return style_redtext;
}
