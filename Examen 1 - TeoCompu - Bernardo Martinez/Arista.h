#pragma once
#ifndef  ARISTA_H
#define ARISTA_H

class Edge {
public:
	/*
		Constructor que le da valor de nullptr a los valores del par ordenado x, y y apuntadores que representan
		la anterior y siguiente arista.
	*/
	Edge() : valueX(nullptr), valueY(nullptr), next(nullptr), previous(nullptr) {};
	/*
		Constructor que recibe los parametros para inicializar una arista con sus valores para x y y y ademas valores
		para la anterior y siguiente arista.
	*/
	Edge(const char*, const char*, Edge*, Edge*);

	/*
		Funcion para darle valor al par ordenado que confirma la arista se recibe el componente x y el componente y.
	*/
	void setValue(const char*, const char*);

	/*
		Funcion para indicar hacia donde apunta el apuntador de siguiente de la arista, osea cual es la arista siguiente.
	*/
	void setNext(Edge*);
	/*
		Funcion para indicar hacia donde apunta el apuntador de anterior de la arista, osea cual es la arista anterior.
	*/
	void setPrevious(Edge*);


	/*
		Funcion que devuelve el valor del componente en x del par ordenado.
	*/
	char* getValueX();
	/*
		Funcion que devuelve el valor del componente en y del par ordenado.
	*/
	char* getValueY();


	/*
		Funcion que devuelve el apuntador a la siguiente arista.
	*/
	Edge* getNext();
	/*
		Funcion que devuelve el apuntador a la anterior arista.
	*/
	Edge* getPrevious();

private:
	//Componente x del par ordenado que forma la arista.
	char* valueX;
	//Componente y del par ordenado que forma la arista.
	char* valueY;

	//Apuntador a la siguiente arista.
	Edge* next;
	//Apuntador a la anterior arista.
	Edge* previous;
};
#endif // ! ARISTA_H
