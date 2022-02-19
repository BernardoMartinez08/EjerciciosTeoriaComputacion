#include "Arista.h"
#include <iostream>

using namespace std;

Edge::Edge(const char* _valorX, const char* _valorY, Edge* _sig, Edge* _ant) : next(_sig), previous(_ant) {
	valueX = new char[strlen(_valorX)];
	strcpy_s(valueX, strlen(_valorX) + 1, _valorX);

	valueY = new char[strlen(_valorY)];
	strcpy_s(valueY, strlen(_valorY) + 1, _valorY);
}

void Edge::setValue(const char* _valorX, const char* _valorY) {
	if (valueX != nullptr)
		delete valueX;

	valueX = new char[strlen(_valorX)];
	strcpy_s(valueX, strlen(_valorX) + 1, _valorX);

	if (valueY != nullptr)
		delete valueY;

	valueY = new char[strlen(_valorY)];
	strcpy_s(valueY, strlen(_valorY) + 1, _valorY);
}

void Edge::setNext(Edge* _sig) {
	this->next = _sig;
}

void Edge::setPrevious(Edge* _ant) {
	this->previous = _ant;
}

char* Edge::getValueX() {
	return this->valueX;
}

char* Edge::getValueY() {
	return this->valueY;
}

Edge* Edge::getNext() {
	return this->next;
}

Edge* Edge::getPrevious() {
	return this->previous;
}