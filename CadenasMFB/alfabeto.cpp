#include "alfabeto.h"

#include "simbolo.h"

#include <QRegularExpression>
#include <QString>
#include <QDebug>

Alfabeto::Alfabeto()
{

}

// llena la lista del alfabeto con simbolos
void Alfabeto::agregarSimbolo(Simbolo mi_simbolo)
{
    conjuntoSimbolos.append(mi_simbolo);
}

//separa los simbolos de un string y agrega al alfabeto
void Alfabeto::agregarAlfabeto(QString &degenerado)
{
    QStringList miAlfabertesdf;

    miAlfabertesdf=degenerado.split(QRegularExpression("\\W+"), QString::SkipEmptyParts);


}

void Alfabeto::mostrarAlfabeto()
{
    QList<Simbolo> :: iterator posicion;

    int enormidad = conjuntoSimbolos.size();

    foreach(Simbolo i, conjuntoSimbolos){
        qDebug() << i.simboloToQString();
    }



    qDebug() << "tiene: " << enormidad << " simbolos";

}

//Retorna una lista de Qstring original del alfabeto
QList<QString> Alfabeto::getQListQStringAlfabeto()
{
    QList<QString> mi_alfabeto;
    Simbolo auxiliar;
    for(int i=0; i < conjuntoSimbolos.size(); i++){
        auxiliar = conjuntoSimbolos.value(i);
        mi_alfabeto.append(auxiliar.simboloToQString());
    }
   return mi_alfabeto;
}
