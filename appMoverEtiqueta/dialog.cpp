#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent): QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

int Timer = 0;

void Dialog::setTimer()
{
    if( Timer == 1 )
    {
        timerHorizontal = new QTimer();
        connect(timerHorizontal, SIGNAL(timeout()), this, SLOT(moverEtiqueta()));
        timerHorizontal->start(100);
    }

    else
        if( Timer == 2 )
        {
            timerVertical = new QTimer();
            connect(timerVertical, SIGNAL(timeout()), this, SLOT(moverEtiquetaVeriticalmente()));
            timerVertical->start(100);
        }
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::moverEtiqueta()
{

    static int x = 0;
    static bool band = true;
    int y = ui -> label->geometry().y();

//SE MUEVE A LA DERECHA
    if( ui->label->geometry().x() < this->width() - (ui->label->width()+5) && band )
      {
          ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
          x+= 10;
          if(ui->label->geometry().x() >this->width() - (ui->label->width()+5) )
              band = false;
      }
//SE MUEVE A LA IZQUIERDA
      if(!band)
      {
          x-= 10;
          ui->label->setGeometry(x,y,ui->label->width(),ui->label->height());
          if (x == 0)
              band = true;

      }
}

void Dialog::moverEtiquetaVeriticalmente()
{
    static int y = ui->label->geometry().y();
    static bool band = true;
    int x = ui->label->geometry().x();

    //SE MUEVE HACIA ABAJO
    if( ui->label->geometry().y() < this->height() - ui->label->height() - ui->BotonDetener->height() - 50 && band )
    {
        y+= 10;
        ui->label->setGeometry(x, y, ui->label->width(), ui->label->height());

        if( ui->label->geometry().y() > this->height() - ui->label->height() - ui->BotonDetener->height() - 50 )
        {
            band = false;
        }
    }
        else

    //SE MUEVE HACIA ARRIBA
    if( !band )
    {
        ui->label->setGeometry( x, y, ui->label->width(), ui->label->height() );
        y-= 10;

        if( y <= 0 )
        {
            band = true;
        }
    }

}


void Dialog::on_moverHorizontal_clicked()
{
    Timer = 1;
    setTimer();
}



void Dialog::on_moverVertical_clicked()
{
    Timer = 2;
    setTimer();
}

void Dialog::on_BotonDetener_clicked()
{
        if ( Timer == 1 )
        {
            timerHorizontal->stop();
        }

        else
            if ( Timer == 2 )
            {
                timerVertical->stop();
            }
}

