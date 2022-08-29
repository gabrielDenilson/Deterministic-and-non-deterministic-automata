#ifndef ALFABETO_H
#define ALFABETO_H

#include "simbolo.h"
#include <QList>


class Alfabeto
{

public:

    Alfabeto();
    void agregarSimbolo(Simbolo);
    void agregarAlfabeto(QString&);
    void mostrarAlfabeto();
    QList<QString> getQListQStringAlfabeto();

private:

    QList <Simbolo> conjuntoSimbolos;


};

#endif // ALFABETO_H
