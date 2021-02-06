//============================================================================
// Name        : cpphomework2.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#define test_driver_mod 1 // for test mode off, change the value 0
#include <iostream>
#include <fstream>
#include <string>

#include "UserInputValue.h"
#include "ComposedShape.h"

using namespace std;

void testDriver();

int main()
{
	if (test_driver_mod)
	{
		testDriver();
	}
	else
	{
		//main container information is requested from the user
		char input;
		ofstream outStream;
		ComposedShape::svgOpen("output.svg", outStream);

		cout << "Please enter the main container shape (R, C, T)" << endl;
		input = UserInputValue::getShapeType();

		if (input == 'R')
		{
			auto mContainer = UserInputValue::buildRect();

			cout << "Please enter the small shape (R, C, T)" << endl;
			input = UserInputValue::getShapeType();

			if (input == 'R')
			{
				auto sShape = UserInputValue::buildRect();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
			else if (input == 'C')
			{
				auto sShape = UserInputValue::buildCirc();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
			else if (input == 'T')
			{
				auto sShape = UserInputValue::buildTrig();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
		}
		else if (input == 'C')
		{
			auto mContainer = UserInputValue::buildCirc();

			cout << "Please enter the small shape (R, C, T)" << endl;
			input = UserInputValue::getShapeType();

			if (input == 'R')
			{
				auto sShape = UserInputValue::buildRect();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
			else if (input == 'C')
			{
				auto sShape = UserInputValue::buildCirc();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
			else if (input == 'T')
			{
				auto sShape = UserInputValue::buildTrig();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
		}
		else if (input == 'T')
		{
			auto mContainer = UserInputValue::buildTrig();

			cout << "Please enter the small shape (R, C, T)" << endl;
			input = UserInputValue::getShapeType();

			if (input == 'R')
			{
				auto sShape = UserInputValue::buildRect();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
			else if (input == 'C')
			{
				auto sShape = UserInputValue::buildCirc();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
			else if (input == 'T')
			{
				auto sShape = UserInputValue::buildTrig();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				Compose.draw(outStream);

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;
			}
		}
		ComposedShape::svgClose(outStream);
	}

	return 0;
}
//test function
void testDriver()
{

	vector<Rectangle> Rectm;
	vector<Circle> Circm;
	vector<Triangle> Trigm;

	vector<Rectangle> Rects;
	vector<Circle> Circs;
	vector<Triangle> Trigs;

	vector<ComposedShape> Compose;

	Rectm.push_back(Rectangle("red", 500, 750));
	Rectm.push_back(Rectangle("pink", 750, 500));
	Rectm.push_back(Rectangle("brown", 600, 500));
	Rectm.push_back(Rectangle("blue", 350, 800));

	Circm.push_back(Circle("brown", 300));
	Circm.push_back(Circle("pink", 500));
	Circm.push_back(Circle("red", 400));
	Circm.push_back(Circle("blue", 250));

	Trigm.push_back(Triangle("blue", 600));
	Trigm.push_back(Triangle("pink", 500));
	Trigm.push_back(Triangle("red", 400));
	Trigm.push_back(Triangle("brown", 700));

	Rects.push_back(Rectangle("green", 110, 15));
	Rects.push_back(Rectangle("yellow", 20, 60));
	Rects.push_back(Rectangle("magenta", 100, 50));
	Rects.push_back(Rectangle("cyan", 75, 30));

	Circs.push_back(Circle("cyan", 30));
	Circs.push_back(Circle("green", 50));
	Circs.push_back(Circle("yellow", 40));
	Circs.push_back(Circle("magenta", 25));

	Trigs.push_back(Triangle("green", 40));
	Trigs.push_back(Triangle("yellow", 15));
	Trigs.push_back(Triangle("cyan", 59));
	Trigs.push_back(Triangle("magenta", 70));

	ofstream outStream;
	string fileName;

	for (decltype(Rectm.size()) i = 0; i < Rectm.size(); i++)
	{
		for (decltype(Rects.size()) j = 0; j < Rects.size(); j++)
		{
			Compose.push_back(ComposedShape(Rectm[i], Rects[j]));
		}
		for (decltype(Circs.size()) j = 0; j < Circs.size(); j++)
		{
			Compose.push_back(ComposedShape(Rectm[i], Circs[j]));
		}
		for (decltype(Trigs.size()) j = 0; j < Trigs.size(); j++)
		{
			Compose.push_back(ComposedShape(Rectm[i], Trigs[j]));
		}
	}
	for (decltype(Circm.size()) i = 0; i < Circm.size(); i++)
	{
		for (decltype(Rects.size()) j = 0; j < Rects.size(); j++)
		{
			Compose.push_back(ComposedShape(Circm[i], Rects[j]));
		}
		for (decltype(Circs.size()) j = 0; j < Circs.size(); j++)
		{
			Compose.push_back(ComposedShape(Circm[i], Circs[j]));
		}
		for (decltype(Trigs.size()) j = 0; j < Trigs.size(); j++)
		{
			Compose.push_back(ComposedShape(Circm[i], Trigs[j]));
		}
	}
	for (decltype(Trigm.size()) i = 0; i < Trigm.size(); i++)
	{
		for (decltype(Rects.size()) j = 0; j < Rects.size(); j++)
		{
			Compose.push_back(ComposedShape(Trigm[i], Rects[j]));
		}
		for (decltype(Circs.size()) j = 0; j < Circs.size(); j++)
		{
			Compose.push_back(ComposedShape(Trigm[i], Circs[j]));
		}
		for (decltype(Trigs.size()) j = 0; j < Trigs.size(); j++)
		{
			Compose.push_back(ComposedShape(Trigm[i], Trigs[j]));
		}
	}

	for (decltype(Compose.size()) i = 0; i < Compose.size(); ++i)
	{
		fileName = "output" + to_string(i + 1) + ".svg";
		ComposedShape::svgOpen(fileName.c_str(), outStream);
		Compose[i].optimalFit();
		Compose[i].draw(outStream);
		ComposedShape::svgClose(outStream);
		cout << i + 1 << ".I can fit at most " << Compose[i].getObjectCount()
			 << " small shapes into the main container. The empty area ("
			 << Compose[i].getMainColor() << ") in container is "
			 << Compose[i].getEmptyArea() << endl;
	}
}
