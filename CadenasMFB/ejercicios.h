#ifndef EJERCICIOS_H
#define EJERCICIOS_H
#include "palabra.h"

class ejercicios
{
public:
    ejercicios();



QVector<QString> prefijoEjercicio(Palabra);

QVector<QString> sufijoEjercicio(Palabra);

QVector<QString> subcadenaPalabra(Palabra);

QVector<QString> quitarIguales(QVector<QString>&);

QVector<QString> inversaDeCadena(Palabra);

};

#endif // EJERCICIOS_H
