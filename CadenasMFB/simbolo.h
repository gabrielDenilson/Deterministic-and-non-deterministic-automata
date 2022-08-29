#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <QString>
#include <QList>


class Simbolo
{

public:
    Simbolo();

    Simbolo(QString);

    void setSimbolo(QString);

     QStringList obtenerSimboloSeparado(QString&);

     Simbolo simboloDelistaEfimera(QStringList, int);

     void obtenerSimboloSuTamanio();

    QString simboloToQString();

    Simbolo stringToSimbolo(QString);

    QString getSimbolo();

    Simbolo charToSimbolo(QChar);

private:


    QString simbolo;

};

#endif // SIMBOLO_H
