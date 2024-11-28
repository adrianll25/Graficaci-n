#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    asignarFigura();
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
