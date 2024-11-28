#include "rectanguloitem.h"

RectanguloItem::RectanguloItem(int ancho, int alto) //QObject *parent) : QObject(parent)
{
    this->ancho = ancho;
    this->alto = alto;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(mover()));

}

void RectanguloItem::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_Left)
        setPos(this->x() - 10, this->y());

    if(evento->key() == Qt::Key_Right)
        setPos(this->x() + 10, this->y());

    if(evento->key() == Qt::Key_Up)
        setPos(this->x(), this->y() - 10);

    if(evento->key() == Qt::Key_Down)
        setPos(this->x(), this->y() + 10);

    if(evento->key() == Qt::Key_Space)
    {
        timer->start(50);
        mover();
    }
    if(evento->key()==Qt::Key_S)
        timer->stop();
}

void RectanguloItem::mover()
{
    if(this->x() < ancho - 50)
        setPos(x() + 10, y());

    static bool der = true;

    if(this->x() < ancho - 50 && der)
    {
        setPos(x() + 10, y());

        if(this->x() >= ancho - 50)
        {
            der = false;
        }
    }
        else

    if(!der)
    {
        setPos(x() - 10, y());

        if(x() <= 0)
        {
            der = true;
        }
    }
}
