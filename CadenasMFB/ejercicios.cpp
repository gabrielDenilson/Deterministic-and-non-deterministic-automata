#include "ejercicios.h"

#include "palabra.h"
#include "simbolo.h"

#include <QVector>
#include <QDebug>

ejercicios::ejercicios()
{

}

QVector<QString> ejercicios::prefijoEjercicio(Palabra mi_palabra)
{
    QVector<QString> prefijoVec;

    QString ini="e";

    prefijoVec.append(ini);

    int tamanio=mi_palabra.getTamanioPalabra();

    Simbolo auxiliar;

    QString prefijo;

    for(int i=0; i<tamanio; i++){
        auxiliar = mi_palabra.getSimboloPosicion(i);
        prefijo.append(auxiliar.simboloToQString());
        prefijoVec.append(prefijo);
    }

    return prefijoVec;
}

QVector<QString> ejercicios::sufijoEjercicio(Palabra mi_palabra)
{
    QVector<QString> mi_vector;

    QString ini="e";

    mi_vector.append(ini);

    int tamanio = mi_palabra.getTamanioPalabra();

    Simbolo auxiliar;

    QString sufijo;

    for(int i=tamanio-1; i > -1 ; i--){
        auxiliar=mi_palabra.getSimboloPosicion(i);
        sufijo.prepend(auxiliar.simboloToQString());
        mi_vector.append(sufijo);
    }
    return mi_vector;
}

QVector<QString> ejercicios::subcadenaPalabra(Palabra mi_palabra)
{
    QVector<QString> subcadena;

    int posicionPadre=0;
    int posicion=0;

    int tamanio=mi_palabra.getTamanioPalabra();

    QString sub;

    //int auxiliar=tamanio;

    //bucle para contar los simbolos
    for(int i=1; i<=tamanio; i++){

        while(posicionPadre <= tamanio-i){

            for(int j=0; j<i; j++){

                Simbolo cadena= mi_palabra.getSimboloPosicion(posicion);

                sub.append(cadena.simboloToQString());

                posicion++;
            }

            subcadena.append(sub);

            posicionPadre++;

            posicion=posicionPadre;

            sub.clear();
        }

        posicionPadre=0;
        posicion=0;
    }

    return quitarIguales(subcadena);
}

QVector<QString> ejercicios::quitarIguales(QVector<QString> & mi_vector)
{
    QVector<QString> auxiliar=mi_vector;

    mi_vector.clear();

    for(int i=0; i<auxiliar.size(); i++){

        QString elemento=auxiliar.value(i);

        if(mi_vector.isEmpty()){

            mi_vector.append(elemento);
        } else {

            int aux=0;

            for(int j=0; j<mi_vector.size(); j++){

                if(elemento == mi_vector.value(j)){

                    aux++;
                }
            }

            if(aux == 0){
                mi_vector.append(elemento);
            }
        }



    }

    return mi_vector;
}


QVector<QString> ejercicios::inversaDeCadena(Palabra mi_palabra)
{
    QVector<QString> convertida;

    QString subcadena;

    Simbolo auxi;

    for(int i=mi_palabra.getTamanioPalabra(); i>=0; i--){
        auxi = mi_palabra.getSimboloPosicion(i-1);

        convertida.append(auxi.simboloToQString());
    }

    return convertida;
}
