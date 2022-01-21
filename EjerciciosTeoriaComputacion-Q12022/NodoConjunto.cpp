#include "NodoConjunto.h"
#include <iostream>

using namespace std;

Node::Node(const char* _valor, Node* _sig, Node* _ant) : next(_sig), previous(_ant) {
	value = new char[strlen(_valor)];
	strcpy_s(value, strlen(_valor) + 1, _valor);
}

void Node::setValue(const char* _valor) {
	if (value != nullptr)
		delete value;

	value = new char[strlen(_valor)];
	strcpy_s(value, strlen(_valor) + 1, _valor);
}

void Node::setNext(Node* _sig) {
	this->next = _sig;
}

void Node::setPrevious(Node* _ant) {
	this->previous = _ant;
}

char* Node::getValue() {
	return this->value;
}

Node* Node::getNext() {
	return this->next;
}

Node* Node::getPrevious() {
	return this->previous;
}