#include "NodoCola.hpp"

NodoCola::NodoCola(Paciente v, NodoCola* sig)     //Antes: int -> Paciente
{
    valor = v;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}