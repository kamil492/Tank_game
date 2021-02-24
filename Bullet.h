#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

/** Klasa Bullet */
class Bullet: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
/// Konstruktor klasy Bullet
    Bullet(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // BULLET_H
