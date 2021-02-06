//============================================================================
// Name        : UserInputValue.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include "UserInputValue.h"

//initialize rectangle object
Rectangle UserInputValue::buildRect()
{
	Rectangle finalRect(getColor(), getHeigthValue(), getWidthValue());

	return finalRect;
}

//initialize triangle object
Triangle UserInputValue::buildTrig()
{
	Triangle finalTrig(getColor(), getLengthValue());

	return finalTrig;
}

//initialize circle object
Circle UserInputValue::buildCirc()
{
	Circle finalCirc(getColor(), getRadiusValue());

	return finalCirc;
}

double UserInputValue::getValue()
{
	double input;
	bool flag;

	do
	{
		cin >> input;

		flag = cin.fail();
		cin.clear();
		cin.ignore(127, '\n');

		if (flag)
		{
			cout << "Not a integer or decimal number. Please enter the again"
				 << endl;
		}
		else if (input <= 0)
		{
			flag = true;
			cout
				<< "Value cannot be zero or smaller than zero. Please enter the again"
				<< endl;
		}
	} while (flag);

	return input;
}

char UserInputValue::getShapeType()
{
	string input;
	bool flag;

	do
	{
		cin >> input;

		if (input == "R" || input == "C" || input == "T" || input == "r" || input == "c" || input == "t")
		{
			flag = false;
		}
		else
		{
			flag = true;
			cout << "Not a R,C,T. Please enter the again" << endl;
		}
	} while (flag);

	if (input == "R" || input == "r")
	{
		return 'R';
	}
	else if (input == "C" || input == "c")
	{
		return 'C';
	}
	else if (input == "T" || input == "t")
	{
		return 'T';
	}
	else
	{
		return 'U'; //Unknown
	}
}

string UserInputValue::getColor()
{
	string input;
	bool flag;
	cout
		<< "Please enter the shape color ( (R)ed, (G)reen, (B)lue, (C)yan, (M)agenta, (Y)ellow, blac(K) ) just enter the capital letters."
		<< endl;
	do
	{
		cin >> input;

		if (input == "R" || input == "G" || input == "B" || input == "C" || input == "M" || input == "Y" || input == "K" || input == "r" || input == "g" || input == "b" || input == "c" || input == "m" || input == "y" || input == "k")
		{
			flag = false;
		}
		else
		{
			flag = true;
			cout << "Not a R,G,B,C,M,Y,K. Please enter the again" << endl;
		}
	} while (flag);

	if (input == "R" || input == "r")
	{
		return "Red";
	}
	else if (input == "G" || input == "g")
	{
		return "Green";
	}
	else if (input == "B" || input == "b")
	{
		return "Blue";
	}
	else if (input == "C" || input == "c")
	{
		return "Cyan";
	}
	else if (input == "M" || input == "m")
	{
		return "Magenta";
	}
	else if (input == "Y" || input == "y")
	{
		return "Yellow";
	}
	else if (input == "K" || input == "k")
	{
		return "Black";
	}
	else
	{
		return "Unknown"; //Unknown
	}
}

inline double UserInputValue::getWidthValue()
{
	cout << "Please enter the width" << endl;
	return getValue();
}

inline double UserInputValue::getHeigthValue()
{
	cout << "Please enter the height" << endl;
	return getValue();
}

inline double UserInputValue::getRadiusValue()
{
	cout << "Please enter the radius" << endl;
	return getValue();
}

inline double UserInputValue::getLengthValue()
{
	cout << "Please enter edge length" << endl;
	return getValue();
}

inline double UserInputValue::getPosXValue()
{
	cout << "Please enter X position" << endl;
	return getValue();
}

inline double UserInputValue::getPosYValue()
{
	cout << "Please enter Y position" << endl;
	return getValue();
}
