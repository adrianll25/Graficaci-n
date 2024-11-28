#include "graficos.h"

void Graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color )
{
    int dx, dy, steps, k;
    float x_inc, y_inc, x, y;
    dx = x2 - x1;
    dy = y2 - y1;

    if ( abs ( dx ) > abs ( dy ) )
        steps = abs ( dx );
    else
        steps = abs ( dy );
    x_inc = ( float )dx/steps;
    y_inc = ( float )dy/steps;
    x = x1;
    y = y1;
    QPen pen ( color, 1 );
    canvas->setPen( pen );

    canvas->drawPoint ( round ( x ), round ( y ) );
    for ( k = 1; k < steps + 1; k++ )
    {
        x = x + x_inc;
        y = y + y_inc;
        canvas->drawPoint ( round ( x ), round ( y ) );
    }
}

void Graficos::lineaBresenham(int x1, int y1, int x2, int y2, QPainter *canvas, QColor color)
{
    int x_inc, y_inc, x_rect, y_rect, x, y, avR, av, avI;
    int dy = ( y2 - y1 );
    int dx = ( x2 - x1 );
    if ( dy >= 0 )
    {
        y_inc = 1;
    }
    else
    {
        dy = -dy;
        y_inc = -1;
    }

    if ( dx >= 0 )
    {
        x_inc = 1;
    }
    else
    {
        dx = -dx;
        x_inc = -1;
    }

    if ( dx >= dy )
    {
        y_rect = 0;
        x_rect = x_inc;
    }
    else
    {
        x_rect = 0;
        y_rect = y_inc;
        int k = dx;
        dx = dy;
        dy = k;
    }

    x = x1;
    y = y1;
    avR = ( 2 * dy );
    av = ( avR - dx );
    avI = ( av - dx );

    QPen pen ( color, 1 );
    canvas->setPen( pen );
    do
    {
        canvas->drawPoint ( x, y );
        //cout << av ;

        if ( av > 0 )
        {
            x = ( x + x_inc );
            y = ( y + y_inc );
            av = ( av + avI );
        }
        else
        {
            x = ( x + x_rect );
            y = ( y + y_rect );
            av = ( av + avR );
        }
    }
    while ( x < x2 );

}

void Graficos::circuloPitagoras(int xc, int yc, int r, QPainter *canvas, QColor color)
{
    QPen pen ( color, 1 );
    canvas->setPen ( pen );
    /*float x = xc - r;
    while ( x <= (xc + r) )*/
    for ( int x = xc - r; x <= ( xc + r ); x++ )
    {
        float y = yc + sqrt ( pow(r,2) - pow( x - xc, 2 ));
        canvas->drawPoint ( x, y );
        y = yc - sqrt ( pow(r,2) - pow( x - xc, 2 ));

        canvas->drawPoint(x, y);
        //x+= 0.2;
    }
}

void Graficos::circuloPolares(int xc, int yc, int radio, QPainter *canvas, QColor color)
{
    QPen pen ( color, 1 );
    canvas->setPen(pen);
    float dth, cdth, sdth, x, y, xtemp;
    dth = 1.0 / radio;
    cdth = cos ( dth );
    sdth = sin ( dth );
    x = 0;
    y = radio;
    while ( y >= x )
    {
        canvas->drawPoint ( round ( xc + x ), round ( yc + y ));
        canvas->drawPoint ( round ( xc - x ), round ( yc + y ));
        canvas->drawPoint ( round ( xc - x ), round ( yc - y ));
        canvas->drawPoint ( round ( xc + x ), round ( yc - y ));

        xtemp = x;
        x = xtemp * cdth - y * sdth;
        y = y * cdth + xtemp * sdth;
    }

}

void Graficos::espiral(QPainter *canvas, QColor color, double radio, double factor )
{
    //DIBUJAMOS A PARTIR DEL CENTRO DE LA FORMA
    int xc = canvas->window().width()/2;
    int yc = canvas->window().height()/2-70;
    //const double dos_pi= M_PI * 2;  //
    const double dos_pi = 6.28318; //M_PI_2
    canvas->setPen(color);
    int cont;
    double dth,cth,sth,x,y,x_tmp,xt,yt;
               //FACTOR MODIFICAR
    dth=dos_pi/( factor * radio); // 1.7, 2.5, ETC
    //decrementar el FACTOR: 16 - 8, 4, 2, 1.8
    //FACTOR SE ASIGNARA DESDE LA INTERFAZ
    cth=cos(dth);
    sth=sin(dth);
    x=0.0;
    y=radio;
    cont=0;
    xt=xc+x;
    yt=yc+y;
    do{
        x_tmp=x;
        x=(x * cth-y * sth);
        y=(y * cth+x_tmp * sth);
        if(x>0){
            x+=0.5;
        }
          else {  x-=0.5;  }
        if(y>0){  y+=0.5;  }
           else{  y-=0.5;  }
        //USAR PUNTOS
        //canvas->drawPoint(xt+.5,round(yt+.5));
        //UTILIZANDO LA LINEADDA
        lineaDDA(round(xt+.5),round(yt+.5),round(xc+x+.5),round(yc+y+.5),canvas,color);
        xt=xc+x;
        yt=yc+y;
        cont++;
    }while(cont<300);
}

void Graficos::espiral2(QPainter *canvas, QColor color)
{
    int xc = canvas->window().width()/2;
    int yc = canvas->window().height()/2 - 75;
    float radio = 1.0;
    QPen pen ( color );
    canvas->setPen ( pen );
    double th, x, y, xt, yt;
    th = 0.0;
    x = radio * cos ( th );
    y = radio * sin ( th );
    xt = xc + x;
    yt = yc + y;
    while ( radio < 200 )
    {
        th += 1.8;
        radio += 1.7;
        x = radio * cos ( th );
        y = radio * sin ( th );
        lineaDDA ( round ( xt + 0.5 ), round ( yt + 0.5 ),
                   round ( xc + x + 0.5 ), round ( yc + y + 0.5 ), canvas, color );
        xt = xc + x;
        yt = yc + y;
    }
}

void Graficos::lineaDDA(int x1, int y1, int x2, int y2, QPainter *canvas )
{
    int dx, dy, steps, k;
    float x_inc, y_inc, x, y;
    dx = x2 - x1;
    dy = y2 - y1;

    if ( abs ( dx ) > abs ( dy ) )
        steps = abs ( dx );
    else
        steps = abs ( dy );
    x_inc = ( float )dx/steps;
    y_inc = ( float )dy/steps;
    x = x1;
    y = y1;
    QPen pen ( QColor ( 0, 0, 200 ), 1 );
    canvas->setPen( pen );

    canvas->drawPoint ( round (x), round ( y ) );
    for ( k = 1; k < steps + 1; k++ )
    {
        x = x + x_inc;
        y = y + y_inc;
        canvas->drawPoint ( round ( x ), round ( y ) );
    }


}
