#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
// klasa button
class Button:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    /** Konstruktor klasy button
    * @param name tekst wyswietlany na przycisku
    * */
    Button(QString name, QGraphicsItem* parent=NULL);

    /// Metoda uzywana do obslugi zdarzen  klikniec myszki
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    /// Metoda używana do obsługi zdarzen najechania mysza
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    /// Metoda używana do obsługi zdarzen najechania mysza
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    /// Sygnał zdarzenia kliknięcia myszą
    void clicked();
private:
    /// tekst wyswietlany na przycisku
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
