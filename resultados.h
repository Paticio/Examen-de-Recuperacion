#ifndef RESULTADOS_H
#define RESULTADOS_H

#include <QDir>
#include <QDialog>
#include <QDate>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
class Resultados;
}

class Resultados : public QDialog
{
    Q_OBJECT

public:
    explicit Resultados(QWidget *parent = nullptr,QString peso=nullptr,QString altura=nullptr, float PesoMaximo = 0, float PesoMinimo = 0,float imc = 0 );
    ~Resultados();

private slots:
    void on_cmdGuradar_released();

private:
    Ui::Resultados *ui;
    QPixmap lienzo;
    QImage imagen;
    QString nombre;
    void dibujar(QString peso,QString altura, float PesoMaximo, float PesoMinimo, float imc);

void dibujarGrafico(float imc);
};

#endif // RESULTADOS_H
