#pragma once
#ifndef  VERTICES_H
#define VERTICES_H

#include "Vertice.h"

class VertexSet {
public:
	/*
		Constructor sin parametros.
	*/
	VertexSet();
	/*
		Funcion para agregar un nuevo vertice, pide como parametros el valor
		que representan el valor del vertice.
	*/
	bool add(const char*);

	/*
		Funcion que imprime en consola el conjunto de vertices.
	*/
	void print();
	/*
		Funcion que devuelve el tamano total del conjunto de aristas.
	*/
	int size();

	/*
		Funcion que devuelve el apuntador al primer vertice del conjunto.
	*/
	Vertex* getFirst();
private:
	//Apuntador al primer vertice del conjunto.
	Vertex* first;
	//Apuntador al ultimo vertice del conjunto.
	Vertex* last;

	/*
		Funcion que nos devulve si el conjunto esta vacio o no.
	*/
	bool empty();
	/*
		Funcion que nos devuelve si un vertice esta incluido en el
		conjunto de vertices.
	*/
	bool belong(const char*);
};
#endif // ! VERTICES_H