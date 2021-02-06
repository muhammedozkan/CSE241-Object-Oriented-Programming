//============================================================================
// Name        : UserInputValue.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <string>

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#ifndef USERINPUTVALUE_H_
#define USERINPUTVALUE_H_

using namespace std;
//Class for retrieve data from the user in main program
class UserInputValue
{
	//public members
  public:
	static char getShapeType();
	static Rectangle buildRect();
	static Triangle buildTrig();
	static Circle buildCirc();

	//private members
  private:
	static string getColor();
	static double getWidthValue();
	static double getHeigthValue();
	static double getRadiusValue();
	static double getLengthValue();
	static double getPosXValue();
	static double getPosYValue();
	static double getValue();
};

#endif /* USERINPUTVALUE_H_ */
