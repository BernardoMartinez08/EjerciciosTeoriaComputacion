#include "ConjuntoAristas.h"
#include <iostream>

using namespace std;

/*
	Constructor sin parametros, el mismo establece la primera y ultima arista del conjunto de las mismas
	apuntando a nullptr.
*/
EdgesSet::EdgesSet() : first(nullptr), last(nullptr) {
}

/*
	Funcion que nos devulve si el conjunto esta vacio o no dependiendo si el primer elemento del conjunto
	apunta a nullptr o no.
*/
bool EdgesSet::empty() {
	return first == nullptr;
}


/*
	Funcion que devuelve el apuntador a la primera arista del conjunto.
*/
Edge* EdgesSet::getFirst() {
	return first;
}

/*
	Funcion para agregar una nueva arista, pide como parametros los valores
	que representan los componentes x y y del par ordenado.

	El procedimiento del mismo crea una nueva arista, luego verifica si el
	conjunto de aristas esta vacia y si lo esta agraga una nueva arista, de
	lo contrario busca si la arista a crear ya existe si no es el caso ento-
	ces se procede a agregar la arista, si ya existe no se agrega.
*/
bool EdgesSet::add(const char* _valorX, const char* _valorY) {
	Edge* nuevo = new Edge(_valorX, _valorY, nullptr, nullptr);

	if (empty())
	{
		first = nuevo;
		last = nuevo;
		last->setNext(first);
		first->setPrevious(last);
		return true;
	}
	else
	{
		if (!belong(nuevo->getValueX(), nuevo->getValueY())) {
			last->setNext(nuevo);
			nuevo->setPrevious(last);
			last = nuevo;

			last->setNext(first);
			first->setPrevious(last);
			return true;
		}
	}

	return false;
}

/*
	Funcion que imprime en consola el conjunto de aristas, esta impresion en consola si el conjunto esta vacio
	imprime un conjunto vacio, de lo contrario recorre todo el conjunto e imprime cada una de las aristas en
	el siguiente formato {(a,b),(b,c)}
	
	Cada arista se imprime con sus dos componente separados por como x,y ademas este par ordenado entre parem-
	tesis (x,y) si existen varias aristas estas van separadas por una coma, y al final estas estan encerradas
	entre llaves {}.
*/
void EdgesSet::print() {
	if (empty()) {
		cout << "{ vacio }";
		return;
	}

	Edge* actual = first;
	cout << "{ ";
	do {
		if (actual != first)
			cout << " , ";

		
		cout << "( " << actual->getValueX() << ", " << actual->getValueY() << " )";
		actual = actual->getNext();
	} while (actual != first);

	cout << " }";
}

/*
	Funcion que nos devuelve si un par ordenado x,y esta incluido en elconjunto de aristas para ello realiza
	una verificacion si el conjunto esta vacio retorna falso, de lo contrario realiza un recorrido en el con-
	junto de aristas si esta existe retorna verdadero al final si no se encuentra retorna falso.
*/
bool EdgesSet::belong(const char* _valorX, const char* _valorY) {
	if (empty()) {
		cout << "\nConjunto esta vacio!\n";
		return false;
	}

	Edge* actual = first;
	do {
		if (strcmp(actual->getValueX(), _valorX) == 0 && strcmp(actual->getValueY(), _valorY) == 0) {
			return true;
		}

		actual = actual->getNext();;

	} while (actual != first);

	return false;
}

/*
	Funcion que devuelve el tamano total del conjunto de aristas para ello realiza una verificacion si el 
	conjunto esta vacio retorna 0 porque no hay elementos, de lo contrario realiza un recorrido en el con-
	junto de aristas y va sumando cada arista recorrido, al final devuelve el tamano total recontado.
*/
int EdgesSet::size()
{
	if (empty()) {
		return 0;
	}

	int _size = 0;
	Edge* actual = first;
	do {
		_size++;
		actual = actual->getNext();;

	} while (actual != first);

	return _size;
}
