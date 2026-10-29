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
    pnodoPila aux;
    Paciente v;                                    //Antes: int -> Paciente
    if(!ultimo)
        return Paciente();                         //Antes: return 0
    aux = ultimo;
    ultimo = aux->siguiente;
    v = aux->valor;
	aux->siguiente = NULL;						//CAMBIO: Declaramos el puntero siguiente a null por seguridad
    longitud--;
    delete aux;
    return v;
}

Paciente Pila::cima()                              //Antes: int -> Paciente
{
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
    while(ultimo) {
		extraer();								//CAMBIO: En vez de volver a eliminar de 1 en 1, llamamos al método extraer en bucle
    }
}

Pila::~Pila()
{
	vaciar();								//CAMBIO: En vez de volver a vaciar la pila con el mismo código, llamamos al método vaciar.
}