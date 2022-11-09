#ifndef TELEVISOR_H_
#define TELEVISOR_H_

enum EstadoVolumen {
    Muteado,
    Activo
};

class Televisor {
    private:
        Vector<Canal*> *canales;
        EstadoVolumen estadoVolumen;
        unsigned int volumen;
        Canal * canalActual;
        unsigned int cantidadTotalCanales;

    public:
        Televisor(unsigned int cantidadTotalCanales);
        ~Televisor();
        void pasarSiguienteCanal();
        void pasarAnteriorCanal();
        void seleccionarCanal(unsigned int posCanal);
        void subirVolumen();
        void bajarVolumen();
        void mutear();
        void getCanalMasAltoEscuchado();
        Canal* getNumeroCanalActual();

    private: 
        void setCanalActual(Canal* canalActual);

};

#endif