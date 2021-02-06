//============================================================================
// Name        : Triangle.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "Triangle.h"
//Class for Triangle of Shape in ComposeShape

//code implementation default constructer
namespace shape
{
Triangle::Triangle()
{
}

//constructer ex: Triangle(color,length)
Triangle::Triangle(string color, double length)
{ //assign class member value
	setPosX(0);
	setPosY(0);
	setPoint1X(length / 2);
	setPoint1Y(0);
	setPoint2X(0);
	setPoint2Y((length / 2) * sqrt(3));
	setPoint3X(length);
	setPoint3Y((length / 2) * sqrt(3));
	setColor(color);
	setRotateAngle(0);
	setRotateX(0);
	setRotateY(0);
	setLength(length);
	setTotalAreas(area());
	setTotalPerimeters(perimeter());
}

//constructer ex: Triangle(posX,posY,point1X,.....,point3Y,color,rotateAngle,rotateX,rotateY,length)
Triangle::Triangle(double posX, double posY, double point1X, double point1Y,
				   double point2X, double point2Y, double point3X, double point3Y,
				   string color, double rotateAngle, double rotateX, double rotateY,
				   double length)
{ //assign class member value
	setPosX(posX);
	setPosY(posY);
	setPoint1X(point1X);
	setPoint1Y(point1Y);
	setPoint2X(point2X);
	setPoint2Y(point2Y);
	setPoint3X(point3X);
	setPoint3Y(point3Y);
	setColor(color);
	setRotateAngle(rotateAngle);
	setRotateX(rotateX);
	setRotateY(rotateY);
	setLength(length);

	//if points value is equal 0, point value is assigned to calculated value
	if (_point1X == 0 && _point1Y == 0 && _point2X == 0 && _point2Y == 0 && _point3X == 0 && _point3Y == 0)
	{
		setPoint1X(_length / 2);
		setPoint1Y(0);
		setPoint2X(0);
		setPoint2Y((_length / 2) * sqrt(3));
		setPoint3X(_length);
		setPoint3Y((_length / 2) * sqrt(3));
	}
	setTotalAreas(area());
	setTotalPerimeters(perimeter());
}

//Prefix version
Shape &Triangle::operator++()
{
	setPosX(getPosX() + 1.0);
	setPosY(getPosY() + 1.0);
	setRotateX(getRotateX() + 1.0);
	setRotateY(getRotateY() + 1.0);
	Shape *shp = new Triangle(getPosX(), getPosY(), getPoint1X(), getPoint1Y(), getPoint2X(), getPoint2Y(), getPoint3X(), getPoint3Y(), getColor(), getRotateAngle(), getRotateX(), getRotateY(), getLength());
	return *shp;
}

//Postfix version
Shape &Triangle::operator++(int ignoreMe)
{
	double tempPosX, tempPosY, tempRotateX, tempRotateY;
	tempPosX = getPosX();
	tempPosY = getPosY();
	tempRotateX = getRotateX();
	tempRotateY = getRotateY();
	setPosX(tempPosX + 1.0);
	setPosY(tempPosY + 1.0);
	setRotateX(tempRotateX + 1.0);
	setRotateY(tempRotateY + 1.0);

	Shape *shp = new Triangle(tempPosX, tempPosY, getPoint1X(), getPoint1Y(), getPoint2X(), getPoint2Y(), getPoint3X(), getPoint3Y(), getColor(), getRotateAngle(), tempRotateX, tempRotateY, getLength());
	return *shp;
}

//Prefix version
Shape &Triangle::operator--()
{
	setPosX(getPosX() - 1.0);
	setPosY(getPosY() - 1.0);
	setRotateX(getRotateX() - 1.0);
	setRotateY(getRotateY() - 1.0);
	Shape *shp = new Triangle(getPosX(), getPosY(), getPoint1X(), getPoint1Y(), getPoint2X(), getPoint2Y(), getPoint3X(), getPoint3Y(), getColor(), getRotateAngle(), getRotateX(), getRotateY(), getLength());
	return *shp;
}

//Postfix version
Shape &Triangle::operator--(int ignoreMe)
{
	double tempPosX, tempPosY, tempRotateX, tempRotateY;
	tempPosX = getPosX();
	tempPosY = getPosY();
	tempRotateX = getRotateX();
	tempRotateY = getRotateY();
	setPosX(tempPosX - 1.0);
	setPosY(tempPosY - 1.0);
	setRotateX(tempRotateX - 1.0);
	setRotateY(tempRotateY - 1.0);

	Shape *shp = new Triangle(tempPosX, tempPosY, getPoint1X(), getPoint1Y(), getPoint2X(), getPoint2Y(), getPoint3X(), getPoint3Y(), getColor(), getRotateAngle(), tempRotateX, tempRotateY, getLength());
	return *shp;
}

//operator overloading - and +
const Triangle Triangle::operator-(const double size) const //buraya bakk
{
	return Triangle(getPosX(), getPosY(), 0, 0, 0, 0, 0, 0, getColor(), getRotateAngle(), getRotateX(), getRotateY(), getLength() - size);
}

const Triangle Triangle::operator+(const double size) const //buraya bakk
{
	return Triangle(getPosX(), getPosY(), 0, 0, 0, 0, 0, 0, getColor(), getRotateAngle(), getRotateX(), getRotateY(), getLength() + size);
}

//get reference ofstream parameter. draw object <<
ostream &operator<<(ostream &outs, Triangle &obj)
{
	outs << "<polygon points=\"" << obj.getPoint1X() + obj.getPosX() << "," << obj.getPoint1Y() + obj.getPosY()
		 << " " << obj.getPoint2X() + obj.getPosX() << "," << obj.getPoint2Y() + obj.getPosY() << " "
		 << obj.getPoint3X() + obj.getPosX() << "," << obj.getPoint3Y() + obj.getPosY()
		 << "\" transform=\"rotate(" << obj.getRotateAngle() << " " << obj.getRotateX()
		 << " " << obj.getRotateY() << ")\" fill=\"" << obj.getColor()
		 << "\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;

	return outs;
}

ostream &Triangle::draw(ostream &outs)
{
	outs << *this;
	return outs;
}

string Triangle::getColor() const
{
	return _color;
}

void Triangle::setColor(string color)
{
	_color = color;
}

double Triangle::getPoint1X() const
{
	return _point1X;
}

//if the point1X value is  smaller than 0, point1X value is assigned 0
void Triangle::setPoint1X(double point1X) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (point1X >= 0)
	{
		_point1X = point1X;
	}
	else
	{
		_point1X = 0;
		throw invalid_argument("Invalid point1X Value assigned 0");
	}
}

double Triangle::getPoint1Y() const
{
	return _point1Y;
}

//if the point1Y value is  smaller than 0, point1Y value is assigned 0
void Triangle::setPoint1Y(double point1Y) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (point1Y >= 0)
	{
		_point1Y = point1Y;
	}
	else
	{
		_point1Y = 0;
		throw invalid_argument("Invalid point1Y Value assigned 0");
	}
}

double Triangle::getPoint2X() const
{
	return _point2X;
}

//if the point2X value is  smaller than 0, point2X value is assigned 0
void Triangle::setPoint2X(double point2X) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (point2X >= 0)
	{
		_point2X = point2X;
	}
	else
	{
		_point2X = 0;
		throw invalid_argument("Invalid point2X Value assigned 0");
	}
}

double Triangle::getPoint2Y() const
{
	return _point2Y;
}

//if the point2Y value is  smaller than 0, point2Y value is assigned 0
void Triangle::setPoint2Y(double point2Y) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (point2Y >= 0)
	{
		_point2Y = point2Y;
	}
	else
	{
		_point2Y = 0;
		throw invalid_argument("Invalid point2Y Value assigned 0");
	}
}

double Triangle::getPoint3X() const
{
	return _point3X;
}

//if the point3X value is  smaller than 0, point3X value is assigned 0
void Triangle::setPoint3X(double point3X) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (point3X >= 0)
	{
		_point3X = point3X;
	}
	else
	{
		_point3X = 0;
		throw invalid_argument("Invalid point3X Value assigned 0");
	}
}

double Triangle::getPoint3Y() const
{
	return _point3Y;
}

//if the point3Y value is  smaller than 0, point3Y value is assigned 0
void Triangle::setPoint3Y(double point3Y) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (point3Y >= 0)
	{
		_point3Y = point3Y;
	}
	else
	{
		_point3Y = 0;
		throw invalid_argument("Invalid point3Y Value assigned 0");
	}
}

double Triangle::getPosX() const
{
	return _posX;
}

//if the posx value is  smaller than 0, posx value is assigned 0
void Triangle::setPosX(double posX) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (posX >= 0)
	{
		_posX = posX;
	}
	else
	{
		_posX = 0;
		throw invalid_argument("Invalid posX Value assigned 0");
	}
}

double Triangle::getPosY() const
{
	return _posY;
}

//if the posy value is  smaller than 0, posy value is assigned 0
void Triangle::setPosY(double posY) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (posY >= 0)
	{
		_posY = posY;
	}
	else
	{
		_posY = 0;
		throw invalid_argument("Invalid posY Value assigned 0");
	}
}

double Triangle::getRotateAngle() const
{
	return _rotateAngle;
}

//if the rotateAngle value is smaller than -360 or greater than 360, rotateAngle value is assigned 0
void Triangle::setRotateAngle(double rotateAngle) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (rotateAngle < 360 && rotateAngle > -360)
	{
		if (rotateAngle < 0)
		{
			_rotateAngle = -1 * rotateAngle;
		}
		else
		{
			_rotateAngle = rotateAngle;
		}
	}
	else
	{
		_rotateAngle = 0;
		throw invalid_argument("Invalid rotateAngle Value assigned 0");
	}
}

double Triangle::getRotateX() const
{
	return _rotateX;
}

//if the radius rotateX is 0 or  smaller than 0, rotateX value is assigned 0
void Triangle::setRotateX(double rotateX) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (rotateX >= 0)
	{
		_rotateX = rotateX;
	}
	else
	{
		_rotateX = 0;
		throw invalid_argument("Invalid rotateX Value assigned 0");
	}
}

double Triangle::getRotateY() const
{
	return _rotateY;
}

//if the radius rotateY is 0 or  smaller than 0, rotateY value is assigned 0
void Triangle::setRotateY(double rotateY) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (rotateY >= 0)
	{
		_rotateY = rotateY;
	}
	else
	{
		_rotateY = 0;
		throw invalid_argument("Invalid rotateY Value assigned 0");
	}
}

double Triangle::getLength() const
{
	return _length;
}

//area calculating
double Triangle::area()
{
	return ((getLength() * getLength() * sqrt(3)) / 4);
}

//perimeter calculating
double Triangle::perimeter()
{
	return (getLength() * 3);
}

//if the length value is 0 or  smaller than 0, length value is assigned 1
void Triangle::setLength(double length) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (length > 0)
	{
		_length = length;
	}
	else
	{
		_length = 1;
		throw invalid_argument("Invalid length Value assigned 1");
	}
}

//static functions
double Triangle::getTotalAreas()
{
	return _totalAreas;
}

void Triangle::setTotalAreas(double totalAreas)
{
	_totalAreas += totalAreas;
}

double Triangle::getTotalPerimeters()
{
	return _totalPerimeters;
}

void Triangle::setTotalPerimeters(double totalPerimeters)
{
	_totalPerimeters += totalPerimeters;
}
} // namespace shape