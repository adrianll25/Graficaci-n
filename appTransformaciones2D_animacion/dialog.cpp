#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    asignarFigura();

    timer1 = new QTimer();
    connect(timer1, SIGNAL(timeout()), this, SLOT(rotarAnimacion1));

    timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(rotarAnimacion2));

    timer3 = new QTimer();
    connect(timer3, SIGNAL(timeout()), this, SLOT(moverGato()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::trasladar(int tX, int tY)
{
    Matrix fig, id, figres; //OBJETOS ESTATICOS

    fig.Inicializa(4,3);
    figres.Inicializa(4,3);
    id.Inicializa(3,3);

    for(int i = 0; i < fig.numRen(); i++)
    {
        for(int j = 0; j < fig.numCol(); j++)
        {
            fig.SET(i,j,Fig[i][j]);
        }
    }

    //Aplicar traslacion
    figres.traslacion(fig, id, tX, tY);

    //Guardamos los puntos transformados en la fig original
    for(int i = 0; i < fig.numRen(); i++)
    {
        for(int j = 0; j < fig.numCol(); j++)
        {
            Fig[i][j] = figres.GET(i,j);
        }
    }

    repaint();
}

void Dialog::escalar(float sX, float sY)
{
    Matrix fig, id, fres;
    fig.Inicializa(4,3);
    id.Inicializa(3,3);
    fres.Inicializa(4,3);
    for(int i = 0; i < fig.numRen(); i++)
        for(int j = 0; j < fig.numCol(); j++)
            fig.SET(i, j, Fig[i][j]);

    fres.escalacion(fig, id, sX, sY);

    for(int i = 0; i < fres.numRen(); i++)
        for(int j = 0; j < fres.numCol(); j++)
            Fig[i][j] = fres.GET(i,j);

    repaint();

}

void Dialog::escalarPuntoFijo(float sX, float sY, int pfx, int pfy)
{
    Matrix fig, id, fres;
    fig.Inicializa(4,3);
    id.Inicializa(3,3);
    fres.Inicializa(4,3);
    for(int i = 0; i < fig.numRen(); i++)
        for(int j = 0; j < fig.numCol(); j++)
            fig.SET(i, j, Fig[i][j]);

    fres.escalacionPuntoFijo(fig, id, sX, sY, pfx, pfy);

    for(int i = 0; i < fres.numRen(); i++)
        for(int j = 0; j < fres.numCol(); j++)
            Fig[i][j] = fres.GET(i,j);

    repaint();

}

//IZQUIERDA
void Dialog::on_Boton1_clicked()
{
   trasladar(tx - ui->spinBox->value(), 0);
}

//DERECHA
void Dialog::on_Boton2_clicked()
{
    trasladar(tx + ui->spinBox->value(), 0);

}

//ABAJO
void Dialog::on_Boton3_clicked()
{
    trasladar(0,ty - ui->spinBox->value());

}

//ARRIBA
void Dialog::on_Boton4_clicked()
{

    trasladar(0,ty + ui->spinBox->value());
}


void Dialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    canvas = new QPainter(this);

    dibujarFiguraMapeada();

    canvas->end();
}
void Dialog::asignarFigura()
{
    /*
    Fig[0][0] = 10;  Fig[0][1] = 10;  Fig[0][2] = 1;
    Fig[1][0] = 30; Fig[1][1] = 10; Fig[1][2] = 1;
    Fig[2][0] = 10; Fig[2][1] = 30;  Fig[2][2] = 1;
    Fig[3][0] = 10;  Fig[3][1] = 10; Fig[3][2] = 1;

    //Respaldar la figura original para resetearla cuando sea necesario
    for(int r = 0; r < 3; r++)
        for(int c = 0; c < 3; c++)
            FigAux[r][c] = Fig[r][c];

    //ancho = this->size().width() - ui->widget->size().width();
    ancho = this->size().width() - ui->widget->size().width();
    centroX = ancho / 2;
    centroY = this->size().height() / 2;

    tx = ty = 0;
    */

    Fig[0][0] = 1; Fig[0][1] = 12; Fig[0][2] = 1;
    Fig[1][0] = 1; Fig[1][1] = 8;  Fig[1][2] = 1;
    Fig[2][0] = 2; Fig[2][1] = 2;  Fig[2][2] = 1;
    Fig[3][0] = 5; Fig[3][1] = 2;  Fig[3][2] = 1;
    Fig[4][0] = 5; Fig[4][1] = 4;  Fig[4][2] = 1;
    Fig[5][0] = 3; Fig[5][1] = 5;  Fig[5][2] = 1;
    Fig[6][0] = 4; Fig[6][1] = 6;  Fig[6][2] = 1;
    Fig[7][0] = 6; Fig[7][1] = 6;  Fig[7][2] = 1;
    Fig[8][0] = 6; Fig[8][1] = 2;  Fig[8][2] = 1;
    Fig[9][0] = 9; Fig[9][1] = 2;  Fig[9][2] = 1;
    Fig[10][0] = 9; Fig[10][1] = 4;Fig[10][2] = 1;
    Fig[11][0] = 8; Fig[11][1] = 4;Fig[11][2] = 1;
    Fig[12][0] = 8; Fig[12][1] = 7;Fig[12][2] = 1;
    Fig[13][0] = 9; Fig[13][1] = 6;Fig[13][2] = 1;
    Fig[14][0] = 11; Fig[14][1] = 5;Fig[14][2] = 1;
    Fig[15][0] = 13; Fig[15][1] = 5;Fig[15][2] = 1;
    Fig[16][0] = 15; Fig[16][1] = 6;Fig[16][2] = 1;
    Fig[17][0] = 16; Fig[17][1] = 7;Fig[17][2] = 1;
    Fig[18][0] = 16; Fig[18][1] = 13;Fig[18][2] = 1;
    Fig[19][0] = 14; Fig[19][1] = 11;Fig[19][2] = 1;
    Fig[20][0] = 10; Fig[20][1] = 11;Fig[20][2] = 1;
    Fig[21][0] = 8; Fig[21][1] = 13;Fig[21][2] = 1;
    Fig[22][0] = 8; Fig[22][1] = 9;Fig[22][2] = 1;
    Fig[23][0] = 6; Fig[23][1] = 11;Fig[23][2] = 1;
    Fig[24][0] = 4; Fig[24][1] = 11;Fig[24][2] = 1;
    Fig[25][0] = 2; Fig[25][1] = 9;Fig[25][2] = 1;
    Fig[26][0] = 2; Fig[26][1] = 12;Fig[26][2] = 1;
    Fig[27][0] = 3; Fig[27][1] = 12;Fig[27][2] = 1;
    Fig[28][0] = 5; Fig[28][1] = 14;Fig[28][2] = 1;
    Fig[29][0] = 5; Fig[29][1] = 15;Fig[29][2] = 1;
    Fig[30][0] = 3; Fig[30][1] = 15;Fig[30][2] = 1;
    Fig[31][0] = 1; Fig[31][1] = 12;Fig[31][2] = 1;

    //Respaldar la figura original para resetearla cuando sea necesario
    for(int r = 0; r < 32; r++)
        for(int c = 0; c < 32; c++)
            FigAux[r][c] = Fig[r][c];

    ancho = this->size().width() - ui->widget->size().width();
    //ancho = this->size().width() - ui->widget->size().width();
    //centroX = ancho / 2;
    //centroY = this->size().height() / 2;

    tx = ty = 0;

}

void Dialog::dibujarFiguraMapeada()
{
    Mapeo dibujo;

    canvas->drawLine(0, size().height()/2, ancho, size().height()/2);
    canvas->drawLine(ancho/2,0,ancho/2,size().height());

    //Colocacion del puerto en el centro de la forma donde se esta dibujando
    dibujo.ventana(ancho / 2, 0, ancho, size().height()/2);
    dibujo.puerto(ancho/2, 0, ancho, size().height()/2);



    //En el rectangulo el ancho y el alto

    canvas->setPen(QColor(0,0,255));

    int L = centroX;
    int M = centroY; //YPVMIN + YPVMAX

    int x1, y1, x2, y2;

    //Calcular los extremos de la linea
    //dibujo.mapear(Fig[0][0], Fig[0][1], x1, y1, L, M);
    //dibujo.mapear(Fig[2][0], Fig[2][1], x2, y2, L, M);

    //canvas->drawLine(x1, y1, x2, y2);

    for(int i = 0; i < 3; i++)
    {
        dibujo.mapear(Fig[i][0], Fig[i][1], x1, y1, L, M);
        dibujo.mapear(Fig[i+1][0], Fig[i+1][1], x2, y2, L, M);

        canvas->drawLine(x1, y1, x2, y2);
    }
}

void Dialog::rotacion(double ang)
{
    Matrix fig, id, figres;

    fig.Inicializa(4,3);
    figres.Inicializa(4,3);
    id.Inicializa(3,3);

    for(int i = 0; i < fig.numRen(); i++)
    {
        for(int j = 0; j < fig.numCol(); j++)
        {
            fig.SET(i,j,Fig[i][j]);
        }
    }

    figres.rotacion(fig, id, ang);

    for(int i = 0; i < figres.numRen(); i++)
    {
        for(int j = 0; j < figres.numCol(); j++)
        {
            Fig[i][j] = figres.GET(i,j);
        }
    }

    repaint();
}

void Dialog::on_pushButton_clicked()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            Fig[i][j] = FigAux[i][j];
        }
    }
    tx = ty = 0;
    update();

}

void Dialog::on_pushButton_2_clicked()
{
    double sX = ui->doubleSpinBox->value();
    double sy = ui->doubleSpinBox_2->value();
    escalar(sX, sy);

}

void Dialog::on_pushButton_3_clicked()
{
    double sX = ui->doubleSpinBox->value();
    double sY = ui->doubleSpinBox_2->value();
    int pfx = int(ui->doubleSpinBox_3->value());
    int pfy = int(ui->doubleSpinBox_4->value());

    escalarPuntoFijo(sX, sY, pfx, pfy);
}

void Dialog::on_btnRotar_clicked()
{
    double ang = ui->doubleSpinBox_5->value();

    rotacion(ang);
}

/*void Dialog::rotarAnimacion1()
{
    static int angulo = 0;
    static int cont = 0;

    if(cont <= 8)
    {
        angulo = 45;
        if(cont == 8)
        {
           angulo = 0;
           cont = 0;
        }

        double pfx = 20;
        double pfy = 30;

        //rotarPuntofijo(angulo, pfx, pfy);
        cont++;
    }

}

*/

void Dialog::moverGato()
{
    static int cont = 1;
    static bool band;

    if(cont <= 50 && band )
    {
        trasladar(1,0);
        cont;

        if(cont > 50)
        {
            band = false;
        }
    }

    else
        if(!band)
        {
            trasladar(-1, 0);
            cont--;

            if(cont == 0)
            {
                band = true;
            }
        }
}

//Animacion
void Dialog::rotarAnimacion1()
{
    static int angulo = 0;
    static int cont = 0;

    if(cont <= 8)
    {
        angulo = 45;
        if(cont == 8)
        {
            angulo = 0;
            cont = 0;
        }
        double pfx = 20; //Usar el valor de los spinbox
        double pfy = 30;

        rotarPuntoFijo(angulo, pfx, pfy);
        cont++;
    }
}

void Dialog::rotarAnimacion2()
{

/*Rotacion con angulo positivo, es en sentido contario a las manecillas del reloj*/
/*Rotacion con angulo negativo, es en sentido a las manecillas del reloj*/
    static bool dir = true;
    static int angulo = 0;
    static int cont = 0;

    if(cont <= 9 && dir == true)
    {
        angulo = 45;
        double pfx = 10;
        double pfy = 10;

        rotarPuntoFijo(angulo, pfx, pfy);
        cont++;

        if(cont == 9)
        {
            angulo = 0;
            cont = 0;
            dir = false;
        }
    }

    if(!dir)
    {
        angulo = -45;
        double pfx = 10;
        double pfy = 10;

        rotarPuntoFijo(angulo, pfx, pfy);
        cont++;

        if(cont == 9)
        {
            angulo = 0;
            cont = 0;
            dir = true;
        }
    }
}


void Dialog::on_pushButton_4_clicked()
{
    timer3->start(50);

}


void Dialog::on_pushButton_5_clicked()
{
    timer2->stop();
    timer1->start(50);

}

void Dialog::on_pushButton_6_clicked()
{
    timer1->stop();
    timer2->start(50);

}
