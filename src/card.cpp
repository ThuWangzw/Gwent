#include "card.h"

Card::Card()
{
    info = new CardInfo;
    image = new CardImage;
}

void Card::InitCard(int cardID)
{
    info->InitCardInfo(cardID);
    image->InitCardImage(cardID);
}

CardImage *Card::getiamge()
{
    return image;
}

CardInfo *Card::getInfo()
{
    return info;
}
