#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "resultados.h"
#include "controlador.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float PesoMaximo;
    float PesoMinimo;

private slots:
    void on_cmdCalcular_released();

private:
    Ui::MainWindow *ui;
   float validarPeso(QString peso);
   Controlador *m_controlador;
   float calcularIMC(QString peso, QString altura );
};
#endif // MAINWINDOW_H
