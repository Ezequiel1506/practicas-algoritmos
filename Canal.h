#ifndef CANAL_H_
#define CANAL_H_
class Canal {
    private:
        unsigned int numero;
        unsigned int volumenActual;
        unsigned int historicoVolumen;

    public:
        /**
         * @brief Construct a new Canal object
         * pre: numero debe ser mayor a 0
         * pos: crea un canal
         */
        Canal(unsigned int numero);

        /**
         * @brief Destroy the Canal object
         * pre:
         * Pos: elimina un canal, libera la memoria
         * 
         */
        ~Canal();
        /**
         * @brief Get the Volumen Ultima Vez object
         * 
         * @return unsigned int 
         */
        unsigned int getVolumenUltimaVez();
        /**
         * @brief Get the Volumen Maximo object
         * 
         * @return unsigned int 
         */
        unsigned int getVolumenMaximo();
        /**
         * @brief Set the Volumen Actual object
         * pre: volumen no puede ser menor a 0
         * pos: setea el volumen con el que se escucha el canal en la variable volumenActual
         */
        void setVolumenActual(unsigned int volumen);
        /**
         * @brief Set the Volumen Maximo object
         * pre: volumentAnterior y volumenActual no pueden ser menores a cero
         * por: guarda el volumen maximo con el que se escucho este canal en la variable historicoVolumen
         * 
         * @param volumenAnterior 
         * @param volumenActual 
         */
        void setVolumenMaximo(unsigned int volumenAnterior, unsigned int volumenActual);

        unsigned int getPosicionCanal();

};
#endif
