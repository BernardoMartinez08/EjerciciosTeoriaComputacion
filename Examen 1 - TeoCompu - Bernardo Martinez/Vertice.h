#pragma once
#ifndef  VERTICE_H
#define VERTICE_H

class Vertex {
public:
	/*
		Constructor que le da valor de nullptr a el valor del vertice y apuntadores que representan
		el anterior y siguiente vertice, ademas en este constructor no se pide un valor para la
		etiqueta que tiene cada vertice.
	*/
	Vertex() : value(nullptr), next(nullptr), previous(nullptr) {};
	/*
		Constructor que recibe los parametros para inicializar un vertice y ademas valores
		para el anterior y siguiente vertice, ademas en este constructor no se pide un valor
		para la etiqueta que tiene cada vertice..
	*/
	Vertex(const char*, Vertex*, Vertex*);


	/*
		Funcion para darle valor al vertice
	*/
	void setValue(const char*);
	/*
		Funcion para darle valor a la etiqueta correspondiente al vertice
	*/
	void setTag(const char*);

	/*
		Funcion para indicar hacia donde apunta el apuntador de siguiente de el vertice, osea cual es el vertice siguiente.
	*/
	void setNext(Vertex*);
	/*
		Funcion para indicar hacia donde apunta el apuntador de anterior de el vertice, osea cual es el vertice anterior.
	*/
	void setPrevious(Vertex*);

	/*
		Funcion que devuelve el valor del vertice.
	*/
	char* getValue();
	/*
		Funcion que devuelve el valor de la etiqueta correspondinte al vertice.
	*/
	char* getTag();

	/*
		Funcion que devuelve el apuntador al siguiente vertice.
	*/
	Vertex* getNext();
	/*
		Funcion que devuelve el apuntador al anterior vertice.
	*/
	Vertex* getPrevious();

private:
	//Apuntador al valor del verrtice
	char* value;
	//Apuntador al valor de la etiqueta correspondiente al vertice
	char* tag = nullptr;

	//Apuntador al siguiente vertice.
	Vertex* next;
	//Apuntador al anterior vertice.
	Vertex* previous;
};
#endif // ! VERTICE_H