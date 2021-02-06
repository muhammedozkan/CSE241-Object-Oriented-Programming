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

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

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
class Polygon
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
		void setX(double x);
		double getY() const;
		void setY(double x);

		//private members
	  private:
		double _x;
		double _y;
	};

	//constructer initialize
	Polygon();
	Polygon(vector<Point2D> &vectPoint);
	Polygon(Rectangle &rect);
	Polygon(Circle &circ);
	Polygon(Triangle &trig);
	Polygon(Point2D &point2d);

	//Big three
	Polygon(const Polygon &obj);
	Polygon &operator=(const Polygon &rightSide);
	~Polygon();

	string getColor() const;
	void setColor(string color);
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle);
	double getRotateX() const;
	void setRotateX(double rotateX);
	double getRotateY() const;
	void setRotateY(double rotateY);

	double getArea() const;
	void setArea(double area);
	double getPerimeter() const;
	void setPerimeter(double perimeter);

	int getPointCount() const;

	//Operators == , !=, and + operators two Polygon operator overloading
	friend Polygon operator+(Polygon &firstOperand, Polygon &secondOperand);

	friend bool operator==(Polygon &firstOperand, Polygon &secondOperand);

	friend bool operator!=(Polygon &firstOperand, Polygon &secondOperand)
	{
		return !(firstOperand == secondOperand);
	}

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, Polygon &obj);

	Point2D &operator[](int index);				//lvalue
	const Point2D &operator[](int index) const; //rvalue

	//private members
  private:
	Point2D *getPointsPtr() const;
	void setPointsPtr(Point2D *pointsPtr);
	void setPointCount(int pointCount);

	Point2D *_pointsPtr; //array initial address
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