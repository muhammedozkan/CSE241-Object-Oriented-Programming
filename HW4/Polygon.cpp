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
Polygon::Polygon()
{
}

//copy constructer
Polygon::Polygon(const Polygon &obj)
{
	setPointCount(obj.getPointCount());
	setPointsPtr(new Point2D[getPointCount()]);
	setColor(obj.getColor());
	setRotateAngle(obj.getRotateAngle());
	setRotateX(obj.getRotateX());
	setRotateY(obj.getRotateY());
	setArea(obj.getArea());
	setPerimeter(obj.getPerimeter());

	for (int i = 0; i < getPointCount(); i++)
	{
		getPointsPtr()[i] = obj[i];
	}
}

//assignment operaotor overloading
Polygon &Polygon::operator=(const Polygon &rightSide)
{
	if (getPointCount() != rightSide.getPointCount())
	{
		delete[] getPointsPtr();
		setPointsPtr(new Point2D[rightSide.getPointCount()]);
	}
	setPointCount(rightSide.getPointCount());
	setPointsPtr(new Point2D[getPointCount()]);
	setColor(rightSide.getColor());
	setRotateAngle(rightSide.getRotateAngle());
	setRotateX(rightSide.getRotateX());
	setRotateY(rightSide.getRotateY());
	setArea(rightSide.getArea());
	setPerimeter(rightSide.getPerimeter());

	for (int i = 0; i < getPointCount(); i++)
	{
		getPointsPtr()[i] = rightSide[i];
	}

	return *this;
}

//Destructor
Polygon::~Polygon()
{
	delete[] getPointsPtr(); //delete array
}

//constructer ex: Polygon(Rectangle)
Polygon::Polygon(Rectangle &rect)
{ //assign class member value
	setPointCount(4);
	setPointsPtr(new Point2D[4]);
	setColor(rect.getColor());
	setRotateAngle(rect.getRotateAngle());
	setRotateX(rect.getRotateX());
	setRotateY(rect.getRotateY());

	getPointsPtr()[0].setX(rect.getPosX() + rect.getX());
	getPointsPtr()[0].setY(rect.getPosY() + rect.getY());

	getPointsPtr()[1].setX(rect.getPosX() + rect.getX());
	getPointsPtr()[1].setY(rect.getPosY() + rect.getHeight() + rect.getY());

	getPointsPtr()[2].setX(rect.getPosX() + rect.getWidth() + rect.getX());
	getPointsPtr()[2].setY(rect.getPosY() + rect.getHeight() + rect.getY());

	getPointsPtr()[3].setX(rect.getPosX() + rect.getWidth() + rect.getX());
	getPointsPtr()[3].setY(rect.getPosY() + rect.getY());

	setArea(rect.area());
	setPerimeter(rect.perimeter());
}

//constructer ex: Polygon(Circle)
Polygon::Polygon(Circle &circ)
{					//assign class member value
	int side = 100; //circle represented side value 100 default value
	setPointCount(side);
	setPointsPtr(new Point2D[side]);
	setColor(circ.getColor());
	setRotateAngle(circ.getRotateAngle());
	setRotateX(circ.getRotateX());
	setRotateY(circ.getRotateY());

	double angle = 2 * M_PI / side;

	for (int i = 0; i < side; ++i)
	{
		getPointsPtr()[i].setX(circ.getPosX() + circ.getRadius() * cos(angle * i));
		getPointsPtr()[i].setY(circ.getPosY() - circ.getRadius() * sin(angle * i));
	}

	setArea(circ.area());
	setPerimeter(circ.perimeter());
}

//reference Polygon [] operator overloading
Polygon::Point2D &Polygon::operator[](int index) //lvalue
{
	decltype(getPointCount()) ndx = index;
	if (ndx < getPointCount())
	{
		return getPointsPtr()[index];
	}
	else
	{
		cout << "Illegal index value. return 0 element" << endl;
		return getPointsPtr()[0];
	}
}

//reference Polygon [] operator overloading
const Polygon::Point2D &Polygon::operator[](int index) const //rvalue
{
	decltype(getPointCount()) ndx = index;
	if (ndx < getPointCount())
	{
		return _pointsPtr[index];
	}
	else
	{
		cout << "Illegal index value. return 0 element" << endl;
		return _pointsPtr[0];
	}
}

//constructer ex: Polygon(Triangle)
Polygon::Polygon(Triangle &trig)
{ //assign class member value
	setPointCount(3);
	setPointsPtr(new Point2D[3]);
	setColor(trig.getColor());
	setRotateAngle(trig.getRotateAngle());
	setRotateX(trig.getRotateX());
	setRotateY(trig.getRotateY());

	getPointsPtr()[0].setX(trig.getPoint1X() + trig.getPosX());
	getPointsPtr()[0].setY(trig.getPoint1Y() + trig.getPosY());

	getPointsPtr()[1].setX(trig.getPoint2X() + trig.getPosX());
	getPointsPtr()[1].setY(trig.getPoint2Y() + trig.getPosY());

	getPointsPtr()[2].setX(trig.getPoint3X() + trig.getPosX());
	getPointsPtr()[2].setY(trig.getPoint3Y() + trig.getPosY());

	setArea(trig.area());
	setPerimeter(trig.perimeter());
}

//get reference ofstream parameter. draw object <<
ostream &operator<<(ostream &outs, Polygon &obj)
{
	outs << "<polygon points=\"";
	for (int i = 0; i < obj.getPointCount(); ++i)
	{
		outs << obj[i].getX() << "," << obj[i].getY();
		if (i + 1 < obj.getPointCount())
		{
			outs << " ";
		}
	}

	outs << "\" transform=\"rotate(" << obj.getRotateAngle() << " " << obj.getRotateX()
		 << " " << obj.getRotateY() << ")\" fill=\"" << obj.getColor()
		 << "\" stroke=\"black\" stroke-width=\"0.5\" />" << endl;

	return outs;
}

//operator overloading +
Polygon operator+(Polygon &firstOperand, Polygon &secondOperand)
{
	int pointCount = firstOperand.getPointCount() + secondOperand.getPointCount();
	Polygon out;
	out.setPointCount(pointCount);
	out.setPointsPtr(new Polygon::Point2D[pointCount]);
	out.setColor("white");
	out.setRotateAngle(0);
	out.setRotateX(0);
	out.setRotateY(0);
	int i;

	for (i = 0; i < firstOperand.getPointCount(); ++i)
	{
		out[i].setX(firstOperand[i].getX());
		out[i].setY(firstOperand[i].getY());
	}

	for (int j = 0; j < secondOperand.getPointCount(); ++j, ++i)
	{
		out[i].setX(secondOperand[j].getX());
		out[i].setY(secondOperand[j].getY());
	}

	return out;
}

//Operators == comparison operators to compare two Polygon operator overloading
bool operator==(Polygon &firstOperand, Polygon &secondOperand)
{
	if (firstOperand.getPointCount() == secondOperand.getPointCount())
	{
		for (int i = 0; i < firstOperand.getPointCount(); ++i)
		{
			if (!(firstOperand[i].getX() == secondOperand[i].getX() && firstOperand[i].getY() == secondOperand[i].getY()))
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

//constructer ex: Polygon(Point2D)
Polygon::Polygon(Point2D &point2d)
{ //assign class member value
	setPointCount(1);
	setPointsPtr(new Point2D[1]);
	setColor("white");
	setRotateAngle(0);
	setRotateX(0);
	setRotateY(0);

	getPointsPtr()[0].setX(point2d.getX());
	getPointsPtr()[0].setY(point2d.getY());

	setArea(0);
	setPerimeter(0);
}

//constructer ex: Polygon(vector<Point2D>)
Polygon::Polygon(vector<Point2D> &vectPoint)
{ //assign class member value
	setPointCount(vectPoint.size());
	setPointsPtr(new Point2D[getPointCount()]);
	setColor("white");
	setRotateAngle(0);
	setRotateX(0);
	setRotateY(0);

	for (int i = 0; i < getPointCount(); ++i)
	{
		getPointsPtr()[i].setX(vectPoint[i].getX());
		getPointsPtr()[i].setY(vectPoint[i].getY());
	}

	setArea(0);		 // not calculated
	setPerimeter(0); // not calculated
}

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

double Polygon::getArea() const
{
	return _area;
}

void Polygon::setArea(double area)
{
	_area = area;
}

double Polygon::getPerimeter() const
{
	return _perimeter;
}

void Polygon::setPerimeter(double perimeter)
{
	_perimeter = perimeter;
}

Polygon::Point2D *Polygon::getPointsPtr() const
{
	return _pointsPtr;
}

void Polygon::setPointsPtr(Point2D *pointsPtr)
{
	_pointsPtr = pointsPtr;
}

double Polygon::Point2D::getX() const
{
	return _x;
}

void Polygon::Point2D::setX(double x)
{

	if (x >= 0)
	{
		_x = x;
	}
	else
	{
		_x = 0;
		cout << "Invalid Point2D Y Value assigned 0" << endl;
	}
}

double Polygon::Point2D::getY() const
{
	return _y;
}

void Polygon::Point2D::setY(double y)
{
	if (y >= 0)
	{
		_y = y;
	}
	else
	{
		_y = 0;
		cout << "Invalid Point2D Y Value assigned 0" << endl;
	}
}
} // namespace shape