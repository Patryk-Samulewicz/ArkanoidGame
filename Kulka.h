#ifndef KULKA_H
#define KULKA_H
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>


//deklaracja klasy kulka
class Kulka : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    //kieunek przemieszczania kulki, konstruktor kulki oraz funkcja ustawiajaca kulke
    Kulka();
    void UstawKulke();
    float xdir;
    float ydir;



};



#endif // KULKA_H
