#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>
#include "ConjuntoAristas.h"
#include "ConjuntoVertices.h"
#include <string>

using namespace std;

class Graph {
public:
	/*
		Constructor que recibe como parametro un string que contiene el grafo en 
		un formato crudo o texto plano en otras palabras.
	*/
	Graph(string);

	/*
		Funcion que nos permite imprimir en consola los vertices y las aristas en
		formato de tabla o matriz.
	*/
	void print();
	/*
		Funcion que permite imprimir en consola los vertices y las aristas, pero en
		este caso imprime las aristas mostrando el vertice y luego todas sus aristas.
	*/
	void printAdjacencyMatrix();

	/*
		Funcion que pide como parametros los vertices seleccionador por cada jugador
		y luego revisa la tabla y devuelve un texto indicando el ganador.
	*/
	string play(int, int);

private:
	//string que almacena el grafo en formato de texto plano.
	string rootGraph = "";

	//Apuntador al conjunto de vertices del grafo o {V}.
	VertexSet* vertices;
	//Apuntador al conjunto de aristas del grafo o {E}.
	EdgesSet* edges;
	//Arreglo que almcena una matriz de adyacencia donde se representan las aristas.
	int** adjacencyMatrix;

	/*
		Funcion para agregar un nuevo vertice, pide como parametros el valor
		que representan el valor del vertice.
	*/
	void addVertex(const char*);
	/*
		Funcion para agregar una nueva arista, pide como parametros los valores
		que representan los componentes x y y del par ordenado.
	*/
	void addEdges(const char*, const char*);

	/*
		Funcion que devuelve la matriz de adyacencia la cual es construida mediante
		el recorrido de las aristas.
	*/
	vector<vector<const char*>> getAdjacencyMatrix();

	/*
		Funcion que devuelve el indice o posicion de un vertice en el conjunto de vertices.
	*/
	int getVertexIndex(const char*);

	/*
		Funcion que permite convertir un grafo en formato de texto plano a conjuntos
		separados de vertices y aristas, extrayendo solo los valores obviando el formato
		osea los parentesis, comas y llaves.
	*/
	void convert();
};

#endif // !GRAFO_H