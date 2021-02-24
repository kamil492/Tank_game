#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    /// ustawienie score na 0
    score = 0;

    /// wyswietlanie tekstu
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",22));
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int Score::getScore(){
    return score;
}

void Score::increasesup()
{
    score+=3;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: -1
}
