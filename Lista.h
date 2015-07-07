#pragma once

#include "Nodo.h"
using namespace std;

template<class T>
class Lista {

	template<class T>
	friend ostream& operator<<(ostream &, const Lista<T>&);

	Nodo<T> * primero; // apunta a la primer Nodo de la lista
	Nodo<T> * ultimo;  // apunta a la ultimo Nodo de la lista

	int longitud;        // cantidad de elementos

public:
	Lista(){
		primero = 0;
		ultimo = 0;
		longitud = 0;
	}

	~Lista(){
		if (this->primero){
			delete this->primero;		//Destruyendo el primer Nodo se destruyen todos
		}
	}

	int esPosicionValida(int){
		return (posicion >= 0 && posicion < longitud);
	}

	// Retorna puntero a la Nodo anterior al indicado
	Nodo<T> * anterior(int posicion){
		Nodo * anteriorPtr = primero;
		int i = 0;
		while (anteriorPtr && i < (posicion - 1)){
			anteriorPtr = anteriorPtr->siguiente;
			i++;
		}
		return anteriorPtr;
	}

	Lista(const Lista&){
		primero = ultimo = 0;
		longitud = 0;
		if (otra.primero){
			this->agregarAlFinal(otra.primero->elemento);
			Nodo * actualPtr = otra.primero;
			while (actualPtr->siguiente){
				this->agregarAlFinal(actualPtr->siguiente->elemento);
				actualPtr = actualPtr->siguiente;
			}
		}

	}

	
	int vacia(){
		return !primero;
	}

	int tamano(){
		return longitud;
	}

	void agregarAlFinal(T elemento){
		Nodo<T> * nuevaPtr = new Nodo<T>(elemento);
		if (vacia()){
			primero = ultimo = nuevaPtr;
		}
		else {
			nuevaPtr->anterior = ultimo;
			ultimo->siguiente = nuevaPtr;
			ultimo = nuevaPtr;
		}
		longitud++;
	}

	void agregarEnMedio(int, T);  // Agregar una Nodo nuevo con en una posicion > 0 y < longitud
	
	// retorna el elemento ubicado en la posicion int, si no existe la posicion retorna null

	T getElemento(int posicion){
		Nodo * actualPtr = anterior(0);
		Elemento resultado = actualPtr->elemento;
		if (esPosicionValida(posicion)){ // Si la posicion es valida!
			actualPtr = anterior(posicion + 1);
			resultado = actualPtr->elemento;
		}
		return resultado;
	}

	//reemplaza un elemento con otro enviado como parametro
	int reemplazar(int posicion, T dato)	{
		if (esPosicionValida(posicion)){

			int i = 0;
			Nodo* it = primero;

			while (i<posicion){
				it->siguiente;
				i++;
			}

			it->elemento = elemento;
			return 0;

		}
		else{
			return -2;
		}

	}

};

template<class T>
ostream& operator<<(ostream & salida, const Lista<T>& lista){
	//salida << " { ";
	if (lista.primero){
		salida << *(lista.primero); // invoca al operator<<(cout, const Nodo& primero)
	}
	salida << endl;
	return salida;
}