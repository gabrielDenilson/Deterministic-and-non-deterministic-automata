#include "simbolo.h"
#include <QString>
#include <QDebug>
#include <QStringList>
#include <QRegularExpression>

#include "locale.h"

//constructor de simbolo vacio
Simbolo::Simbolo()
{
    simbolo = "";
}

//Constructor para enviar un QString  a Simbolo
Simbolo::Simbolo(QString myfuckignSimbol)
{
    simbolo = myfuckignSimbol;
}

//envia un QString a Simbolo
void Simbolo::setSimbolo(QString otroSimbolo)
{
    simbolo = otroSimbolo;
}

//Retorna una ListaDeQStrings
QStringList Simbolo::obtenerSimboloSeparado(QString &inconmensurable)
{
    setlocale(LC_CTYPE, "Spanish");

    QStringList efimero;

    efimero = inconmensurable.split(QRegularExpression("\\W+"), QString::SkipEmptyParts);

            //QRegularExpression("\\W+"), QString::SkipEmptyParts
    return efimero;
}

//convierte el valor del indice en un simbolo
Simbolo Simbolo::simboloDelistaEfimera(QStringList pan, int trinchera){
    QString emplazamiento;
    Simbolo inmarcesible;
    emplazamiento=pan.value(trinchera);
    inmarcesible.stringToSimbolo(emplazamiento);
    return inmarcesible;
}

//MODIFICAR O MORIR
//retorna un mensaje con el tamaño del simbolo
void Simbolo::obtenerSimboloSuTamanio()
{
    int tama=simbolo.length();

    qDebug() << "Su tamanio es de : "<< tama;


}

//metodo para convertir un simbolo a un QString
QString Simbolo::simboloToQString()
{
    QString valor = simbolo;

    return valor;
}

//Convierte un Qstring y Retorna un Simbolo
Simbolo Simbolo::stringToSimbolo(QString priapo)
{
    simbolo = priapo;

    return simbolo;
}

//Retorna el simbolo en su primitivo QString
QString Simbolo::getSimbolo()
{
    return simbolo;
}

//convierte un char a un simbolo
Simbolo Simbolo::charToSimbolo(QChar letra)
{
    QString fantasma= letra;
    simbolo = fantasma;
    return simbolo;
}

