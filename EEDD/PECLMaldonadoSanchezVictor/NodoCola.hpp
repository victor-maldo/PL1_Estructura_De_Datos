#ifndef NODOCOLA_HPP
#define NODOCOLA_HPP

#include <iostream>
#include "Paciente.hpp"       
using namespace std;

class NodoCola
{
public:
    NodoCola(Paciente* v, NodoCola* sig = NULL);   
    ~NodoCola();
private:
    Paciente* valor;                               
    NodoCola* siguiente;
    friend class Cola;
};
typedef NodoCola* pnodoCola;

#endif