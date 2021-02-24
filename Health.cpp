#include "Health.h"
#include <QFont>
#include <Game.h>


extern Game * game;

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    /// ustawienie zdrowia na 3
    health = 3;

    /// wyswietlenie zycia
    setPlainText(QString("Health: ") + QString::number(health)); // zycie: 3
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",22));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // zycie: 2
    if (health == 0){
    game->gameover();
    }
}



int Health::getHealth(){
    return health;
}
