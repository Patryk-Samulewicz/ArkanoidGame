#include "Kulka.h"


// nadanie kierunku i grafiki kulce (wymiary 10x10)
Kulka::Kulka()
{ 
    this->setPixmap(QPixmap(":/grafika/kulka.png"));
    this->xdir = (1.1);
    this->ydir = -(1.8);
    UstawKulke();
}

//ustawienie kulki na planszy
void Kulka::UstawKulke()
{
    this->setPos(635,635);
}


