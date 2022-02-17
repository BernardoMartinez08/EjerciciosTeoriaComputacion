#include "ConjuntoAristas.h"
#include <iostream>

using namespace std;

EdgesSet::EdgesSet() : first(nullptr), last(nullptr) {
}

bool EdgesSet::empty() {
	return first == nullptr;
}

Edge* EdgesSet::getFirst() {
	return first;
}

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
		last->setNext(nuevo);
		nuevo->setPrevious(last);
		last = nuevo;

		last->setNext(first);
		first->setPrevious(last);
		return true;
	}

	return false;
}

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

	cout << "}";
}

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
