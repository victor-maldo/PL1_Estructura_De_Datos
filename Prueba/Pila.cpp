#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}

void Pila::insertar(Paciente v)                    //Antes: int -> Paciente
{
    pnodoPila nuevo;
    nuevo = new NodoPila(v, ultimo);
    ultimo = nuevo;
    longitud++;
}

Paciente Pila::extraer()                           //Antes: int -> Paciente
{
    pnodoPila nodo;
    Paciente v;                                    //Antes: int -> Paciente
    if(!ultimo)
        return Paciente();                         //Antes: return 0
    nodo = ultimo;
    ultimo = nodo->siguiente;
    v = nodo->valor;
    longitud--;
    delete nodo;
    return v;
}

Paciente Pila::cima()                              //Antes: int -> Paciente
{
    pnodoPila nodo;
    if(!ultimo)
        return Paciente();                         //Antes: return 0
    return ultimo->valor;
}

void Pila::mostrar()
{
    pnodoPila aux = ultimo;
    while(aux) {
        aux->valor.mostrar();                      //Antes: cout << " -> " << aux->valor
        aux = aux->siguiente;
    }
}

int Pila::getLongitud()
{
    return this->longitud;
}

bool Pila::esVacia()                               //nuevo
{
    return ultimo == NULL;
}

void Pila::vaciar()                                //nuevo
{
    pnodoPila aux;
    while(ultimo) {
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
    longitud = 0;
}

Pila::~Pila()
{
    pnodoPila aux;
    while(ultimo) {
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}