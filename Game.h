//#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QtWidgets>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QMediaPlayer>
#include "mainwindow.h"
#include <QPushButton>
#include <QObject>
#include <QPoint>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include <QEventLoop>
#include "Paletka.h"
#include "Kulka.h"
#include "Bloczek.h"
#include "QuadTree.h"

//wymuszenie pierszenstwa kompilacji innych klas z ktorych bedziemy korzystac w klasie glownej
class Bloczki;
class QuadTree;
class Kulka;
class Paletka;
class QGraphicsView;

//deklaracja klasy glownej zawierajacej wszystkie potrzebne elementy
class Game : public QObject
{
    Q_OBJECT
public:
    Game *game;
    QGraphicsScene *scena;
    QGraphicsView *widok;
    QWidget w;
    Game();
    void ButtonStart1();
    void ButtonStart2();
    void ButtonStart3();
    void ButtonQuit();
    void Menu();
    void Koniec();
    void Wygrana();
    void Start();
    QPushButton *buttonStart1;
    QPushButton *buttonStart2;
    QPushButton *buttonStart3;
    QPushButton *buttonQuit;
    Paletka *paletka;
    Kulka *kulka;
    Bloczek *bloczki;
    QTimer *zegar;
    QMediaPlayer *music;
    int ileBloczkow;
    Quad *center;
    Node  *tempp = new Node();
    int a,c,d;
    QLabel *label;
    QLabel *labelLose;
    QLabel *labelWin;

    //deklaracja slotow obslugiwanych przez sygnaly
public slots:
    void UstawBloczki1();
    void UstawBloczki2();
    void UstawBloczki3();
    void Start1();
    void Start2();
    void Start3();
    void Quit();
    void RuchKulki();
    int ZmianaKierunku();
    int SprawdzKolizje();
};


