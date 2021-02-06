//============================================================================
// Name        : ComposedShape.h
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#ifndef COMPOSEDSHAPE_H_
#define COMPOSEDSHAPE_H_
//if not M_PI define value,value is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;

class ComposedShape
{
	//public members
  public:
	//constructer initialize
	ComposedShape();
	ComposedShape(Rectangle &mContainer, Rectangle &sShape);
	ComposedShape(Rectangle &mContainer, Circle &sShape);
	ComposedShape(Rectangle &mContainer, Triangle &sShape);
	ComposedShape(Circle &mContainer, Rectangle &sShape);
	ComposedShape(Circle &mContainer, Circle &sShape);
	ComposedShape(Circle &mContainer, Triangle &sShape);
	ComposedShape(Triangle &mContainer, Rectangle &sShape);
	ComposedShape(Triangle &mContainer, Circle &sShape);
	ComposedShape(Triangle &mContainer, Triangle &sShape);

	//get set and public function prototype
	void optimalFit();

	static int svgOpen(string fileName, ofstream &svg);
	static int svgClose(ofstream &svg);

	double getEmptyArea() const;
	void setEmptyArea(double emptyArea);
	int getObjectCount() const;
	void setObjectCount(int objectCount);
	vector<Rectangle> &getShapesRect();
	void setShapesRect(vector<Rectangle> shapesRect);
	vector<Circle> &getShapesCirc();
	void setShapesCirc(vector<Circle> shapesCirc);
	vector<Triangle> &getShapesTrig();
	void setShapesTrig(vector<Triangle> shapesTrig);
	char getContainerType() const;
	void setContainerType(char containerType);
	char getShapeType() const;
	void setShapeType(char shapeType);
	Circle &getMainCirc();
	void setMainCirc(Circle mainCirc);
	Rectangle &getMainRect();
	void setMainRect(Rectangle mainRect);
	Triangle &getMainTrig();
	void setMainTrig(Triangle mainTrig);
	Circle &getSmallCirc();
	void setSmallCirc(Circle smallCirc);
	Rectangle &getSmallRect();
	void setSmallRect(Rectangle smallRect);
	Triangle &getSmallTrig();
	void setSmallTrig(Triangle smallTrig);
	void draw(ofstream &svg); //get reference ofstream parameter
	string getMainColor() const;
	void setMainColor(string mainColor);
	//private members
  private:
	vector<Rectangle> optimalRectRect(Rectangle &mContainer, Rectangle &sShape);
	vector<Circle> optimalRectCirc(Rectangle &mContainer, Circle &sShape);
	vector<Triangle> optimalRectTrig(Rectangle &mContainer, Triangle &sShape);
	vector<Rectangle> optimalCircRect(Circle &mContainer, Rectangle &sShape);
	vector<Circle> optimalCircCirc(Circle &mContainer, Circle &sShape);
	vector<Triangle> optimalCircTrig(Circle &mContainer, Triangle &sShape);
	vector<Rectangle> optimalTrigRect(Triangle &mContainer, Rectangle &sShape);
	vector<Circle> optimalTrigCirc(Triangle &mContainer, Circle &sShape);
	vector<Triangle> optimalTrigTrig(Triangle &mContainer, Triangle &sShape);
	Rectangle _mainRect;
	Rectangle _smallRect;
	Circle _mainCirc;
	Circle _smallCirc;
	Triangle _mainTrig;
	Triangle _smallTrig;
	char _mContainerType;
	char _sShapeType;
	double _emptyArea;
	int _objectCount;
	string _mainColor;
	vector<Rectangle> _shapesRect;
	vector<Circle> _shapesCirc;
	vector<Triangle> _shapesTrig;
};

#endif /* COMPOSEDSHAPE_H_ */
