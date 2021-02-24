#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> duzy int
#include "Game.h"
#include "TankEn.h"


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    /// podlaczenie timera do funkcji ruchu
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    ///ustawienie predkosci poruszania
    speed=5;

    ///ustawienie randomowej pozycji
    int random_number = (rand()/10) % 500;
    setPos(600,random_number);

    /// ustawienie ikony wroga
    setPixmap(QPixmap(":/images/enemy1.png"));

    /// start timera
    timer->start(50);
}

void Enemy::move(){
    /// poruszanie sie wroga
    setPos(x()-speed,y());
    /// usuwanie jesli wyjdzie poza obszar
    if (pos().x() < 0){
        ///zmniejszenie zycia jesli wyjdzie poza obszar
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }

}
