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
		last->setNext(nuevo);
		nuevo->setPrevious(last);
		last = nuevo;

		last->setNext(first);
		first->setPrevious(last);
		return true;
	}

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

		if(actual->getTag() != nullptr)
			cout << "( " << actual->getValue() << ", " << actual->getTag() << " )";
		else
			cout << "( " << actual->getValue() << ", " << "empty )";

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


bool VertexSet::tag(const char* _valor, const char* _tag)
{
	if (empty()) {
		return false;
	}

	Vertex* actual = first;
	do {
		if (strcmp(actual->getValue(), _valor) == 0) {
			actual->setTag(_tag);
			return true;
		}

		actual = actual->getNext();;

	} while (actual != first);

	return false;
}
