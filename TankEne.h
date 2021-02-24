#ifndef TANKENE_H
#define TANKENE_H

#endif // TANKENE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Enemy.h"
/** Klasa TankEn*/
class TankEne:public Enemy
{
    Q_OBJECT
public:
    /// Konstruktor klasy TankEne
    TankEne(QGraphicsItem * parent=0);

};
