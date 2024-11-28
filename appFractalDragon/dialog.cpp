#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    signo = -1;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    if(formarDragon)
        dragon();
    if(formarHenon)
        Henon();
    if(formarArabesco)
        arabesco();
    if(formarMalthius)
        Malthius();
    if(formarMalthius2)
        Malthius2();
    if(formarMaldebrot)
        Maldelbrot();

    formarDragon = false;
    formarHenon = false;
    formarArabesco = false;
    formarMalthius = false;
    formarMalthius2 = false;
    formarMaldebrot = false;

}

void Dialog::dragon()
{
    QPainter canvas (this);
    int i;
    paso = 4096;
    ejeX[1] = canvas.window().width()/4;
    ejeX[4097] = 3 * canvas.window().width()/4;
    ejeY[1] = ejeY[4097] = canvas.window().height()/2;
    canvas.setPen(QColor(50,50,200));

    //DIBUJAR LA PRIMER LINEA
    for ( i = 1; i<= 13; i++)
    {
        generarDragon ( &canvas );
        paso /=2;
    }
}

void Dialog::generarDragon(QPainter *canvas)
{
    int j, dx, dy;
    j = paso / 2;
    //TERMINAR DE CODIFICAR
    canvas->setPen(QColor(0,0, qrand()%155 + 100));
    for(int i = 1; i <= 4096; i+= paso)
    {
        dx = ejeX [paso+i] - ejeX[i];
        dy = ejeY [paso+i] - ejeY[i];
        signo *= -1;

        ejeX [i+j] = ejeX[i] + ( dx + ( dy * signo ))/2;
        ejeY [i+j] = ejeY[i] + ( dy - ( dx * signo ))/2;

        canvas->drawLine(ejeX[i], ejeY[i], ejeX[i+j], ejeY[i+j]);
        canvas->drawLine(ejeX[i], ejeY[i], ejeX[i+j], ejeY[i+j]);


    }

}

void Dialog::Henon()
{
    QPainter canvas (this);
    EscalaX = 1;
    EscalaY = 1;
    DespX = 0;
    DespY = 0;
    maxX = canvas.window().width();
    maxY = canvas.window().height();
    extranioConfinador(&canvas);
}

void Dialog::arabesco()
{
    QPainter canvas (this);
    int i;
    paso = 4096;
    ejeX[1] = canvas.window().width()/4;
    ejeX[4097] = 3 * canvas.window().width()/4;
    ejeY[1] = ejeY[4097] = canvas.window().height()/2;
    canvas.setPen(QColor(50,50,200));

    //DIBUJAR LA PRIMER LINEA
    for ( i = 1; i<= 13; i++)
    {
        generarArabesco( &canvas );
        paso /=2;
    }

}

void Dialog::generarArabesco(QPainter *canvas)
{
    int j, dx, dy;
    j = paso / 2;
    //TERMINAR DE CODIFICAR
    canvas->setPen(QColor(0,0, qrand()%155 + 100));
    for(int i = 1; i <= 4096; i+= paso)
    {
        dx = ejeX [paso+i] - ejeX[i];
        dy = ejeY [paso+i] - ejeY[i];
        //signo *= -1;

        ejeX [i+j] = ejeX[i] + ( dx + ( dy * signo ))/2;
        ejeY [i+j] = ejeY[i] + ( dy - ( dx * signo ))/2;

        canvas->drawLine(ejeX[i], ejeY[i], ejeX[i+j], ejeY[i+j]);
        canvas->drawLine(ejeX[i], ejeY[i], ejeX[i+j], ejeY[i+j]);

    }

}

void Dialog::Maldelbrot()
{
    QPainter canvas ( this );
    int maxX, maxY, Limite, i, j, Pasos, Terminar;
    double PasoX, PasoY, PosX, PosY, OrigX, OrigY, DimX, DimY, IterX, IterY, TempX;
    maxX = canvas.window().width();
    maxY = canvas.window().height();
    Limite = 100;

    OrigX = -2.0;
    OrigY = -1.25;
    DimX = 0.5;
    DimY = 1.25;

    PasoX = ( DimX - OrigX ) / maxX;
    PasoY = ( DimY - OrigY ) / maxY;
    for ( i =0; i <= maxX; i++ )
        for ( j = 0; j <= maxY; j++ )
        {
            PosX = OrigX + i * PasoX;
            PosY = OrigY + j * PasoY;
            IterX = 0.0;
            IterY = 0.0;
            Terminar = Pasos = 0;

            while ( !Terminar )
            {
                TempX = ( IterX * IterX ) - ( IterY * IterY ) + PosX;
                IterY = 2 * ( IterX * IterY ) + PosY;
                IterX = TempX;
                Pasos++;
                if ( hypot ( fabs ( IterX ), fabs ( IterY ) ) >= 2.0 )
                    Terminar++;
                if ( Pasos >= Limite )
                    Terminar++;
                if ( kbhit() )
                {
                    i = maxX;
                    j = maxY;
                    Terminar ++;
                }
            }
            if ( Pasos < Limite )
                canvas.setPen ( qRgb(qrand()%255, qrand()%255, qrand()%255) );
                canvas.drawPoint ( i,j );
        }
    Pausa ();
}

void Dialog::Pausa()
{
    while ( kbhit() )
        getch ();
    getch;
}

void Dialog::Malthius()
{
    QPainter canvas ( this );
    maxX = canvas.window().width();
    maxY = canvas.window().height();
    extranioConfinadorM (&canvas);

}

void Dialog::Malthius2()
{
    QPainter canvas ( this );
    maxX = canvas.window().width();
    maxY = canvas.window().height();
    extranioConfinadorM2 (&canvas);

}

void Dialog::extranioConfinador(QPainter *canvas)
{
    int a, i, Color, PosX, PosY;
    double Xant, Xnuevo, Yant, Ynuevo;
    Xant = Xnuevo = Yant = Ynuevo = 0;

    for ( Color = 1; Color <= 15; Color++ )
    {
        for ( i = 1; i<= 0x02FF; i++ )
        {
            canvas->setPen ( Color );
            Xnuevo = Yant + 1 - ( 1.4 * Xant * Xant );
            Ynuevo = 0.3 * Xant;
            PosX = ( Xnuevo * maxX / 3 * EscalaX ) + maxX / 2 + DespX;
            PosY = ( Ynuevo * maxY * EscalaY ) + maxY / 2 + DespY;
            if ( ( PosX >= 0 ) && ( PosX <= maxX ) && ( PosY >= 0 ) && ( PosY <= maxY ) )
                canvas->drawPoint ( PosX, PosY );
            Yant = Ynuevo;
            Xant = Xnuevo;
        }
    }

}

void Dialog::extranioConfinadorM(QPainter *canvas)
{
    int i, j, k, l , Color, Contador, X, Y;
    double PobAnt, PobNueva, Razon;

    PobNueva = 0.0;
    Razon = 2.3;
    Color = 0x000000;
    for ( j = 1; j <= 151; j++ )
    {
        Color ++;
        if ( Color >= 0x7FFFD4 )
            Color = 0x0000FF;
        Contador = 0;
        Razon += 0.01;
        PobAnt = 0.01;
        for ( i = 1; i <= 0x00FF; i++ )
        {
            PobNueva = Razon * ( PobAnt * ( 1 - PobAnt ) );
            X = PobAnt * maxX;
            Y = maxY - ( PobNueva * maxY );
            canvas->setPen ( Color );
            canvas->drawPoint ( X, Y );
            if ( PobAnt == PobNueva )
                Contador++;
            else if ( Contador > 10 )
                i = 0x00FF;

            PobAnt = PobNueva;
        }
    }

}

void Dialog::extranioConfinadorM2(QPainter *canvas)
{
    int i, j, k, l, Color, Contador;
    double PobAnt, PobNueva, X, Y, Razon;

    PobAnt = PobNueva = 0.0;
    Razon = 2.3;
    Y = 0;
    for ( j = 1; j <= 15 ; j++ )
    {
        Color ++;
        if ( Color > 0xFF00FF )
            Color = 0x0000FF;
        for ( k = 1; k <= 10; k++ )
        {
            Contador = 0;
            Razon = Razon + 0.01;
            PobAnt = 0.01;
            for ( int i = 1 ; i <= 1000 ; i++ )
            {
                PobNueva = Razon * ( PobAnt * ( 1 - PobAnt ) );
                X = PobNueva - PobAnt;
                canvas->setPen ( Color );
                canvas->drawPoint ( ( X * maxX /2 ) + maxX / 2, ( maxY / 2 ) - ( Y * maxY / 2 ) );
                if ( PobAnt == PobNueva )
                    Contador++;
                else
                    Contador = 0;
                if ( Contador > 100 )
                    i = 10000;
                PobAnt = PobNueva;
                Y = X;
            }
        }
    }

}

void Dialog::on_pushButton_clicked()
{
    formarDragon = true;
    update();
}

void Dialog::on_pushButton_3_clicked()
{
    formarHenon = true;
    update();
}

void Dialog::on_pushButton_2_clicked()
{
    formarArabesco = true;
    update();
}

void Dialog::on_pushButton_4_clicked()
{
    formarMalthius = true;
    update();
}

void Dialog::on_pushButton_5_clicked()
{
    formarMalthius2 = true;
    update();

}

void Dialog::on_pushButton_6_clicked()
{
    formarMaldebrot = true;
    update();

}
