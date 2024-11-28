#ifndef MODIFICARIMAGEN_H
#define MODIFICARIMAGEN_H

#include <QImage>
#include <QDialog>


class ModificarImagen
{

public:
    ModificarImagen();
    QImage modificarImagenRGB(const QImage &in, int r, int g, int b);
};

#endif // MODIFICARIMAGEN_H
