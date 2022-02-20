#include "Arista.h"
#include <iostream>

using namespace std;

/*
	Constructor que le da valor con los parametros recibidos a los valores del par ordenado x, y y apuntadores que representan
	la anterior y siguiente arista.
*/
Edge::Edge(const char* _valorX, const char* _valorY, Edge* _sig, Edge* _ant) : next(_sig), previous(_ant) {
	valueX = new char[strlen(_valorX)];
	strcpy_s(valueX, strlen(_valorX) + 1, _valorX);

	valueY = new char[strlen(_valorY)];
	strcpy_s(valueY, strlen(_valorY) + 1, _valorY);
}

/*
	Funcion para darle valor al par ordenado que conforma la arista se recibe el componente x y el componente y se verifica que
	los valores esten en nullptr inicialmente, sino se elimina su valor y se le asigna el nuevo valor.
*/
void Edge::setValue(const char* _valorX, const char* _valorY) {
	if (valueX != nullptr)
		delete valueX;

	valueX = new char[strlen(_valorX)];
	strcpy_s(valueX, strlen(_valorX) + 1, _valorX);

	if (valueY != nullptr)
		delete valueY;

	valueY = new char[strlen(_valorY)];
	strcpy_s(valueY, strlen(_valorY) + 1, _valorY);
}

/*
	Funcion que actualiza el apuntador de siguiente de la arista, osea indica cual es la arista siguiente.
*/
void Edge::setNext(Edge* _sig) {
	this->next = _sig;
}

/*
	Funcion que actualiza el apuntador de anterior de la arista, osea indica cual es la arista anterior.
*/
void Edge::setPrevious(Edge* _ant) {
	this->previous = _ant;
}


/*
	Funcion que devuelve el valor del componente en x del par ordenado.
*/
char* Edge::getValueX() {
	return this->valueX;
}

/*
	Funcion que devuelve el valor del componente en y del par ordenado.
*/
char* Edge::getValueY() {
	return this->valueY;
}

/*
	Funcion que devuelve el apuntador a la siguiente arista.
*/
Edge* Edge::getNext() {
	return this->next;
}

/*
	Funcion que devuelve el apuntador a la anterior arista.
*/
Edge* Edge::getPrevious() {
	return this->previous;
}