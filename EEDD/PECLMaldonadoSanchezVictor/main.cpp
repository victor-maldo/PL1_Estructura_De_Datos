#include "Controlador.hpp"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	Controlador Controlador;
	char opcion;

	do {
		cout << "\tPacientes en la pila -> " << Controlador.pacientesEnPila() << "\n\tPacientes en las colas:\n \t\tSala A-> " << Controlador.pacientesEnSalaA() << "\tSala B-> "
             << Controlador.pacientesEnSalaB() << "\tSala C-> " << Controlador.pacientesEnSalaC() << "\tSala D-> " << Controlador.pacientesEnSalaD()
             << " \n\tPacientes en las listas:\n \t\tQuirofano Apendicitis-> " << Controlador.pacientesEnListaApendicitis() << "\tQuirofano hernias-> " << Controlador.pacientesEnListaHernias() 
             << "\n\tPacientes en el arbol -> " << 0 /*controlador.pacientesEnArbol()*/ << "\n";
        cout << "\t----------------------------------------------------------------------\n\n";

		cout << "\tA. Generar 12 pacientes de forma aleatoria y almacenarlos en la Pila.\n";
        cout << "\tB. Consultar todos los pacientes generados en la Pila (pendientes de entrar en las salas).\n";
        cout << "\tC. Borrar los pacientes generados en la pila.\n";
        cout << "\tD. Simular llegada de los pacientes en las colas.\n";
        cout << "\tE. Consultar los pacientes de las salas A y B.\n";
        cout << "\tF. Consultar los pacientes de las salas C y D.\n";
        cout << "\tG. Borrar los todos los pacientes de las salas.\n";
        cout << "\tH. Simular la entrada de los pacientes a los quirofanos (a las listas).\n";
        cout << "\tI. Mostrar los pacientes que hay en el quirofano que atiende apendicitis.\n";
        cout << "\tJ. Mostrar los pacientes que hay en el quirofano que atiende hernias.\n";
        cout << "\tK. Buscar en las listas el paciente con apendicitis de menor prioridad y el de hernia con mayor "
                "prioridad.\n";
        cout << "\tL. Reiniciar el programa.\n";
        cout << "\tM. Crear y dibujar el ABB en consola.\n";
        cout << "\tN. Mostrar los datos de todos los pacientes con apendicitis ordenados por numero de habitacion en orden ascendente.\n";
        cout << "\tO. Mostrar los datos de todos los pacientes con hernias ordenados por numero de habitacion en orden ascendente.\n";
        cout << "\tP. Mostrar los datos de todos los pacientes recorriendo el arbol en inorden.\n";
        cout << "\tQ. Buscar en el ABB los pacientes con apendicitis de la habitacion cuyo numero es el mayor y cuyo numero es el menor y los pacientes con "
                "hernias de la habitacion cuyo numero es el mayor y cuyo numero es el menor.\n";
        cout << "\tR. Contar el numero de pacientes almacenados en el ABB cuyos numeros de habitacion son impares.\n";
        cout << "\tT. Mostrar los pacientes que se encuentran almacenados en un nodo hoja.\n";
        cout << "\tU. Eliminar un paciente indicado por su numero de habitacion (que se pide desde consola) y mostrar el arbol "
                "resultante tras la eliminacion de dicho paciente.\n";
        cout << "\tS. Salir.\n\n";

		cout << "\tIndique la opcion deseada: ";
		cin >> opcion;
		opcion = toupper(opcion);
		// system("clear");
		system("cls");

		switch(opcion) {

		case 'A':
			Controlador.genera12Pacientes();
			break;
		case 'B':
			Controlador.muestraPacientes();
			break;
		case 'C':
			Controlador.borraPacientesPila();
			break;
		case 'D':
			Controlador.encolarPacientes();
			break;
		case 'E':
			Controlador.muestraPacientesSalasAyB();
			break;
		case 'F':
			Controlador.muestraPacientesSalasCyD();
			break;
		case 'G':
			Controlador.borraPacientesColas();
			break;
		case 'H':
			Controlador.enlistarPacientes();
			break;
		case 'I':
			Controlador.muestraPacientesApendicitis();
			break;
		case 'J':
			Controlador.muestraPacientesHernias();
			break;
		case 'K':
			Controlador.buscarPacientes();
			break;
		case 'L':
			Controlador.reiniciar();
			break;
		case 'M':
			//...;
			break;
		case 'N':
			//...;
			break;
		case 'O':
			//...;
			break;
		case 'P':
			//...;
			break;
		case 'Q':
			//...;
			break;
		case 'R':
			//...;
			break;
		case 'T':
			//...;
			break;
		case 'U':
			//...;
			break;
		case 'S':
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opcion incorrecta!\n\n";
			break;
		}
	} while(opcion != 'S');

	return 0;
}