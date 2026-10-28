#ifndef PILA_HPP
#define PILA_HPP

#include "NodoPila.hpp"

class Pila
{
public: 
	Pila();
	~Pila();
	void insertar(Paciente v);  // Antes: int -> Paciente
	Paciente extraer();         // Antes: int -> Paciente
	Paciente cima();            // Antes: int -> Paciente
	void mostrar();
	int getLongitud();
	bool esVacia();             //nuevo
	void vaciar();              //nuevo

private:
	pnodoPila ultimo;
	int longitud;
};

#endif