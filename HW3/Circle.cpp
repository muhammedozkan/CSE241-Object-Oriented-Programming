//============================================================================
// Name        : Circle.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "Circle.h"
//Class for Circle of Shape in ComposeShape

//code implementation default constructer
Circle::Circle()
{
}

//constructer ex: Circle(color,radius)
Circle::Circle(string color, double radius)
{ //assign class member value
	setPosX(radius);
	setPosY(radius);
	setRadius(radius);
	setColor(color);
	setRotateAngle(0);
	setRotateX(0);
	setRotateY(0);
	setTotalAreas(area());
	setTotalPerimeters(perimeter());
}

//constructer ex: Circle(posX,posY,radius,color,rotateAngle,rotateX,rotateY)
Circle::Circle(double posX, double posY, double radius, string color,
			   double rotateAngle, double rotateX, double rotateY)
{ //assign class member value
	setPosX(posX);
	setPosY(posY);
	setRadius(radius);
	setColor(color);
	setRotateAngle(rotateAngle);
	setRotateX(rotateX);
	setRotateY(rotateY);

	//draw position assignment
	if (_posX < _radius)
	{
		setPosX(_radius);
	}
	if (_posY < _radius)
	{
		setPosY(_radius);
	}

	setTotalAreas(area());
	setTotalPerimeters(perimeter());
}

//Prefix version
Circle Circle::operator++()
{
	setPosX(getPosX() + 1.0);
	setPosY(getPosY() + 1.0);

	return Circle(getPosX(), getPosY(), getRadius(), getColor(), getRotateAngle(), getRotateX(), getRotateY());
}

//Postfix version
Circle Circle::operator++(int ignoreMe)
{
	double tempPosX, tempPosY;
	tempPosX = getPosX();
	tempPosY = getPosY();
	setPosX(tempPosX + 1.0);
	setPosY(tempPosY + 1.0);

	return Circle(tempPosX, tempPosY, getRadius(), getColor(), getRotateAngle(), getRotateX(), getRotateY());
}

//Prefix version
Circle Circle::operator--()
{
	setPosX(getPosX() - 1.0);
	setPosY(getPosY() - 1.0);

	return Circle(getPosX(), getPosY(), getRadius(), getColor(), getRotateAngle(), getRotateX(), getRotateY());
}

//Postfix version
Circle Circle::operator--(int ignoreMe)
{
	double tempPosX, tempPosY;
	tempPosX = getPosX();
	tempPosY = getPosY();
	setPosX(tempPosX - 1.0);
	setPosY(tempPosY - 1.0);

	return Circle(tempPosX, tempPosY, getRadius(), getColor(), getRotateAngle(), getRotateX(), getRotateY());
}

//operator overloading - and +
const Circle Circle::operator-(const double size) const
{

	return Circle(getPosX() - size, getPosY() - size, getRadius() - size, getColor(), getRotateAngle(), getRotateX(), getRotateY());
}

const Circle Circle::operator+(const double size) const
{

	return Circle(getPosX() + size, getPosY() + size, getRadius() + size, getColor(), getRotateAngle(), getRotateX(), getRotateY());
}

//get reference ofstream parameter. draw object <<
ostream &operator<<(ostream &outs, Circle &obj)
{
	outs << "<circle cx=\"" << obj.getPosX() << "\" cy=\"" << obj.getPosY() << "\" r=\""
		 << obj.getRadius() << "\" transform=\"rotate(" << obj.getRotateAngle() << " "
		 << obj.getRotateX() << " " << obj.getRotateY() << ")\" fill=\"" << obj.getColor()
		 << "\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;

	return outs;
}

string Circle::getColor() const
{
	return _color;
}

void Circle::setColor(string color)
{
	_color = color;
}

double Circle::getPosX() const
{
	return _posX;
}

//if the posx value is  smaller than 0, posx value is assigned 0
void Circle::setPosX(double posX)
{
	if (posX >= 0)
	{
		_posX = posX;
	}
	else
	{
		_posX = 0;
		cout << "Invalid posX Value assigned 0" << endl;
	}
}

double Circle::getPosY() const
{
	return _posY;
}

//if the posy value is  smaller than 0, posy value is assigned 0
void Circle::setPosY(double posY)
{
	if (posY >= 0)
	{
		_posY = posY;
	}
	else
	{
		_posY = 0;
		cout << "Invalid posY Value assigned 0" << endl;
	}
}

double Circle::getRadius() const
{
	return _radius;
}

//if the radius value is 0 or  smaller than 0, radius value is assigned 1
void Circle::setRadius(double radius)
{
	if (radius > 0)
	{
		_radius = radius;
	}
	else
	{
		_radius = 1;
		cout << "Invalid radius Value assigned 1" << endl;
	}
}

double Circle::getRotateAngle() const
{
	return _rotateAngle;
}

//if the rotateAngle value is smaller than -360 or greater than 360, rotateAngle value is assigned 0
void Circle::setRotateAngle(double rotateAngle)
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
		cout << "Invalid rotateAngle Value assigned 0" << endl;
	}
}

double Circle::getRotateX() const
{
	return _rotateX;
}

//if the radius rotateX is 0 or  smaller than 0, rotateX value is assigned 0
void Circle::setRotateX(double rotateX)
{
	if (rotateX >= 0)
	{
		_rotateX = rotateX;
	}
	else
	{
		_rotateX = 0;
		cout << "Invalid rotateX Value assigned 0" << endl;
	}
}

double Circle::getRotateY() const
{
	return _rotateY;
}

//area calculating
double Circle::area()
{
	return (M_PI * _radius * _radius);
}

//perimeter calculating
double Circle::perimeter()
{
	return (2 * M_PI * getRadius());
}

//if the radius rotateY is 0 or  smaller than 0, rotateY value is assigned 0
void Circle::setRotateY(double rotateY)
{
	if (rotateY >= 0)
	{
		_rotateY = rotateY;
	}
	else
	{
		_rotateY = 0;
		cout << "Invalid rotateY Value assigned 0" << endl;
	}
}

//static functions
double Circle::getTotalAreas()
{
	return _totalAreas;
}

void Circle::setTotalAreas(double totalAreas)
{
	_totalAreas += totalAreas;
}

double Circle::getTotalPerimeters()
{
	return _totalPerimeters;
}

void Circle::setTotalPerimeters(double totalPerimeters)
{
	_totalPerimeters += totalPerimeters;
}