#ifndef BLOCZEK_H
#define BLOCZEK_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <QVector>

//definicja klasy bloczek

class Bloczek : public QGraphicsPixmapItem
{
public:
    //pozycja bloczka oraz jego id
    int xpos,ypos,id;
    Bloczek();
};

#endif // BLOCZEK_H
