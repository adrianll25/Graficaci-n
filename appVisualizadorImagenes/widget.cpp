#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QPixmap imagen("pez2.png");
    QPixmap imagen("C:\\Users\\adria\\Desktop\\IMAGENES\\Gatos.gif");
    ui->label->setPixmap(imagen);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    QFileDialog dialogo(this);
    dialogo.setNameFilter("Imagenes ( *.png *.bmp *.jpg *.jpeg *.gif )");
    dialogo.setViewMode(QFileDialog::Detail);

    QString nomarch = QFileDialog::getOpenFileName(this, "Abrir Imagen",
                                                   "C:\\Users\\adria\\Desktop\\IMAGENES\\",
                                                   "Imagenes ( *.png *.bmp *.jpg *.jpeg *.gif )");


    if(!nomarch.isEmpty())
    {
        QImage imagen(nomarch);
        ui->label->setPixmap(QPixmap::fromImage(imagen));
        ui->label->setScaledContents(true);
    }


}
