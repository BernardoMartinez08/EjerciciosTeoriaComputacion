#pragma once
#ifndef  NODO_VERTICE_H
#define NODO_VERTICE_H

class Vertex {
public:
	Vertex() : value(nullptr), next(nullptr), previous(nullptr) {};
	Vertex(const char*, Vertex*, Vertex*);

	void setValue(const char*);
	void setTag(const char*);

	void setNext(Vertex*);
	void setPrevious(Vertex*);

	char* getValue();
	char* getTag();

	Vertex* getNext();
	Vertex* getPrevious();

private:
	char* value;
	char* tag = nullptr;

	Vertex* next;
	Vertex* previous;
};
#endif // ! NODO_VERTICE_H