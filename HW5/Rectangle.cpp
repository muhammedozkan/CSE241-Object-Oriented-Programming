//============================================================================
// Name        : Rectangle.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "Rectangle.h"
//Class for Rectangle of Shape in ComposeShape

//code implementation default constructer
namespace shape
{
Rectangle::Rectangle()
{
}

//constructer ex: Rectangle(color,height,width)
Rectangle::Rectangle(string color, double height, double width)
{ //assign class member value
	setPosX(0);
	setPosY(0);
	setWidth(width);
	setHeight(height);
	setColor(color);
	setRotateAngle(0);
	setRotateX(0);
	setRotateY(0);
	setX(0);
	setY(0);
	setTotalAreas(area());
	setTotalPerimeters(perimeter());
}

//constructer ex: Circle(posX,posY,width,height,color,rotateAngle,rotateX,rotateY,x,y)
Rectangle::Rectangle(double posX, double posY, double width, double height,
					 string color, double rotateAngle, double rotateX, double rotateY,
					 double x, double y)
{ //assign class member value
	setPosX(posX);
	setPosY(posY);
	setWidth(width);
	setHeight(height);
	setColor(color);
	setRotateAngle(rotateAngle);
	setRotateX(rotateX);
	setRotateY(rotateY);
	setX(x);
	setY(y);

	setTotalAreas(area());
	setTotalPerimeters(perimeter());
}

//Prefix version
Shape &Rectangle::operator++()
{
	setPosX(getPosX() + 1.0);
	setPosY(getPosY() + 1.0);
	setRotateX(getRotateX() + 1.0);
	setRotateY(getRotateY() + 1.0);
	Shape *shp = new Rectangle(getPosX(), getPosY(), getWidth(), getHeight(), getColor(), getRotateAngle(), getRotateX(), getRotateY(), getX(), getY());

	return *shp;
}

//Postfix version
Shape &Rectangle::operator++(int ignoreMe)
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

	Shape *shp = new Rectangle(tempPosX, tempPosY, getWidth(), getHeight(), getColor(), getRotateAngle(), tempRotateX, tempRotateY, getX(), getY());
	return *shp;
}

//Prefix version
Shape &Rectangle::operator--()
{
	setPosX(getPosX() - 1.0);
	setPosY(getPosY() - 1.0);
	setRotateX(getRotateX() - 1.0);
	setRotateY(getRotateY() - 1.0);
	Shape *shp = new Rectangle(getPosX(), getPosY(), getWidth(), getHeight(), getColor(), getRotateAngle(), getRotateX(), getRotateY(), getX(), getY());
	return *shp;
}

//Postfix version
Shape &Rectangle::operator--(int ignoreMe)
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

	Shape *shp = new Rectangle(tempPosX, tempPosY, getWidth(), getHeight(), getColor(), getRotateAngle(), tempRotateX, tempRotateY, getX(), getY());
	return *shp;
}

//operator overloading - and +
const Rectangle Rectangle::operator-(const double size) const
{
	return Rectangle(getPosX(), getPosY(), getWidth() - size, getHeight() - size, getColor(), getRotateAngle(), getRotateX(), getRotateY(), getX(), getY());
}

const Rectangle Rectangle::operator+(const double size) const
{
	return Rectangle(getPosX(), getPosY(), getWidth() + size, getHeight() + size, getColor(), getRotateAngle(), getRotateX(), getRotateY(), getX(), getY());
}

//get reference ofstream parameter. draw object <<
ostream &operator<<(ostream &outs, Rectangle &obj)
{
	outs << "<rect x=\"" << obj.getPosX() + obj.getX() << "\"  y=\"" << obj.getPosY() + obj.getY()
		 << "\" width=\"" << obj.getWidth() << "\" height=\"" << obj.getHeight()
		 << "\" transform=\"rotate(" << obj.getRotateAngle() << " " << obj.getRotateX() + obj.getX()
		 << " " << obj.getRotateY() + obj.getY() << ")\" fill=\"" << obj.getColor()
		 << "\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;

	return outs;
}

ostream &Rectangle::draw(ostream &outs)
{
	outs << *this;

	return outs;
}

string Rectangle::getColor() const
{
	return _color;
}

void Rectangle::setColor(string color)
{
	_color = color;
}

double Rectangle::getHeight() const
{
	return _height;
}

//if the height value is 0 or  smaller than 0, height value is assigned 1
void Rectangle::setHeight(double height) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (height > 0)
	{
		_height = height;
	}
	else
	{
		_height = 1;
		throw invalid_argument("Invalid height Value assigned 1");
	}
}

double Rectangle::getPosX() const
{
	return _posX;
}

//if the posx value is  smaller than 0, posx value is assigned 0
void Rectangle::setPosX(double posX) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
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

double Rectangle::getPosY() const
{
	return _posY;
}

//if the posy value is  smaller than 0, posy value is assigned 0
void Rectangle::setPosY(double posY) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
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

double Rectangle::getRotateAngle() const
{
	return _rotateAngle;
}

//if the rotateAngle value is smaller than -360 or greater than 360, rotateAngle value is assigned 0
void Rectangle::setRotateAngle(double rotateAngle) throw(invalid_argument) //dynamic exception specifications are deprecated in
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

double Rectangle::getRotateX() const
{
	return _rotateX;
}

//if the radius rotateX is 0 or  smaller than 0, rotateX value is assigned 0
void Rectangle::setRotateX(double rotateX) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
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

//if the radius rotateY is 0 or  smaller than 0, rotateY value is assigned 0
double Rectangle::getRotateY() const
{
	return _rotateY;
}

void Rectangle::setRotateY(double rotateY) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
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

double Rectangle::getWidth() const
{
	return _width;
}

//if the width value is 0 or  smaller than 0, width value is assigned 1
void Rectangle::setWidth(double width) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (width > 0)
	{
		_width = width;
	}
	else
	{
		_width = 1;
		throw invalid_argument("Invalid width Value assigned 1");
	}
}

double Rectangle::getX() const
{
	return _x;
}

//if the x value is  smaller than 0, x value is assigned 0
void Rectangle::setX(double x) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (x >= 0)
	{
		_x = x;
	}
	else
	{
		_x = 0;
		throw invalid_argument("Invalid x Value assigned 0");
	}
}

double Rectangle::getY() const
{
	return _y;
}

//area calculating
double Rectangle::area()
{
	return (_width * _height);
}

//perimeter calculating
double Rectangle::perimeter()
{
	return ((getWidth() + getHeight()) * 2);
}

//if the y value is  smaller than 0, y value is assigned 0
void Rectangle::setY(double y) throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (y >= 0)
	{
		_y = y;
	}
	else
	{
		_y = 0;
		throw invalid_argument("Invalid y Value assigned 0");
	}
}

//static functions
double Rectangle::getTotalAreas()
{
	return _totalAreas;
}

void Rectangle::setTotalAreas(double totalAreas)
{
	_totalAreas += totalAreas;
}

double Rectangle::getTotalPerimeters()
{
	return _totalPerimeters;
}

void Rectangle::setTotalPerimeters(double totalPerimeters)
{
	_totalPerimeters += totalPerimeters;
}
} // namespace shape