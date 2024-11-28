#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QTimer>

#include "mapeo.h"
#include "matrix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void paintEvent(QPaintEvent *event);
    void asignarFigura();
    void dibujarFigura(); //Ya no se va a utilizar
    void dibujarFiguraMapeada();

    void trasladar( int tx, int ty);
    void escalar(float, float);
    void escalarPuntoFijo(float sX, float sY, int pfx, int pfy);

    void rotacion(double ang);
    void rotarPuntoFijo(float angulo, float pfX, float pfY);
    void rotarAnimacion1();
    void rotarAnimacion2();

private slots:
    void on_Boton1_clicked();

    void on_Boton2_clicked();

    void on_Boton3_clicked();

    void on_Boton4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_btnRotar_clicked();

    //Animaciones
    void moverGato();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Dialog *ui;

    QPainter *canvas;

    float Fig[32][32];
    float FigAux[32][32];

    int ancho; //Ancho del area de dibujo
    int centroX, centroY;

    QTimer *timer1, *timer2, *timer3;

    //TRASLACION
    int tx, ty;


};
#endif // DIALOG_H
