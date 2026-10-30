#include "NodoLista.hpp"

NodoLista::NodoLista(Paciente* v, NodoLista* sig)
{
	valor = v;
	siguiente = sig;
}
NodoLista::~NodoLista()
{
}