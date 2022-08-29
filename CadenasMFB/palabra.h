#ifndef PALABRA_H
#define PALABRA_H

#include "alfabeto.h"
#include "simbolo.h"
#include <QVector>

class Palabra
{
public:
    Palabra();

//    Palabra(Simbolo);

    //introduce un simbolo al vector de "secuencia" de la palabra
    void setSimbolo(Simbolo);

    QString getPalabra();

    int getTamanioPalabra();

    bool palabraSobreAlafabeto(Palabra, Alfabeto);

    QVector<Simbolo> getSecuencia() const;

    void setSecuencia(const QVector<Simbolo> &value);

    void setPalabra(QString);

    Simbolo getSimboloPosicion(int);

    QString palabraToQString();

    bool validarGuiPalabaOverAlfabeto(QString, QString);


private:

    QVector<Simbolo> secuencia;
    Simbolo* elqueapunta;
};

#endif // PALABRA_H
