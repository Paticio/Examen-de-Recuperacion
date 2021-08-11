#include "controlador.h"
#include <QDate>

Controlador::Controlador(QObject *parent) : QObject(parent)
{

}

float Controlador::validarPeso(QString peso)
{

    if(peso.toFloat() > PesoMaximo){
        PesoMaximo = peso.toFloat();
    }else if(peso.toFloat() < PesoMinimo){
        PesoMinimo = peso.toFloat();

    }



}

void Controlador::guardarpeso(float PesoMaximo, float PesoMinimo)
{
    QFile votos("peso.csv");
    QTextStream io;
    io.setDevice(&votos);
    votos.open(QIODevice::ReadWrite | QIODevice::Text);

    io << "PesoMaximo; " << PesoMaximo << endl;
    io << "PesoMinimo; " << PesoMinimo << endl;
    votos.close();

}

void Controlador::cargarpeso(float &PesoMaximo, float &PesoMinimo)
{
     QFile votos("peso.csv");
    QTextStream io;
    io.setDevice(&votos);
    votos.open(QIODevice::ReadWrite | QIODevice::Text);
    if(!votos.isOpen())
    {
        QMessageBox::information(0, tr("Aviso"), tr("Error de Apertura"));
    }
    io.setDevice(&votos);

    while(!io.atEnd())
    {
        auto linea = io.readLine();
        auto valores =linea.split(";");
        int numeroColumnas = valores.size();
        for(int i = 0; i< numeroColumnas; i++)
        {
            if(valores.at(0) == "PesoMaximo")
            {
                PesoMaximo = (valores.at(1).toFloat());
            }
            else if(valores.at(0) == "PesoMinimo")
            {
                PesoMinimo = (valores.at(1).toFloat());
            }

        }

    }
}

void Controlador::guardarRegistro(QString peso, QString altura, float imc)
{
    QFile votos("registro.csv");
    QTextStream io;
    io.setDevice(&votos);
    votos.open(QIODevice::ReadWrite | QIODevice::Text);

    io << "Altura; " << altura << endl;
    io << "Peso; " << peso << endl;
    io << "IMC; " << imc << endl;
    io << "Fecha; " << QDate::currentDate().toString("dd-MM-yyyy") << endl;
    votos.close();
}
