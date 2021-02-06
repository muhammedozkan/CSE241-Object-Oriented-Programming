//============================================================================
// Name        : Rectangle.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include "Rectangle.h"
//Class for Rectangle of Shape in ComposeShape
//code implementation
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
}
//get reference ofstream parameter. draw object
void Rectangle::draw(ofstream &file)
{
	file << "<rect x=\"" << _posX + _x << "\"  y=\"" << _posY + _y
		 << "\" width=\"" << _width << "\" height=\"" << _height
		 << "\" transform=\"rotate(" << _rotateAngle << " " << _rotateX + _x
		 << " " << _rotateY + _y << ")\" fill=\"" << _color
		 << "\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;
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
void Rectangle::setHeight(double height)
{
	if (height > 0)
	{
		_height = height;
	}
	else
	{
		_height = 1;
		cout << "Invalid height Value assigned 1" << endl;
	}
}

double Rectangle::getPosX() const
{
	return _posX;
}
//if the posx value is  smaller than 0, posx value is assigned 0
void Rectangle::setPosX(double posX)
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

double Rectangle::getPosY() const
{
	return _posY;
}
//if the posy value is  smaller than 0, posy value is assigned 0
void Rectangle::setPosY(double posY)
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

double Rectangle::getRotateAngle() const
{
	return _rotateAngle;
}
//if the rotateAngle value is smaller than -360 or greater than 360, rotateAngle value is assigned 0
void Rectangle::setRotateAngle(double rotateAngle)
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

double Rectangle::getRotateX() const
{
	return _rotateX;
}
//if the radius rotateX is 0 or  smaller than 0, rotateX value is assigned 0
void Rectangle::setRotateX(double rotateX)
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
//if the radius rotateY is 0 or  smaller than 0, rotateY value is assigned 0
double Rectangle::getRotateY() const
{
	return _rotateY;
}

void Rectangle::setRotateY(double rotateY)
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

double Rectangle::getWidth() const
{
	return _width;
}
//if the width value is 0 or  smaller than 0, width value is assigned 1
void Rectangle::setWidth(double width)
{
	if (width > 0)
	{
		_width = width;
	}
	else
	{
		_width = 1;
		cout << "Invalid width Value assigned 1" << endl;
	}
}

double Rectangle::getX() const
{
	return _x;
}
//if the x value is  smaller than 0, x value is assigned 0
void Rectangle::setX(double x)
{
	if (x >= 0)
	{
		_x = x;
	}
	else
	{
		_x = 0;
		cout << "Invalid x Value assigned 0" << endl;
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
//if the y value is  smaller than 0, y value is assigned 0
void Rectangle::setY(double y)
{
	if (y >= 0)
	{
		_y = y;
	}
	else
	{
		_y = 0;
		cout << "Invalid y Value assigned 0" << endl;
	}
}
