#include <Bloczek.h>

//konstrunktor ustawiajacy grafike bloczka (wymiary 80x20)
Bloczek::Bloczek()
{
    this->setPixmap(QPixmap(":/grafika/bloczek.png"));
}

