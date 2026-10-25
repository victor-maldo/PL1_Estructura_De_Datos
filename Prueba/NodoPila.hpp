#include <iostream>
#include "Paciente.hpp"         //nuevo
using namespace std;

class NodoPila
{
public:
	NodoPila(Paciente v, NodoPila* sig = NULL);   //Antes: int -> Paciente
	~NodoPila();
private:
	Paciente valor;                               //Antes: int -> Paciente
	NodoPila* siguiente;
	friend class Pila;
};

typedef NodoPila* pnodoPila;