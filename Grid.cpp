#include "Grid.h"
#include "InputData.h"
#include <iostream>
using namespace std;

Grid::Grid()
{
	int verticalNodeNumber = InputData::getVerticalNodeNumber();
	int horizontalNodeNumber = InputData::getHorizontalNodeNumber();
	double nodeHight = InputData::getGridHeight()/(verticalNodeNumber-1);
	double nodeWidth = InputData::getGridWidth()/(horizontalNodeNumber-1);
    Nodes=new Node*[verticalNodeNumber*horizontalNodeNumber];
    int nono=0;
	for ( int i = 0; i < horizontalNodeNumber; i++)
	{
		for ( int j = 0; j < verticalNodeNumber; j++)
		{
			Nodes[nono]=new Node(i*nodeWidth, j*nodeHight);
			nono++;
		}
	}
    Elements=new Element*[(verticalNodeNumber-1)*(horizontalNodeNumber-1)];
	int id = 0;

	for (int i = 0; i < horizontalNodeNumber - 1; i++)
	{
		for (int j = 1; j < verticalNodeNumber; j++)
		{
			int * nodesId = new int[4];
			nodesId[0] = j +  verticalNodeNumber * i;
			nodesId[1] = j +  verticalNodeNumber  * (i+1);
			nodesId[2] = j + 1 + verticalNodeNumber * (i+1);
			nodesId[3] = j + 1 + verticalNodeNumber * i;

			Elements[id++]=new Element(id+1, nodesId);

		}
	}
}


Grid::~Grid()
{
}


void Grid::printGrid()
{
    int verticalNodeNumber = InputData::getVerticalNodeNumber()-1;
	int horizontalNodeNumber = InputData::getHorizontalNodeNumber()-1;
	for (int i = 0; i <verticalNodeNumber*horizontalNodeNumber; i++)
	{
	    cout<<"Element o nr. ";
		cout<<Elements[i]->getId();
		int * nodesId = Elements[i]->getNodesId();
        cout<<" z wezlami:  ";
		cout << "| "<<  nodesId[0] << "| ";
		cout << nodesId[1] << "| ";
		cout << nodesId[2] << "| ";
		cout << nodesId[3]<< "| " <<endl;
	}
}

Element** Grid::getElements()
{

    return Elements;
}
