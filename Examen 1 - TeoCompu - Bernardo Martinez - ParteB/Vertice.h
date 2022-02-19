#pragma once
#ifndef  VERTICE_H
#define VERTICE_H

class Vertex {
public:
	Vertex() : value(nullptr), next(nullptr), previous(nullptr) {};
	Vertex(const char*, Vertex*, Vertex*);

	void setValue(const char*);

	void setNext(Vertex*);
	void setPrevious(Vertex*);

	char* getValue();

	Vertex* getNext();
	Vertex* getPrevious();

private:
	char* value;

	Vertex* next;
	Vertex* previous;
};
#endif // ! VERTICE_H