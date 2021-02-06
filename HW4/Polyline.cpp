//============================================================================
// Name        : Polyline.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "Polyline.h"
//Class for Polyline of Shape in ComposeShape
namespace shape
{
Polyline::Polyline()
{
}

//copy constructer
Polyline::Polyline(const Polyline &obj)
{
	setPointCount(obj.getPointCount());
	setPointsPtr(new Point2D[getPointCount()]);
	setColor(obj.getColor());
	setRotateAngle(obj.getRotateAngle());
	setRotateX(obj.getRotateX());
	setRotateY(obj.getRotateY());

	for (int i = 0; i < getPointCount(); i++)
	{
		getPointsPtr()[i] = obj[i];
	}
}

//assignment operaotor overloading
Polyline &Polyline::operator=(const Polyline &rightSide)
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

	for (int i = 0; i < getPointCount(); i++)
	{
		getPointsPtr()[i] = rightSide[i];
	}

	return *this;
}

//Destructor
Polyline::~Polyline()
{
	delete[] getPointsPtr(); //delete array
}

//constructer ex: Polygon(Rectangle)
Polyline::Polyline(Rectangle &rect)
{ //assign class member value
	setPointCount(4);
	setPointsPtr(new Point2D[4]);
	setColor(rect.getColor());
	setRotateAngle(rect.getRotateAngle());
	setRotateX(rect.getRotateX());
	setRotateY(rect.getRotateY());

	getPointsPtr()[0].setX(rect.getPosX());
	getPointsPtr()[0].setY(rect.getPosY());

	getPointsPtr()[1].setX(rect.getPosX());
	getPointsPtr()[1].setY(rect.getPosY() + rect.getHeight());

	getPointsPtr()[2].setX(rect.getPosX() + rect.getWidth());
	getPointsPtr()[2].setY(rect.getPosY() + rect.getHeight());

	getPointsPtr()[3].setX(rect.getPosX() + rect.getWidth());
	getPointsPtr()[3].setY(rect.getPosY());
}

//constructer ex: Polygon(Circle)
Polyline::Polyline(Circle &circ)
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
}

//reference Polyline [] operator overloading
Polyline::Point2D &Polyline::operator[](int index) //lvalue
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

//reference Polyline [] operator overloading
const Polyline::Point2D &Polyline::operator[](int index) const //rvalue
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
Polyline::Polyline(Triangle &trig)
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
}

//get reference ofstream parameter. draw object <<
ostream &operator<<(ostream &outs, Polyline &obj)
{
	outs << "<polyline points=\"";
	for (int i = 0; i < obj.getPointCount(); ++i)
	{
		outs << obj[i].getX() << "," << obj[i].getY();
		if (i + 1 < obj.getPointCount())
		{
			outs << " ";
		}
	}

	outs << "\" transform=\"rotate(" << obj.getRotateAngle() << " " << obj.getRotateX()
		 << " " << obj.getRotateY() << ")\" stroke=\"" << obj.getColor()
		 << "\" fill=\"white\" stroke-width=\"1\" />" << endl;

	return outs;
}

//operator overloading +
Polyline operator+(Polyline &firstOperand, Polyline &secondOperand)
{
	int pointCount = firstOperand.getPointCount() + secondOperand.getPointCount();
	Polyline out;
	out.setPointCount(pointCount);
	out.setPointsPtr(new Polyline::Point2D[pointCount]);
	out.setColor("black");
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

//Operators == comparison operators to compare Polyline shape operator overloading
bool operator==(Polyline &firstOperand, Polyline &secondOperand)
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
Polyline::Polyline(Point2D &point2d)
{ //assign class member value
	setPointCount(1);
	setPointsPtr(new Point2D[1]);
	setColor("white");
	setRotateAngle(0);
	setRotateX(0);
	setRotateY(0);

	getPointsPtr()[0].setX(point2d.getX());
	getPointsPtr()[0].setY(point2d.getY());
}

//constructer ex: Polygon(vector<Point2D>)
Polyline::Polyline(vector<Point2D> &vectPoint)
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
}

Polyline::Point2D::Point2D()
{
}

//constructer ex: Point2D(x,y)
Polyline::Point2D::Point2D(double x, double y)
{ //assign class member value
	setX(x);
	setY(y);
}

string Polyline::getColor() const
{
	return _color;
}

void Polyline::setColor(string color)
{
	_color = color;
}

double Polyline::getRotateAngle() const
{
	return _rotateAngle;
}

void Polyline::setRotateAngle(double rotateAngle)
{
	_rotateAngle = rotateAngle;
}

double Polyline::getRotateX() const
{
	return _rotateX;
}

void Polyline::setRotateX(double rotateX)
{
	_rotateX = rotateX;
}

double Polyline::getRotateY() const
{
	return _rotateY;
}

void Polyline::setRotateY(double rotateY)
{
	_rotateY = rotateY;
}

int Polyline::getPointCount() const
{
	return _pointCount;
}

void Polyline::setPointCount(int pointCount)
{
	_pointCount = pointCount;
}

Polyline::Point2D *Polyline::getPointsPtr() const
{
	return _pointsPtr;
}

void Polyline::setPointsPtr(Point2D *pointsPtr)
{
	_pointsPtr = pointsPtr;
}

double Polyline::Point2D::getX() const
{
	return _x;
}

void Polyline::Point2D::setX(double x)
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

double Polyline::Point2D::getY() const
{
	return _y;
}

void Polyline::Point2D::setY(double y)
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