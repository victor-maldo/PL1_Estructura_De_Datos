#ifndef PACIENTE_HPP
#define PACIENTE_HPP

#include <iostream>
#include <string>
using namespace std;

class Paciente
{
public:
    Paciente();
    Paciente(int numeroDni, bool apendicitis);
    ~Paciente();

    string getDni();
    int getId();
    int getHabitacion();
    bool tieneApendicitis();

    void setId(int id);
    void setHabitacion(int habitacion);

    void mostrar();

private:
    string dni;
    int id;
    int habitacion;
    bool apendicitis;
};

#endif