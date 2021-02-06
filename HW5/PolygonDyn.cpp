//============================================================================
// Name        : PolygonDyn.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "PolygonDyn.h"
//Class for PolygonDyn of Shape in ComposeShape
namespace shape
{
PolygonDyn::PolygonDyn()
{
	setPointsPtr(nullptr);
}

//copy constructer
PolygonDyn::PolygonDyn(const PolygonDyn &obj)
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
PolygonDyn &PolygonDyn::operator=(const PolygonDyn &rightSide)
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
PolygonDyn::~PolygonDyn()
{
	delete[] getPointsPtr(); //delete array
}

//constructer ex: PolygonDyn(Rectangle)
PolygonDyn::PolygonDyn(Rectangle &rect)
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

//constructer ex: PolygonDyn(Circle)
PolygonDyn::PolygonDyn(Circle &circ)
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

//reference PolygonDyn [] operator overloading
PolygonDyn::Point2D &PolygonDyn::operator[](int index) throw(out_of_range) //dynamic exception specifications are deprecated in C++11  //lvalue
{
	decltype(getPointCount()) ndx = index;
	if (ndx < getPointCount())
	{
		return getPointsPtr()[index];
	}
	else
	{
		throw out_of_range("Illegal index value. return 0 element");
	}
}

//reference PolygonDyn [] operator overloading
const PolygonDyn::Point2D &PolygonDyn::operator[](int index) const throw(out_of_range) //dynamic exception specifications are deprecated in C++11 //rvalue
{
	decltype(getPointCount()) ndx = index;
	if (ndx < getPointCount())
	{
		return _pointsPtr[index];
	}
	else
	{
		throw out_of_range("Illegal index value. return 0 element");
	}
}

//constructer ex: PolygonDyn(Triangle)
PolygonDyn::PolygonDyn(Triangle &trig)
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
ostream &operator<<(ostream &outs, PolygonDyn &obj)
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

ostream &PolygonDyn::draw(ostream &outs)
{
	outs << *this;
	return outs;
}

//Prefix version
Shape &PolygonDyn::operator++()
{
	for (int i = 0; i < getPointCount(); ++i)
	{
		(*this)[i].setX((*this)[i].getX() + 1.0);
		(*this)[i].setY((*this)[i].getY() + 1.0);
	}

	Shape *shp = new PolygonDyn(*this);

	return *shp;
}

//Postfix version
Shape &PolygonDyn::operator++(int ignoreMe)
{
	double tempPosX, tempPosY;

	Shape *shp = new PolygonDyn(*this);
	for (int i = 0; i < getPointCount(); ++i)
	{
		tempPosX = (*this)[i].getX();
		tempPosY = (*this)[i].getY();
		tempPosX += 1.0;
		tempPosY += 1.0;
		(*this)[i].setX(tempPosX);
		(*this)[i].setY(tempPosY);
	}
	return *shp;
}

//Prefix version
Shape &PolygonDyn::operator--()
{
	for (int i = 0; i < getPointCount(); ++i)
	{
		(*this)[i].setX((*this)[i].getX() - 1.0);
		(*this)[i].setY((*this)[i].getY() - 1.0);
	}

	Shape *shp = new PolygonDyn(*this);

	return *shp;
}

//Postfix version
Shape &PolygonDyn::operator--(int ignoreMe)
{
	double tempPosX, tempPosY;

	Shape *shp = new PolygonDyn(*this);
	for (int i = 0; i < getPointCount(); ++i)
	{
		tempPosX = (*this)[i].getX();
		tempPosY = (*this)[i].getY();
		tempPosX -= 1.0;
		tempPosY -= 1.0;
		(*this)[i].setX(tempPosX);
		(*this)[i].setY(tempPosY);
	}
	return *shp;
}

//area calculating
double PolygonDyn::area()
{
	return (getArea());
}

//perimeter calculating
double PolygonDyn::perimeter()
{
	return (getPerimeter());
}

//operator overloading +
PolygonDyn operator+(PolygonDyn &firstOperand, PolygonDyn &secondOperand)
{
	int pointCount = firstOperand.getPointCount() + secondOperand.getPointCount();
	PolygonDyn out;
	out.setPointCount(pointCount);
	out.setPointsPtr(new PolygonDyn::Point2D[pointCount]);
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

//Operators == comparison operators to compare two PolygonDyn operator overloading
bool operator==(PolygonDyn &firstOperand, PolygonDyn &secondOperand)
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

//constructer ex: PolygonDyn(Point2D)
PolygonDyn::PolygonDyn(Point2D &point2d)
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

//constructer ex: PolygonDyn(vector<Point2D>)
PolygonDyn::PolygonDyn(vector<Point2D> &vectPoint)
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

PolygonDyn::Point2D *PolygonDyn::getPointsPtr() const
{
	return _pointsPtr;
}

void PolygonDyn::setPointsPtr(Point2D *pointsPtr)
{
	_pointsPtr = pointsPtr;
}

} // namespace shape