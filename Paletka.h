#ifndef PALETKA_H
#define PALETKA_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPainter>
#pragma once

//definicja klasy paletki
class Paletka : public QGraphicsPixmapItem
{
public:
    //konstruktor paletki, funkcja ustawiajaca paletke, oraz funkcja przyjmujaca zdarzenia naciskania klawiszy
    Paletka();
    void UstawPaletke();
    void keyPressEvent(QKeyEvent *event);

};

#endif // PALETKA_H
