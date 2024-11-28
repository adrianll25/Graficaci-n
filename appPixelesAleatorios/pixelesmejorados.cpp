#include "pixelesmejorados.h"
#include "ui_pixelesmejorados.h"

PixelesMejorados::PixelesMejorados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PixelesMejorados)
{
    ui->setupUi(this);
    timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
}

PixelesMejorados::~PixelesMejorados()
{
    delete ui;
}

void PixelesMejorados::paintEvent(QPaintEvent *evt)
{
    Q_UNUSED(evt)
    //QPainter canvas(this);

    pixeles();
    /*for(int i = 0; i < 10000; i++)
    //{
        //QPen pen1(QColor(rand()%155+100,rand()%155+100,rand()%155+100));
        //pen1.setWidth(3);
        //canvas.setPen(pen1);
        //canvas.drawPoint(rand()%this->width()+10,rand()%height()-50);
    }*/
}

void PixelesMejorados::pixeles()
{
    QPainter canvas ( this );
    for ( int i = 0; i < 25000; i++ )
    {
        int rojo = ui->spinBoxRojo->value ( );
        int verde = ui->spinBoxVerde->value ( );
        int azul = ui->spinBoxAzul->value ( );

        QPen pen1 ( QColor ( rojo, verde, azul ) );
        pen1.setWidth ( ui->horizontalSlider->value ( ) );
        canvas.setPen ( pen1 );
        canvas.drawPoint ( rand()%this->width() , rand () % height() - 250 );
     }
}

void PixelesMejorados::on_BotonIniciar_clicked()
{
    timer->start ( 10 );
}

void PixelesMejorados::on_BotonDetener_clicked()
{
    timer->stop ();
}


void PixelesMejorados::on_dialRojo_valueChanged(int value)
{
    ui->spinBoxRojo->setValue( value );
}



void PixelesMejorados::on_dialVerde_valueChanged(int value)
{
    ui->spinBoxVerde->setValue( value );
}

void PixelesMejorados::on_dialAzul_valueChanged(int value)
{
    ui->spinBoxAzul->setValue( value );
}

void PixelesMejorados::on_spinBoxRojo_valueChanged(int arg1)
{
    ui->dialRojo->setValue( arg1 );
}


void PixelesMejorados::on_spinBoxVerde_valueChanged(int arg1)
{
    ui->dialVerde->setValue( arg1 );
}



void PixelesMejorados::on_spinBoxAzul_valueChanged(int arg1)
{
    ui->dialAzul->setValue( arg1 );
}
