#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
#include "TankEn.h"
#include "TankEne.h"
#include "Tanknem.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

 setPixmap(QPixmap(":/images/Player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    /// poruszanie prawo lewo
    if (gamemode == 1){
    if (event->key() == Qt::Key_Up){
        if (pos().y() > 0)
        setPos(x(),y()-10);
    }
    else if (event->key() == Qt::Key_Down){
        if (pos().y() + 100 < 600)
        setPos(x(),y()+10);
    }
    /// strzelanie spacja
    else if (event->key() == Qt::Key_Space){
        /// utworzenie kuli
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+100,y()+15);
        scene()->addItem(bullet);
    }
}
}
void Player::spawn(){
    /// tworzenie wroga
if (gamemode==1){
    int random_number = (rand() % 3);
    if (random_number==0)
    {
        TankEn * enemy = new TankEn();
        scene()->addItem(enemy);

    }
    else if (random_number==2)
    {
        TankEne * enemy = new TankEne();
        scene()->addItem(enemy);

    }
    else
    {
        Tanknem * enemy = new Tanknem();
        scene()->addItem(enemy);

    }
}
}


