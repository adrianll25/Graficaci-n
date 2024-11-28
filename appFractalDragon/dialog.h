#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "graficos.h"
#include <conio.h>
#include <stdio.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Dialog *ui;

    void paintEvent(QPaintEvent *e)override;
    void dragon();
    void extranioConfinador (QPainter *canvas);
    void extranioConfinadorM (QPainter *canvas);
    void extranioConfinadorM2 (QPainter *canvas);
    void Henon();
    void arabesco();
    void Malthius();
    void Malthius2();
    void generarDragon(QPainter *canvas);
    void generarArabesco(QPainter *canvas);
    void Maldelbrot();
    void Pausa();
    int ejeX[4098], ejeY[4098], paso;
    int signo;
    int maxColores;
    int maxX, maxY;
    double EscalaX, EscalaY, DespX, DespY;
    bool formarDragon = false;
    bool formarHenon = false;
    bool formarArabesco = false;
    bool formarMalthius = false;
    bool formarMalthius2 = false;
    bool formarMaldebrot = false;


};
#endif // DIALOG_H
