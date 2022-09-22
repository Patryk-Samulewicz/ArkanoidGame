#ifndef QUADTREE_H
#define QUADTREE_H
#include <QGraphicsRectItem>

//pomocnicza struktura przechowujaca pozycje punktu z konstruktorami
struct Point
{
    int x;
    int y;
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    Point()
    {
        x = 0;
        y = 0;
    }
};

// Pomocnicza struktura przechowujaca dane punktu oraz dane bloczka (id)
struct Node
{
    Point pos;
    int data;
    Node(Point _pos, int _data)
    {
        pos = _pos;
        data = _data;
    }
    Node()
    {
        data = 0;
    }
};

// deklaracja klasy drzewa czworkowego
class Quad
{
    public:
    // przechowanie danych dotyczacych granicy wezla na planszy
    Point topLeft;
    Point botRight;

    // przechowanie danych wezla
    Node *n;

    // dzieci wezla, stworzenie potomkow
    Quad *topLeftTree;
    Quad *topRightTree;
    Quad *botLeftTree;
    Quad *botRightTree;

    //konstruktor domyslny
    Quad()
    {
        topLeft = Point(0, 0);
        botRight = Point(0, 0);
        n = NULL;
        topLeftTree = NULL;
        topRightTree = NULL;
        botLeftTree = NULL;
        botRightTree = NULL;
    }

    //konstruktor przyjmujacy dane o granicach na planszy
    Quad(Point topL, Point botR)
    {
        n = NULL;
        topLeftTree = NULL;
        topRightTree = NULL;
        botLeftTree = NULL;
        botRightTree = NULL;
        topLeft = topL;
        botRight = botR;
    }
    //funkcja dodajaca
    void insert(Node*);
    //funkcja wyszukujaca
    Node* search(Point);
    //funkcja sprawdzajaca punkt
    bool inBoundary(Point);
};

#endif // QUADTREE_H
