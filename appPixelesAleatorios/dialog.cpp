#include "dialog.h"
#include "ui_dialog.h"
#include "pixelesmejorados.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    timer = new QTimer();
    //connect(timer,SIGNAL(timeout()),this,SLOT(repaint()));
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *evt)
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

void Dialog::pixeles()
{
    QPainter canvas(this);
    for(int i = 0; i < 1000; i++)
    {
        QPen pen1(QColor(255,0,0));
        pen1.setWidth(3);
        canvas.setPen(pen1);        //x                 //y
        canvas.drawPoint(rand()%this->width()/2,(rand()%height()-50)/2);
    }

    for(int i = 0; i < 1000; i++)
    {
        QPen pen1(QColor(0,255,0));
        pen1.setWidth(3);
        canvas.setPen(pen1);
        canvas.drawPoint(rand()%this->width()/2+(this->width()/2),(rand()%height()-50)/2);
    }

    for(int i = 0; i < 1000; i++)
    {
        QPen pen1(QColor(0,0,255));
        pen1.setWidth(3);
        canvas.setPen(pen1);
        canvas.drawPoint(rand()%this->width()/2,(rand()%height())/2+(this->height()-60)/2);
    }

    for(int i = 0; i < 1000; i++)
    {
        QPen pen1(QColor(255,255,0));
        pen1.setWidth(3);
        canvas.setPen(pen1);
        canvas.drawPoint(rand()%this->width()/2+(this->width()/2),(rand()%height())/2+(this->height()-60)/2);
    }
}

void Dialog::on_pushButton_clicked()
{
    timer->start(30);
}

void Dialog::on_pushButton_2_clicked()
{
    timer->stop();
}

void Dialog::on_pushButton_3_clicked()
{
    close();
}

void Dialog::on_pushButton_4_clicked()
{
    //PixelesMejorados pix;
    //pix.setModal(true);
    //pix.exec();
    pix = new PixelesMejorados(this);
    pix->show();

}
