#include "mapeo.h"
#include <math.h>

/*
Mapeo::Mapeo()
{

}
*/

void Mapeo::ventana(float wx1, float wy1, float wx2, float wy2)
{
    XWmin = wx1;
    YWmin = wy1;
    XWmax = wx2;
    YWmax = wy2;
}

void Mapeo::puerto(int pvx1, int pvy1, int pvx2, int pvy2)
{
    XPVmin = pvx1;
    YPVmin = pvy1;
    XPVmax = pvx2;
    YPVmax = pvy2;
}

void Mapeo::mapear(int X, int Y, int &XT, int &YT, int L, int M)
{
    float sX, sY;

    sX = (XPVmax - XPVmin) / (XWmax - XWmin);
    sY = (YPVmax - YPVmin) / (YWmax - YWmin);

    XT = int(round(sX * (X - XWmin) + XPVmin + L));
    YT = int(round(sY * (YWmin - Y) - YPVmin + M));
}
