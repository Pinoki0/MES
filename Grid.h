#pragma once
#include "Node.h"
#include "Element.h"
#include <vector>
using namespace std;

class Grid
{
	Node** Nodes;
	Element** Elements;
public:
	Grid();
	~Grid();
    Element** getElements();
	void printGrid();
};
