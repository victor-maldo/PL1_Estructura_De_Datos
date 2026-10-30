#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Paciente* v)                   
{
    pnodoCola nuevo;
    nuevo = new NodoCola(v);
    if(ultimo)
        ultimo->siguiente = nuevo;
    ultimo = nuevo;
    if(!primero)
        primero = nuevo;
    longitud++;
}

void Cola::mostrar()
{
    pnodoCola aux = primero;
    while(aux) {
        aux->valor->mostrar();                     
        aux = aux->siguiente;
    }
}

Paciente* Cola::eliminar()                         
{
    pnodoCola aux;
    Paciente* v;                                   
    aux = primero;
    if(!aux)
        return NULL;                        
    primero = aux->siguiente;
    v = aux->valor;
	aux->siguiente = NULL;
    delete aux;
    if(!primero)
        ultimo = NULL;
    longitud--;
    return v;
}

Paciente* Cola::verPrimero()                       
{
    if(!primero)                                  
        return NULL;
    return primero->valor;
}

int Cola::getLongitud()                           
{
    return longitud;
}

bool Cola::esVacia()                              
{
    return primero == NULL;
}

void Cola::vaciar()                               
{
    while(primero)
        eliminar();
}

Cola::~Cola()
{
	vaciar();
}