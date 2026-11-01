#include "Pila.hpp"

Pila::Pila()
{
    ultimo = NULL;
    longitud = 0;
}

void Pila::insertar(Paciente* v)                    
{
    pnodoPila nuevo;
    nuevo = new NodoPila(v, ultimo);
    ultimo = nuevo;
    longitud++;
}

Paciente* Pila::extraer()                           
{
    pnodoPila aux;
    Paciente* v;                                    
    if(!ultimo)
        return NULL;                         
    aux = ultimo;
    ultimo = aux->siguiente;
    v = aux->valor;
	aux->siguiente = NULL;
    longitud--;
    delete aux;
    return v;
}

Paciente* Pila::cima()                              
{
    if(!ultimo)
        return NULL;                         
    return ultimo->valor;
}

void Pila::mostrar()
{
    pnodoPila aux = ultimo;
    while(aux) {
        aux->valor->mostrar();                      
        aux = aux->siguiente;
    }
}

int Pila::getLongitud()
{
    return this->longitud;
}

bool Pila::esVacia()                               
{
    return ultimo == NULL;
}

void Pila::vaciar()
{
    while(ultimo) {
		delete extraer();          
    }
}

Pila::~Pila()
{
	vaciar();
}