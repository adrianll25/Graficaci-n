#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerBalon = new QTimer();
    connect(timerBalon, SIGNAL(timeout()), this, SLOT(MoverVerticalmente()));
    connect(timerBalon, SIGNAL(timeout()), this, SLOT(MoverHorizontalmente()));

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_BotonInciar_clicked()
{
    timerBalon->start(100);
}

void MainWindow::on_BotonDetener_clicked()
{
    timerBalon->stop();
}

void MainWindow::MoverVerticalmente()
{
    static int y = ui->label_2->geometry().y();
    static bool band = true;
    int x = ui->label_2->geometry().x();

    //SE MUEVE HACIA ABAJO
    if(x < ui->PorteriaFutbol->geometry().width()-ui->label_2->geometry().width()-10 && band )
    {
        y+= 10;
        ui->label_2->setGeometry(x, y, ui->label_2->width(), ui->label_2->height());

        if( ui->label_2->geometry().y() > this->height() - ui->label_2->height() - ui->BotonDetener->height() - 50 )
        {
            band = false;
        }
    }

    //SE MUEVE HACIA ARRIBA
    if( !band )
    {
        ui->label_2->setGeometry( x, y, ui->label_2->width(), ui->label_2->height() );
        y-= 10;

        if( y <= 0 )
        {
            band = true;
        }
    }

}


void MainWindow::MoverHorizontalmente()
{

    static int x = ui->label_2->geometry().x();
    static bool band = true;
    int y = ui->label_2->geometry().y();

    //Derecha
    if( x < ui->PorteriaFutbol->geometry().width()-ui->label_2->geometry().width()-10 && band )
    {
        ui->label_2->setGeometry(x, y, ui->label_2->width(), ui->label_2->height());
        x+= 10;

        if(ui->label_2->geometry().x() > this->width() - ui->label_2->width())
        {
            band = false;
        }
    }

     //Izquierda
    if(!band)
    {
        x-= 10;
        ui->label_2->setGeometry(x, y, ui->label_2->width(), ui->label_2->height());

        if(x <= 0)
        {
            band = true;
        }
    }
}
