#pragma once
#ifndef  ARISTAS_H
#define ARISTAS_H

#include "Arista.h"

class EdgesSet {
public:
	/*
		Constructor sin parametros.
	*/
	EdgesSet();
	/*
		Funcion para agregar una nueva arista, pide como parametros los valores
		que representan los componentes x y y del par ordenado.
	*/
	bool add(const char*, const char*);

	/*
		Funcion que imprime en consola el conjunto de aristas.
	*/
	void print();
	/*
		Funcion que devuelve el tamano total del conjunto de aristas.
	*/
	int size();

	/*
		Funcion que devuelve el apuntador a la primera arista del conjunto.
	*/
	Edge* getFirst();

	/*
		Funcion que nos devuelve si un par ordenado x,y esta incluido en el
		conjunto de aristas.
	*/
	bool belong(const char*, const char*);
private:
	//Apuntador a la primer arista del conjunto.
	Edge* first;
	//Apuntador a la ultima arista del conjunto
	Edge* last;

	/*
		Funcion que nos devulve si el conjunto esta vacio o no
	*/
	bool empty();
};
#endif // ! ARISTAS_H
