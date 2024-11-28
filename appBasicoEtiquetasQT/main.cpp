//#include <QCoreApplication>
  #include <QApplication>
  #include <QLabel>
  #include <QWidget>
  #include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Estatico
/*
    QLabel etiqueta("TEC LAGUNA");
    etiqueta.show();
*/
    //Dinamico
/*
    QLabel *etiqueta = new QLabel("TEC LAGUNA");
    etiqueta->show();
*/
    //QWidget ventana;                //Se envia la referencia &
    //QVBoxLayout *layoutPrincipal = new QVBoxLayout(&ventana);

    QWidget *ventana = new QWidget();              //Se envia la referencia & (En los punteros esta implicita)
    //QVBoxLayout *layoutPrincipal = new QVBoxLayout(ventana);
    QHBoxLayout *layoutPrincipal = new QHBoxLayout(ventana);


    //Etiqueta italica
    QLabel *etiqueta1 = new QLabel("<h6><i>ETIQUETA 1, PRACTICANDO CON </i>""<font color = #ff0000> QT 5 </font></h6>");

    etiqueta1->setFrameStyle(QFrame::Panel | QFrame::Box);

    QLabel *etiqueta2 = new QLabel("<h6><b>ETIQUETA 2, PRACTICANDO CON </b>""<font color = #7FFFD4> QT 5 </font></h6>");

    etiqueta2->setAlignment(Qt::AlignBottom | Qt::AlignRight);

    QLabel *etiqueta3 = new QLabel("<h6><u>ETIQUETA 3, PRACTICANDO CON</u>""<font color = #7FFF00> QT 5 </font></h6");
    etiqueta3->setAlignment(Qt::AlignCenter | Qt::AlignHCenter);

    QLabel *etiqueta4 = new QLabel("<h6><code>ETIQUETA 4, PRACTICANDO CON</code>""<font color = #008B8B> QT 5 </font></h6");
    etiqueta3->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    QLabel *etiqueta5 = new QLabel("<h6><del>ETIQUETA 5, PRACTICANDO CON</del>""<font color = #FFFF00> QT 5 </font></h6");
    etiqueta3->setAlignment(Qt::AlignBottom | Qt::AlignJustify);


    layoutPrincipal->addWidget(etiqueta1);
    layoutPrincipal->addWidget(etiqueta2);
    layoutPrincipal->addWidget(etiqueta3);
    layoutPrincipal->addWidget(etiqueta4);
    layoutPrincipal->addWidget(etiqueta5);

    //ventana.resize(400,400);
    //ventana.show();

    ventana->resize(400, 400);
    ventana->show();

    return a.exec();
}
