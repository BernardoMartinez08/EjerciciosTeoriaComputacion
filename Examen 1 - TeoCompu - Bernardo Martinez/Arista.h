#pragma once
#ifndef  ARISTA_H
#define ARISTA_H

class Edge {
public:
	Edge() : valueX(nullptr), valueY(nullptr), next(nullptr), previous(nullptr) {};
	Edge(const char*, const char*, Edge*, Edge*);

	void setValue(const char*, const char*);

	void setNext(Edge*);
	void setPrevious(Edge*);

	char* getValueX();
	char* getValueY();

	Edge* getNext();
	Edge* getPrevious();

private:
	char* valueX;
	char* valueY;

	Edge* next;
	Edge* previous;
};
#endif // ! ARISTA_H
