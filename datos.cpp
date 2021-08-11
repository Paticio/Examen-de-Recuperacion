#include "datos.h"

Datos::Datos(QObject *parent) : QObject(parent)
{

}

float Datos::peso() const
{
    return m_peso;
}

void Datos::setPeso(float peso)
{
    m_peso = peso;
}

float Datos::altura() const
{
    return m_altura;
}

void Datos::setAltura(float altura)
{
    m_altura = altura;
}
