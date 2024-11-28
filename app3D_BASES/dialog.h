#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPainter>
#include <QKeyEvent>
#include "mapeo.h"
#include <math.h>
#include <QtMath>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

#define radianes (g) ((double)(g)*M_PI/180.0)

struct Puntos3D
{
    int x, y, z;
    bool opcion;
};

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    void asignaCubo();
    void paintEvent (QPaintEvent *evento);
    void keyPressEvent ( QKeyEvent *e);
    void asignacion ();
    void proyeccionCubo ();
    void dibujarCubo ();
    void inicializarPuerto ();

    void lineTo3D ( int x, int y, int z, float alpha, float phi, int i );
    void moveTo3D ( int x, int y, int z, float alpha, float phi, int i );

private slots:
    void on_dial_sliderMoved(int position);

    void on_dial_2_valueChanged(int value);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_checkBox_clicked();

private:
    Ui::Dialog *ui;

    QPainter *canvas;
    QPointF points [16];

    Puntos3D *cubo;

    Mapeo mapeo;
    int L;
    int M;
    int ancho;
    float Alpha;
    float Phi;

    int tX, tY, tZ;

    //rotacion 3d
    bool rX, rY, rZ, habTeclado = false;
    int xC, yC, zC;
    float anguloX, anguloY, anguloZ;
};
#endif // DIALOG_H
