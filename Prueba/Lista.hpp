#include "NodoLista.hpp"

class Lista
{
public:
	Lista();
	~Lista();
	void instertarEnOrden(Paciente v);
	void mostrar();
	Paciente extraerPrimero()
	Paciente getPrimero();
	Paciente getUltimo();
	int getLongitud();
	bool esVacia();
	void vaciar();
private:
	pnodoLista primero;
	int longitud;
}