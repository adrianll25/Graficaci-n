#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>
#include <QtGui>


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

    void moverEtiqueta();

    void moverEtiquetaVeriticalmente();

    void setTimer();

    void on_moverHorizontal_clicked();

    void on_moverVertical_clicked();

    void on_BotonDetener_clicked();

private:
    Ui::Dialog *ui;

    QTimer *timerHorizontal;
    QTimer *timerVertical;
};
#endif // DIALOG_H
