#include "stdafx.h"
#include "ElementoPersona.h"


ElementoPersona::ElementoPersona(int id, string nombre) {
	this->id = id;
	this->nombre = nombre;
}

ElementoPersona::~ElementoPersona() {
}

int ElementoPersona::getId() {
	return id;
}

string ElementoPersona::getNombre() {
	return nombre;
}

void ElementoPersona::setId(int id) {
	this->id = id;
}

void ElementoPersona::setNombre(string nombre) {
	this->nombre = nombre;
}

void ElementoPersona::imprimir(ostream& out) const {
	out << id << " - " << nombre;
}