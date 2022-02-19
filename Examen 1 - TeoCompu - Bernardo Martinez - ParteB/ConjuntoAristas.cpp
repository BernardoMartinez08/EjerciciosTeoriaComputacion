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
