#include "grafico.h"
#include <math.h>

grafico::grafico()
{

}

void grafico::lineaDDA(int x1, int x2, int y1, int y2, QPainter *canvas){
    int dx, dy, steps, k;
    float x_inc, y_inc, x, y;
    dx = x2 - x1;
    dy = y2 - y1;

    if ( abs(dx)>abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    x_inc = (float)dx/steps;
    y_inc = (float)dy/steps;
    x = 1;
    y = 1;
    QPen pen(QColor(0,0,200), 1);
    canvas->setPen(pen);
    //EN VEZ DE FLOOR USAR ROUND
    //Canvas->draPoint(floor(x), floor(y));
    canvas->drawPoint(round(x), round(y));
    for(k=1; k<steps+1; k++)
    {
        x = x + x_inc;
        y = y + y_inc;
        //Canvas->draPoint(floor(x), floor(y));
    canvas->drawPoint(round(x), round(y));
    }

}

void grafico::circuloPitagoras(int xc, int yc, int radio, QPainter *canvas)
{
    canvas->setPen(QColor(0,0,200));
    float y;
    //EL EJE X DEL CIRCULO(DIAMETRO) SE RECORRE EN INC. UNITARIOS
    for(int x = xc-radio; x <= xc+radio; x++)
    {
        y = yc + sqrt((radio * radio) - pow((x-xc), 2.0));
        canvas->drawPoint(x, int(y));
        y = yc - sqrt(pow(radio, 2.0)- ((x-xc)*(x-xc)));
        canvas->drawPoint(x, int(y));

    }

}

void grafico::circuloPolares(int xc, int yc, int radio, QPainter *canvas)
{
    canvas->setPen(QColor(0,0,200));
    float dth, cdth, sdth, x, y, xtemp;
    dth = 1.0/radio;
    cdth=cos(dth);
    sdth=sin(dth);
    x=0;
    y=radio;

    while (y >= x)
    {
        canvas->drawPoint(round(xc+x), round(yc + y));
        canvas->drawPoint(round(xc-x), round(yc + y));
        canvas->drawPoint(round(xc-x), round(yc - y));
        canvas->drawPoint(round(xc+x), round(yc - y));

        xtemp = x;
        x = xtemp*cdth - y * sdth;
        y = y * cdth + xtemp * sdth;

    }

}

void grafico::espiral1(QPainter *canvas, QColor color)
{
    //DIBUJAMOS APARTIR DEL CENTRO DE LA FORMA
    int xc = canvas->window().width()/2;
    int yc = canvas->window().height()/2-70;
    int radio = 5; //original

    //const double dos_pi = N_PI * 2;
    const double dos_pi = 6.28318;

    canvas->setPen(color);

    int cont;
    double dth, cth, sth, x, y, x_tmp, xt, yt;

    //FACTOR MODIFICAR
    //recibir como parametro el factor 16 y cambio por factor
    dth = dos_pi/(16 * radio);

    //FACTOR SE ASIGNARA DESDE LA INTERFAZ
    cth = cos(dth);
    sth = sin(dth);
    x = 0.0;//radio
    y = radio;
    cont = 0;
    xt = xc + x;
    yt = yc + y;

    do
    {
        x_tmp = x;
        x = ( x * cth - y * sth );
        y = ( y * cth + x_tmp * sth);

        if(x>0)
        {
            x += 0.5;
        }

        else
        {
            x -= 0.5;
        }

        if ( y >0 )
        {
            y += 0.5;
        }

        else
        {
            y -= 0.5;
        }

        //USAR PUNTOS
        canvas->drawPoint(xt+.5, round(yt+.5));

        //UTILIZANDO LINEADA
        //lineaDDA(round(xt +.5), round(yt+.5), round(xc+x+.5), round(yc+y+.5), canvas, color);
        xt = xc + x;
        yt = yc + y;
        cont ++;
    }

    while (cont<300);

}

void grafico::espiral2(QPainter *canvas, QColor color)
{
    int xc = canvas->window().width()/2;
    int yc = canvas->window().height()/2-80;
    float radio = 1.0;
    canvas->setPen(color);
    double th,x,y,xt,yt;
    th = 0.0;
    x = radio * cos(th);
    y = radio * sin(th);
    xt = xc + x;
    yt = yc + y;
    while (radio<230)
    {
       th += 3.7;
       radio += 0.9;
       x = radio * cos(th);
       y = radio * cos(th);

       //PARAMETROS
       //lineaDDA(round(xt + .5), round(yt + .5), round(xc + x + .5), round(yc + y + .5), canvas, color);
       canvas->drawPoint(xt+.5, round(yt+.5));


       xt = xc + x;
       yt = yc + y;

    }

}


