#ifndef RECTANGULOITEM_H
#define RECTANGULOITEM_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
class RectanguloItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit RectanguloItem(int ancho = 100, int alto = 100);//QObject *parent = nullptr);

    void keyPressEvent(QKeyEvent *evento);
signals:

private:
    int ancho, alto;
    QTimer *timer;

public slots:
    void mover();

};

#endif // RECTANGULOITEM_H
