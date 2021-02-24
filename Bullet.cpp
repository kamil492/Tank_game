#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include "TankEn.h"
#include "TankEne.h"
#include "Tanknem.h"

extern Game * game; // obiekt globalny - gra

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    /// stworzenie kuli - image
    setPixmap(QPixmap(":/images/tankBullet.png"));

    /// stworzenie i podlaczenie timera do kuli
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    /// start timera
    timer->start(50);
}


void Bullet::move(){
    /// dostep do listy obiektow kolidujacych z kula
    QList<QGraphicsItem *> colliding_items = collidingItems();

    /// jesli obiekt to wrog - zniszcz kule i wroga
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(TankEne)){
            /// zwiekszenie punktacji
            game->score->increase();

            /// usuniecie ze sceny - kula i wrog
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            /// usuniecie z pamieci
            delete colliding_items[i];
            delete this;

            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(TankEn)) {
            game->score->increase();

            /// usuniecie ze sceny - kula i wrog
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            /// usuniecie z pamieci
            delete colliding_items[i];
            delete this;

            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Tanknem)) {
            game->score->increasesup();

            /// usuniecie ze sceny - kula i wrog
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            /// usuniecie z pamieci
            delete colliding_items[i];
            delete this;

            return;
        }
    }

    /// jesli brak kolizji - kula leci dalej
    setPos(x()+10,y());
    /// usuniecie kuli po wyjsciu poza obszar
    if (pos().x() > 800){
        scene()->removeItem(this);
        delete this;
    }
}
