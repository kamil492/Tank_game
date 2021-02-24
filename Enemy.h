#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

/** Klasa Enemy */
class Enemy: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /// Konstruktor klasy Enemy
    Enemy(QGraphicsItem * parent=0);
public slots:
    /// Metoda do poruszania wrogow
    void move();
    protected:
    /// predkosc wroga
    int speed;
};

#endif // ENEMY_H
