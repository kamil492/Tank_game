#include "Tanknem.h"
#include <QTimer>
#include "Game.h"
#include <QDebug>


extern Game * game;

Tanknem::Tanknem(QGraphicsItem *parent)
{
    ///set speed
    speed=10;
    ///ustawienie randomowej pozycji
    int random_number = (rand()/10) % 500;
    setPos(600,random_number);

    /// ustawienie ikony wroga
    setPixmap(QPixmap(":/images/Tanknem.png"));


}
