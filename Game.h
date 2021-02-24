#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

/** Klasa Game */
class Game: public QGraphicsView{
    Q_OBJECT
public:
    /// Konstruktor klasy Enemy
    Game(QWidget * parent=0);
    /// Metoda do wyswietlania menu glownego
    void displayMainMenu();
    /// Metoda do ustawienia parametrow okna gameover
    void gameover();
    /** Metoda do wysietlenia okna game over
    * @param texToDisplay tekst wyswietlany na ekranie
    * */
    void displayGameOverWindow(QString textToDisplay);
    /// wskaznik do sceny
    QGraphicsScene * scene;
    /// wskaznik do gracza
    Player * player;
    /// wskaznik do punktacji
    Score * score;
    /// wskaznik do zdrowia
    Health * health;
public slots:
    /// Metoda używana do startu gry
    void start();

private:
    /** Metoda do rysowania okna w oknie
    * @param x - pozycja x na scenie
    * @param y - pozycja y na scenie
    * @param width szerokosc okna
    * @param height wysokosc okna
    * @param color kolor wyswietlanego okna
    * @param opacity przezroczystosc wyswietlanego okna
    * */
    void drawWindow(int x, int y, int width, int height, QColor color, double opacity);

};

#endif // GAME_H
