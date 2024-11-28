#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
#include <QPushButton>
#include <QHBoxLayout>
#include <QObject>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget ventana;
    //QVBoxLayout *layoutPrincipal = new QVBoxLayout(&ventana);
    //QHBoxLayout *layoutPrincipal = new QHBoxLayout(&ventana);

    QGridLayout *gridlayout = new QGridLayout(&ventana);

    QLabel *label = new QLabel("0");
    QSpinBox *spinBox = new QSpinBox();
    QSlider *slider = new QSlider(Qt::Horizontal);
    QPushButton *boton1 = new QPushButton("Salir");
    QPushButton *boton2 = new QPushButton("Sumar");

    /*layoutPrincipal->addWidget(label);
    layoutPrincipal->addWidget(spinBox);
    layoutPrincipal->addWidget(slider);
    layoutPrincipal->addWidget(boton1);
    */
    //layoutPrincipal->addWidget(boton2);

    gridlayout -> addWidget(label,0,0,1,1);
    gridlayout ->addWidget(spinBox, 0,1,1,1);
    gridlayout->addWidget(slider,1,0,1,3);
    gridlayout->addWidget(boton1, 2,0,1,1);
    gridlayout->addWidget(boton2, 2,1,1,1);


    QObject::connect(spinBox, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), label, SLOT(setNum(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(boton1, SIGNAL(clicked()), qApp,SLOT(quit));
    ventana.show();

    return a.exec();


}
