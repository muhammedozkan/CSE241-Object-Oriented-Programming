//============================================================================
// Name        : Polyline.h
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

#ifndef POLYLINE_H_
#define POLYLINE_H_

//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
//Class for Polyline of Shape in ComposeShape
namespace shape
{
class Polyline
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
	Polyline();
	Polyline(vector<Point2D> &vectPoint);
	Polyline(Rectangle &rect);
	Polyline(Circle &circ);
	Polyline(Triangle &trig);
	Polyline(Point2D &point2d);

	//Big three
	Polyline(const Polyline &obj);
	Polyline &operator=(const Polyline &rightSide);
	~Polyline();

	string getColor() const;
	void setColor(string color);
	double getRotateAngle() const;
	void setRotateAngle(double rotateAngle);
	double getRotateX() const;
	void setRotateX(double rotateX);
	double getRotateY() const;
	void setRotateY(double rotateY);

	int getPointCount() const;

	//Operators == , !=, and + operators two Polyline operator overloading
	friend Polyline operator+(Polyline &firstOperand, Polyline &secondOperand);

	friend bool operator==(Polyline &firstOperand, Polyline &secondOperand);

	friend bool operator!=(Polyline &firstOperand, Polyline &secondOperand)
	{
		return !(firstOperand == secondOperand);
	}

	//get reference ostream parameter friend operator overloading
	friend ostream &operator<<(ostream &outs, Polyline &obj);

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
	double _rotateAngle;
	double _rotateX;
	double _rotateY;
};
} // namespace shape
#endif /* Polyline_H_ */