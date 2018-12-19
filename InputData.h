#pragma once
#include<fstream>
#include<string>
using namespace std;
class InputData
{
	ifstream plik;
	static double gridHeight;
	static  double gridWidth;
	static  int verticalNodeNumber;
	static int horizontalNodeNumber;
	static double thermalConductivity;
	static double temperature;
public:
	InputData();
   ~InputData();

	static double getGridHeight();
	static  double getGridWidth();
	static   int getVerticalNodeNumber();
	static int getHorizontalNodeNumber();
	static  double getTemperature();
	static  double getThermalConductivity();
};
