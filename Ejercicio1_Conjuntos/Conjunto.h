#pragma once
#ifndef  LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "NodoConjunto.h"

class Set {
public:
	Set();
	bool addNode(const char*);
	bool deleteNode(const char*);

	void print();

	bool belong(const char*);
	bool notBelong(const char*);

	bool equalTo(Set);

	Set unionSets(Set);
	Set intersectSets(Set);
private:
	Node* first;
	Node* last;

	bool areEqual(Set, Set);
	bool empty();
};
#endif // ! LISTACIRCULAR_H