#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BotonInciar_clicked();

    void on_BotonDetener_clicked();

    void MoverVerticalmente();
    void MoverHorizontalmente();

private:
    Ui::MainWindow *ui;
    QTimer *timerBalon;

};
#endif // MAINWINDOW_H
