#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QImage>
#include "pixelesmejorados.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

    QImage modificarImagenRGB(const QImage &in);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
    PixelesMejorados *pix;

};
#endif // DIALOG_H
