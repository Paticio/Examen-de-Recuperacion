#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDate fecha = QDate::currentDate();
    ui->outFecha->setText(fecha.toString("dd-MM-yyyy"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmdCalcular_released()
{
    QString altura;
    QString peso;
    altura = ui->inAltura->text();
    peso = ui->inPeso->text();
    this->validarPeso(peso);

    Resultados *resultados = new Resultados(this,peso,altura,PesoMaximo, PesoMinimo, this->calcularIMC(peso,altura));
    m_controlador->guardarRegistro(peso, altura,this->calcularIMC(peso,altura));
    resultados->exec();

}

float MainWindow::validarPeso(QString peso)
{

    m_controlador->cargarpeso(PesoMaximo, PesoMinimo);

    if(peso.toFloat() > PesoMaximo){
        PesoMaximo = peso.toFloat();
    }
    if(peso.toFloat() < PesoMinimo){
        PesoMinimo = peso.toFloat();

    }

    m_controlador->guardarpeso(PesoMaximo, PesoMinimo);
}

float MainWindow::calcularIMC(QString peso, QString altura)
{
    float alt2 = altura.toFloat()* altura.toFloat();
    float imc = peso.toFloat()/alt2;
    return imc;


}
