#include "Element.h"
#include "InputData.h"


Element::Element( int id, int * nodesId)
{
	this->id = id;
	this->nodesId = nodesId;
	this->thermalConductivity = InputData::getThermalConductivity();
}


Element::~Element()
{
	delete nodesId;
}


 int Element::getId()
{
	return id;
}


int * Element::getNodesId()
{
	return nodesId;
}
