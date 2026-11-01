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

	for(int i = 0; i < 100; i++)        
		idUsado[i] = false;
	for(int i = 0; i < 300; i++)        
		habUsada[i] = false;
}

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


void Controlador::genera12Pacientes()
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
			int dni = (rand() % 10000) * 10000 + rand() % 10000;
			Paciente* nuevoPaciente = new Paciente(dni, enfermedad);
			
			pilaPacientes.insertar(nuevoPaciente);
			
			std::cout << "Paciente con DNI: " << nuevoPaciente->getDni() << " y con " << (enfermedad ? "Apendicitis" : "Hernia") << " creado correctamente.\n";
 
		}
	}
}

void Controlador::muestraPacientes()
{
	std::cout << "Pacientes en la pila:\n";
	pilaPacientes.mostrar();
}

void Controlador::borraPacientesPila()
{
	pilaPacientes.vaciar();
	std::cout << "Pila de pacientes vaciada con éxito\n";
}

void Controlador::encolarPacientes()
{
	char sala;
	while (pilaPacientes.getLongitud() > 0){
		Paciente* paciente = pilaPacientes.cima();
		if(paciente->tieneApendicitis()){

			if(contadorIdApendicitis > 49){                                  
				std::cout << "No quedan IDs libres para apendicitis\n";
				break;
			}
			int id, hab;                                                     
			do { id = rand() % 49 + 1; } while(idUsado[id]);                 
			do { hab = rand() % 99 + 101; } while(habUsada[hab]);            
			idUsado[id] = true;                                              
			habUsada[hab] = true;                                            

			paciente->setId(id);                                             
			paciente->setHabitacion(hab);                                    
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

			if(contadorIdHernias > 99){                                      
				std::cout << "No quedan IDs libres para hernias\n";
				break;
			}
			int id, hab;                                                     
			do { id = rand() % 49 + 51; } while(idUsado[id]);                
			do { hab = rand() % 99 + 201; } while(habUsada[hab]);            
			idUsado[id] = true;                                              
			habUsada[hab] = true;                                            

			paciente->setId(id);                                             
			paciente->setHabitacion(hab);                                    
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
		std::cout << "Paciente :" << paciente->getDni() << " insertado en la sala " << sala << " en la habitación " << paciente->getHabitacion() << "\n"; 
		pilaPacientes.extraer();
		
	}

}



void Controlador::muestraPacientesSalasAyB()
{
	std::cout << "Sala A:\n";
	salaA.mostrar();
	std::cout << "Sala B:\n";
	salaB.mostrar();
}

void Controlador::muestraPacientesSalasCyD()
{
	std::cout << "Sala C:\n";
	salaC.mostrar();
	std::cout << "Sala D:\n";
	salaD.mostrar();
}

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

void Controlador::enlistarPacientes()
{
	while(!salaA.esVacia()){
		quirofanoApendicitis.insertarEnOrden(salaA.eliminar()); 
		
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

void Controlador::muestraPacientesApendicitis()
{
	std::cout << "Quirofano apendicitis:\n";
	quirofanoApendicitis.mostrar();
}

void Controlador::muestraPacientesHernias()
{
	std::cout << "Quirofano hernias:\n";
	quirofanoHernias.mostrar();
}

void Controlador::buscarPacientes()
{
	if(quirofanoApendicitis.esVacia()){                                   
		std::cout << "No hay pacientes con apendicitis en el quirofano\n";
	}else{
		std::cout << "Apendicitis menor prioridad -> ";
		quirofanoApendicitis.getUltimo()->mostrar();
	}
	if(quirofanoHernias.esVacia()){                                       
		std::cout << "No hay pacientes con hernias en el quirofano\n";
	}else{
		std::cout << "Hernias mayor prioridad -> ";
		quirofanoHernias.getPrimero()->mostrar();
	}
}

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

	for(int i = 0; i < 100; i++)        
		idUsado[i] = false;
	for(int i = 0; i < 300; i++)        
		habUsada[i] = false;
}
Controlador::~Controlador()
{
}