#pragma once

#include <iostream>

template<class T>
class Nodo {

	template<class T>
	friend ostream& operator<<(ostream &salida, const Nodo<T>& Nodo);

public:
	T elemento;
	Nodo<T> * siguiente;	// Apunta la siguiente Nodo en la lista
	Nodo<T> * anterior;		// Apunta a la Nodo anterior en la lista

	Nodo(T elemento){
		this->elemento = elemento;
		//this->anterior = null;
		//this->siguiente = null;
		
	}

	~Nodo(){
		if (this->siguiente){
			delete this->siguiente;
		}
	}

};

template<class T>
ostream& operator<<(ostream &salida, const Nodo<T>& Nodo){
	salida << Nodo.elemento;
	if (Nodo.siguiente){
		//salida << " , ";
		salida << endl;
		salida << *(Nodo.siguiente); // Llamado recursivo a si mismo
	}
	return salida;
}