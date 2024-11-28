#include <QApplication>
#include <QWidget>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *widget = new QWidget();

    widget -> setGeometry(100,100,300,300);

    QPalette paleta (widget->palette());

    //paleta.setColor(QPalette::Background, Qt::blue);

    //paleta.setColor(QPalette::Window, QColor(Qt::green));

    //paleta.setColor(QPalette::Window, QColor::fromRgb(100,100,0));

    //paleta.setColor(QPalette::Window, QColor(16711680)); //ROJO; ESTAN INVERTIDOS
    //paleta.setColor(QPalette::Window, QColor(65280)); // VERDE;
    //paleta.setColor(QPalette::Window, QColor(255)); // ROJO

    int color = 16777215;//24 bits USAR OPERACIONES  A NIVEL DE BIT
      //color &= 65280; //Verde
      //color &= 16711680;//Rojo
      //color &= 66047;//Azul

    color |= 16711680;


    paleta.setColor(QPalette::Window, QColor(color));

    //INVESTIGAR EL QRANDOMGENERATOR
    //srand(time(NULL));

    //paleta.setColor(QPalette::Window, QColor::fromRgb(rand()%155+100, rand()%155+100, rand()%155+100));

    //!Utilizando 3 variables, una para cada color.
     //int r, g, b;

     //Valores enteros
     //r = 51;
     //g = 154;
     //b = 154;

     //Valores binarios
     //r = 0b00110011;
     //g = 0b10011010;
     //b = 0b10011010;

     //paleta.setColor(QPalette::Window, QColor(r,g,b));

     /*
     //!Utilizando una sola variable.
     int rgb;

     rgb = 0b001100111001101010011010;

     rgb = rgb >> 16;
     //!                                      R         v         A
     //!Despues del desplazamiento queda, 0000 0000 0000 0000 0011 0011
     rgb = rgb << 16;
     //!                                      R         V        A
     //!Despues del desplazamiento queda, 0011 0011 0000 0000 0000 0000

    paleta.setColor(QPalette::Window, QColor(rgb));

    */

    widget->setAutoFillBackground(true);
    widget->setPalette(paleta);

    //ESTUDIAR LOS OPERADORES A NIVEL DE BIT(BITWISE)
    //EVALUACION PROX LUNES

    widget->show();

    return a.exec();

}
