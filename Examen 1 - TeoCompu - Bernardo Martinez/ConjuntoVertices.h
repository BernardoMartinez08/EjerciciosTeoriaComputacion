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

	bool tag(const char*, const char*);
private:
	Vertex* first;
	Vertex* last;

	bool empty();
};
#endif // ! VERTICES_H