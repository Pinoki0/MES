#include "InputData.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
InputData::InputData()
{

	plik.open("dane.txt");

		std::string txt;
		getline(plik, txt, '=');
		getline(plik, txt, '\n');
		gridHeight = stod(txt);

		getline(plik, txt, '=');
		getline(plik, txt, '\n');
		gridWidth  = stod(txt);

		getline(plik, txt, '=');
		getline(plik, txt, '\n');
		verticalNodeNumber= stoi(txt);

		getline(plik, txt, '=');
		getline(plik, txt, '\n');
		horizontalNodeNumber= stoi(txt);

		getline(plik, txt, '=');
		getline(plik, txt, '\n');
		thermalConductivity = stod(txt);

		getline(plik, txt, '=');
		getline(plik, txt, '\n');
		temperature = stod(txt);

		plik.close();

}


InputData::~InputData()
{
}


double InputData::getGridHeight()
{
	return gridHeight;
}


 double InputData::getGridWidth()
{
	return gridWidth;
}


 int InputData::getVerticalNodeNumber()
{
	return verticalNodeNumber;
}


 int InputData::getHorizontalNodeNumber()
{
	return horizontalNodeNumber;
}


double InputData::getTemperature()
{
	return temperature;
}


double InputData::getThermalConductivity()
{
	return thermalConductivity;
}


double InputData::gridHeight;
double InputData::gridWidth;
int InputData::verticalNodeNumber;
int InputData::horizontalNodeNumber;
double InputData::thermalConductivity;
double InputData::temperature;
