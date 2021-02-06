//============================================================================
// Name        : cpphomework3.cpp
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

namespace //unnamed namespace
{
void testDriver();
}

double Triangle::_totalAreas = 0;
double Triangle::_totalPerimeters = 0;

double Rectangle::_totalAreas = 0;
double Rectangle::_totalPerimeters = 0;

double Circle::_totalAreas = 0;
double Circle::_totalPerimeters = 0;

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
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
			}
			else if (input == 'C')
			{
				auto sShape = UserInputValue::buildCirc();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
			}
			else if (input == 'T')
			{
				auto sShape = UserInputValue::buildTrig();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
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
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
			}
			else if (input == 'C')
			{
				auto sShape = UserInputValue::buildCirc();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
			}
			else if (input == 'T')
			{
				auto sShape = UserInputValue::buildTrig();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
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
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
			}
			else if (input == 'C')
			{
				auto sShape = UserInputValue::buildCirc();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
			}
			else if (input == 'T')
			{
				auto sShape = UserInputValue::buildTrig();
				ComposedShape Compose(mContainer, sShape);

				Compose.optimalFit();
				outStream << Compose;

				cout << "I can fit at most " << Compose.getObjectCount()
					 << " small shapes into the main container. The empty area ("
					 << Compose.getMainColor() << ") in container is "
					 << Compose.getEmptyArea() << endl;

				cout << "Container Area :" << mContainer.area() << " Container Perimeter :" << mContainer.perimeter() << endl;
				cout << "Shape Area :" << sShape.area() << " Shape Perimeter :" << sShape.perimeter() << endl;
			}
		}
		ComposedShape::svgClose(outStream);
	}
	cout << "Static Func. Rectangle Total Areas " << (int)Rectangle::getTotalAreas() << "  Static Func. Rectangle Total Perimeters " << (int)Rectangle::getTotalPerimeters() << endl; //küçük şekilde bir tane fazla alan ve çevre ekliyor bakılacak
	cout << "Static Func. Triangle Total Areas " << (int)Triangle::getTotalAreas() << "  Static Func. Triangle Total Perimeters " << (int)Triangle::getTotalPerimeters() << endl;
	cout << "Static Func. Circle Total Areas " << (int)Circle::getTotalAreas() << "  Static Func. Circle Total Perimeters " << (int)Circle::getTotalPerimeters() << endl;
	return 0;
}

//test function
namespace //unnamed namespace
{
void testDriver()
{

	vector<Rectangle> Rectm;
	vector<Circle> Circm;
	vector<Triangle> Trigm;

	vector<Rectangle> Rects;
	vector<Circle> Circs;
	vector<Triangle> Trigs;

	vector<ComposedShape> Compose;

	Rectm.push_back(Rectangle("red", 550, 800) - 50);  //- operator example
	Rectm.push_back(Rectangle("pink", 700, 450) + 50); //+ operator example

	Rectangle r1("purple", 500, 500);
	r1++;
	++r1;
	r1++;
	++r1;
	r1++;
	++r1;
	r1++;
	++r1;
	r1++;
	++r1;
	Rectm.push_back(r1);

	r1.setColor("dimgrey"); //-- operator example
	--r1;
	r1--;
	--r1;
	r1--;
	--r1;
	Rectm.push_back(r1);

	Circm.push_back(Circle("brown", 350) - 50); //- operator example
	Circm.push_back(Circle("pink", 450) + 50);  //+ operator example

	Circle c1("dimgrey", 500); //++ operator example
	c1++;
	++c1;
	c1++;
	++c1;
	c1++;
	++c1;
	c1++;
	++c1;
	c1++;
	++c1;
	Circm.push_back(c1);

	c1.setColor("purple"); //-- operator example
	c1--;
	--c1;
	c1--;
	--c1;
	c1--;
	Circm.push_back(c1);

	Trigm.push_back(Triangle("blue", 650) - 50); //- operator example
	Trigm.push_back(Triangle("pink", 450) + 50); //+ operator example

	Triangle t1("dimgrey", 500); //++ operator example
	t1++;
	++t1;
	t1++;
	++t1;
	t1++;
	++t1;
	t1++;
	++t1;
	t1++;
	++t1;
	Trigm.push_back(t1);

	t1.setColor("purple"); //-- operator example
	t1--;
	--t1;
	t1--;
	--t1;
	t1--;
	Trigm.push_back(t1);

	Rects.push_back(Rectangle("green", 110, 15));
	Rects.push_back(Rectangle("yellow", 20, 60));

	Circs.push_back(Circle("cyan", 30));
	Circs.push_back(Circle("green", 50));

	Trigs.push_back(Triangle("green", 40));
	Trigs.push_back(Triangle("yellow", 15));

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
		outStream << Compose[i];
		ComposedShape::svgClose(outStream);
		cout << i + 1 << ".I can fit at most " << Compose[i].getObjectCount()
			 << " small shapes into the main container. The empty area ("
			 << Compose[i].getMainColor() << ") in container is "
			 << Compose[i].getEmptyArea() << endl;

		cout << "Container Area :" << Compose[i].getMainShape().getArea() << " Container Perimeter :" << Compose[i].getMainShape().getPerimeter() << endl;
		cout << "Shape Area :" << Compose[i].getSmallShape().getArea() << " Shape Perimeter :" << Compose[i].getSmallShape().getPerimeter() << endl;
	}

	//Polyline example
	Polyline p1(r1);
	Polyline p2(c1);
	Polyline p3(t1);
	//+ operator ex.
	Polyline p4(p2 + p3);
	Polyline p5(p3 + p2);
	ComposedShape::svgOpen("outputPolyline1.svg", outStream);
	outStream << p1;
	ComposedShape::svgClose(outStream);

	ComposedShape::svgOpen("outputPolyline2.svg", outStream);
	outStream << p2;
	ComposedShape::svgClose(outStream);

	ComposedShape::svgOpen("outputPolyline3.svg", outStream);
	outStream << p3;
	ComposedShape::svgClose(outStream);

	ComposedShape::svgOpen("outputPolyline4.svg", outStream);
	outStream << p4;
	ComposedShape::svgClose(outStream);

	ComposedShape::svgOpen("outputPolyline5.svg", outStream);
	outStream << p5;
	ComposedShape::svgClose(outStream);

	//Polygon example
	Polygon p6(c1);
	Polygon p7(t1);
	//+ operator ex.
	Polygon p8(p6 + p7);
	Polygon p9(p7 + p6);
	ComposedShape::svgOpen("outputPolygon1.svg", outStream);
	outStream << p8;
	ComposedShape::svgClose(outStream);

	ComposedShape::svgOpen("outputPolygon2.svg", outStream);
	outStream << p9;
	ComposedShape::svgClose(outStream);
}
} // namespace