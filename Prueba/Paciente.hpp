#include <iostream>
#include <iomanip>
using namespace std;

class Persona
{
public:
	Persona(int edad);
	int getEdad();
	bool esMujer();
	void setEdad(int edad);
	void mostar();
	~Persona();
private:
	bool genero;
	int edad;
	char DNI[10];
	
	void generarDNI();
};