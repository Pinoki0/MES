#pragma once
#include "Node.h"

class Element
{
	int id;
	int * nodesId;
    double thermalConductivity;
public:
	Element( int id, int * nodesId);
	~Element();

	int getId();
	int * getNodesId();
};
