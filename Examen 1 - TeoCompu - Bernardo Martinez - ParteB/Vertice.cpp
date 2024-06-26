#include "Vertice.h"
#include <iostream>

using namespace std;

/*
	Constructor que recibe los parametros para inicializar un vertice y ademas valores
	para el anterior y siguiente vertice.
*/
Vertex::Vertex(const char* _valor, Vertex* _sig, Vertex* _ant) : next(_sig), previous(_ant) {
	value = new char[strlen(_valor)];
	strcpy_s(value, strlen(_valor) + 1, _valor);
}

/*
	Funcion para darle valor al vertice, esta funcion verifica si el apuntdor esta a nullptr
	de lo contrario borra el valor actual que posee y lo sustituye con el nuevo valor recibido
	de parametro.
*/
void Vertex::setValue(const char* _valor) {
	if (value != nullptr)
		delete value;

	value = new char[strlen(_valor)];
	strcpy_s(value, strlen(_valor) + 1, _valor);
}

/*
	Funcion para indicar hacia donde apunta el apuntador de siguiente de el vertice, osea cual es el vertice siguiente,
	para ello recibe el nuevo siguiente y lo asigna.
*/
void Vertex::setNext(Vertex* _sig) {
	this->next = _sig;
}

/*
	Funcion para indicar hacia donde apunta el apuntador de anterior de el vertice, osea cual es el vertice anterior,
	para ello recibe el nuevo siguiente y lo asigna.
*/
void Vertex::setPrevious(Vertex* _ant) {
	this->previous = _ant;
}

/*
	Funcion que devuelve el valor del vertice.
*/
char* Vertex::getValue() {
	return this->value;
}

/*
	Funcion que devuelve el apuntador al siguiente vertice.
*/
Vertex* Vertex::getNext() {
	return this->next;
}

/*
	Funcion que devuelve el apuntador al anterior vertice.
*/
Vertex* Vertex::getPrevious() {
	return this->previous;
}