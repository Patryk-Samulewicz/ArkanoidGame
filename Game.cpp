#include "Game.h"

//konstruktor gry
Game::Game()
{
    //utworzenie sceny oraz widoku
    scena = new QGraphicsScene();
    widok = new QGraphicsView(scena);

    //nadanie rozmiarow sceny ukrycie paskow przewijania i nadanie tla
    widok->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    widok->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scena->setSceneRect(0,0,1280,720);
    scena->setBackgroundBrush(QBrush(QImage(":/grafika/background.jpg")));

    //stylizacja widzetu menu gry
    w.setObjectName("widget");
    w.setStyleSheet("#widget {background-image: url(:/grafika/background.jpg); }");

    //nadanie rozmiaru menu i wywolanie go
    widok->setFixedSize(1280,720);
    w.setFixedSize(1280,720);
    Menu();



}



//przycisk z pierwsza plansza
void Game::ButtonStart1()
{
    //dodanie przyciskuy do widzetu
    buttonStart1 = new QPushButton("",&w);

    //wystylizowanie go z uzyciem css
    buttonStart1->setObjectName("button_1");
    buttonStart1->setStyleSheet("#button_1 {background-color: green; }");

    //nadanie rozmiarow textu i wyswietlenie go
    buttonStart1->setGeometry(QRect(200,400,250,100));
    buttonStart1->setText("Poziom 1");
    buttonStart1->show();

    //polaczenie sygnalu klikniecia ze startem
    connect(buttonStart1,SIGNAL(clicked()),this,SLOT(Start1()));
}

//przycisk z druga plansza
void Game::ButtonStart2()
{
    buttonStart2 = new QPushButton("",&w);
    buttonStart2->setObjectName("button_2");
    buttonStart2->setStyleSheet("#button_2 {background-color: yellow; }");
    buttonStart2->setGeometry(QRect(500,400,250,100));
    buttonStart2->setText("Poziom 2");
    buttonStart2->show();
    connect(buttonStart2,SIGNAL(clicked()),this,SLOT(Start2()));
}

//przycisk z trzeca plansza
void Game::ButtonStart3()
{
    buttonStart3 = new QPushButton("",&w);
    buttonStart3->setObjectName("button_3");
    buttonStart3->setStyleSheet("#button_3 {background-color: red; }");
    buttonStart3->setGeometry(QRect(800,400,250,100));
    buttonStart3->setText("Poziom 3");
    buttonStart3->show();
    connect(buttonStart3,SIGNAL(clicked()),this,SLOT(Start3()));

}

//przycisk wyjscia z gry
void Game::ButtonQuit()
{
    buttonQuit = new QPushButton("",&w);
    buttonQuit->setObjectName("button_q");
    buttonQuit->setStyleSheet("#button_q {background-color: blue; }");
    buttonQuit->setGeometry(QRect(500,600,250,100));
    buttonQuit->setText("WYJSCIE");
    buttonQuit->show();
    connect(buttonQuit,SIGNAL(clicked()),this,SLOT(Quit()));

}

//menu gry
void Game::Menu()
{
    //wyswietlenie widzetu i utworzenie przyciskow
    label = new QLabel(&w);
    label->setObjectName("label");

    label->setPixmap(QPixmap(":/grafika/arkanoid.png"));
    label->setGeometry(QRect(100,20,1080,200));

    music = new QMediaPlayer();

    music->setMedia(QUrl("qrc:/sound/videoplayback3.mp3"));
    music->play();

    w.show();
    ButtonStart1();
    ButtonStart2();
    ButtonStart3();
    ButtonQuit();

}

//przegrana
void Game::Koniec()
{

    music->setMedia(QUrl("qrc:/sound/lose.mp3"));
    music->play();


    scena->addPixmap(QPixmap(":/grafika/gameover.jpg"));



    //deklaracja opoznienia aby zaczekac na odtworzenie sie calego dzwieku
    QEventLoop loop;
    QTimer::singleShot(6000, &loop, SLOT(quit()));
    loop.exec();

    //usuniecie i zamkniecie wszystkich elementow i powrot do menu
    widok->close();
    delete zegar;
    delete kulka;
    delete paletka;
    delete center;
    delete[] bloczki;
    scena->clear();

    Menu();
}

void Game::Wygrana()
{
    music->setMedia(QUrl("qrc:/sound/victory.mp3"));
    music->play();


    scena->addPixmap(QPixmap(":/grafika/win.png"));



    //deklaracja opoznienia aby zaczekac na odtworzenie sie calego dzwieku
    QEventLoop loop;
    QTimer::singleShot(6000, &loop, SLOT(quit()));
    loop.exec();

    //usuniecie i zamkniecie wszystkich elementow i powrot do menu
    widok->close();
    delete zegar;
    delete kulka;
    delete paletka;
    delete center;
    delete[] bloczki;
    scena->clear();

    Menu();
}

//pierwsza plansza
void Game::UstawBloczki1()
{
    //ustawienie pozycji poczatkowej od ktorej bedziemy ustawiac bloczki
    int pozycjax=320,pozycjay=0;
    ileBloczkow = 0;
    Node *temp;

    //utworzenie tablicy bloczkow
    bloczki = new Bloczek[40];

    music->setMedia(QUrl("qrc:/sound/game1.mp3"));
    music->play();

    //plansza bedzie miala 40 bloczkow
    for (int i=0; i < 40 ; i++ )
    {
        //nadanie pozycji oraz id bloczka
        bloczki[i].setPos(pozycjax,pozycjay);
        bloczki[i].xpos = pozycjax;
        bloczki[i].ypos = pozycjay;
        bloczki[i].id = ileBloczkow;

        //przypisanie go do zmienej pomocniczej
        temp = new Node(Point(pozycjax,pozycjay),ileBloczkow);

        //dodanie do drzewa oraz do sceny bloczka
        center->insert(temp);
        scena->addItem(&bloczki[i]);
        ileBloczkow ++;

        //przesyniecie sie do nastepnej pozycji
        pozycjax += 80;
        if (pozycjax >= 960)
        {
            pozycjay += 20;
            pozycjax = 320;
        }
    }

}

//druga plansza
void Game::UstawBloczki2()
{
    int pozycjax=0, pozycjay=0;
    ileBloczkow = 0;
    Node *temp;


    //utworzenie tablicy bloczkow
    bloczki = new Bloczek[80];

    music->setMedia(QUrl("qrc:/sound/game2.mp3"));
    music->play();
    for (int i=0; i < 80; i++ )
    {
        bloczki[i].setPos(pozycjax,pozycjay);
        bloczki[i].xpos = pozycjax;
        bloczki[i].ypos = pozycjay;
        bloczki[i].id = ileBloczkow;
        temp = new Node(Point(pozycjax,pozycjay),ileBloczkow);

        center->insert(temp);
        scena->addItem(&bloczki[i]);
        ileBloczkow ++;
        pozycjax += 80;
        if (pozycjax >= 1280)
        {
            pozycjay += 20;
            pozycjax = 0;
        }
    }

}


//trzecia plansza
void Game::UstawBloczki3()
{
    int pozycjax=0,pozycjay=0;
    ileBloczkow = 0;
    Node *temp;


    //utworzenie tablicy bloczkow
    bloczki = new Bloczek[288];

    music->setMedia(QUrl("qrc:/sound/game3.mp3"));
    music->play();
    for (int i=0; i < 288 ; i++ )
    {
        bloczki[i].setPos(pozycjax,pozycjay);
        bloczki[i].xpos = pozycjax;
        bloczki[i].ypos = pozycjay;
        bloczki[i].id = ileBloczkow;
        temp = new Node(Point(pozycjax,pozycjay),ileBloczkow);

        center->insert(temp);
        scena->addItem(&bloczki[i]);
        ileBloczkow ++;
        pozycjax += 80;
        if (pozycjax >= 1280)
        {
            pozycjay += 20;
            pozycjax = 0;
        }
    }

}

//funkcja rozpoczynajaca gre
void Game::Start()
{
    //usuniece elementow menu
    delete buttonQuit;
    delete buttonStart1;
    delete buttonStart2;
    delete buttonStart3;
    music->stop();
    w.close();

    //utworzenie zegara wedlug ktorego bedzie dzialac gra oraz paletki kulki i drzewa
    zegar = new QTimer();
    paletka = new Paletka;
    kulka = new Kulka;
    center =  new Quad(Point(0,0),Point(1280,720));

    //ustawienie elementow i dodanie ich do sceny
    paletka->UstawPaletke();
    kulka->UstawKulke();
    scena->addItem(paletka);
    scena->addItem(kulka);

    //sprawdzenie ktora plansze wybrac
    if(a==1)
        UstawBloczki1();
    else if(a==2)
        UstawBloczki2();
    else if(a==3)
        UstawBloczki3();

    //polaczenie sygnalu konca zegara z poruszaniem kulki, zmiana jej kierunku i sprawdzeniem jej kolizji z bloczkami
    connect(zegar,SIGNAL(timeout()),this,SLOT(RuchKulki()));
    connect(zegar,SIGNAL(timeout()),this,SLOT(ZmianaKierunku()));
    connect(zegar,SIGNAL(timeout()),this,SLOT(SprawdzKolizje()));

    //ustawiamy na 8 milisekund
    zegar->start(8);
    widok->show();

}

//funkcje pomocnicze okreslajace jak ulozyc bloczki na planszy
void Game::Start1()
{
    a=1;
    Start();
}

void Game::Start2()
{
    a=2;
    Start();
}

void Game::Start3()
{
    a=3;
    Start();
}


//zamkniece aplikacji
void Game::Quit()
{
    QCoreApplication::exit();
}


//poruszanie kulki zgodnie z kierunkiem i zapisanie jej tymczasowej pozycji
void Game::RuchKulki()
{
    kulka->moveBy(kulka->xdir,kulka->ydir);
    c=round(kulka->pos().x()); d=round(kulka->pos().y());
}


//odbijanie pilki
int Game::ZmianaKierunku()
{
    //odbicie kulki od lewej i prawej granicy
    if (kulka->pos().x()>= 1280-10 || kulka->pos().x()<= 0)
        {
            kulka->xdir = -(kulka->xdir);
            return 0;
        }

    //odbicie kulki od gory
    if (kulka->pos().y() <= 0)
        {
            kulka->ydir = -(kulka->ydir);
            return 0;
        }

    //gdy kulka trafi na dol ekranu przegrywamy
    if (kulka->pos().y() >= 720-10)
        {
            Koniec();
            return 0;
        }

    //odbicie kulki od paletki, zmiana stopni kierunku poruszania sie kulki w zaleznosci od tego gdzie uderzyla w paletke
    if (kulka->collidesWithItem(paletka))
    {
        kulka->setPos(kulka->x(), kulka->y()-3);
        kulka->ydir = -(kulka->ydir);

        if(kulka->pos().x() < paletka->pos().x())
        {
            kulka->xdir = -2.5;
        }
        else if(kulka->pos().x() < paletka->pos().x()+10)
        {
            kulka->xdir = -2;
        }
        else if(kulka->pos().x() < paletka->pos().x()+20)
        {
            kulka->xdir = -1.5;
        }
        else if(kulka->pos().x() < paletka->pos().x()+30)
        {
            kulka->xdir = -1;
        }
        else if(kulka->pos().x() < paletka->pos().x()+40)
        {
            kulka->xdir = -0.5;
        }
        else if(kulka->pos().x() < paletka->pos().x()+50)
        {
            kulka->xdir = 0;
        }
        else if(kulka->pos().x() < paletka->pos().x()+60)
        {
            kulka->xdir = 0.5;
        }
        else if(kulka->pos().x() < paletka->pos().x()+70)
        {
            kulka->xdir = 1;
        }
        else if(kulka->pos().x() < paletka->pos().x()+80)
        {
            kulka->xdir = 1.5;
        }
        else if(kulka->pos().x() < paletka->pos().x()+90)
        {
            kulka->xdir = 2;
        }
        else if(kulka->pos().x() < paletka->pos().x()+100)
        {
            kulka->xdir = 2.5;
        }
        return 0;
    }
    return 0;
}

//sprawdzenie kolizji z bloczkami
int Game::SprawdzKolizje()
{
    //jezeli usunieto wszystkie bloczki zakoncz gre
    if (ileBloczkow == 0)
    {
        Wygrana();
    }
    //utworzenie zmiennej pomocniczej
    Node  *tempp = new Node();

    //przeszukanie wszystkich punktow w danym obszarze
    for(int i=(-80); i<80 ; i++)
    {
        for(int j=(-20); j<20 ; j++)
        {
            //jezeli dany punkt zawiera bloczek
            if (center->search(Point(c+i,d+j)) != NULL)
            {
                //przypisz go do zmiennej pomocniczej
                tempp = center->search(Point(c+i,d+j));

                //sprawdz czy kulka koliduje z bloczkiem o id z wyszukanego punktu
                if (kulka->collidesWithItem(&bloczki[tempp->data]))
                {
                    //zmien kierunek w zaleznosci od tego z ktorej strony uderzono w bloczek i usun go

                    if (kulka->pos().y() <= bloczki[tempp->data].pos().y()+20)
                    {
                        scena->removeItem(&bloczki[tempp->data]);
                        bloczki[tempp->data].setPos(-100,-30);
                        kulka->setPos(kulka->x(),kulka->y()+3);
                        kulka->ydir = -(kulka->ydir);
                        ileBloczkow --;

                    }

                    else if (kulka->pos().x()+10 >= bloczki[tempp->data].pos().x())


                    {
                        scena->removeItem(&bloczki[tempp->data]);
                        kulka->setPos(kulka->x()-3,kulka->y());
                        kulka->xdir = -(kulka->xdir);
                        bloczki[tempp->data].setPos(-100,-30);
                        ileBloczkow --;

                    }
                    else if (kulka->pos().x() <= bloczki[tempp->data].pos().x()+80)

                    {
                        scena->removeItem(&bloczki[tempp->data]);
                        kulka->setPos(kulka->x()+3,kulka->y());
                        kulka->xdir = -(kulka->xdir);
                        bloczki[tempp->data].setPos(-100,-30);
                        ileBloczkow --;

                    }



                    return 0;
                }
            }
        }
    }

    return 0;
}
