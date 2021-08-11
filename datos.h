#ifndef DATOS_H
#define DATOS_H

#include <QObject>

class Datos : public QObject
{
    Q_OBJECT
public:
    explicit Datos(QObject *parent = nullptr);
    float peso() const;
    void setPeso(float peso);

    float altura() const;
    void setAltura(float altura);

private:
    float m_peso;
    float m_altura;
signals:

};

#endif // DATOS_H
