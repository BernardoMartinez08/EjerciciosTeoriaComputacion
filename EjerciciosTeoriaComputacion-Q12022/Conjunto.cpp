#include "Conjunto.h"
#include <iostream>

using namespace std;

Set::Set() : first(nullptr), last(nullptr) {
}

bool Set::empty() {
	return first == nullptr;
}

void Set::addNode(const char* _valor) {
	Node* nuevo = new Node(_valor, nullptr, nullptr);

	if (empty())
	{
		first = nuevo;
		last = nuevo;
		last->setNext(first);
		first->setPrevious(last);
	}
	else
	{
		last->setNext(nuevo);
		nuevo->setPrevious(last);
		last = nuevo;

		last->setNext(first);
		first->setPrevious(last);
	}

	cout << "Elemento agregado!\n";
}

void Set::deleteNode(const char* _valor) {
	if (empty()) {
		cout << "\nConjunto esta vacio!\n";
		return;
	}

	Node* actual = first;
	do {
		if (strcmp(actual->getValue(), _valor) == 0) {
			if (actual == first) {
				first = actual->getNext();
				first->setPrevious(last);
				last->setNext(first);

			}
			else if (actual == last) {
				last = last->getPrevious();
				last->setNext(first);
				first->setPrevious(last);
			}
			else {
				actual->getPrevious()->setNext(actual->getNext());
				actual->getNext()->setPrevious(actual->getPrevious());
			}

			delete actual;
			return;
		}
		actual = actual->getNext();
	} while (actual != first);
}

void Set::print() {
	if (empty()) {
		cout << "\nConjunto esta vacio!\n";
		return;
	}

	Node* actual = first;
	cout << "\n";
	do {
		cout << "[ " << actual->getValue() << " ] ";
		actual = actual->getNext();
	} while (actual != first);

	cout << std::endl;
}