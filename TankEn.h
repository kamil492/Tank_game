#ifndef TANKEN_H
#define TANKEN_H

#endif // TANKEN_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Enemy.h"
/** Klasa TankEn*/
class TankEn:public Enemy
{
    Q_OBJECT
public:
    /// Konstruktor klasy TankEn
    TankEn(QGraphicsItem * parent=0);

};
