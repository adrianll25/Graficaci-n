#ifndef GRAFICOS_H
#define GRAFICOS_H
#include <QPainter>
#include <QColor>
#include <QtMath>
#include <iostream>

using namespace std;

class Graficos
{
public:
    Graficos();

    int round ( float n )
    {
        return int ( n+0.5 );
    }

    void lineaDDA ( int x1, int y1, int x2, int y2, QPainter * canvas );
    void lineaDDA ( int x1, int y1, int x2, int y2, QPainter * canvas, QColor color  );
    void lineaBresenham ( int x1, int y1, int x2, int y2, QPainter *canvas, QColor color);
    void circuloPitagoras ( int xc, int yc, int r, QPainter *canvas, QColor color );
    void circuloPolares (  int xc, int yc, int r, QPainter *canvas, QColor color );
    void espiral ( QPainter *canvas, QColor color, double radio, double factor );
    void espiral2 ( QPainter *canvas, QColor color );
};

#endif // GRAFICOS_H
