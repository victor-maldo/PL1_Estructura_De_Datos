#ifndef CONTROLADOR_HPP
#define CONTROLADOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"

class Controlador
{
public:
	Controlador();
	~Controlador();
	
<<<<<<< HEAD
	
	int pacientesEnPila();
	int pacientesEnSalaA();
	int pacientesEnSalaB();
	int pacientesEnSalaC();
	int pacientesEnSalaD();
	int pacientesEnListaApendicitis();
	int pacientesEnListaHernias();
	void opcionA_generarPacientes();
	void opcionB_mostrarPila();
	void opcionC_borrarPila();
	void opcionD_pasarAColas();
	void opcionE_mostrarSalasAB();
	void opcionF_mostrarSalasCD();
	void opcionG_borrarSalas();
	void opcionH_pasarAListas();
	void opcionI_mostrarQuirofanoApendicitis();
	void opcionJ_mostrarQuirofanoHernias();
	void opcionK_mostrarExtremosPrioridad();
	void opcionL_Reiniciar();
=======
	void genera12Pacientes();
	void muestraPacientes();
	void borraPacientesPila();
	void encolarPacientes();
	void muestraPacientesSalasAyB();
	void muestraPacientesSalasCyD();
	void borraPacientesColas();
	void enlistarPacientes();
	void muestraPacientesApendicitis();
	void muestraPacientesHernias();
	void buscarPacientes();
	void reiniciar();
>>>>>>> cad20a68d21e3a1d60e59fceab87d248b2724942
	
private:
	Pila pilaPacientes;
	Cola salaA;
	Cola salaB;
	Cola salaC;
	Cola salaD;
	
	Lista quirofanoApendicitis;
	Lista quirofanoHernias;
	
	int contadorIdApendicitis;
	int contadorIdHernias;
	int contadorHabApendicitis;
	int contadorHabHernias;
};

#endif
