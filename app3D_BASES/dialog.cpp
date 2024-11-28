#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    Alpha = 63.4;
    Phi = 30;
    tX = tY = tZ = 0;

    //centro del cubo ejemplo
    xC = 150;
    yC = 100;
    zC = 50;

    rX = rY  = rZ = false;
    anguloX = anguloY = anguloZ = 0;
    asignaCubo ();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::asignaCubo()
{
    Puntos3D cuboBase [] = {{100, 50, 0, 0},
                            {200,50,0, 1},
                            {200,150,0 ,1},
                            {100, 150, 0, 1},
                            {100, 50, 0, 1},
                            {100,50,100, 1},
                            {200, 50, 100, 1},
                            {200,50,0, 1},
                            {200,50,100, 0},
                            {200,150,100, 1},
                            {200,150,0, 1},
                            {200,150,100, 0},
                            {100,150,100, 1},
                            {100,150,0, 1},
                            {100,150,100, 0},
                            {100,50,100, 1}};

    cubo = new Puntos3D [16];
    for ( int i = 0; i < 16; i++)
        cubo [i] = cuboBase [i];

    inicializarPuerto();
    ancho = this->size().width() - ui->widget->size().width();

}

void Dialog::paintEvent(QPaintEvent *evento)
{
    Q_UNUSED ( evento );
    inicializarPuerto ();
    proyeccionCubo ();

}

void Dialog::proyeccionCubo()
{
    canvas = new QPainter (this);
    canvas->setPen(QPen(Qt::blue, 3));//para los ejes
    //EJE X
    canvas->drawLine( 0, this->size().height()-(ui->widget_2->height())-2, ancho, size().height()-(ui->widget_2->height())-2);
    //EJE Y
    canvas->drawLine ( 1,0,1,size().height()-ui->widget_2->height());
    //EJE Z
    int zx1 = 0;
    int zy1 = 0;

    int zx2 = ancho * cos ( qDegreesToRadians(Phi));
    int zy2 = ancho * sin ( qDegreesToRadians(Phi));

    float x1, y1, x2, y2;
    mapeo.mapear ( zx1, zy1, x1, y1, L, M);
    mapeo.mapear ( zx2, zy2, x2, y2, L, M);

    //DIBUJAR EJE Z
    canvas->drawLine(x1, y1, x2, y2);

    //ROTACION
    float x, y, z;
    for ( int i = 0; i < 16; i++ )
    {
        x = cubo[i].x;
        y = cubo[i].y;
        z = cubo[i].z;
        if ( rX )
        {
            x = cubo[i].x;

              y=floor((yC+(cubo[i].y-yC)*cos(qDegreesToRadians(anguloX))+(cubo[i].z-zC)*sin(qDegreesToRadians(anguloX)))+0.5);
              z=floor((zC+(-(cubo[i].y-yC)*sin(qDegreesToRadians(anguloX)))+(cubo[i].z-zC)*cos(qDegreesToRadians(anguloX)))+0.5);
           }
          if (rY)
          {

                y = cubo[i].y;
                x = floor((xC+(cubo[i].x-xC)*cos(qDegreesToRadians(anguloY))-(cubo[i].z-zC)*sin(qDegreesToRadians(anguloY)))+0.5);
                z = floor((zC+(cubo[i].x-xC)*sin(qDegreesToRadians(anguloY))+(cubo[i].z-zC)*cos(qDegreesToRadians(anguloY)))+0.5);
          }
          if (rZ)
          {
              z = cubo[i].z;
              x = floor((xC+(cubo[i].x-xC)*cos(qDegreesToRadians(anguloZ))-(cubo[i].y-yC)*sin(qDegreesToRadians(anguloZ)))+0.5);
              y = floor((yC+(cubo[i].x-xC)*sin(qDegreesToRadians(anguloZ))+(cubo[i].y-yC)*cos(qDegreesToRadians(anguloZ)))+0.5);
          }

          //CALCULAR LA PROYECCION Y DIBUJO DEL CUBO
          if ( cubo[i].opcion ) // 0 = MOVE-TO, 1 = LINE-TO
              lineTo3D (x + tX ,y + tY ,z + tZ ,qDegreesToRadians(Alpha),qDegreesToRadians(Phi),i);
          else
              moveTo3D(x + tX,y + tY ,z + tZ ,qDegreesToRadians(Alpha),qDegreesToRadians(Phi),i);

    }

    canvas->setPen(QPen(QColor(255,100, 0), 3));
    dibujarCubo();
    canvas->end();

}

void Dialog::dibujarCubo()
{
    for ( int i = 0; i < 15; i++ )
        canvas->drawLine(points[i].x(), points[i].y(),
                         points[i+1].x(), points[i+1].y());
}

void Dialog::inicializarPuerto()
{
    mapeo.ventana(0,0, size().width() - ancho, size().height()-ui->widget_2->height());
    mapeo.puerto(0,0, size().width() - ancho, size().height()-ui->widget_2->height());
    L = 0;
    M = size ().height()-ui->widget_2->height();
}

void Dialog::lineTo3D(int x, int y, int z, float alpha, float phi, int i)
{
    int xp, yp;
    int longitud;
    float tanalpha;
    if (( tanalpha = tan(alpha )) != 0 )
        longitud = (int) ( z/tanalpha);
    else
        longitud = 0;

    xp = x + longitud * cos (phi);
    yp = y + longitud * sin (phi);

    //MAPEAR LOS VALORES PROYECTADOS
    float x1, y1;
    mapeo.mapear(xp,yp,x1,y1,L,M);

    //SE ASIGNAN UNO A UNO LOS VERTICES DEL CUBO
    points[i].setX(x1);
    points[i].setY(y1);
}

void Dialog::moveTo3D(int x, int y, int z, float alpha, float phi, int i)
{
    int xp, yp;
    int longitud;
    float tanalpha;
    if (( tanalpha = tan(alpha )) != 0 )
        longitud = (int) ( z/tanalpha);
    else
        longitud = 0;

    xp = x + longitud * cos (phi);
    yp = y + longitud * sin (phi);

    //MAPEAR LOS VALORES PROYECTADOS
    float x1, y1;
    mapeo.mapear(xp, yp, x1, y1, L, M);

    //SE ASIGNAN UNO A UNO LOS VERTICES DEL CUBO
    points[i].setX(x1);
    points[i].setY(y1);
}

void Dialog::on_dial_sliderMoved(int position)
{
    Alpha = position;
    inicializarPuerto ();
    update ();
}

void Dialog::on_dial_2_valueChanged(int value)
{
    Phi = value;
    inicializarPuerto();
    repaint();

}

void Dialog::on_pushButton_clicked()
{
    tX += 5;
    repaint();
}

void Dialog::on_pushButton_2_clicked()
{
    tX -= 5;
    repaint();
}

void Dialog::on_pushButton_3_clicked()
{
    tY += 5;
    repaint();
}

void Dialog::on_pushButton_4_clicked()
{
    tY -= 5;
    repaint();
}

void Dialog::on_pushButton_5_clicked()
{
    tZ += 5;
    repaint();
}

void Dialog::on_pushButton_6_clicked()
{
    tZ-= 5;
    repaint();

}

void Dialog::keyPressEvent(QKeyEvent *event)
{
    if ( habTeclado )
    {
        //ROTACION

        if(event->key() == Qt::Key_Q)
        {
            anguloX+=5; rX=true;  rY=false;  rZ=false;
        }
        if(event->key() == Qt::Key_W)
        {
            anguloX-=5; rX=true;  rY=false;  rZ=false;
        }
        if(event->key() == Qt::Key_E)
        {
            anguloY+=5; rX=false;  rY=true;  rZ=false;
        }
        if(event->key() == Qt::Key_R)
        {
            anguloY-=5; rX=false;  rY=true;  rZ=false;
        }
        if(event->key() == Qt::Key_T)
        {
            anguloZ+=5; rX=false;  rY=false;  rZ=true;
        }
        if(event->key() == Qt::Key_Y)
        {
            anguloZ-=5; rX=false;  rY=false;  rZ=true;
        }
    }
    update();
}

void Dialog::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked())
    {
        ui->widget->setEnabled(false);
        habTeclado = true;
    }
    else
    {
        ui->widget->setEnabled(true);
        habTeclado = false;
    }
}
