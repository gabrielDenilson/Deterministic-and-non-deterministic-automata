#include "palabra.h"
#include "simbolo.h"

#include <QDebug>

Palabra::Palabra()
{
    elqueapunta=secuencia.data();
}

//agrega un nuevo simbolo a la PALABRA
void Palabra::setSimbolo(Simbolo encarnacion)
{
        secuencia.append(encarnacion);
}

//retorna un QString con uniendo todos los simbolos de la palabra
QString Palabra::getPalabra()
{
    QString palabra;
    QVector<Simbolo> copia=secuencia;

    for(int i=0; i<secuencia.size(); i++){
        Simbolo aux(copia.at(i));
        palabra.append(aux.simboloToQString());

    }
    return palabra;
}

//retorna el tamaño de la palabra compuesta por un vector de simbolos
int Palabra::getTamanioPalabra()
{
    int envergadura=secuencia.size();

    return envergadura;
}

//Retorna true si la palabra pertenece al alfabeto, false si no pertenece al alfabeto
bool Palabra::palabraSobreAlafabeto(Palabra termino, Alfabeto abece)
{
    QList<QString> mi_listaAlfabeto = abece.getQListQStringAlfabeto();

    Simbolo auxiliar;

    int tamanioPalabra=termino.getTamanioPalabra();

    int tamanioAlfabeto=mi_listaAlfabeto.size();

    int mi_flag = 0;

    for(int i = 0; i < tamanioPalabra; i++){

        auxiliar = termino.getSimboloPosicion(i);

        for(int j=0; j<tamanioAlfabeto; j++){
            qDebug() << auxiliar.simboloToQString() << " = " << mi_listaAlfabeto.value(j);
            if(auxiliar.simboloToQString() == mi_listaAlfabeto.value(j))
                mi_flag ++;
        }
    }

    if (mi_flag == tamanioPalabra){
        return true;
    } else {
        return false;
    }
}

//Retorna un Qvector de simbolos, perteneciente a la palabra
QVector<Simbolo> Palabra::getSecuencia() const
{
    //mientras, para hacer la prueba que si reconoce todo el vector
    QString mientras;
    Simbolo unratito;
    for(int i=0; i<secuencia.size(); i++){
        unratito=secuencia.at(i);
        mientras= unratito.simboloToQString();
        qDebug() << mientras;
    }
    //
    int tama=secuencia.size();
    qDebug() << tama;

    return secuencia;
}

//envia un Qvector de simbolos al constructor de secuencia
void Palabra::setSecuencia(const QVector<Simbolo> &value)
{
    secuencia = value;
}

//descompone un Qstring en charizares simbolos y los agrega a la PALABRA
void Palabra::setPalabra(QString vocablo)
{
    Simbolo lolo;
    QChar cuchar;
    for(int i=0; i<vocablo.size(); i++){
        cuchar=vocablo.at(i);
        lolo.charToSimbolo(cuchar);
        setSimbolo(lolo);
    }
}

Simbolo Palabra::getSimboloPosicion(int position)
{
    Simbolo palabra;
    palabra=secuencia.value(position);
    return palabra;
}

//#### error, revisar, convierte la palabra en un QString
QString Palabra::palabraToQString()
{
    //para adicionar los simbolos
    QString converted;

    //auxiliar para converted
    Simbolo auxiliar;

    for(int i=0; i < secuencia.size(); i++){
        auxiliar = secuencia.value(i);
        converted.append(auxiliar.simboloToQString());
    }

    return converted;
}

bool Palabra::validarGuiPalabaOverAlfabeto(QString mi_palabra, QString mi_alfabeto)
{
    //lista dada por usuario
    //QString listaUsuario="ñ,ñ,ñ,a,b,c,d,e,f,g,h,i,j,k,l,m,n,ñ,o,p,q,r,s,t,u,v,w,x,y,z,ñ,ñ,ñ";

    //creamos Alfabeto
    Alfabeto alfabeto;

    //creamos simbolo
    Simbolo simbol;

    //creamos lista para guardar
    QStringList listaDegenerada;

    if(mi_alfabeto == "Alfabeto Esp."){
        mi_alfabeto = "a,b,c,d,e,f,g,h,i,j,k,l,m,n,ñ,o,p,q,r,s,t,u,v,w,x,y,z";
    }

    //agregamos una lista de string en listaDegenerada
    listaDegenerada=simbol.obtenerSimboloSeparado(mi_alfabeto);


    for(int i=0; i<listaDegenerada.size(); i++){
        //llenamos el alfabeto con los simbolos de la lista
        alfabeto.agregarSimbolo(simbol.simboloDelistaEfimera(listaDegenerada,i));
    }

    alfabeto.mostrarAlfabeto();

    Palabra sobreAlfa;

    sobreAlfa.setPalabra(mi_palabra);
    bool siono = sobreAlfa.palabraSobreAlafabeto(sobreAlfa, alfabeto);

    return siono;
}





