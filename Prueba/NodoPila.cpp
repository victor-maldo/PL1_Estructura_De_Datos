#include "NodoPila.hpp"

NodoPila::NodoPila(Paciente* v, NodoPila* sig)     
{
	valor = v;
	siguiente = sig;
}

NodoPila::~NodoPila()
{
}