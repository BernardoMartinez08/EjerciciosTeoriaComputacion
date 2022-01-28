#pragma once
#ifndef  NODO_CONJUNTO_H
#define NODO_CONJUNTO_H

class Node {
public:
	Node() : value(nullptr), next(nullptr), previous(nullptr) {};
	Node(const char*, Node*, Node*);

	void setValue(const char*);
	void setNext(Node*);
	void setPrevious(Node*);

	char* getValue();
	Node* getNext();
	Node* getPrevious();

private:
	char* value;
	Node* next;
	Node* previous;
};
#endif // ! NODO_CONJUNTO_H