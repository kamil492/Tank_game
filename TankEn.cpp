#include "TankEn.h"
#include <QTimer>
#include "Game.h"
#include <QDebug>


extern Game * game;

TankEn::TankEn(QGraphicsItem *parent)
{
    /// ustawienie predkosci wroga
    speed=5;

    /// ustawienie randomowej pozycji
    int random_number = (rand()/10) % 500;
    setPos(600,random_number);

    /// ustawienie ikony wroga
    setPixmap(QPixmap(":/images/enemy1.png"));




}
