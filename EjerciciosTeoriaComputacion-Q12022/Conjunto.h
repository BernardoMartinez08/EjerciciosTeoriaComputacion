#pragma once
#ifndef  LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "NodoConjunto.h"

class Set {
public:
	Set();
	void addNode(const char*);
	void deleteNode(const char*);
	void print();
private:
	Node* first;
	Node* last;

	bool empty();
};
#endif // ! LISTACIRCULAR_H