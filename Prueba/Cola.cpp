#include "Cola.hpp"

Cola::Cola()
{
    primero = NULL;
    ultimo = NULL;
    longitud = 0;
}

void Cola::insertar(Paciente v)                   //Antes: int -> Paciente
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
        aux->valor.mostrar();                     //Antes: cout << aux->valor
        aux = aux->siguiente;
    }
}

Paciente Cola::eliminar()                         //Antes: int -> Paciente
{
    pnodoCola aux;
    Paciente v;                                   //Antes: int -> Paciente
    aux = primero;
    if(!aux)
        return Paciente();                        //Antes: return 0
    primero = aux->siguiente;
    v = aux->valor;
	aux->siguiente = NULL;						//CAMBIO: Declaramos el puntero siguiente a null por seguridad
    delete aux;
    if(!primero)
        ultimo = NULL;
    longitud--;
    return v;
}

Paciente Cola::verPrimero()                       // CAMBIO: int -> Paciente
{
    if(!primero)                                  // CAMBIO: comprobación nueva
        return Paciente();
    return primero->valor;
}

int Cola::getLongitud()                           // CAMBIO: nuevo
{
    return longitud;
}

bool Cola::esVacia()                              // CAMBIO: nuevo
{
    return primero == NULL;
}

void Cola::vaciar()                               // CAMBIO: nuevo
{
    while(primero)
        eliminar();
}

Cola::~Cola()
{
	vaciar();		//CAMBIO: En vez de volver a poner el contenido del método "vaciar", directamente le llamamos.
}