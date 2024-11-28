#ifndef MAPEO_H
#define MAPEO_H


class Mapeo
{
    //EN EL MUNDO REAL, SE PUEDEN UTILIZAR LAS UNIDADES DE MEDIA QUE SE REQUIERAN
    float XWmin,YWmin,XWmax,YWmax; //DEFINE EL AREA DE LA VENTANA (MUNDO REAL)
    int XPVmin, YPVmin, XPVmax,YPVmax; //DEFINE EL AREA DE DIBUJO EN EL DISPOSITIVO

public:
   // Mapeo();
     //REPRESENTA EL AREA DEL MUNDO REAL
    void ventana(float wx1,float wy1,float wx2, float wy2);
    //REPRESENTA EL AREA DE DESPLIEGUE
    void puerto(int pvx1,int pvy1, int pvx2, int pvy2);
        // X, Y POS. DEL MUNDO REAL,  XT , YT LA POS. EN EL DISP. DE DESPLIEGUE
    void mapear(int X, int Y, int &XT, int &YT, int L, int M);//L y M REPRESENTAN EL ORIGEN

};

#endif // MAPEO_H
