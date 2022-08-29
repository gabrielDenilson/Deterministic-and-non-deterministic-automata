#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>

#include "palabra.h"
#include "ejercicios.h"

#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Lenguajes Formales");

    ui->comboBox->addItem("Alfabeto Esp.");



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generarPrefijoPushButton_clicked()
{
    QString validacion = ui->comboBox->currentText();

    QString valorLineEdit = ui->cadenaLineEdit->text();

    //creamos el objeto palabra
    Palabra prefijoGui;


    //verificamos que pertenece al alfabeto
    ui->labelAviso->clear();
    bool flag = prefijoGui.validarGuiPalabaOverAlfabeto(valorLineEdit, validacion);

    if (flag == false){
        QColor colorAviso = Qt::red;

        ui->labelAviso->setPalette(QPalette(colorAviso));
        ui->labelAviso->setText("La palabra no pertenece al alfabeto");
        return;
    }

    //enviamos el valor ingresado al constructor
    prefijoGui.setPalabra(valorLineEdit);

    //creamos el ejercicio
    ejercicios mi_prefijo;

    QVector<QString> mi_vector;

    mi_vector = mi_prefijo.prefijoEjercicio(prefijoGui);

    QColor color;

    color = Qt::black;

    ui->prefijoTextBrowser->setTextColor(color);

    for (int i=0; i<mi_vector.size(); i++) {
        ui->prefijoTextBrowser->append(mi_vector.value(i));
    }

}

void MainWindow::on_generarSufijoPushButton_clicked()
{
    QString valorLineEditSufijo = ui->sufijoLineEdit2->text();

    Palabra sufijoGui;

    sufijoGui.setPalabra(valorLineEditSufijo);

    ejercicios mi_sufijo;

    QVector<QString> mi_vector;

    mi_vector = mi_sufijo.sufijoEjercicio(sufijoGui);

    QColor color;

    color = Qt::black;

    ui->prefijoTextBrowser2->setTextColor(color);

    for (int i =0; i < mi_vector.size(); i++) {
        ui->prefijoTextBrowser2->append(mi_vector.value(i));
    }
}

void MainWindow::on_generarSubcadenaPushButton_clicked()
{
    QString valorLineEditSubcadena = ui->entradaSubcadenaLineEdit->text();

    Palabra subcadenaGui;

    subcadenaGui.setPalabra(valorLineEditSubcadena);

    ejercicios mi_subcadena;

    QVector<QString> mi_vector;

    mi_vector = mi_subcadena.subcadenaPalabra(subcadenaGui);

    QColor color;

    color = Qt::black;

    ui->subcadenaTextBrowser->setTextColor(color);

    for(int i=0; i < mi_vector.size(); i++){
        ui->subcadenaTextBrowser->append(mi_vector.value(i));
    }
}

void MainWindow::on_generarInversaPushButton_clicked()
{

    QString valorLineEditInversa = ui->inversaLineEdit->text();

    Palabra inversaGui;

    inversaGui.setPalabra(valorLineEditInversa);

    ejercicios mi_inversa;

    QVector<QString> mi_vector;

    mi_vector= mi_inversa.inversaDeCadena(inversaGui);

    QColor color = Qt::black;



    QString todoUno;
    for(int i=0; i < mi_vector.size(); i++){
        todoUno.append(mi_vector.value(i));
        //ui->inversaTextBrowser->append(mi_vector.value(i));
    }

    ui->inversaTextBrowser->setTextColor(color);

    ui->inversaTextBrowser->append(todoUno);
}
