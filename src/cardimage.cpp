#include "cardimage.h"

CardImage::CardImage()
{
    button = new QPushButton;
}

void CardImage::InitCardImage(int cardID)
{
    QString m_String(":/image/image");
    m_String.append(QString::number(cardID));
    //open
    QFile m_File(m_String);
    m_File.open(QIODevice::ReadOnly);

    QByteArray m_byte = m_File.readAll();
    m_File.close();
    QJsonDocument m_json = QJsonDocument::fromJson(m_byte);
    QJsonObject CardJson = m_json.object();

    imageID = CardJson.value("CardID").toInt();
    button = new QPushButton();
    QPixmap m_image(CardJson.value("image").toString());
    button->setIcon(m_image);
    QSize size(100,142);
    button->setIconSize(size);
    button->setFixedSize(size);
}

QPushButton *CardImage::getButton()
{
    return button;
}

void CardImage::setButton(QPushButton *newButton)
{
    button = newButton;
}

int CardImage::getimageID()
{
    return imageID;
}

void CardImage::setimageID(int newID)
{
    imageID = newID;
}
