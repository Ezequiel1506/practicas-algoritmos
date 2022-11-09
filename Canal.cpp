#include "Canal.h"

Canal::Canal(unsigned int numero){
    if(numero<= 0){
        throw "Error, el numero de canal no puede ser 0";
    }
    this->numero = numero;
}
Canal::Canal(){}
Canal::~Canal(){}

unsigned int Canal::getVolumenUltimaVez(){
    return this->volumenActual;
}
unsigned int Canal::getVolumenMaximo(){
    return this->historicoVolumen;

}
void Canal::setVolumenActual(unsigned int volumen){
    if(volumen < 0){
        throw "Error volumen no puede ser menor a 0";
    }
    this->volumenActual=volumen;
}


void Canal::setVolumenMaximo(unsigned int volumenMaximoAnterior, unsigned int volumenActual){
    if(volumenMaximoAnterior<0){
        throw "Error volumen anterior";
    }
    if(volumenActual<0){
        throw "Error volumen actual";
    }

    if(volumenActual>volumenMaximoAnterior){
        this->historicoVolumen=volumenActual;
    }
    else {
        this->historicoVolumen=volumenMaximoAnterior;
    }
}
unsigned int Canal::getPosicionCanal(){
    return this->numero;
}
