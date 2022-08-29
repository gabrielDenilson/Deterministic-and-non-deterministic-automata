#include "mainwindow.h"
#include <QString>
#include <QDebug>
#include <QVector>

#include "simbolo.h"
#include "alfabeto.h"
#include "palabra.h"

#include "ejercicios.h"
#include "locale.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE, "Spanish");

    QApplication a(argc, argv);

    a.setStyle("fusion");

    MainWindow w;

    w.show();

    //lista dada por usuario
    QString listaUsuario="ñ,ñ,ñ,a,b,c,d,e,f,g,h,i,j,k,l,m,n,ñ,o,p,q,r,s,t,u,v,w,x,y,z,ñ,ñ,ñ";

    //creamos Alfabeto
    Alfabeto alfabetoespanol;

    //creamos simbolo
    Simbolo simbol;

    //creamos lista para guardar
    QStringList listaDegenerada;

    //agregamos una lista de string en listaDegenerada
    listaDegenerada=simbol.obtenerSimboloSeparado(listaUsuario);


    for(int i=0; i<listaDegenerada.size(); i++){
        //llenamos el alfabeto con los simbolos de la lista
        alfabetoespanol.agregarSimbolo(simbol.simboloDelistaEfimera(listaDegenerada,i));
    }

    alfabetoespanol.mostrarAlfabeto();

    Palabra sobreAlfa;
    QString mi_palabra = "xilfono";
    sobreAlfa.setPalabra(mi_palabra);
    bool siono = sobreAlfa.palabraSobreAlafabeto(sobreAlfa, alfabetoespanol);

    qDebug() << siono;

    qDebug() << "---------------------";

    QString cadena="estdlmundo4ever";
    QString alfabeto="Alfabeto Esp.";

    Palabra prb;

    bool ths = prb.validarGuiPalabaOverAlfabeto(cadena, alfabeto);

    qDebug() << ths;





    return a.exec();
}
