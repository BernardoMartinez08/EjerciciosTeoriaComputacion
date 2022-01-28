#include "Conjunto.h"
#include <iostream>

using namespace std;

Set::Set() : first(nullptr), last(nullptr) {
}

bool Set::empty() {
	return first == nullptr;
}

bool Set::addNode(const char* _valor) {
	Node* nuevo = new Node(_valor, nullptr, nullptr);

	if (empty())
	{
		first = nuevo;
		last = nuevo;
		last->setNext(first);
		first->setPrevious(last);
		cout << "Elemento: " << _valor << " agregado!\n";
		return true;
	}
	else
	{
		last->setNext(nuevo);
		nuevo->setPrevious(last);
		last = nuevo;

		last->setNext(first);
		first->setPrevious(last);
		cout << "Elemento: " << _valor << " agregado!\n";
		return true;
	}

	cout << "Elemento: " << _valor << " no fue agregado!\n";
	return false;
}

bool Set::deleteNode(const char* _valor) {
	if (empty()) {
		cout << "\nConjunto esta vacio!\n";
		return false;
	}
	else if (notBelong(_valor)) {
		cout << "Elemento: " << _valor << " no encontrado en el conjunto!\n";
		return false;
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
		}

		actual = actual->getNext();;

	} while (actual != first);

	cout << "Elemento: " << _valor << " eliminado!\n";
	return true;
}

void Set::print() {
	if (empty()) {
		cout << "\nConjunto esta vacio!\n";
		return;
	}

	Node* actual = first;
	cout << "\n{ ";
	do {
		if (actual != first)
			cout << " , ";

		cout << actual->getValue();
		actual = actual->getNext();
	} while (actual != first);

	cout << "}\n\n";
}

bool Set::belong(const char* _valor){
	if (empty()) {
		cout << "\nConjunto esta vacio!\n";
		return false;
	}

	Node* actual = first;
	do {
		if (strcmp(actual->getValue(), _valor) == 0) {
			return true;
		}

		actual = actual->getNext();;

	} while (actual != first);

	return false;
}

bool Set::notBelong(const char* _valor) {
	if (empty()) {
		cout << "\nConjunto esta vacio!\n";
		return true;
	}

	Node* actual = first;
	do {
		if (strcmp(actual->getValue(), _valor) == 0) {
			return false;
		}

		actual = actual->getNext();;

	} while (actual != first);

	return true;
}

bool Set::areEqual(Set _setX, Set _setY)
{
	Node* actual = _setX.first;
	do {
		if (_setY.notBelong(actual->getValue()) == true) {
			return false;
		}

		actual = actual->getNext();;

	} while (actual != _setX.first);

	return true;
}

bool Set::equalTo(Set _set)
{
	if (empty() && _set.empty()) {
		cout << "\nConjuntos estan vacios!\n";
		cout << "Los Conjuntos son Iguales\n";
		return true;
	}
	else if (empty()) {
		cout << "\nConjunto 1 esta vacio!\n";
		cout << "Los Conjuntos no son Iguales\n";
		return false;
	}
	else if (_set.empty()) {
		cout << "\nConjunto 2 esta vacio!\n";
		cout << "Los Conjuntos no son Iguales\n";
		return false;
	}

	if (!areEqual(*this, _set) || !areEqual(_set, *this)) {
		cout << "Los Conjuntos no son Iguales\n";
		return false;
	}

	cout << "Los Conjuntos son Iguales\n";
	return true;
}
