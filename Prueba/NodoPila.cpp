#include "NodoPila.hpp"

NodoPila::NodoPila(Paciente v, NodoPila* sig)     //Antes: int -> Paciente
{
	valor = v;
	siguiente = sig;
}

NodoPila::~NodoPila()
{
}