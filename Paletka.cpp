#include "Paletka.h"

//nadanie grafiki paletce (wymiary 100x20) oraz ustawienie aby to ona zbierała zdaerzenia klawiszy
Paletka::Paletka()
{
    this->setPixmap(QPixmap(":/grafika/paletka.png"));
    this->setFlag(QGraphicsItem::ItemIsFocusable);
    this->setFocus();

}

//ustawienie pozycji paletki
void Paletka::UstawPaletke()
{
    this->setPos(590,650);
}

//obsluga zdarzen nacisniecia klawiszy, poruszanie paletki po planszy w osi X
void Paletka::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Left)
       {
           if(pos().x()>0)
               moveBy(-15,0);
       }

       else if (event->key()==Qt::Key_Right)
       {
           if(pos().x()<1180)
               moveBy(15,0);
       }
}


