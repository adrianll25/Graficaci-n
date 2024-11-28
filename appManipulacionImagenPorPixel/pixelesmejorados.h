#ifndef PIXELESMEJORADOS_H
#define PIXELESMEJORADOS_H

#include <QDialog>
#include <QImage>
#include <QFileDialog>

#include "modificarimagen.h"

namespace Ui {
class PixelesMejorados;
}

class PixelesMejorados : public QDialog
{
    Q_OBJECT

public:
    explicit PixelesMejorados(QWidget *parent = nullptr);
    ~PixelesMejorados();

    QImage modificarImagenRGB(const QImage &in, int r, int g, int b);

private slots:


    void on_AbrirImagen_clicked();

    void on_NuevoProyecto_clicked();

    void on_BotonPink_clicked();

    void on_BotonVintage_clicked();

    void on_BotonDark_clicked();

    void on_BotonCinema_clicked();

    void on_BotonStory_clicked();

    void on_BotonJALL_clicked();

    void on_BotonFilm_clicked();

    void on_BotonSkin_clicked();

    void on_BotonRed_clicked();

    void on_BotonBlue_clicked();

    void on_BotonGreen_clicked();

    void on_BotonRazer_clicked();

private:
    Ui::PixelesMejorados *ui;
    ModificarImagen *ImagenModificada = new ModificarImagen();
};

#endif // PIXELESMEJORADOS_H
