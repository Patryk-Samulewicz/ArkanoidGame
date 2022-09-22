#include "QuadTree.h"



// dodawanie wezla do drzewa
void Quad::insert(Node *node)
{
    if (node == NULL)
        return;

    // jezeli obecne granice nie pozwalaja na dodanie wezla przerwij funkcje
    if (!inBoundary(node->pos))
        return;

    // bedac w okreslonych granicach na planszy
    // oraz nie mogac podzielic tej granicy na kolejny obszar
    // morzemy umiescic w niej wezel
    if (abs(topLeft.x - botRight.x) <= 4 &&
        abs(topLeft.y - botRight.y) <= 4) //liczba elementow w jednej galezi drzewa
    {
        if (n == NULL)
            n = node;
        return;
    }

    //jezeli nadal ne mozemy umiescic wezla przesuwamy sie w dol drzewa
    if ((topLeft.x + botRight.x) / 2 >= node->pos.x)
    {
        // przesuwanie sie w lewo-gora
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y)
        {
            if (topLeftTree == NULL)
                topLeftTree = new Quad(Point(topLeft.x, topLeft.y), Point((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2));

            //wywolanie rekurencyjne
            topLeftTree->insert(node);
        }

        // przesuwanie sie w lewo-dol
        else
        {
            if (botLeftTree == NULL)
                botLeftTree = new Quad(Point(topLeft.x, (topLeft.y + botRight.y) / 2), Point((topLeft.x + botRight.x) / 2, botRight.y));

            //wywolanie rekurencyjne
            botLeftTree->insert(node);
        }
    }
    else
    {
        // przesuwanie sie w prawo-gora
        if ((topLeft.y + botRight.y) / 2 >= node->pos.y)
        {
            if (topRightTree == NULL)           
                topRightTree = new Quad(Point((topLeft.x + botRight.x) / 2, topLeft.y), Point(botRight.x, (topLeft.y + botRight.y) / 2));

            //wywolanie rekurencyjne
            topRightTree->insert(node);
        }

        // przesuwanie sie w prawo-dol
        else
        {
            if (botRightTree == NULL)
                botRightTree = new Quad( Point((topLeft.x + botRight.x) / 2, (topLeft.y + botRight.y) / 2), Point(botRight.x, botRight.y));

            //wywolanie rekurencyjne
            botRightTree->insert(node);
        }
    }
}

// znajdowanie punktu na planszy poprzez drzewo
Node* Quad::search(Point p)
{
    // sprawdzenie czy punkt znajduje sie w obecnym obszarze
    if (!inBoundary(p))
        return NULL;

    // bedac w okreslonych granicach na planszy
    // oraz nie mogac podzielic tej granicy na kolejny obszar
    // morzemy zwrocic wezel ktorego szukamy
    if (n != NULL)
        return n;

    //jezeli nadal ne mozemy znalesc wezla z naszym punktem przesuwamy sie w dol drzewa
    if ((topLeft.x + botRight.x) / 2 >= p.x)
    {
        // przesuwanie sie w lewo-gora
        if ((topLeft.y + botRight.y) / 2 >= p.y)
        {
            if (topLeftTree == NULL)
                return NULL;
            //wywolanie rekurencyjne
            return topLeftTree->search(p);
        }

        // przesuwanie sie w lewo-dol
        else
        {
            if (botLeftTree == NULL)
                return NULL;
            //wywolanie rekurencyjne
            return botLeftTree->search(p);
        }
    }
    else
    {
        // przesuwanie sie w prawo-gora
        if ((topLeft.y + botRight.y) / 2 >= p.y)
        {
            if (topRightTree == NULL)
                return NULL;
            //wywolanie rekurencyjne
            return topRightTree->search(p);
        }

        // przesuwanie sie w prawo-dol
        else
        {
            if (botRightTree == NULL)
                return NULL;
            //wywolanie rekurencyjne
            return botRightTree->search(p);
        }
    }
};


// funkcja sprawdzajaca zwracajaca true gdy punkt znajduje sie w okreslonych granicach na planszy
bool Quad::inBoundary(Point p)
{
    return (p.x >= topLeft.x &&
        p.x <= botRight.x &&
        p.y >= topLeft.y &&
        p.y <= botRight.y);
}

