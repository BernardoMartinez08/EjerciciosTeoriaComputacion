#pragma once
#ifndef  ARISTAS_H
#define ARISTAS_H

#include "Arista.h"

class EdgesSet {
public:
	EdgesSet();
	bool add(const char*, const char*);

	void print();
	int size();

	Edge* getFirst();
private:
	Edge* first;
	Edge* last;

	bool empty();
};
#endif // ! ARISTAS_H