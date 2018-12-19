#include "Node.h"
#include "InputData.h"


Node::Node(double x, double y)
{
	this->x = x;
	this->y = y;
	this->t = InputData::getTemperature();
}

Node::Node(){}
Node::~Node(){}
