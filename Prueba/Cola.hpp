#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"

class Cola
{
public:
    Cola();
    ~Cola();
    void insertar(Paciente v);  //Antes: int -> Paciente
    Paciente eliminar();        //Antes: int -> Paciente
    void mostrar();
    Paciente verPrimero();      //Antes: int -> Paciente
    int getLongitud();          //nuevo
    bool esVacia();             //nuevo
    void vaciar();              //nuevo
private:
    pnodoCola primero, ultimo;
    int longitud;
};

#endif