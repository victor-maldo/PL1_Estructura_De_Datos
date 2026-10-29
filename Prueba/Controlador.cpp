#include "Controlador.hpp"
#include <cstdlib>
#include <ctime>
Controlador::Controlador()
{
	contadorIdApendicitis = 1;
	contadorIdHernias = 51;
	contadorHabApendicitis = 101;
	contadorHabHernias = 201;
	srand(time(NULL));
}

<<<<<<< HEAD
int Controlador::pacientesEnPila()
{
	return pilaPacientes.getLongitud();
}

int Controlador::pacientesEnSalaA()
{
	return salaA.getLongitud();
}

int Controlador::pacientesEnSalaB()
{
	return salaB.getLongitud();
}

int Controlador::pacientesEnSalaC()
{
	return salaC.getLongitud();
}

int Controlador::pacientesEnSalaD()
{
	return salaD.getLongitud();
}

int Controlador::pacientesEnListaApendicitis()
{
	return quirofanoApendicitis.getLongitud();
}

int Controlador::pacientesEnListaHernias()
{
	return quirofanoHernias.getLongitud();
}


void Controlador::opcionA_generarPacientes()
=======
void Controlador::genera12Pacientes()
>>>>>>> cad20a68d21e3a1d60e59fceab87d248b2724942
{
	if(pilaPacientes.getLongitud() == 48){
		std::cout <<"No se puede genera más pacientes, pila llena\n";
	}else{
		for(int i = 0; i < 12; i++){
			if(pilaPacientes.getLongitud() == 48){
				std::cout <<"No se puede generar más pacientes, pila llena";
				break;
			}
			
			int enfermedad = rand() % 2;
			int dni = (rand() % (99999999 - 10000000 + 1)) + 10000000;
			Paciente nuevoPaciente(dni, enfermedad);
			
			pilaPacientes.insertar(nuevoPaciente);
			
			std::cout << "Paciente con DNI: " << nuevoPaciente.getDni() << " y con " << (enfermedad ? "Apendicitis" : "Hernia") << " creado correctamente.\n";
 
		}
	}
}

void Controlador::opcionB_mostrarPila()
void Controlador::muestraPacientes()
{
	std::cout << "Pacientes en la pila:\n";
	pilaPacientes.mostrar();
}

void Controlador::opcionC_borrarPila()
void Controlador::borraPacientesPila()
{
	pilaPacientes.vaciar();
	std::cout << "Pila de pacientes vaciada con éxito\n";
}

void Controlador::opcionD_pasarAColas()
void Controlador::encolarPacientes()
{
	char sala;
	while (pilaPacientes.getLongitud() > 0){
		Paciente paciente = pilaPacientes.cima();
		if(paciente.tieneApendicitis()){
			
			paciente.setId(contadorIdApendicitis);
			paciente.setHabitacion(contadorHabApendicitis);
			contadorIdApendicitis++;
			contadorHabApendicitis++;
			
			if(salaA.getLongitud() <= salaB.getLongitud()){
				salaA.insertar(paciente);
				sala = 'A';
			}else{
				salaB.insertar(paciente);
				sala = 'B';
			}
		}else{
			
			paciente.setId(contadorIdHernias);
			paciente.setHabitacion(contadorHabHernias);
			contadorIdHernias++;
			contadorHabHernias++;
			
			if(salaC.getLongitud() <= salaD.getLongitud()){
				salaC.insertar(paciente);
				sala = 'C';
			}else{
				salaD.insertar(paciente);
				sala = 'D';
			}
		}
		std::cout << "Paciente :" << paciente.getDni() << " insertado en la sala " << sala << " en la habitación " << paciente.getHabitacion() << "\n"; 
		pilaPacientes.extraer();
		
	}

}

void Controlador::opcionE_mostrarSalasAB()
void Controlador::muestraPacientesSalasAyB()
{
	std::cout << "Sala A:\n";
	salaA.mostrar();
	std::cout << "Sala B:\n";
	salaB.mostrar();
}

void Controlador::opcionF_mostrarSalasCD()
void Controlador::muestraPacientesSalasCyD()
{
	std::cout << "Sala C:\n";
	salaC.mostrar();
	std::cout << "Sala D:\n";
	salaD.mostrar();
}

void Controlador::opcionG_borrarSalas()
void Controlador::borraPacientesColas()
{
	salaA.vaciar();
	std::cout << "Sala A borrada con exito\n";
	salaB.vaciar();
	std::cout << "Sala B borrada con exito\n";
	salaC.vaciar();
	std::cout << "Sala C borrada con exito\n";
	salaD.vaciar();
	std::cout << "Sala D borrada con exito\n";
}

void Controlador::opcionH_pasarAListas()
void Controlador::enlistarPacientes()
{
	while(!salaA.esVacia()){
<<<<<<< HEAD
		quirofanoApendicitis.insertarEnOrden(salaA.eliminar());
=======
		quirofanoApendicitis.insertarEnOrden(salaA.eliminar()); //He quitado los ; que había detrás del paréntesis salaABCD.eliminar
>>>>>>> cad20a68d21e3a1d60e59fceab87d248b2724942
		
	}
	while(!salaB.esVacia()){
		quirofanoApendicitis.insertarEnOrden(salaB.eliminar());
		
	}
	while(!salaC.esVacia()){
		quirofanoHernias.insertarEnOrden(salaC.eliminar());
		
	}
	while(!salaD.esVacia()){
		quirofanoHernias.insertarEnOrden(salaD.eliminar());
		
	}
}
void Controlador::opcionI_mostrarQuirofanoApendicitis()
void Controlador::muestraPacientesApendicitis()
{
	std::cout << "Quirofano apendicitis:\n";
	quirofanoApendicitis.mostrar();
}

void Controlador::opcionJ_mostrarQuirofanoHernias()
void Controlador::muestraPacientesHernias()
{
	std::cout << "Quirofano hernias:\n";
	quirofanoHernias.mostrar();
}

void Controlador::opcionK_mostrarExtremosPrioridad()
void Controlador::buscarPacientes()
{
	std::cout << "Paciente con apendicitis con menor prioridad:\n";
	quirofanoApendicitis.getUltimo().mostrar();
	std::cout << "Paciente con hernias de mayor prioridad:\n";
	quirofanoHernias.getPrimero().mostrar();
}

void Controlador::opcionL_Reiniciar()
void Controlador::reiniciar()
{
	pilaPacientes.vaciar();
	salaA.vaciar();
	salaB.vaciar();
	salaC.vaciar();
	salaD.vaciar();
	quirofanoApendicitis.vaciar();
	quirofanoHernias.vaciar();
	contadorIdApendicitis = 1;
	contadorIdHernias = 51;
	contadorHabApendicitis = 101;
	contadorHabHernias = 201;
	
}

Controlador::~Controlador()
{
}