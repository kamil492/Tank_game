#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
/** Klasa Health */
class Health: public QGraphicsTextItem{
public:
    /// Konstruktor klasy Health
    Health(QGraphicsItem * parent=0);
    /// Metoda do zmniejszania liczby zyc
    void decrease();
    /// pozyskiwanie ilosci zyc
    int getHealth();
private:
    /// ilosc zyc
    int health;

};

#endif // HEALTH_H
