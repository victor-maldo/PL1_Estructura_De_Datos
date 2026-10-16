#include <iostream>
#include <iomanip>
using namespace std;

class Paciente
{
public:
	Paciente(int edad);
	int getEdad();
	bool esMujer();
	void setEdad(int edad);
	void mostar();
	~Paciente();
private:
	bool genero;
	int edad;
	char DNI[10];
	
	void generarDNI();
};