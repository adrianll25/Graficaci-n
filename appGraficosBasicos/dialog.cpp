#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    x1=y1=x2=y2 = 0;
    linea = circuloPitagoras = false;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *evt)
{
    Q_UNUSED(evt);
    canvas = new QPainter(this);

    //grafico Graficos;
    //Graficos.lineaDDA(x1, x2, y1, y2, canvas);
    grafico *graficos = new grafico();
    if(linea)
        graficos->lineaDDA(x1,y1,x2,y2,canvas);
    else if(circuloPitagoras)
        graficos->circuloPitagoras(xc,yc,radio,canvas);
    else if(circuloPolares)
        graficos->circuloPolares(xc,yc,radio,canvas);

    canvas->end();
}

void Dialog::mousePressEvent(QMouseEvent *event)
{
    //X1
    ui->lineEdit->setText(QString::number(event->pos().x()));
    //Y1
    ui->lineEdit_2->setText(QString::number(event->pos().y()));

}

void Dialog::mouseReleaseEvent(QMouseEvent *event)
{
    //X2
    ui->lineEdit_3->setText(QString::number(event->pos().x()));
    //Y2
    ui->lineEdit_4->setText(QString::number(event->pos().y()));

}

void Dialog::mouseMoveEvent(QMouseEvent *event)
{
    ui->lineEdit_3->setText(QString::number(event->pos().x()));
    ui->lineEdit_4->setText(QString::number(event->pos().y()));

    on_pushButton_clicked();
}

void Dialog::on_pushButton_clicked()//Trazar linea
{
    x1 = ui->lineEdit->text().toInt();
    x2 = ui->lineEdit_2->text().toInt();
    y1 = ui->lineEdit_3->text().toInt();
    y2 = ui->lineEdit_4->text().toInt();
    linea = true;
    update();

}

void Dialog::on_pushButton_2_clicked()//Colorear
{
    QColor colorSeleccionado = QColorDialog::getColor(Qt::white, this, "Seleccione el color: ");
    if(colorSeleccionado.isValid())
        color = colorSeleccionado;
}





void Dialog::on_pushButton_3_clicked()
{
    xc = ui->spinBox->value();
    yc = ui->spinBox_2->value();
    radio = ui->spinBox_3->value();
    circuloPitagoras=true;
    repaint();
}

void Dialog::on_pushButton_4_clicked()
{
    xc = ui->spinBox->value();
    yc = ui->spinBox_2->value();
    radio = ui->spinBox_3->value();
    circuloPolares=true;
    repaint();

}

void Dialog::on_pushButton_5_clicked()
{
    espiral1 = true;
    linea = circuloPitagoras = circuloPolares = espiral2 = false;
    update();

}

void Dialog::on_pushButton_6_clicked()
{
    espiral2 = true;
    linea = circuloPitagoras = circuloPolares = espiral1 = false;
    update();

}
