#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::keyPressEvent(QKeyEvent *EVT)
{
    if(EVT->key() == Qt::Key_Up)
        ui->label->setText("PRESIONASTE FLECHA ARRIBA");

    if(EVT->key() == Qt::Key_Down)
        ui->label->setText("PRESIONASTE FLECHA ABAJO");

    if(EVT->key() == Qt::Key_Left)
        ui->label->setText("PRESIONASTE FLECHA IZQUIERDA");

    if(EVT->key() == Qt::Key_Right)
        ui->label->setText("PRESIONASTE FLECHA DERECHA");

    /*ROTACION 2D TRANSFORMACION DE LOS PUNTOS DE UN OBJETO SITUADOS EN TRAYECTORIA CIRCULAR
      PARA ESTA TRANSFORMACION SE ESPECIFICA UN ANGULO DE ROTACION CON EL CUAL DETERMINAMOS
      EL GIRO DE CADA VERTICE DEL POLIGONO, SE UTILIZA LA SIG. MATRIZ*/
}
