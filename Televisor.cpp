#include "Televisor.h"
#include "Canal.h"
#include "Vector.h"
#include <iostream>


#define CANTIDAD_MAXIMA_CANALES 140
#define VOLUMEN_MAXIMO 100
#define VOLUMEN_MINIMO 0

Televisor::Televisor(unsigned int cantidadTotalCanales){
    if (cantidadTotalCanales>CANTIDAD_MAXIMA_CANALES){
        throw "El televisor no puede tener mas de 140 canales";
    }
    this->canales = new Vector<Canal*>(cantidadTotalCanales, NULL);
    for (int i = 1; 1<=this->canales->getLongitud(); i++ ){
        Canal* canal = new Canal(i);
        this->canales->agregar(i, canal);
    }
    setCanalActual(this->canales->obtener(1));
}

Televisor::~Televisor(){
    delete this->canales;
}

void Televisor::pasarSiguienteCanal(){
    unsigned int posCanalActual = this->canalActual->getPosicionCanal();
    if(posCanalActual == cantidadTotalCanales){
        setCanalActual(this->canales->obtener(1));
    }
    else{
        setCanalActual(this->canales->obtener(posCanalActual++));
    }
}

void Televisor::pasarAnteriorCanal(){
    unsigned int posCanalActual = this->canalActual->getPosicionCanal();
    if(posCanalActual == 1){
        setCanalActual(this->canales->obtener(cantidadTotalCanales));
    }
    else{
        setCanalActual(this->canales->obtener(posCanalActual--));
    }
}

void Televisor::seleccionarCanal(unsigned int posCanal){
    if(posCanal<=0){
        throw "El canal no puede ser menor a 1";
    }
    if(posCanal > cantidadTotalCanales){
        throw "Error";
    }
        this->canales->obtener(posCanal);
        setCanalActual(this->canales->obtener(posCanal));        
}

void Televisor::subirVolumen(){
    unsigned int volumen = this->getVolumen();
    if (volumen>VOLUMEN_MAXIMO){
        this->setVolumen(VOLUMEN_MAXIMO);
    }
    this->setVolumen(volumen++);
    this->canalActual->setVolumenActual(volumen++);
}

void Televisor::bajarVolumen(){
    unsigned int volumen = this->getVolumen();
    if (volumen<VOLUMEN_MINIMO){
        this->setVolumen(VOLUMEN_MINIMO);
    }
    this->setVolumen(volumen--);
    this->canalActual->setVolumenActual(volumen--);
}

void Televisor::mutear(){
    this->estadoVolumen=Muteado;
}
Canal* Televisor::getCanalMasAltoEscuchado(){
    Canal* canalMasAltoEscuchado = new Canal();
    unsigned int volumenMasAlto = 0;
    for (int i = 1; 1<=this->canales->getLongitud(); i++ ){
        if(volumenMasAlto < this->canales->obtener(i)->getVolumenMaximo()){
            canalMasAltoEscuchado=this->canales->obtener(i);
        }
    }
    return canalMasAltoEscuchado;

}

Canal* Televisor::getNumeroCanalActual(){
    return this->canalActual;
}

void Televisor::setCanalActual(Canal* canal){
    if(canal == NULL){
        throw "Error, canal no puede ser nulo";
    }
    this->canalActual=canal;
}

unsigned int Televisor::getVolumen(){
    return this->volumen;
}
void Televisor::setVolumen(unsigned int volumen){
    if (volumen>VOLUMEN_MAXIMO){
        throw "Error";
    }
    if (volumen<VOLUMEN_MINIMO){
        throw "Error";
    }
    this->volumen=volumen;
}


    

