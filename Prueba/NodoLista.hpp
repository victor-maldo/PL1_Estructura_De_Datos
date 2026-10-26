#include <iostream>
#include "Paciente.hpp"
using namespace std;

class NodoLista
{
public:
	NodoLista(Paciente v, NodoLista* sig = NULL);
	~NodoLista();
private;
	Paciente valor;
	NodoLista* siguiente;
	friend class Lista;
};
typedef NodoLista* pnodoLista;