#include "resultados.h"
#include "ui_resultados.h"

Resultados::Resultados(QWidget *parent, QString peso,QString altura, float PesoMaximo , float PesoMinimo, float imc) :
    QDialog(parent),
    ui(new Ui::Resultados)
{
    ui->setupUi(this);
    lienzo = QPixmap(523,500);
    this->dibujar(peso,altura, PesoMaximo, PesoMinimo, imc);
}

Resultados::~Resultados()
{
    delete ui;
}

void Resultados::on_cmdGuradar_released()
{
    //Crear un objeto QDir a partir del directorio del usuario
        QDir directorio = QDir::home();

        //Agregar al path absoluto del objeto un nombre por defecto del archivo
        QString pathArchivo = directorio.absolutePath();

        QString nombreArchivo = QFileDialog::getSaveFileName(
                    this,"Guardar imagen",pathArchivo,"Imagenes (*.png)");
        if (!nombreArchivo.isEmpty()){
            if (lienzo.save(nombreArchivo))
                QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
            else
                QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
        }
        this->close();
}

void Resultados::dibujar(QString peso,QString altura, float PesoMaximo, float PesoMinimo, float imc)
{
    QDate fecha = QDate::currentDate();
    //Rellenar el lienzo de color blanco
    lienzo.fill(Qt::white);

    //Crear el pintor
    QPainter painter(&lienzo);

    int x = 50;
    int y = 50;
    painter.setFont(QFont("Arial", 10));
    painter.drawText(x,y,"Actual: " + peso);
    painter.drawText(x,y+20,"Peso Maximo: " + QString::number(PesoMaximo,'f',2));
    painter.drawText(x,y+40,"Peso Minimo: " + QString::number(PesoMinimo,'f',2));
    painter.drawText(x,y+60,"imc(kg/mʌ2):" + QString::number(imc,'f',2));
    painter.drawText(x,y+80,"Altura:" + altura);
    painter.drawText(x+200, y+110,tr("Fecha: ") + fecha.toString("dd-MM-yyyy"));
    painter.setFont(QFont("Arial Bold",6));
    QColor color1(210,226,221);
    QColor color2(85,108,137);
    QColor color3(112,215,121);
    QColor color4(238,239,195);
    QColor color5(236,200,97);
    QColor color6(232,69,82);
    y = 200;
    int alto = 50;
    painter.drawText(x,y+alto + 20,"15");
    painter.drawText(x+39,y+alto + 20,"16");
    painter.drawText(x+98,y+alto + 20,"18.5");
    painter.drawText(x+177,y+alto + 20,"25");
    painter.drawText(x+236,y+alto + 20,"30");
    painter.drawText(x+305,y+alto + 20,"35");
    painter.drawText(x+365,y+alto + 20,"40");

    painter.setPen(color1);
    painter.setBrush(color1);
    painter.drawRect(x,y,30,alto);

    painter.setPen(color2);
    painter.setBrush(color2);
    painter.drawRect(x+39,y,50,alto);

    painter.setPen(color3);
    painter.setBrush(color3);
    painter.drawRect(x+98,y,70,alto);

    painter.setPen(color4);
    painter.setBrush(color4);
    painter.drawRect(x+177,y,50,alto);

    painter.setPen(color5);
    painter.setBrush(color5);
    painter.drawRect(x+236,y,60,alto);

    painter.setPen(color6);
    painter.setBrush(color6);
    painter.drawRect(x+305,y,60,alto);

    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawText(100-5, y-10, QString::number(imc));
    painter.drawRoundedRect(100,y-3,5,alto + 8,3, 1.5);

    ui->outResultados->setPixmap(lienzo);
}


