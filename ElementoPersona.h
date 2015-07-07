#pragma once

#include "Elemento.h"
using namespace std;

class ElementoPersona {

protected:
	int id;
	string nombre;

public:
	ElementoPersona(int, string);
	~ElementoPersona();
	int compareTo(Elemento *);
	void imprimir(ostream &) const;

	void setId(int);
	void setNombre(string);
	int getId();
	string getNombre();
};