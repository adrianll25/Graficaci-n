#include "dialog.h"
#include "ui_dialog.h"
#include <iostream>

using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    dibujoOrientacionNormal = dibujoMapeado = false;
    XPVmin=150, XPVmax=350, YPVmin=100, YPVmax=400;
    rx1=150, ry1=100, rAncho=200, rAlto=300;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    canvas = new QPainter(this);
    if(dibujoOrientacionNormal)
        dibujarFigura();
    else if(dibujoMapeado)
        dibujarFiguarMapeada();

    canvas->end();
}
void Dialog::asignarFigura()
{                                 // TENIA 1
    //Fig[0][0] = 10; Fig[0][1] = -10; Fig[0][2]= 1;
    //Fig[1][0] = 30; Fig[1][1] = -10; Fig[1][2]= 1;
    //Fig[2][0] = 10; Fig[2][1] = -30; Fig[2][2]= 1;
    //REGRESA AL INICIO DE LA FIGURA
    //Fig[3][0] = 10; Fig[3][1] = -10; Fig[3][2]= 1;


    //Fig[0][0] = 0; Fig[0][1] = 0; Fig[0][2]= 1;
    //Fig[1][0] = 10000; Fig[1][1] = 0; Fig[1][2]= 1;
    //Fig[2][0] = 0; Fig[2][1] = 10000; Fig[2][2]= 1;
    //REGRESA AL INICIO DE LA FIGURA
    //Fig[3][0] = 0; Fig[3][1] = 0; Fig[3][2]= 1;


    //Fig[0][0] = 0; Fig[0][1] = 0; Fig[0][2]= 1;
    //Fig[1][0] = 7.3; Fig[1][1] = 3.2; Fig[1][2]= 1;
    //Fig[2][0] = 5.3; Fig[2][1] = 5.5; Fig[2][2]= 1;
    //REGRESA AL INICIO DE LA FIGURA
    //Fig[3][0] = 0; Fig[3][1] = 0; Fig[3][2]= 1;

    Fig[0][0] = 22; Fig[0][1] = 20;  Fig[0][2] = 1;
    Fig[1][0] = 0;  Fig[1][1] = 20;   Fig[1][2] = 1;
    Fig[2][0] = 22; Fig[2][1] = 0;    Fig[2][2] = 1;
    Fig[3][0] = 22/2; Fig[3][1] = 28; Fig[3][2] = 1;

    // regresa al inicio de la figura
    Fig[4][0] = 0; Fig[4][1] = 0; Fig[4][2] = 1;


    //RESPALDAR LA FIGURA ORIGINAL PARA RESETEARLA CUANDO SEA NECESARIO
    for(int r = 0; r < 4; r++)
        for(int c = 0; c < 3 ; c++ )
            FigAux[r][c] = Fig[r][c];

    ancho = this->size().width() - ui->widget->size().width();
    centroX = ancho / 2;
    centroY = this->size().height()/2;


}
void Dialog::dibujarFigura()
{
//dibujar los ejes cartesianos
    //LINEA HORIZONTAL
    canvas->drawLine(0, size().height()/2,ancho,size().height()/2);
    //LINEA VERTICAL
    canvas->drawLine(ancho/2,0,ancho/2,size().height());
    canvas->setPen(QColor(255,0,0));
    for(int i = 0; i < 3; i++)
        //ESQ. SUP. IZQ
       //canvas->drawLine(Fig[i][0],Fig[i][1], Fig[i+1][0], Fig[i+1][1]);
        //CENTRO
        canvas->drawLine(centroX+Fig[i][0],centroY+Fig[i][1], centroX+Fig[i+1][0], centroY+Fig[i+1][1]);


}
void Dialog::dibujarFiguarMapeada()
{
    //dibujar los ejes cartesianos
        //LINEA HORIZONTAL
        //canvas->drawLine(0, size().height()/2,ancho,size().height()/2);
        //LINEA VERTICAL
        //canvas->drawLine(ancho/2,0,ancho/2,size().height());

    Mapeo dibujo;
    // VENTANA REPRESENTA EL MUNDO REAL
    //dibujo.ventana(0,0,ancho,size().height());
    //dibujo.ventana(ancho/2, 0, ancho, size().height() / 2);
    //PUERTO DE VISION REPRESENTA EL AREA DE DESPLIEGUE EN EL DISPOSITIVO
    //dibujo.puerto(0, 0, ancho/2, size().height() / 2);

    //dibujo.ventana(0,0,10, 10);

    //TAMAÑO DE UNA HOJA DE MAQUINA
    //dibujo.ventana(0,0,21.5, 28);
    //dibujo.ventana(0,0,22, 28);
    //dibujo.puerto(0, 0, ancho/2, size().height() / 2);

//COLOCACION DEL PUERTO EN EL CENTRO DE LA FOTMA DONDE SE ESTA DIBUJANDO
    dibujo.ventana(0,0,22, 28);
    dibujo.puerto(150, 100, 350, 400);
    //EL VALOR
    //EN EL PUERTO SE REQUIEREN DE VERTICES
    //dibujar eñ rectangulo que MOSTRARA EL PUERTO DE VISION
    canvas->drawRect(150,100,200,300);

    canvas->setPen(QColor(0,0,255));
    //REPRESENTAN EL ORIGEN EN EL MAPEO, ESQ. INF. IZQ.
    // int L = 0;
    // int M = this->size().height();

    //int L = 0;//centroX; SI XPVMIN ES EL FACTOR DE TRANSALACION
    //int L = centroX;
    //int M = centroY;

    int L = 0;
    int M = 500;//YVPMIN + YVPMAX


    int x1, y1,x2,y2;
    //CALCULAR LOS EXTREMOS DE LA LINEA
    dibujo.mapear(Fig[0][0],Fig[0][1],x1,y1, L, M );
    dibujo.mapear(Fig[2][0], Fig[2][1], x2, y2, L , M);

    canvas->drawLine(x1,y1,x2,y2);

    for(int i = 0; i < 2; i++)
    {
        dibujo.mapear(Fig[i][0],Fig[i][1],x1,y1, L, M );
        dibujo.mapear(Fig[i+1][0], Fig[i+1][1], x2, y2, L , M);
        canvas->drawLine(x1,y1,x2,y2);
    }



}
void Dialog::on_pushButton_clicked()
{
   asignarFigura();
   dibujoOrientacionNormal = true;
   dibujoMapeado = false;
   repaint();
}

void Dialog::on_pushButton_2_clicked()
{
    asignarFigura();
    dibujoOrientacionNormal = false;
    dibujoMapeado = true;
    repaint();
}

void Dialog::on_pushButton_3_clicked()
{
        if(XPVmax>220){
        XPVmax -= 10;
        YPVmax -= 10;
        XPVmin += 10;
        YPVmin += 10;
        rx1+=10;
        ry1+=10;
        rAncho-=20;
        rAlto-=20;
        on_pushButton_2_clicked();
        }
}

void Dialog::on_pushButton_4_clicked()
{
    if(XPVmax<440){
    XPVmax += 10;
    YPVmax += 10;
    XPVmin -= 10;
    YPVmin -= 10;
    rx1-=10;
    ry1-=10;
    rAncho+=20;
    rAlto+=20;
    on_pushButton_2_clicked();
    }
}

void Dialog::on_pushButton_5_clicked()
{

}
