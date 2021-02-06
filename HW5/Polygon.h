//============================================================================
// Name        : Polygon.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <stdexcept>
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "Shape.h"

#ifndef POLYGON_H_
#define POLYGON_H_

//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
//Class for Polygon of Shape in ComposeShape
namespace shape
{
class Polygon : public Shape
{
	//public members
  public:
	//Point2D inner class definition
	class Point2D
	{
		//public members
	  public:
		//constructer initialize
		Point2D();
		Point2D(double x, double y);

		double getX() const;
		void setX(double x) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11
		double getY() const;
		void setY(double x) throw(invalid_argument); //dynamic exception specifications are deprecated in C++11

		//private members
	  private:
		double _x;
		double _y;
	};

	virtual double area() = 0;				  //pure virtual function
	virtual double perimeter() = 0;			  //pure virtual function
	virtual ostream &draw(ostream &outs) = 0; //pure virtual function

	//operator overloading pure virtual function
	virtual Shape &operator++() = 0;	//Prefix version
	virtual Shape &operator++(int) = 0; //Postfix version
	virtual Shape &operator--() = 0;	//Prefix version
	virtual Shape &operator--(int) = 0; //Postfix version

	string getColor() const;
	void setColor(string color);
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle);
	double getRotateX() const;
	void setRotateX(double rotateX);
	double getRotateY() const;
	void setRotateY(double rotateY);

	void setArea(double area);
	void setPerimeter(double perimeter);
	double getArea() const;
	double getPerimeter() const;
	int getPointCount() const;

	//private members
  protected:
	void setPointCount(int pointCount);

	int _pointCount;
	string _color;
	double _area;
	double _perimeter;
	double _rotateAngle;
	double _rotateX;
	double _rotateY;
};
} // namespace shape
#endif /* POLYGON_H_ */