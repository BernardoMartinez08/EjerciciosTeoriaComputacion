#include "Vertice.h"
#include <iostream>

using namespace std;

Vertex::Vertex(const char* _valor, Vertex* _sig, Vertex* _ant) : next(_sig), previous(_ant) {
	value = new char[strlen(_valor)];
	strcpy_s(value, strlen(_valor) + 1, _valor);

	tag = nullptr;
}

void Vertex::setValue(const char* _valor) {
	if (value != nullptr)
		delete value;

	value = new char[strlen(_valor)];
	strcpy_s(value, strlen(_valor) + 1, _valor);
}

void Vertex::setTag(const char* _tag) {
	if (tag != nullptr)
		delete tag;

	tag = new char[strlen(_tag)];
	strcpy_s(tag, strlen(_tag) + 1, _tag);
}

void Vertex::setNext(Vertex* _sig) {
	this->next = _sig;
}

void Vertex::setPrevious(Vertex* _ant) {
	this->previous = _ant;
}

char* Vertex::getValue() {
	return this->value;
}

char* Vertex::getTag() {
	return this->tag;
}

Vertex* Vertex::getNext() {
	return this->next;
}

Vertex* Vertex::getPrevious() {
	return this->previous;
}