#ifndef TANKNEM_H
#define TANKNEM_H

#endif // TANKNEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include "Enemy.h"
/** Klasa Tanknem*/
class Tanknem:public Enemy
{
    Q_OBJECT
public:
    /// Konstruktor klasy Tanknem
    Tanknem(QGraphicsItem * parent=0);

};
