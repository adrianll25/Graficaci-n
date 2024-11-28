#include "pixelesmejorados.h"
#include "ui_pixelesmejorados.h"

PixelesMejorados::PixelesMejorados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PixelesMejorados)
{
    ui->setupUi(this);

}

PixelesMejorados::~PixelesMejorados()
{
    delete ui;
}

QString path;


void PixelesMejorados::on_AbrirImagen_clicked()
{
    QFileDialog dialogo(this);
    dialogo.setNameFilter("Imagenes ( *.png *.bmp *.jpg *.jpeg *.gif )");
    dialogo.setViewMode(QFileDialog::Detail);

    QString nomarch = QFileDialog::getOpenFileName(this, "Abrir Imagen",
                                                   "C:\\",
                                                   "Imagenes ( *.png *.bmp *.jpg *.jpeg *.gif )");


    if(!nomarch.isEmpty())
    {
        path=nomarch;
        QImage imagen(nomarch);
        ui->ImageOriginal->setPixmap(QPixmap::fromImage(imagen));
        ui->ImageOriginal->setScaledContents(true);
    }
}


void PixelesMejorados::on_NuevoProyecto_clicked()
{
    ui->ImageOriginal->setText("IMAGEN ORIGINAL");
    ui->ImagenEditada->setText("IMAGEN EDITADA");

}

void PixelesMejorados::on_BotonPink_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 112, 33, 45);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonVintage_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 5, 4, 8);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonDark_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 230, 230, 255);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonCinema_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 211, 212, 213);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonStory_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 20, 40, 60);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonJALL_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 28, 16, 56);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonFilm_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 33,66,99);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonSkin_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 103, 255, 159);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonRed_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 198, 20, 20);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonBlue_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 255, 74, 152);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonGreen_clicked()
{
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 85, 66, 6);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);

}

void PixelesMejorados::on_BotonRazer_clicked()
{
    //QPixmap const *pm = ui->ImageOriginal->pixmap();
    //img = pm->toImage();
    QImage imagen(path);
    imagen=ImagenModificada->modificarImagenRGB(imagen, 135,45,236);
    ui->ImagenEditada->setPixmap(QPixmap::fromImage(imagen));
    ui->ImagenEditada->setScaledContents(true);
}
