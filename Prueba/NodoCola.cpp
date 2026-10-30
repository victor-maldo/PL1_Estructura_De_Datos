#include "NodoCola.hpp"

NodoCola::NodoCola(Paciente v, NodoCola* sig)     
{
    valor = v;
    siguiente = sig;
}

NodoCola::~NodoCola()
{
}