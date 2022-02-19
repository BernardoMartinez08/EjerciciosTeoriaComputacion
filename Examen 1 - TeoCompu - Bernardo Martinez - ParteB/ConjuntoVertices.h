#pragma once
#ifndef  VERTICES_H
#define VERTICES_H

#include "Vertice.h"

class VertexSet {
public:
	VertexSet();
	bool add(const char*);

	void print();
	int size();

	Vertex* getFirst();
private:
	Vertex* first;
	Vertex* last;

	bool empty();
	bool belong(const char*);
};
#endif // ! VERTICES_H