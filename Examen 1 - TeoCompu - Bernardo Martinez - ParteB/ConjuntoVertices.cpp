#include "ConjuntoVertices.h"
#include <iostream>

using namespace std;


/*
	Constructor sin parametros, el mismo establece el primer y ultimo vertice del conjunto de los mismos
	apuntando a nullptr.
*/
VertexSet::VertexSet() : first(nullptr), last(nullptr) {
}

/*
	Funcion que nos devulve si el conjunto esta vacio o no dependiendo si el primer elemento del conjunto
	apunta a nullptr o no.
*/
bool VertexSet::empty() {
	return first == nullptr;
}

/*
	Funcion que devuelve el apuntador al primer vertice del conjunto.
*/
Vertex* VertexSet::getFirst() {
	return first;
}

/*
	Funcion para agregar un nuevo vertice, pide como parametros el valor que
	representa el valor de la arista.

	El procedimiento del mismo crea un nuevo vertice, luego verifica si el
	conjunto de vertices esta vacio y si lo esta agraga un nuevo vertice, de
	lo contrario busca si el vertice a crear ya existe si no es el caso ento-
	ces se procede a agregar el nuevevo vertice, si ya existe no se agrega.
*/
bool VertexSet::add(const char* _valor) {
	Vertex* nuevo = new Vertex(_valor, nullptr, nullptr);

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
		if (!belong(nuevo->getValue())) {
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
	Funcion que nos devuelve si un vertice esta incluido en el conjunto de vertices para ello realiza
	una verificacion si el conjunto esta vacio retorna falso, de lo contrario realiza un recorrido en el con-
	junto de vertices si este existe retorna verdadero al final si no se encuentra retorna falso.
*/
bool VertexSet::belong(const char* _valor) {
	if (empty()) {
		cout << "\nConjunto esta vacio!\n";
		return false;
	}

	Vertex* actual = first;
	do {
		if (strcmp(actual->getValue(), _valor) == 0) {
			return true;
		}

		actual = actual->getNext();;

	} while (actual != first);

	return false;
}

/*
	Funcion que imprime en consola el conjunto de vertices, esta impresion en consola si el conjunto esta vacio
	imprime un conjunto vacio, de lo contrario recorre todo el conjunto e imprime cada uno de los vertices en
	el siguiente formato {a,b}.

	Cada vertice se imprime en el formato anteriro descrito cada vertice separado por comas a,b ademas estos van
	encerrados entre llaves {}.
*/
void VertexSet::print() {
	if (empty()) {
		cout << "{ vacio }";
		return;
	}

	Vertex* actual = first;
	cout << "{ ";
	do {
		if (actual != first)
			cout << " , ";

		cout << actual->getValue();

		actual = actual->getNext();
	} while (actual != first);

	cout << " }";
}

/*
	Funcion que devuelve el tamano total del conjunto de vertices para ello realiza una verificacion si el
	conjunto esta vacio retorna 0 porque no hay elementos, de lo contrario realiza un recorrido en el con-
	junto de vertices y va sumando cada vertice recorrido, al final devuelve el tamano total recontado.
*/
int VertexSet::size()
{
	if (empty()) {
		return 0;
	}

	int _size = 0;
	Vertex* actual = first;
	do {
		_size++;
		actual = actual->getNext();;

	} while (actual != first);

	return _size;
}
