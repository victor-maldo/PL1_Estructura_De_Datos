#include "Lista.hpp"

Lista::Lista()
{
	primero = NULL;
	longitud = 0;
}

void Lista::insertarEnOrden(Paciente v)
{
	pnodoLista nuevo = new NodoLista(v);
	
	if(!primero){
		primero = nuevo;
	} else if(v.getId() > primero->valor.getId()){
		nuevo->siguiente = primero;
		primero = nuevo;
	}else{
		pnodoLista aux = primero;
		
		while(aux->siguiente != NULL && aux->siguiente->valor.getId() >= v.getId()){
			aux = aux->siguiente;
		}
		nuevo->siguiente = aux->siguiente;
		aux->siguiente = nuevo;
	}
	longitud++;
}

void Lista::mostrar(){
	pnodoLista aux = primero;
	while(aux){
		aux->valor.mostrar();
		aux = aux->siguiente;
	}
}

Paciente Lista::extrearPrimero(){
Paciente Lista::extraerPrimero(){
	if(!primero){
		return Paciente();
	}
	pnodoLista aux = primero;
	Paciente v;
	primero = primero->siguiente;
	v = aux->valor;
	aux->siguiente = NULL;
	delete aux;
	longitud--;
	return v;
}
Paciente Lista::getPrimero(){
	if(!primero){
		return Paciente(); //Consultar al profe sobre manejo de excepciones
	}
	return primero->valor;
}

Paciente Lista::getUltimo(){
	if(!primero){
		return Paciente();
	}
	pnodoLista aux = primero;
	while(aux->siguiente != NULL){
		aux = aux->siguiente;
	}
	return aux->valor;
}

int Lista::getLongitud(){
	return longitud;
}

bool Lista::esVacia(){
	return primero == NULL;
}

void Lista::vaciar(){
	pnodoLista aux;
								// Innecesario pnodoLista aux;   
	while(primero){
		extrear_primero();
		extraerPrimero();
	}
}

Lista::~Lista()
{
	vaciar();
}