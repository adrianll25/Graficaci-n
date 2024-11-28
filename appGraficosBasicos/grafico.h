#ifndef GRAFICO_H
#define GRAFICO_H

#include <QPainter>
#include <QColor>

class grafico
{
public:
    grafico();

    //EN LUGAR DE USAR FLOOR O CEIL

    int round(float n
              ){
        return int(n+0.5);
    }

    void lineaDDA(int x1, int x2, int y1, int y2, QPainter *canvas);
    //IMPLEMENTAR   OTRO METODO PARA RECIBIR COMOO PARAMETRO EL COLOR QUE EL USUARIO SELECCIONO
    void lineaDDA(int x1, int x2, int y1, int y2, QPainter *canvas, QColor color);
    //METODO CIRCULO PITAGORAS
    void circuloPitagoras(int xc, int yc, int radio, QPainter *canvas);
    //METODO CIRCULO POLARES
    void circuloPolares(int xc, int yc, int radio, QPainter *canvas);
    //METODO ESPIRALES
    void espiral1(QPainter *canvas, QColor color);
    void espiral2(QPainter *canvas, QColor color);
};

#endif // GRAFICO_H
