#include "Paciente.hpp"
Paciente::Paciente(int edad)
{
	this->edad = edad;
	this->genero = (rand() % 2);
	this->generarDNI();
}
int Paciente::getEdad()
{
	return this->edad;
}
bool Paciente::esmujer()
{
	return this->genero;
}
void Paciente::serEdad(int edad)
{
	this->edad - edad;
}
void Paciente::mostrar()
{
	string sexo = "El hombre ";
	if(genero)
		sexo = "La mujer ";
	cout << "\t" << setw(10) << sexo << " con DNI " << DNI << " tiene " << edad << " anyos " << endl;
}
void Paciente::generarDNI()
{
	char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
	int numDNI = 0, aux = 1E7;
	for(int i = 0; i < 8; i++){
		int num = rand() % 10;
		this->DNI[i] = '0' + num;
		numDNI = numDNI + num * aux;
		aux /= 10;
	}
	this->DNI[8] = letras[numDNI % 23];
	this->DNI[9] = '\0';
}
Paciente::~Paciente()
{
}