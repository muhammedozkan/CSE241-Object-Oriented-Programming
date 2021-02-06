//============================================================================
// Name        : Polygon.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "Polygon.h"
//Class for Polygon of Shape in ComposeShape
namespace shape
{

Polygon::Point2D::Point2D()
{
}

//constructer ex: Point2D(x,y)
Polygon::Point2D::Point2D(double x, double y)
{ //assign class member value
	setX(x);
	setY(y);
}

string Polygon::getColor() const
{
	return _color;
}

void Polygon::setColor(string color)
{
	_color = color;
}

double Polygon::getRotateAngle() const
{
	return _rotateAngle;
}

void Polygon::setRotateAngle(double rotateAngle)
{
	_rotateAngle = rotateAngle;
}

double Polygon::getRotateX() const
{
	return _rotateX;
}

void Polygon::setRotateX(double rotateX)
{
	_rotateX = rotateX;
}

double Polygon::getRotateY() const
{
	return _rotateY;
}

void Polygon::setRotateY(double rotateY)
{
	_rotateY = rotateY;
}

int Polygon::getPointCount() const
{
	return _pointCount;
}

void Polygon::setPointCount(int pointCount)
{
	_pointCount = pointCount;
}

void Polygon::setArea(double area)
{
	_area = area;
}

void Polygon::setPerimeter(double perimeter)
{
	_perimeter = perimeter;
}

double Polygon::getArea() const
{
	return _area;
}

double Polygon::getPerimeter() const
{
	return _perimeter;
}

double Polygon::Point2D::getX() const
{
	return _x;
}

void Polygon::Point2D::setX(double x) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (x >= 0)
	{
		_x = x;
	}
	else
	{
		_x = 0;
		throw invalid_argument("Invalid Point2D Y Value assigned 0");
	}
}

double Polygon::Point2D::getY() const
{
	return _y;
}

void Polygon::Point2D::setY(double y) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (y >= 0)
	{
		_y = y;
	}
	else
	{
		_y = 0;
		throw invalid_argument("Invalid Point2D Y Value assigned 0");
	}
}
} // namespace shape