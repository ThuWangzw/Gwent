#include "logicmaingame.h"
#include <QDebug>
LogicMainGame::LogicMainGame()
{
    for(int i = 0;i<6;i++)
    {
        Field[i].setID(i);;
    }
    //connect
    for(int i = 0;i<6;i++)
    {
        connect(&(Field[i]),SIGNAL(WeatherHarm(int,int)),this,SLOT(weatherAct(int,int)));
    }
    connect(this,SIGNAL(abilityEnd()),this,SLOT(gameCacu()));
    connect(this,SIGNAL(cardChange()),this,SLOT(cardChangeAction()));
}

void LogicMainGame::play()
{
    lastfirst = playerID;
    gameNum++;
    while(true)
    {
        if(gameStatus==1)
        {
            BeginMTurn();
            if(!MPass)
            {
                QEventLoop *myLoop = new QEventLoop;
                connect(this,SIGNAL(TurnEnd()),myLoop,SLOT(quit()));
                myLoop->exec();
                disconnect(this,SIGNAL(TurnEnd()),myLoop,SLOT(quit()));
            }
            else
            {
                gameCacu();
            }
        }
        if(passnum==2)
        {
            if(MPower>EPower)
            {
                MWin++;
                qDebug()<<"i win";
                lastwinner = 0;
            }
            else if(MPower<EPower)
            {
                EWin++;
                qDebug()<<"i lose";
                lastwinner = 1;
            }
            else lastwinner = 2;
            mGrade.push_back(MPower);
            eGrade.push_back(EPower);
            emit nextGame(lastwinner,2,MCardGroup,MCardHand,ECardGroup,ECardHand,tcpServer,tcpClient,soc);
            break;
        }
        if(gameStatus==4)
        {
            BeginETurn();
            if(!EPass)
            {
                enemyAction();
            }
            else gameCacu();
        }
        if(passnum==2)
        {
            if(MPower>EPower)
            {
                MWin++;
                qDebug()<<"i win";
                lastwinner = 0;
            }
            else if(MPower<EPower)
            {
                EWin++;
                qDebug()<<"i lose";
                lastwinner = 1;
            }
            else lastwinner = 2;
            mGrade.push_back(MPower);
            eGrade.push_back(EPower);
            emit nextGame(lastwinner,2,MCardGroup,MCardHand,ECardGroup,ECardHand,tcpServer,tcpClient,soc);
            break;
        }
    }

    //next

    ChooseTheFirst();
    gameNum++;
    while(true)
    {
        if(gameStatus==1)
        {
            BeginMTurn();
            if(!MPass)
            {
                QEventLoop *myLoop = new QEventLoop;
                connect(this,SIGNAL(TurnEnd()),myLoop,SLOT(quit()));
                myLoop->exec();
                disconnect(this,SIGNAL(TurnEnd()),myLoop,SLOT(quit()));
                delete myLoop;
            }
            else gameCacu();
        }
        if(passnum==2)
        {
            if(MPower>EPower)
            {
                MWin++;
                lastwinner = 0;
            }
            else if(MPower<EPower)
            {
                EWin++;
                lastwinner = 1;
            }
            else lastwinner = 2;
            mGrade.push_back(MPower);
            eGrade.push_back(EPower);
            if(MWin>EWin)
            {
                gameEnd(WIN);
                return;
            }
            else if(MWin<EWin)
            {
                gameEnd(LOSE);
                return;
            }
            emit nextGame(lastwinner,1,MCardGroup,MCardHand,ECardGroup,ECardHand,tcpServer,tcpClient,soc);
            break;
        }
        if(gameStatus==4)
        {
            BeginETurn();
            if(!EPass)
            {
                enemyAction();
            }
            else gameCacu();
        }
        if(passnum==2)
        {
            if(MPower>EPower)
            {
                MWin++;
                lastwinner = 0;
            }
            else if(MPower<EPower)
            {
                EWin++;
                lastwinner = 1;
            }
            else lastwinner = 2;
            mGrade.push_back(MPower);
            eGrade.push_back(EPower);
            if(MWin>EWin)
            {
                gameEnd(WIN);
                return;
            }
            else if(MWin<EWin)
            {
                gameEnd(LOSE);
                return;
            }
            emit nextGame(lastwinner,1,MCardGroup,MCardHand,ECardGroup,ECardHand,tcpServer,tcpClient,soc);
            break;
        }
    }

    //next
    ChooseTheFirst();
    gameNum++;
    while(true)
    {
        if(gameStatus==1)
        {
            BeginMTurn();
            if(!MPass)
            {
                QEventLoop *myLoop = new QEventLoop;
                connect(this,SIGNAL(TurnEnd()),myLoop,SLOT(quit()));
                myLoop->exec();
                disconnect(this,SIGNAL(TurnEnd()),myLoop,SLOT(quit()));
                delete myLoop;
            }
            else gameCacu();
        }
        if(passnum==2)
        {
            if(MPower>EPower)
            {
                MWin++;
            }
            else if(MPower<EPower)
            {
                EWin++;
            }
            mGrade.push_back(MPower);
            eGrade.push_back(EPower);
            break;
        }
        if(gameStatus==4)
        {
            BeginETurn();
            if(!EPass)
            {
                enemyAction();
            }
            else gameCacu();
        }
        if(passnum==2)
        {
            if(MPower>EPower)
            {
                MWin++;
            }
            else if(MPower<EPower)
            {
                EWin++;
            }
            mGrade.push_back(MPower);
            eGrade.push_back(EPower);
            break;
        }
    }

    if(MWin==2)
    {
        gameEnd(WIN);
    }
    else if(EWin==2)
    {
        gameEnd(LOSE);
    }
    else gameEnd(DRAW);
}

void LogicMainGame::allclear()
{
    vector<CardInfo*> temp;
    MCardGroup.clear();
    MCardGroup.swap(temp);
    ECardGroup.clear();
    ECardGroup.swap(temp);
    ECardHand.clear();
    ECardHand.swap(temp);
    MCardHand.clear();
    MCardHand.swap(temp);
    MCardTomb.clear();
    MCardTomb.swap(temp);
    ECardTomb.clear();
    ECardTomb.swap(temp);
    MCardGiveup.clear();
    MCardGiveup.swap(temp);
    ECardGiveup.clear();
    ECardGiveup.swap(temp);
    for(int i=0;i<6;i++)
    {
        FieldCard[i].clear();
        FieldCard[i].swap(temp);
    }
    vector<int> v;
    MCardHandID.clear();
    MCardHandID.swap(v);

    ECardHandID.clear();
    ECardHandID.swap(v);

    EHand.clear();
    EHand.swap(v);
    for(int i=0;i<6;i++)
    {
        FieldCardID[i].clear();
        FieldCardID[i].swap(v);
    }
    MCardHandPower.clear();
    MCardHandPower.swap(v);

    ECardHandPower.clear();
    ECardHandPower.swap(v);

    mGrade.clear();
    mGrade.swap(v);
    eGrade.clear();
    eGrade.swap(v);

    for(int i=0;i<6;i++)
    {
        FieldCardPower[i].clear();
        FieldCardPower[i].swap(v);
    }
    //battlefield
    for(int i=0;i<6;i++) Field[i].clear();
    //
    gameStatus = 1;
    MWin = 0;
    EWin = 0;
    passnum = 0;
    MPower = 0;
    EPower = 0;
    lastwinner = 2;
    MPass = 0;
    EPass = 0;
    gameNum = 0;
}

void LogicMainGame::onegameclear()
{
    //vector
    vector<CardInfo*> temp;

    MCardGroup.clear();
    MCardGroup.swap(temp);

    ECardGroup.clear();
    ECardGroup.swap(temp);

    ECardHand.clear();
    ECardHand.swap(temp);

    MCardHand.clear();
    MCardHand.swap(temp);
    for(int i=0;i<3;i++)
    {
        for(vector<CardInfo*>::iterator iter = FieldCard[i].begin();iter!=FieldCard[i].end();iter++) MCardTomb.push_back(*iter);
        FieldCard[i].clear();
        FieldCard[i].swap(temp);
    }
    for(int i=3;i<6;i++)
    {
        for(vector<CardInfo*>::iterator iter = FieldCard[i].begin();iter!=FieldCard[i].end();iter++) ECardTomb.push_back(*iter);
        FieldCard[i].clear();
        FieldCard[i].swap(temp);
    }
    vector<int> v;
    MCardHandID.clear();
    MCardHandID.swap(v);

    ECardHandID.clear();
    ECardHandID.swap(v);

    for(int i=0;i<6;i++)
    {
        FieldCardID[i].clear();
        FieldCardID[i].swap(v);
    }
    MCardHandPower.clear();
    MCardHandPower.swap(v);

    ECardHandPower.clear();
    ECardHandPower.swap(v);

    for(int i=0;i<6;i++)
    {
        FieldCardPower[i].clear();
        FieldCardPower[i].swap(v);
    }
    for(int i=0;i<6;i++) Field[i].clear();
    passnum = 0;
    MPower = 0;
    EPower = 0;
    gameStatus = 1;
    MPass = 0;
    EPass = 0;
}

void LogicMainGame::ChooseTheFirst()
{
    if(lastwinner==0) gameStatus = 1;
    else if(lastwinner==1) gameStatus = 4;
    else
    {
        if(lastfirst==0)
        {
            gameStatus=4;
            lastfirst = 1;
        }
        else
        {
            gameStatus = 1;
            lastfirst = 0;
        }
    }
    emit cardChange();
}

void LogicMainGame::BeginETurn()
{
    //my e
    for(int i = 0;i<3;i++)
    {
        for(vector<CardInfo*>::iterator iter = FieldCard[i].begin();iter!=FieldCard[i].end();iter++)
        {
            CardInfo* now = *iter;
            now->BeginETurn();
        }
    }
    //en m
    for(int i = 3;i<6;i++)
    {
        for(vector<CardInfo*>::iterator iter = FieldCard[i].begin();iter!=FieldCard[i].end();iter++)
        {
            CardInfo* now = *iter;
            now->BeginMTurn();
        }
    }
    //weather
    for(int i = 0;i<3;i++)
    {
        Field[i].WeatherAction();
    }
}

void LogicMainGame::BeginMTurn()
{
    //my m
    for(int i = 0;i<3;i++)
    {
        for(vector<CardInfo*>::iterator iter = FieldCard[i].begin();iter!=FieldCard[i].end();iter++)
        {
            CardInfo* now = *iter;
            now->BeginMTurn();
        }
    }
    //en e
    for(int i = 3;i<6;i++)
    {
        for(vector<CardInfo*>::iterator iter = FieldCard[i].begin();iter!=FieldCard[i].end();iter++)
        {
            CardInfo* now = *iter;
            now->BeginETurn();
        }
    }
    //weather
    for(int i = 3;i<6;i++)
    {
        Field[i].WeatherAction();
    }
}

void LogicMainGame::Init(std::vector<int>&mgroup,std::vector<int>&mhand,std::vector<int>&egroup,std::vector<int>&ehand,QTcpServer *server,QTcpSocket *client,int flag)
{
    allclear();
    //who is first

    tcpserver = server;
    tcpClient = client;
    soc = flag;
    srand((unsigned)time(NULL));
    if(!soc)
    {
        playerID = rand()%2;
        if(playerID) gameStatus=4;
        else gameStatus = 1;
    }
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(test()));
    if(!soc)
    {
        //first send
        QByteArray buffer;
        QDataStream stream(&buffer,QIODevice::WriteOnly);
        stream.setVersion(QDataStream::Qt_5_9);
        stream<<((int)mgroup.size());
        for(vector<int>::iterator iter = mgroup.begin();iter!=mgroup.end();iter++)
            stream<<*iter;
        stream<<((int)mhand.size());
        for(vector<int>::iterator iter = mhand.begin();iter!=mhand.end();iter++)
            stream<<*iter;
        stream<<(1-playerID);
        tcpServer = tcpserver->nextPendingConnection();
        tcpServer->write(buffer);
        //second recvd

        QDataStream mstream;
        mstream.setDevice(tcpServer);
        mstream.setVersion(QDataStream::Qt_5_9);
        if(mstream.atEnd())
        {//if stream not have,wait
            QEventLoop *loop = new QEventLoop;
            connect(tcpServer,SIGNAL(readyRead()),this,SLOT(readEnemy()));
            connect(this,SIGNAL(enemyrecvend()),loop,SLOT(quit()));
            loop->exec();
            disconnect(tcpServer,SIGNAL(readyRead()),this,SLOT(readEnemy()));
            disconnect(this,SIGNAL(enemyrecvend()),loop,SLOT(quit()));
            delete loop;
        }
        else
        {//if have ,read
            readEnemy();
        }
    }
    else
    {
        QDataStream mstream;
        mstream.setDevice(tcpClient);
        mstream.setVersion(QDataStream::Qt_5_9);
        //first
        if(mstream.atEnd())
        {//if stream not have,wait
            QEventLoop *loop = new QEventLoop;
            connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readEnemy()));
            connect(this,SIGNAL(enemyrecvend()),loop,SLOT(quit()));
            loop->exec();
            disconnect(tcpClient,SIGNAL(readyRead()),this,SLOT(readEnemy()));
            disconnect(this,SIGNAL(enemyrecvend()),loop,SLOT(quit()));
            delete loop;
        }
        else
        {//if have ,read
            readEnemy();
        }
        //second
        QByteArray buffer;
        QDataStream stream(&buffer,QIODevice::WriteOnly);
        stream.setVersion(QDataStream::Qt_5_9);
        stream<<((int)mgroup.size());
        for(vector<int>::iterator iter = mgroup.begin();iter!=mgroup.end();iter++)
        {
            stream<<*iter;
        }
        stream<<((int)mhand.size());
        for(vector<int>::iterator iter = mhand.begin();iter!=mhand.end();iter++)
        {
            stream<<*iter;
        }
        tcpClient->write(buffer);
    }
    //recv
    for(vector<int>::iterator iter = mgroup.begin();iter!=mgroup.end();iter++)
    {
        int id = *iter;
        MCardGroup.push_back(fingCard(id));
    }
    for(vector<int>::iterator iter = mhand.begin();iter!=mhand.end();iter++)
    {
        int id = *iter;
        //leader
        if(iter==mhand.begin()) MCardHand.push_back(fingCard(id));
        else MCardHand.push_back(MCardGroup[id]);
    }
    //delete

    std::sort(mhand.begin(),mhand.end(),std::greater<int>());
    for(int i = 1; i< mhand.size();i++)
    {
        vector<CardInfo*>::iterator iter = MCardGroup.begin();
        for(int j = 0;j<mhand[i];j++,iter++);
        CardInfo*now = *iter;
        MCardGroup.erase(iter);
    }

    std::sort(EHand.begin(),EHand.end(),std::greater<int>());
    for(int i = 1; i< EHand.size();i++)
    {
        vector<CardInfo*>::iterator iter = ECardGroup.begin();
        for(int j = 0;j<EHand[i];j++,iter++);
        ECardGroup.erase(iter);
    }
    emit cardChange();
    play();
}

CardInfo *LogicMainGame::fingCard(int id)
{
    Card *newcard;
    switch (id)
    {
    case 1:
        newcard = new Arachas;
        break;
    case 2:
        newcard = new ArachasBehemoth;
        break;
    case 3:
        newcard = new ArachasLarva;
        break;
    case 4:
        newcard = new Archgriffin;
        break;
    case 5:
        newcard = new BekkersTwistedMirror;
        break;
    case 6:
        newcard = new BitingFrost;
        break;
    case 7:
        newcard = new Caranthir;
        break;
    case 8:
        newcard = new CelaenoHarpy;
        break;
    case 9:
        newcard = new CommandersHorn;
        break;
    case 10:
        newcard = new CroneBrewess;
        break;
    case 11:
        newcard = new CroneWeavess;
        break;
    case 12:
        newcard = new CroneWhispess;
        break;
    case 13:
        newcard = new Dagon;
        break;
    case 14:
        newcard = new EarthElemental;
        break;
    case 15:
        newcard = new FirstLight;
        break;
    case 16:
        newcard = new Foglet;
        break;
    case 17:
        newcard = new Frightener;
        break;
    case 18:
        newcard = new Geels;
        break;
    case 19:
        newcard = new GeraltIgni;
        break;
    case 20:
        newcard = new HarpyBaby;
        break;
    case 21:
        newcard = new HarpyEgg;
        break;
    case 22:
        newcard = new ImpenetrableFog;
        break;
    case 23:
        newcard = new Lacerate;
        break;
    case 24:
        newcard = new LesserEarthElemental;
        break;
    case 25:
        newcard = new RabidWolf;
        break;
    case 26:
        newcard = new Realign;
        break;
    case 27:
        newcard = new Roach;
        break;
    case 28:
        newcard = new Sunny;
        break;
    case 29:
        newcard = new ThunderboltPotion;
        break;
    case 30:
        newcard = new TorrentialRain;
        break;
    case 31:
        newcard = new UnseenElder;
        break;
    case 32:
        newcard = new VranWarrior;
        break;
    case 33:
        newcard = new WildHuntRider;
        break;
    case 34:
        newcard = new WoodlandSpirit;
        break;
    default:
        break;
    }
    return newcard->getInfo();
}

void LogicMainGame::cardChangeAction()
{
    //update data
    vector<int> v;
    MCardHandID.clear();
    MCardHandID.swap(v);

    ECardHandID.clear();
    ECardHandID.swap(v);

    for(int i=0;i<6;i++)
    {
        FieldCardID[i].clear();
        FieldCardID[i].swap(v);
    }
    MCardHandPower.clear();
    MCardHandPower.swap(v);

    ECardHandPower.clear();
    ECardHandPower.swap(v);

    for(int i=0;i<6;i++)
    {
        FieldCardPower[i].clear();
        FieldCardPower[i].swap(v);
    }

    vector<CardInfo*>::iterator iter;
    for(iter = MCardHand.begin();iter!=MCardHand.end();iter++)
    {
        CardInfo *now = *iter;
        MCardHandID.push_back(now->getID());
        MCardHandPower.push_back(now->getPower());
    }
    for(iter = ECardHand.begin();iter!=ECardHand.end();iter++)
    {
        CardInfo *now = *iter;
        ECardHandID.push_back(now->getID());
        ECardHandPower.push_back(now->getPower());
    }
    for(int i = 0;i<6;i++)
    {
        for(iter = FieldCard[i].begin();iter!=FieldCard[i].end();iter++)
        {
            CardInfo *now = *iter;
            FieldCardID[i].push_back(now->getID());
            FieldCardPower[i].push_back(now->getPower());
        }
    }
    int turn;
    if(gameStatus==1) turn = 0;
    else if(gameStatus==4) turn = 1;
    emit repaint(turn,MCardHandID,FieldCardID[0],FieldCardID[1],FieldCardID[2],FieldCardID[3],FieldCardID[4],FieldCardID[5],ECardHandID,
            MCardHandPower,FieldCardPower[0],FieldCardPower[1],FieldCardPower[2],FieldCardPower[3],FieldCardPower[4],FieldCardPower[5],ECardHandPower);
}

void LogicMainGame::gameCacu()
{
    //updete
    MPower = 0;
    for(int i = 0;i<3;i++)
    {
        vector<CardInfo*>::iterator iter = FieldCard[i].begin();
        for(;iter!=FieldCard[i].end();iter++)
        {
            CardInfo *now = *iter;
            MPower += now->getPower();
        }
    }

    EPower = 0;
    for(int i = 3;i<6;i++)
    {
        vector<CardInfo*>::iterator iter = FieldCard[i].begin();
        for(;iter!=FieldCard[i].end();iter++)
        {
            CardInfo *now = *iter;
            EPower += now->getPower();
        }
    }
    //
    if(gameStatus<4)
    {
        //send action
        gameStatus = 4;
        QByteArray buffer;
        QDataStream stream(&buffer,QIODevice::ReadWrite);
        stream.setVersion(QDataStream::Qt_5_9);
        stream<<mAction;
        if(mAction!=-1) stream << mPlace;
        if(!soc) tcpServer->write(buffer);
        else tcpClient->write(buffer);
    }
    else gameStatus = 1;
    emit cardChange();
    emit TurnEnd();
}

void LogicMainGame::nextGameBegin(vector<CardInfo*>&mgroup,vector<CardInfo*>&mhand,vector<CardInfo*>&egroup,vector<CardInfo*>&ehand)
{
    onegameclear();
    //add
    for(vector<CardInfo*>::iterator iter = mgroup.begin();iter!=mgroup.end();iter++)
    {
        CardInfo *now = *iter;
        MCardGroup.push_back(now);
    }
    for(vector<CardInfo*>::iterator iter = mhand.begin();iter!=mhand.end();iter++)
    {
        CardInfo* now = *iter;
        //leader
        MCardHand.push_back(now);
    }
    for(vector<CardInfo*>::iterator iter = egroup.begin();iter!=egroup.end();iter++)
    {
        CardInfo *now = *iter;
        ECardGroup.push_back(now);
    }
    for(vector<CardInfo*>::iterator iter = ehand.begin();iter!=ehand.end();iter++)
    {
        CardInfo *now = *iter;
        //leader
        ECardHand.push_back(now);
    }
    emit recvNext();
}

void LogicMainGame::gameEnd(int winner)
{
    emit AllEnd(winner,gameNum,mGrade,eGrade);
}

void LogicMainGame::weatherAct(int id, int weather)
{
    int rainsum = FieldCard[id].size();
    int icesum = FieldCard[id].size();
    int fogsum = FieldCard[id].size();
    int FogTargetNum = 0;
    vector<CardInfo*>::iterator fogiter = FieldCard[id].begin();
    CardInfo *IceTarget = FieldCard[id][0];
    int IceTargetNum = 0;
    vector<CardInfo*>::iterator iceiter = FieldCard[id].begin();
    CardInfo *Target[2];
    int targetNum[2];
    CardInfo *FogTarget = FieldCard[id][0];

    switch (weather)    
    {
    case RAIN:    

        if(rainsum>1)
        {

            targetNum[0] = rand()&rainsum;
            while(true)
            {
                targetNum[1] = rand()%rainsum;
                if(targetNum[1]!=targetNum[0]) break;
            }
            Target[0] = FieldCard[id][targetNum[0]];
            Target[1] = FieldCard[id][targetNum[1]];
            if(Target[0]->getPower()==Field[id].getRainPower())
            {
                Target[0]->setPower(0);
                GotoTomb(id,targetNum[0]);
            }
            else Target[0]->setPower(Target[0]->getPower()-Field[id].getRainPower());
            if(Target[1]->getPower()==Field[id].getRainPower())
            {
                Target[1]->setPower(0);
                GotoTomb(id,targetNum[1]);
            }
            else Target[1]->setPower(Target[1]->getPower()-Field[id].getRainPower());
        }
        else if(rainsum == 1)
        {
            CardInfo *Target = FieldCard[id][0];
            if(Target->getPower()<=Field[id].getRainPower())
            {
                Target->setPower(0);
                GotoTomb(id,0);
            }
            else Target->setPower(Target->getPower()-Field[id].getRainPower());
        }
        break;
    case ICE:

        if(icesum=0) break;

        for(int i = 0;iceiter!=FieldCard[id].end();iceiter++,i++)
        {
            CardInfo *now = *iceiter;
            if(now->getPower()<IceTarget->getPower())
            {
                IceTarget = now;
                IceTargetNum = 0;
            }
        }
        if(IceTarget->getPower()<=Field[id].getIcePower())
        {
            IceTarget->setPower(0);
            GotoTomb(id,IceTargetNum);
        }
        else IceTarget->setPower(IceTarget->getPower()-Field[id].getIcePower());
        break;
    case FOG:

        if(fogsum=0) break;


        for(int i = 0;fogiter!=FieldCard[id].end();fogiter++,i++)
        {
            CardInfo *now = *fogiter;
            if(now->getPower()>FogTarget->getPower())
            {
                FogTarget = now;
                FogTargetNum = 0;
            }
        }
        if(FogTarget->getPower()<=Field[id].getFogPower())
        {
            FogTarget->setPower(0);
            GotoTomb(id,FogTargetNum);
        }
        else FogTarget->setPower(FogTarget->getPower()-Field[id].getFogPower());
        break;
    default:
        break;
    }
}

void LogicMainGame::GotoTomb(int fieldID, int num)
{
    int i = 0;
    CardInfo *now;
    vector<CardInfo*>::iterator iter;
    for(iter = FieldCard[fieldID].begin();i<num;i++,iter++);
    now = *iter;
    if(fieldID>2) ECardTomb.push_back(now);
    FieldCard[fieldID].erase(iter);
}

void LogicMainGame::ChooseWhichDeploy(int sender)
{
    if(gameStatus!=1) return;
    MAction = MCardHand[sender];
    mAction = sender;
    vector<CardInfo*>::iterator iter = MCardHand.begin();
    for(int i = 0;i<sender;i++,iter++);
    MCardHand.erase(iter);
    gameStatus++;

}

void LogicMainGame::ChooseWhereDeploy(int place)
{
    if(gameStatus!=2) return;
    int i = place%10;
    int n = place/10 + 1;
    mPlace = place;

    if(MAction->getPosition()<3&&MAction->getPosition()!=2-i) return;
    if(MAction->getPosition()==3&&i>2) return;
    if(MAction->getPosition()==4&&i<3) return;
    vector<CardInfo*>::iterator iter = FieldCard[i].begin();
    for(int j = 0;j<n;j++,iter++);
    FieldCard[i].insert(iter,MAction);

    MAction->Deploy(place,FieldCard,Field,MCardGroup,0);
    gameStatus++;
    emit abilityEnd();
}

void LogicMainGame::ChooseWhereDeploy_Field(int i)
{
    mPlace = i;

    if(gameStatus!=2) return;
    if(MAction->getPosition()<3&&MAction->getPosition()!=2-i) return;

    if(MAction->getPosition()==3&&i>2) return;
    if(MAction->getPosition()==4&&i<3) return;
    vector<CardInfo*>::iterator iter = FieldCard[i].begin();
    FieldCard[i].insert(iter,MAction);
    gameStatus++;
    MAction->Deploy(i,FieldCard,Field,MCardGroup,0);
    emit abilityEnd();
}

void LogicMainGame::enemyAction()
{
    if(gameStatus!=4) return;    
    CardInfo *eactioncard;

    //recv
    QEventLoop *loop = new QEventLoop;
    if(!soc) connect(tcpServer,SIGNAL(readyRead()),this,SLOT(readEnemyAction()));
    else connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readEnemyAction()));
    connect(this,SIGNAL(enemyrecvend()),loop,SLOT(quit()));
    qDebug()<<"read enemy action";
    loop->exec();
    connect(this,SIGNAL(enemyrecvend()),loop,SLOT(quit()));
    if(!soc) disconnect(tcpServer,SIGNAL(readyRead()),this,SLOT(readEnemyAction()));
    else disconnect(tcpClient,SIGNAL(readyRead()),this,SLOT(readEnemyAction()));

    if(eAction==-1)
    {
        PassGameCacu(1);
        return;
    }
    eactioncard = ECardHand[eAction];
    vector<CardInfo*>::iterator iter = ECardHand.begin();
    for(int i = 0;i<eAction;i++,iter++);
    ECardHand.erase(iter);
    gameStatus++;

    int i = ePlace%10;
    i = 5-i;
    int n = ePlace/10;
    vector<CardInfo*>::iterator eiter = FieldCard[i].begin();
    for(int j = 0;j<n;j++,eiter++);
    FieldCard[i].insert(eiter,eactioncard);

    eactioncard->Deploy(ePlace,FieldCard,Field,ECardGroup,1);
    gameStatus++;
    emit abilityEnd();
}

void LogicMainGame::PassGameCacu(int num)
{
    if((gameStatus>2)&&(num==0)) return;
    if((!MPass)&&(num==0)) {passnum++;mAction = -1;}
    if((!EPass)&&(num==1)) passnum++;
    if(num==0) MPass = 1;
    if(num==1) EPass = 1;
    emit abilityEnd();
}

void LogicMainGame::readEnemy()
{
    QDataStream stream;
    if(!soc) stream.setDevice(tcpServer);
    else stream.setDevice(tcpClient);
    stream.setVersion(QDataStream::Qt_5_9);
    int egroupSize;
    stream>>egroupSize;
    for(int i = 0; i < egroupSize; i++)
    {
        int num;
        stream>>num;
        ECardGroup.push_back(fingCard(num));
    }
    int ehandsize;
    stream>>ehandsize;
    for(int i = 0; i < ehandsize; i++)
    {
        int num;
        stream>>num;
        EHand.push_back(num);
        if(i==0) ECardHand.push_back(fingCard(num));
        else ECardHand.push_back(ECardGroup[num]);
    }
    if(soc)
    {
        stream>>playerID;
        if(playerID) gameStatus = 4;
        else gameStatus = 1;
    }
    emit enemyrecvend();
}

void LogicMainGame::test()
{

}

void LogicMainGame::readEnemyAction()
{
    QDataStream stream;
    if(!soc) stream.setDevice(tcpServer);
    else stream.setDevice(tcpClient);
    stream.setVersion(QDataStream::Qt_5_9);
    stream>>eAction;
    qDebug()<<"e action"<<eAction;
    if(eAction!=-1)
    {
        stream>>ePlace;
        qDebug()<<"e place"<<ePlace;
    }
    emit enemyrecvend();
}

