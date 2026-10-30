#include "Paciente.hpp"
#include <iomanip>

Paciente::Paciente()
{
    dni = "";
    id = 0;
    habitacion = 0;
    apendicitis = false;
}

Paciente::Paciente(int numeroDni, bool apendicitis)
{
    const string letras = "TRWAGMYFPDXBNJZSQVHLCKE";

    string numero = to_string(numeroDni);
    while (numero.length() < 8)          
        numero = "0" + numero;

    dni = numero + letras[numeroDni % 23];
    this->apendicitis = apendicitis;
    id = 0;
    habitacion = 0;
}

Paciente::~Paciente() {}

string Paciente::getDni()           
{ 
	return dni; 
}

int    Paciente::getId()            
{ 
	return id; 
}

int    Paciente::getHabitacion()    
{ 
	return habitacion; 
}

bool   Paciente::tieneApendicitis() 
{ 
	return apendicitis; 
}

void Paciente::setId(int id)                 
{ 
	this->id = id; 
}

void Paciente::setHabitacion(int habitacion) 
{ 
	this->habitacion = habitacion; 
}

void Paciente::mostrar()
{
    cout << "El paciente cuyo DNI es " << dni;
    if (apendicitis)
        cout << " tiene apendicitis";
    else
        cout << "     tiene hernias";      

    if (id != 0)
        cout << ", su ID es: " << setw(2) << id
             << " y su habitacion asignada es: " << habitacion;
    cout << endl;
}