#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    /// rysowanie przycisku
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);

    /// rysowanie tekstu
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    /// pozwolenie na reakcje
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    /// zmiana koloru
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    /// zmiana na dark gray

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkGray);
    setBrush(brush);
}
