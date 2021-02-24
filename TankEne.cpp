#include "TankEne.h"
#include <QTimer>
#include "Game.h"
#include <QDebug>


extern Game * game;

TankEne::TankEne(QGraphicsItem *parent)
{
    /// ustawienie predkosci wroga
    speed=7;

    ///ustawienie randomowej pozycji
    int random_number = (rand()/10) % 500;
    setPos(600,random_number);

    /// ustawienie ikony wroga
    setPixmap(QPixmap(":/images/enemy2.png"));




}
