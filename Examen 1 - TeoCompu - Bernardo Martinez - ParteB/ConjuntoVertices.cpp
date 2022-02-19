#include "ConjuntoVertices.h"
#include <iostream>

using namespace std;

VertexSet::VertexSet() : first(nullptr), last(nullptr) {
}

bool VertexSet::empty() {
	return first == nullptr;
}

Vertex* VertexSet::getFirst() {
	return first;
}

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

	cout << "}";
}

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