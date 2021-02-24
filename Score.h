#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
/** Klasa Score*/
class Score: public QGraphicsTextItem{
public:
    /// Konstruktor klasy Score
    Score(QGraphicsItem * parent=0);
    /// Metoda do zwiekszania ilosci punktow
    void increase();
    /// Metoda do pozyskiwania ilosci punktow
    int getScore();
    /// Metoda do zwiekszania ilosci punktow dla bonusowego pojazdu
    void increasesup();
private:
    /// zmienna score
    int score;
};

#endif // SCORE_H
