#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QImage>
#include "Button.h"
#include "QtMath"
#include "QGraphicsScene"

Game::Game(QWidget *parent){
    /// utowrzenie sceny
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,506,450); // ustawienie rozmiaru sceny - 506 na 450
    setBackgroundBrush(QBrush(QImage(":/images/MainMenu.jpg")));

    /// wizualizacja sceny (menu startowe)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(506,450);


}

void Game::start()
{ ///przed startem czyszczenie - ustawienie nowej sceny na potrzeby gry
    scene->clear();

    scene->setSceneRect(0,0,800,600);
    setFixedSize(800,600);
    setBackgroundBrush(QBrush(QImage(":/images/tlo.jpg")));
    /// utworzenie gracza
    player = new Player();

    player->setPos(0,400); /// ustawienie pozycji gracza
    /// ustawienie focusu na gracza
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    /// dodanie gracza do sceny
    scene->addItem(player);
    player ->gamemode = 1;
    /// stworzenie score i health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+35);
    scene->addItem(health);

    /// spawnowanie przeciwnikow
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    show();


}



void Game::drawWindow(int x, int y, int width, int height, QColor color, double opacity)
{
    /// narysowanie okna o okreslonej wielkosci i polozeniu
      QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
      QBrush brush;
      brush.setStyle(Qt::SolidPattern);
      brush.setColor(color);
      panel->setBrush(brush);
      panel->setOpacity(opacity);
      scene->addItem(panel);
}

void Game::displayMainMenu()
{
    /// wyswietlenie tekstu

    QGraphicsTextItem* Gamename = new QGraphicsTextItem(QString("Tank Game"));
    QFont GamenameFont("comic sans",55);
    Gamename->setFont(GamenameFont);
    Gamename->setDefaultTextColor(Qt::white);
    int gxPosition = this->width()/2 - Gamename->boundingRect().width()/2;
    int gyPosition = 20;
    Gamename->setPos(gxPosition,gyPosition);
    scene->addItem(Gamename);

    /// utworzenie przycisku start
    Button* startButton = new Button(QString("Start"));
    int sxPosition = this->width()/2 - startButton->boundingRect().width()/2;
    int syPosition = 275;
    startButton->setPos(sxPosition,syPosition);
    connect(startButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(startButton);

    /// utworzenie przycisku wyjscie

    Button* quitButton = new Button(QString("Quit"));
    int qxPosition = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPosition = 335;
    quitButton->setPos(qxPosition,qyPosition);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    /// wyswietlenie  podpis autora

    QGraphicsTextItem* autor= new QGraphicsTextItem(QString("Made by: Kamil Kowalczyk"));
    autor->setPlainText(QString("Made by: Kamil Kowalczyk"));
    autor->setFont(QFont("times",7));
    autor->setDefaultTextColor(Qt::white);
    int axPosition = this->width()/2 + 135;
    int ayPosition = 430;
    autor->setPos(axPosition,ayPosition);
    scene->addItem(autor);
}

void Game::gameover()
{
    int playerscore=score->getScore();
     QString message = QStringLiteral(" Your score is : %1.").arg(playerscore);
    displayGameOverWindow(message);

}

void Game::displayGameOverWindow(QString textToDisplay)
{
    player->gamemode= 0;
    /// wylaczenie wszystkich obiektow na scenie
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
           scene->items()[i]->setVisible(false);
       }

    /// wyswietlane lekkoprzezroczyste okno
    drawWindow(0,0,1024,768,Qt::black,0.65);

    /// narysowanie menu game over
    drawWindow(200,100,400,400,Qt::lightGray,0.75);
    /// stworzenie przycisku play again

    Button* playAgain = new Button(QString("Play again"));
    playAgain->setPos(300,350);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(start()));
    /// stworzenie przycisku quit
    Button* Quit = new Button(QString("Quit"));
    Quit->setPos(300,430);
    scene->addItem(Quit);
    connect(Quit,SIGNAL(clicked()),this,SLOT(close()));

    QGraphicsTextItem* scoreText = new QGraphicsTextItem(textToDisplay);
    scoreText->setFont(QFont("times",20));
    scoreText->setDefaultTextColor(Qt::black);
    scoreText->setPos(300,200);
    scene->addItem(scoreText);

}


