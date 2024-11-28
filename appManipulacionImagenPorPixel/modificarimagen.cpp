#include "modificarimagen.h"

ModificarImagen::ModificarImagen()
{

}

QImage ModificarImagen::modificarImagenRGB(const QImage &in, int r, int g, int b)
{
    //ASIGNAMOS EL TAMAÑO DE LA IMAGEN DE ENTRADA (in) Y SU FORMATO
    QImage out(in.size(), in.format());

    //RECORREMOS EL ARREGLO BIDIMENSIONAL DE LA IMAGEN (PIXELES QUE LO COMPONEN)
    for(int linea = 0; linea <in.height(); linea++)
    {
        const QRgb *inPixel = reinterpret_cast<const QRgb*>(in.scanLine(linea));
        QRgb *outPixeles = reinterpret_cast<QRgb *>(out.scanLine(linea));

        //RECORREMOS IMAGEN POR COLUMNA
        for(int pos = 0; pos < in.width(); pos++)
        {
            int red = qRed(inPixel[pos]);
            int green = qGreen(inPixel[pos]);
            int blue = qBlue(inPixel[pos]);
            int alpha = qAlpha(inPixel[pos]);

            outPixeles[pos] = qRgba(red+r, green+g, blue+b, alpha);

            //outPixeles[pos] = qRgba(red, green, blue, alpha);
            //outPixeles[pos] = qRgba(blue, red, green, alpha);
            //outPixeles[pos] = qRgba(green, blue, red, alpha);
            //outPixeles[pos] = qRgba(red, 0, 0, alpha);
            //outPixeles[pos] = qRgba(0, green, 0, alpha);
            //outPixeles[pos] = qRgba(0, 0, blue, alpha);
            // outPixeles[pos] = qRgba(blue, blue, blue, alpha);

            //APLICANDO CORRIMIENTO DE BITS

            //outPixeles[pos] = qRgba(0, green<<3, 0, alpha);
            //outPixeles[pos] = qRgba( green<<3,0, 0, alpha);

            //APLICAR OPERADORES A NIVEL DE BIT

            //outPixeles[pos] = qRgba( red & 0x0000fa, (green & 0x00aa00) <<1, blue & 0xcc0000 , alpha);
            //outPixeles[pos] = qRgba( red ^ 0x0000fa, green ^ 0x00aa00 <<1, blue ^ 0xcc0000 , alpha);
            //outPixeles[pos] = qRgba( red ^ 0x0000fa, green ^ 0x00aa00, blue ^ 0xcc0000 , alpha);




        }

    }

    return out;
}
