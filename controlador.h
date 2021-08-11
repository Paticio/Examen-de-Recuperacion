#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include <QObject>
#include <QMessageBox>
#include <QDir>
#include <QTextStream>
#include <QFile>

class Controlador : public QObject
{
    Q_OBJECT
public:
    explicit Controlador(QObject *parent = nullptr);
    float validarPeso(QString peso);
    float PesoMaximo;
    float PesoMinimo;
    void guardarpeso(float PesoMaximo, float PesoMinimo);
    void cargarpeso(float &PesoMaximo, float &PesoMinimo);
    void guardarRegistro(QString peso, QString altura, float imc );

signals:

};

#endif // CONTROLADOR_H
