#include <iostream>
#include "Paciente.hpp"         //nuevo
using namespace std;

class NodoCola
{
public:
    NodoCola(Paciente v, NodoCola* sig = NULL);   //Antes: int -> Paciente
    ~NodoCola();
private:
    Paciente valor;                               //Antes: int -> Paciente
    NodoCola* siguiente;
    friend class Cola;
};
typedef NodoCola* pnodoCola;