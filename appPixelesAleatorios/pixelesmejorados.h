#ifndef PIXELESMEJORADOS_H
#define PIXELESMEJORADOS_H

#include <QDialog>
#include <QPainter>
#include <QTimer>

namespace Ui {
class PixelesMejorados;
}

class PixelesMejorados : public QDialog
{
    Q_OBJECT

public:
    explicit PixelesMejorados(QWidget *parent = nullptr);
    ~PixelesMejorados();

private slots:
    void on_BotonIniciar_clicked();

    void on_BotonDetener_clicked();

    void on_dialRojo_valueChanged(int value);

    void on_dialVerde_valueChanged(int value);

    void on_dialAzul_valueChanged(int value);

    void on_spinBoxRojo_valueChanged(int arg1);

    void on_spinBoxVerde_valueChanged(int arg1);

    void on_spinBoxAzul_valueChanged(int arg1);

private:
    Ui::PixelesMejorados *ui;
    QTimer *timer;

    void paintEvent ( QPaintEvent *evt ) override;

    void pixeles ();
};

#endif // PIXELESMEJORADOS_H
