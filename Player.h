#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
/** Klasa Player*/
class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /// Konstruktor klasy Player
    Player(QGraphicsItem * parent=0);
    /// Metoda do obslugi zdarzen - wciskania klawiszy klawiatury
    void keyPressEvent(QKeyEvent * event);
    /// zmienna do sprawdzania czy gra sie nie zakonczyla
    int gamemode=1;
public slots:
    /// Metoda do spawnowania przeciwnikow
    void spawn();
};

#endif // PLAYER_H
