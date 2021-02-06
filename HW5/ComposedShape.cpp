//============================================================================
// Name        : ComposedShape.cpp
// Author      : MuhammedOZKAN 151044084
// Version     :
// Copyright   : @pithblood
// Description :
//============================================================================

#include "ComposedShape.h"
//Class for Compose Shape
//code implementation

//constructer ex: ComposedShape(Rectangle&,Rectangle&) get reference object
ComposedShape::ComposedShape(Rectangle &mContainer, Rectangle &sShape)
{ //assign class member value

	_main.setType(ShapeElem::shapeType::Rectangle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Rectangle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

//constructer ex: ComposedShape(Rectangle&,Circle&) get reference object
ComposedShape::ComposedShape(Rectangle &mContainer, Circle &sShape)
{ //assign class member value

	_main.setType(ShapeElem::shapeType::Rectangle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Circle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

//constructer ex: ComposedShape(Rectangle&,Triangle&) get reference object
ComposedShape::ComposedShape(Rectangle &mContainer, Triangle &sShape)
{ //assign class member value
	_main.setType(ShapeElem::shapeType::Rectangle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Triangle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

//constructer ex: ComposedShape(Circle&,Rectangle&) get reference object
ComposedShape::ComposedShape(Circle &mContainer, Rectangle &sShape)
{ //assign class member value
	_main.setType(ShapeElem::shapeType::Circle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Rectangle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

//constructer ex: ComposedShape(Circle&,Circle&) get reference object
ComposedShape::ComposedShape(Circle &mContainer, Circle &sShape)
{ //assign class member value
	_main.setType(ShapeElem::shapeType::Circle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Circle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

//constructer ex: ComposedShape(Circle&,Triangle&) get reference object
ComposedShape::ComposedShape(Circle &mContainer, Triangle &sShape)
{ //assign class member value
	_main.setType(ShapeElem::shapeType::Circle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Triangle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

//constructer ex: ComposedShape(Triangle&,Rectangle&) get reference object
ComposedShape::ComposedShape(Triangle &mContainer, Rectangle &sShape)
{ //assign class member value
	_main.setType(ShapeElem::shapeType::Triangle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Rectangle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

//constructer ex: ComposedShape(Triangle&,Circle&) get reference object
ComposedShape::ComposedShape(Triangle &mContainer, Circle &sShape)
{ //assign class member value
	_main.setType(ShapeElem::shapeType::Triangle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Circle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

//constructer ex: ComposedShape(Triangle&,Triangle&) get reference object
ComposedShape::ComposedShape(Triangle &mContainer, Triangle &sShape)
{ //assign class member value
	_main.setType(ShapeElem::shapeType::Triangle);
	_main.setPtrShape(&mContainer);
	_shape.setType(ShapeElem::shapeType::Triangle);
	_shape.setPtrShape(&sShape);
	setMainColor(mContainer.getColor());
}

void ComposedShape::optimalRectRect(Rectangle *mContainer, Rectangle *sShape)
{
	int row = mContainer->getHeight() / sShape->getHeight(); //calculating the maximum row
	int col = mContainer->getWidth() / sShape->getWidth();   //calculating the maximum column
	int row2 = mContainer->getHeight() / sShape->getWidth(); //calculating the maximum row
	int col2 = mContainer->getWidth() / sShape->getHeight(); //calculating the maximum column

	double temp;
	int i, j;

	if (getMainShape().getType() == ShapeElem::shapeType::Rectangle)
	{

		*this += dynamic_cast<Shape *>(mContainer);
	}

	//most circles drawn statement is selected.if row*col is maximum, following statement. if not, following the else statement

	if (row * col >= row2 * col2)
	{
		for (i = 0; i < row; i++) //row loop
		{
			for (j = 0; j < col; j++) //column loop
			{

				Rectangle *rect = new Rectangle(j * sShape->getWidth() + sShape->getX() + mContainer->getPosX(),
												i * sShape->getHeight() + sShape->getY() + mContainer->getPosY(),
												sShape->getWidth(), sShape->getHeight(),
												sShape->getColor(), 0, 0, 0, mContainer->getX(),
												mContainer->getY());

				*this += dynamic_cast<Shape *>(rect); //example instead of _shapes.push_back(shp);
			}
		}

		double diffcol = mContainer->getWidth() - (col * sShape->getWidth());
		double diffrow = mContainer->getHeight() - (row * sShape->getHeight());

		if (diffcol >= sShape->getHeight()) //placing rotated rectangles in empty spaces
		{
			for (int t = 0;
				 t < (mContainer->getWidth() - (col * sShape->getWidth())) / sShape->getHeight() - 1; t++)
			{
				for (int k = 0;
					 k < mContainer->getHeight() / sShape->getWidth() - 1;
					 k++)
				{
					Rectangle *rect = new Rectangle((j * sShape->getWidth()) + sShape->getX() + (t * sShape->getHeight()) + mContainer->getPosX(),
													k * sShape->getWidth() + sShape->getY() + mContainer->getPosY(), sShape->getHeight(), sShape->getWidth(),
													sShape->getColor(), 0, 0, 0, mContainer->getX(), mContainer->getY());

					*this += dynamic_cast<Shape *>(rect);
				}
			}
		}
		else if (diffrow >= sShape->getWidth())
		{
			for (int t = 0;
				 t < (mContainer->getHeight() - (row * sShape->getHeight())) / sShape->getWidth() - 1; t++)
			{
				for (int k = 0;
					 k < mContainer->getWidth() / sShape->getHeight() - 1;
					 k++)
				{
					Rectangle *rect = new Rectangle((k * sShape->getHeight()) + sShape->getX() + mContainer->getPosX(), (i * sShape->getHeight()) + sShape->getY() + (t * sShape->getWidth()) + mContainer->getPosY(),
													sShape->getHeight(), sShape->getWidth(), sShape->getColor(), 0, 0, 0, mContainer->getX(), mContainer->getY());

					*this += dynamic_cast<Shape *>(rect);
				}
			}
		}
	}
	else
	{
		//the data is swapped(width, height,row)
		temp = sShape->getWidth();
		sShape->setWidth(sShape->getHeight());
		sShape->setHeight(temp);
		int i, j;

		for (i = 0; i < row2; i++) //row loop
		{
			for (j = 0; j < col2; j++) //column loop
			{
				Rectangle *rect = new Rectangle((j * sShape->getWidth()) + sShape->getX() + mContainer->getPosX(),
												(i * sShape->getHeight()) + sShape->getY() + mContainer->getPosY(),
												sShape->getWidth(), sShape->getHeight(),
												sShape->getColor(), 0, 0, 0, mContainer->getX(),
												mContainer->getY());

				*this += dynamic_cast<Shape *>(rect);
			}
		}

		double diffcol = mContainer->getWidth() - (col2 * sShape->getWidth());
		double diffrow = mContainer->getHeight() - (row2 * sShape->getHeight());

		if (diffcol >= sShape->getHeight()) //placing rotated rectangles in empty spaces
		{
			for (int t = 0;
				 t < (mContainer->getWidth() - (col2 * sShape->getWidth())) / sShape->getHeight() - 1; t++)
			{
				for (int k = 0;
					 k < mContainer->getHeight() / sShape->getWidth() - 1;
					 k++)
				{
					Rectangle *rect = new Rectangle((j * sShape->getWidth()) + sShape->getX() + (t * sShape->getHeight()) + mContainer->getPosX(),
													(k * sShape->getWidth()) + sShape->getY() + mContainer->getPosY(), sShape->getHeight(), sShape->getWidth(),
													sShape->getColor(), 0, 0, 0, mContainer->getX(), mContainer->getY());

					*this += dynamic_cast<Shape *>(rect);
				}
			}
		}
		else if (diffrow >= sShape->getWidth())
		{
			for (int t = 0;
				 t < (mContainer->getHeight() - (row2 * sShape->getHeight())) / sShape->getWidth() - 1; t++)
			{
				for (int k = 0;
					 k < mContainer->getWidth() / sShape->getHeight() - 1;
					 k++)
				{
					Rectangle *rect = new Rectangle((k * sShape->getHeight()) + sShape->getX() + mContainer->getPosX(),
													(i * sShape->getHeight()) + sShape->getY() + (t * sShape->getWidth()) + mContainer->getPosY(),
													sShape->getHeight(), sShape->getWidth(), sShape->getColor(), 0, 0, 0,
													mContainer->getX(), mContainer->getY());

					*this += dynamic_cast<Shape *>(rect);
				}
			}
		}
	}
	Rectangle::setTotalAreas(-sShape->area());
	Rectangle::setTotalPerimeters(-sShape->perimeter());
}

void ComposedShape::optimalRectCirc(Rectangle *mContainer, Circle *sShape)
{

	int row1 = mContainer->getHeight() / (2 * sShape->getRadius()); //rectangle pattern calculating the maximum row
	int col1 = mContainer->getWidth() / (2 * sShape->getRadius());  //rectangle pattern calculating the maximum column
	int rectPattern = row1 * col1;									// rectangle pattern max circle value
	int row2 = 0;
	int col2 = 0;

	row2 = (mContainer->getHeight() / (sShape->getRadius() + (sShape->getRadius() * sqrt(3)) - (sShape->getRadius() * (sqrt(3) / 1.7635)))) - 0.001; //triangle pattern calculating the maximum row
	col2 = ((mContainer->getWidth() - sShape->getRadius()) / (sShape->getRadius() * 2));															 //triangle pattern calculating the maximum column

	int trigeven = ceil((double)row2 / 2) * col1; //even rows
	int trigodd = row2 / 2 * col2;				  //odd rows
	int trigPattern = trigodd + trigeven;		  // triangle pattern max circle value

	*this += dynamic_cast<Shape *>(mContainer);
	//most circles drawn statement is selected.if trigPattern is maximum, following the else statement
	if (rectPattern >= trigPattern)
	{
		for (int i = 0; i < row1; i++) //row loop
		{
			for (int j = 0; j < col1; j++) //column loop
			{
				Circle *circ = new Circle((j * 2 * sShape->getRadius()) + sShape->getRadius() + mContainer->getPosX(),
										  (i * 2 * sShape->getRadius()) + sShape->getRadius() + mContainer->getPosY(),
										  sShape->getRadius(), sShape->getColor(), 0, 0, 0);

				*this += dynamic_cast<Shape *>(circ);
			}
		}
	}
	else
	{
		for (int i = 0; i < row2; i++) //row loop
		{
			if (i % 2 == 0)
			{
				int j;

				for (j = 0; j < col2; j++) //column loop
				{
					Circle *circ = new Circle((j * 2 * sShape->getRadius()) + sShape->getRadius() + mContainer->getPosX(),
											  ((sShape->getRadius() * sqrt(3)) * i) + sShape->getRadius() + mContainer->getPosY(),
											  sShape->getRadius(), sShape->getColor(), 0, 0, 0);

					*this += dynamic_cast<Shape *>(circ);
				}

				if (mContainer->getWidth() >= ((col2 * 2 * sShape->getRadius()) + (sShape->getRadius() * 2)))
				{
					Circle *circ = new Circle((j * 2 * sShape->getRadius()) + sShape->getRadius() + mContainer->getPosX(),
											  ((sShape->getRadius() * sqrt(3)) * i) + sShape->getRadius() + mContainer->getPosY(),
											  sShape->getRadius(), sShape->getColor(), 0, 0, 0);

					*this += dynamic_cast<Shape *>(circ);
				}
			}
			else
			{
				if ((mContainer->getHeight() >= ((sShape->getRadius() * sqrt(3)) * i) + (sShape->getRadius() * sqrt(3))) || row2 % 2 == 1)
				{
					for (int j = 0; j < col2; j++) //column loop
					{
						Circle *circ = new Circle((j * 2 * sShape->getRadius()) + sShape->getRadius() * 2 + mContainer->getPosX(),
												  (sShape->getRadius() * sqrt(3) * i) + sShape->getRadius() + mContainer->getPosY(),
												  sShape->getRadius(), sShape->getColor(), 0, 0, 0);

						*this += dynamic_cast<Shape *>(circ);
					}
				}
			}
		}
	}
	Circle::setTotalAreas(-sShape->area());
	Circle::setTotalPerimeters(-sShape->perimeter());
}

void ComposedShape::optimalRectTrig(Rectangle *mContainer, Triangle *sShape)
{

	int row = mContainer->getHeight() / ((sShape->getLength() / 2) * sqrt(3)); //calculating the maximum row
	int col = mContainer->getWidth() / sShape->getLength();					   //calculating the maximum column

	*this += dynamic_cast<Shape *>(mContainer);
	for (int i = 0; i < row; i++) //row loop
	{
		for (int j = 0; j < col; j++) //column loop
		{
			Triangle *trig = new Triangle(mContainer->getPosX(), mContainer->getPosY(),
										  (sShape->getLength() / 2) + sShape->getLength() * j,
										  (sShape->getLength() / 2) * sqrt(3) * i, sShape->getLength() * j,
										  (sShape->getLength() / 2) * sqrt(3) + (sShape->getLength() / 2) * sqrt(3) * i,
										  sShape->getLength() + (sShape->getLength() * j),
										  (sShape->getLength() / 2) * sqrt(3) + (sShape->getLength() / 2) * sqrt(3) * i,
										  sShape->getColor(), 0, 0, 0, sShape->getLength());

			*this += dynamic_cast<Shape *>(trig);
		}
	}

	col = (mContainer->getWidth() - (sShape->getLength() / 2)) / sShape->getLength(); //sliding pattern calculated

	for (int i = 0; i < row; i++) //row loop
	{
		for (int j = 0; j < col; j++) //column loop
		{
			Triangle *trig = new Triangle(mContainer->getPosX(), mContainer->getPosY(),
										  (sShape->getLength() / 2) + sShape->getLength() * j,
										  (sShape->getLength() / 2) * sqrt(3) * i,
										  sShape->getLength() + (sShape->getLength() * j),
										  (sShape->getLength() / 2) * sqrt(3) + (sShape->getLength() / 2) * sqrt(3) * i,
										  (sShape->getLength() / 2) + (sShape->getLength() * j) + sShape->getLength(),
										  (sShape->getLength() / 2) * sqrt(3) * i,
										  sShape->getColor(), 0, 0, 0, sShape->getLength());

			*this += dynamic_cast<Shape *>(trig);
		}
	}
	Triangle::setTotalAreas(-sShape->area());
	Triangle::setTotalPerimeters(-sShape->perimeter());
}

void ComposedShape::optimalCircRect(Circle *mContainer, Rectangle *sShape)
{

	double coordinate = mContainer->getRadius() / sqrt(2); //45-45-90 triangle left-top cordinate
	double temp;
	double x;
	int t;

	//calculating the maximum line on the edges of the circle
	int ekstrarow = (mContainer->getRadius() - coordinate) / sShape->getHeight();
	int ekstrarow1 = (mContainer->getRadius() - coordinate) / sShape->getWidth();
	int boxcount1 = 0;
	int boxcount2 = 0;

	*this += dynamic_cast<Shape *>(mContainer);

	//rectangles in the rectangle function draws rectangles in the middle of the circle.
	Rectangle middle(mContainer->getPosX() - mContainer->getRadius(), mContainer->getPosY() - mContainer->getRadius(), coordinate * 2, coordinate * 2,
					 mContainer->getColor(), 0, 0, 0, mContainer->getRadius() - coordinate,
					 mContainer->getRadius() - coordinate);

	optimalRectRect(&middle, sShape);

	//calculating the maximum line on the edges of the circle
	for (int p = 0; p < ekstrarow; p++)
	{
		x = sqrt(
			pow(mContainer->getRadius(), 2) - pow((coordinate + sShape->getHeight()) + (p * sShape->getHeight()), 2));
		t = x / sShape->getWidth();
		boxcount1 += t;
	}

	for (int p = 0; p < ekstrarow1; p++)
	{
		x = sqrt(
			pow(mContainer->getRadius(), 2) - pow((coordinate + sShape->getWidth()) + (p * sShape->getWidth()), 2));
		t = x / sShape->getHeight();
		boxcount2 += t;
	}
	//most rectangular drawn statement is selected.if boxcount2 is maximum, the data is swapped(width, height,row)
	if (boxcount2 > boxcount1)
	{
		temp = sShape->getWidth();
		sShape->setWidth(sShape->getHeight());
		sShape->setHeight(temp);
		ekstrarow = ekstrarow1;
	}

	for (int k = 0; k < 4; k++) //rotation loop
	{
		for (int p = 0; p < ekstrarow; p++) //row loop
		{
			x = sqrt(pow(mContainer->getRadius(), 2) - pow((coordinate + sShape->getHeight()) + (p * sShape->getHeight()), 2)); //the beam distance is calculated according to the sShape->getHeight().
			t = x / sShape->getWidth();																							//calculates how many boxes are drawn

			for (int j = 0; j < t; j++) //column loop
			{
				Rectangle *rect1 = new Rectangle(mContainer->getRadius() + (j * sShape->getWidth()) + mContainer->getPosX() - mContainer->getRadius(),
												 (p * sShape->getHeight()) + (coordinate + mContainer->getRadius()) + mContainer->getPosY() - mContainer->getRadius(),
												 sShape->getWidth(), sShape->getHeight(), sShape->getColor(), k * 90,
												 mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(), mContainer->getRadius() + mContainer->getPosY() - mContainer->getRadius(), 0, 0);

				*this += dynamic_cast<Shape *>(rect1);

				Rectangle *rect2 = new Rectangle((mContainer->getRadius() - sShape->getWidth()) - (j * sShape->getWidth()) + mContainer->getPosX() - mContainer->getRadius(),
												 (p * sShape->getHeight()) + (coordinate + mContainer->getRadius()) + mContainer->getPosY() - mContainer->getRadius(),
												 sShape->getWidth(), sShape->getHeight(),
												 sShape->getColor(), k * 90, mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(), mContainer->getRadius() + mContainer->getPosY() - mContainer->getRadius(), 0, 0);

				*this += dynamic_cast<Shape *>(rect2);
			}
		}
	}
	Rectangle::setTotalAreas(-sShape->area());
	Rectangle::setTotalPerimeters(-sShape->perimeter());
}

void ComposedShape::optimalCircCirc(Circle *mContainer, Circle *sShape)
{

	double angle;
	double diffangle;
	int val;
	double diff = fmod(mContainer->getRadius(), 2 * sShape->getRadius()); //mContainer->getRadius() % 2*sShape->getRadius(),  fmod, double type modulus function
	diff /= sShape->getRadius() * 2;

	*this += dynamic_cast<Shape *>(mContainer);
	for (int i = 0; i < mContainer->getRadius() / (2 * sShape->getRadius());
		 i++)
	{
		angle = asin(sShape->getRadius() / ((mContainer->getRadius() - sShape->getRadius()) - (2 * sShape->getRadius() * i)));
		val = M_PI / angle; //calculate how small circle fits diameter
		diffangle = fmod(M_PI, angle);
		diffangle /= val;
		angle += diffangle;
		angle = ((180 / M_PI) * (angle * 2)); //calculated angle

		for (int k = 0; k < val; k++)
		{
			Circle *circ = new Circle(mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(),
									  sShape->getRadius() + (2 * sShape->getRadius() * i) + mContainer->getPosY() - mContainer->getRadius(),
									  sShape->getRadius(), sShape->getColor(), k * angle,
									  mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(), mContainer->getRadius() + mContainer->getPosY() - mContainer->getRadius());

			*this += dynamic_cast<Shape *>(circ);
		}
	}

	if (diff >= 0.5 && diff < 1) //if there is enough space in the center, one more circle is added.
	{
		Circle *circ = new Circle(mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(), mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(),
								  sShape->getRadius(), sShape->getColor(), 0, 0, 0);

		*this += dynamic_cast<Shape *>(circ);
	}
	Circle::setTotalAreas(-sShape->area());
	Circle::setTotalPerimeters(-sShape->perimeter());
}

void ComposedShape::optimalCircTrig(Circle *mContainer, Triangle *sShape)
{

	int row = (mContainer->getRadius() / 2 * sqrt(3)) / ((sShape->getLength() / 2) * sqrt(3)); //calculating line on the edges of the circle
	int i, j, t;
	double x;
	int ekstrarow = (mContainer->getRadius() - (row * (sShape->getLength() / 2) * sqrt(3))) / ((sShape->getLength() / 2) * sqrt(3)); //calculating the maximum line on the radius

	*this += dynamic_cast<Shape *>(mContainer);
	for (int k = 0; k < 6; k++) //rotation loop
	{
		for (i = 0; i < row; i++) //row loop
		{
			for (j = 0; j <= i; j++) //column loop
			{
				Triangle *trig = new Triangle(mContainer->getPosX() - mContainer->getRadius(), mContainer->getPosY() - mContainer->getRadius(), (sShape->getLength() * j) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() / 2,
											  (sShape->getLength() / 2) * sqrt(3) * i + mContainer->getRadius(),
											  ((sShape->getLength() * j) - (sShape->getLength() / 2)) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() / 2,
											  (sShape->getLength() / 2) * sqrt(3) + ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
											  (sShape->getLength() / 2) + (sShape->getLength() * j) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() / 2,
											  ((sShape->getLength() / 2) * sqrt(3)) + ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
											  sShape->getColor(), k * 60, mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(), mContainer->getRadius() + mContainer->getPosY() - mContainer->getRadius(), sShape->getLength());

				*this += dynamic_cast<Shape *>(trig);

				if (i < row - 1)
				{
					Triangle *trig = new Triangle(mContainer->getPosX() - mContainer->getRadius(), mContainer->getPosY() - mContainer->getRadius(), (sShape->getLength() * j) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() / 2,
												  ((sShape->getLength() / 2) * sqrt(3) * i) + 2 * (sShape->getLength() / 2) * sqrt(3) + mContainer->getRadius(),
												  ((sShape->getLength() * j) - (sShape->getLength() / 2)) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() / 2,
												  (sShape->getLength() / 2) * sqrt(3) + ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
												  (sShape->getLength() / 2) + (sShape->getLength() * j) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() / 2,
												  ((sShape->getLength() / 2) * sqrt(3)) + ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
												  sShape->getColor(), k * 60, mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(), mContainer->getRadius() + mContainer->getPosY() - mContainer->getRadius(), sShape->getLength());

					*this += dynamic_cast<Shape *>(trig);
				}
			}
		}

		for (int p = 0; p < ekstrarow; p++) //row loop
		{
			x = sqrt(
				pow(mContainer->getRadius(), 2) - pow((row + 1 + p) * (sShape->getLength() / 2) * sqrt(3), 2));
			t = x / sShape->getLength(); //calculates how many boxes are drawn

			for (int l = (t - 2 + (p / 2)); l > ((p - t) - (p / 2) - 1); l--) //column loop odd
			{
				Triangle *trig = new Triangle(mContainer->getPosX() - mContainer->getRadius(), mContainer->getPosY() - mContainer->getRadius(), (sShape->getLength() * l) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() + (sShape->getLength() / 2),
											  ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
											  ((sShape->getLength() * l) - (sShape->getLength() / 2)) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() + sShape->getLength() / 2,
											  (sShape->getLength() / 2) * sqrt(3) + ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
											  (sShape->getLength() / 2) + (sShape->getLength() * l) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() + sShape->getLength() / 2,
											  (sShape->getLength() / 2) * sqrt(3) + ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
											  sShape->getColor(), k * 60, mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(), mContainer->getRadius() + mContainer->getPosY() - mContainer->getRadius(), sShape->getLength());

				*this += dynamic_cast<Shape *>(trig);
			}

			for (int m = (t - 1 + (p / 2)); m > ((p - t) - (p / 2) - 1); m--) //column loop even
			{
				Triangle *trig = new Triangle(mContainer->getPosX() - mContainer->getRadius(), mContainer->getPosY() - mContainer->getRadius(), (sShape->getLength() * m) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() + (sShape->getLength() / 2),
											  ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
											  ((sShape->getLength() * m) - (sShape->getLength() / 2)) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() + sShape->getLength() / 2,
											  (sShape->getLength() / 2) * sqrt(3) + ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
											  (sShape->getLength() * m) + ((mContainer->getRadius() / 2) - (i * (sShape->getLength() / 2))) + mContainer->getRadius() - sShape->getLength() + (sShape->getLength() / 2),
											  ((sShape->getLength() / 2) * sqrt(3) * i) + mContainer->getRadius(),
											  sShape->getColor(), k * 60, mContainer->getRadius() + mContainer->getPosX() - mContainer->getRadius(), mContainer->getRadius() + mContainer->getPosY() - mContainer->getRadius(), sShape->getLength());

				*this += dynamic_cast<Shape *>(trig);
			}
			i++;
		}
	}
	Triangle::setTotalAreas(-sShape->area());
	Triangle::setTotalPerimeters(-sShape->perimeter());
}

void ComposedShape::optimalTrigRect(Triangle *mContainer, Rectangle *sShape)
{

	//calculating the maximum row
	int row = ((mContainer->getLength() / 2) * sqrt(3)) / sShape->getHeight();
	int row1 = ((mContainer->getLength() / 2) * sqrt(3)) / sShape->getWidth();
	int t;
	double temp;
	int boxcount1 = 0, boxcount2 = 0;
	double diff;

	*this += dynamic_cast<Shape *>(mContainer);
	//calculating the maximum line on the edges of the rectangles
	for (int p = 0; p < row; p++)
	{
		t = ((((mContainer->getLength() / 2) * sqrt(3) - (sShape->getHeight() * (p + 1))) / sqrt(3) * 2) / sShape->getWidth());
		boxcount1 += t;
	}

	for (int p = 0; p < row1; p++)
	{
		t = ((((mContainer->getLength() / 2) * sqrt(3) - (sShape->getWidth() * (p + 1))) / sqrt(3) * 2) / sShape->getHeight());
		boxcount2 += t;
	}
	//most rectangular drawn statement is selected.if boxcount2 is maximum, the data is swapped(width, height,row)
	if (boxcount2 > boxcount1)
	{
		temp = sShape->getWidth();
		sShape->setWidth(sShape->getHeight());
		sShape->setHeight(temp);
		row = row1;
	}

	for (int i = 0; i < row; i++) //row loop
	{
		t = ((((mContainer->getLength() / 2) * sqrt(3) - (sShape->getHeight() * (i + 1))) / sqrt(3) * 2) / sShape->getWidth());
		diff = fmod((((mContainer->getLength() / 2) * sqrt(3) - (sShape->getHeight() * (i + 1))) / sqrt(3) * 2), sShape->getWidth()) / 2;

		for (int j = 0; j < t; j++) //column loop
		{
			Rectangle *rect = new Rectangle((sShape->getHeight() / sqrt(3)) + diff + (j * sShape->getWidth()) + (i * (sShape->getHeight() / sqrt(3))) + mContainer->getPosX(),
											((mContainer->getLength() / 2) * sqrt(3)) - (sShape->getHeight() * (i + 1)) + mContainer->getPosY(),
											sShape->getWidth(), sShape->getHeight(), sShape->getColor(), 0, 0, 0, 0, 0);

			*this += dynamic_cast<Shape *>(rect);
		}
	}
	Rectangle::setTotalAreas(-sShape->area());
	Rectangle::setTotalPerimeters(-sShape->perimeter());
}

void ComposedShape::optimalTrigCirc(Triangle *mContainer, Circle *sShape)
{

	int row = ceil(
		(((mContainer->getLength() - sShape->getRadius() * 4)) / (2 * sShape->getRadius())) - 0.7275); //calculating row

	*this += dynamic_cast<Shape *>(mContainer);
	for (int i = 0; i <= row; i++) //row loop
	{
		for (int j = 0; j <= i / 2; j++) //column loop
		{
			if (i % 2 == 1)
			{
				Circle *circ1 = new Circle((mContainer->getLength() / 2) - ((sShape->getRadius() * j * 2) + (sShape->getRadius())) + mContainer->getPosX(),
										   (2 * sShape->getRadius()) + (sShape->getRadius() * sqrt(3) * i) + mContainer->getPosY(),
										   sShape->getRadius(), sShape->getColor(), 0, 0, 0);

				*this += dynamic_cast<Shape *>(circ1);

				Circle *circ2 = new Circle((mContainer->getLength() / 2) + ((sShape->getRadius() * j * 2) + (sShape->getRadius())) + mContainer->getPosX(),
										   (2 * sShape->getRadius()) + (sShape->getRadius() * sqrt(3) * i) + mContainer->getPosY(),
										   sShape->getRadius(), sShape->getColor(), 0, 0, 0);

				*this += dynamic_cast<Shape *>(circ2);
			}
			else
			{
				Circle *circ = new Circle((mContainer->getLength() / 2) - (sShape->getRadius() * j * 2) + mContainer->getPosX(),
										  (2 * sShape->getRadius()) + (sShape->getRadius() * sqrt(3) * i) + mContainer->getPosY(),
										  sShape->getRadius(), sShape->getColor(), 0, 0, 0);

				*this += dynamic_cast<Shape *>(circ);
			}
		}

		for (int k = 1; k <= i / 2; k++) //column loop
		{
			if (i % 2 != 1)
			{
				Circle *circ = new Circle((mContainer->getLength() / 2) + (sShape->getRadius() * k * 2) + mContainer->getPosX(),
										  (2 * sShape->getRadius()) + (sShape->getRadius() * sqrt(3) * i) + mContainer->getPosY(),
										  sShape->getRadius(), sShape->getColor(), 0, 0, 0);

				*this += dynamic_cast<Shape *>(circ);
			}
		}
	}
	Circle::setTotalAreas(-sShape->area());
	Circle::setTotalPerimeters(-sShape->perimeter());
}

void ComposedShape::optimalTrigTrig(Triangle *mContainer, Triangle *sShape)
{
	//calculating the maximum row
	int row = (mContainer->getLength() / 2 * sqrt(3)) / ((sShape->getLength() / 2) * sqrt(3));

	*this += dynamic_cast<Shape *>(mContainer);
	for (int i = 0; i < row; i++) //row loop
	{
		for (int j = 0; j <= i; j++) //column loop
		{
			Triangle *trig = new Triangle(mContainer->getPosX(), mContainer->getPosY(), sShape->getLength() * j + ((mContainer->getLength() / 2) - (i * (sShape->getLength() / 2))),
										  (sShape->getLength() / 2) * sqrt(3) * i, ((sShape->getLength() * j) - (sShape->getLength() / 2)) + ((mContainer->getLength() / 2) - (i * (sShape->getLength() / 2))),
										  (sShape->getLength() / 2) * sqrt(3) + (sShape->getLength() / 2) * sqrt(3) * i,
										  sShape->getLength() / 2 + (sShape->getLength() * j) + ((mContainer->getLength() / 2) - (i * (sShape->getLength() / 2))),
										  (sShape->getLength() / 2) * sqrt(3) + (sShape->getLength() / 2) * sqrt(3) * i,
										  sShape->getColor(), 0, 0, 0, sShape->getLength());

			*this += dynamic_cast<Shape *>(trig);

			if (i < row - 1)
			{
				Triangle *trig = new Triangle(mContainer->getPosX(), mContainer->getPosY(), sShape->getLength() * j + ((mContainer->getLength() / 2) - (i * (sShape->getLength() / 2))),
											  ((sShape->getLength() / 2) * sqrt(3) * i) + 2 * (sShape->getLength() / 2) * sqrt(3),
											  ((sShape->getLength() * j) - (sShape->getLength() / 2)) + ((mContainer->getLength() / 2) - (i * (sShape->getLength() / 2))),
											  (sShape->getLength() / 2) * sqrt(3) + (sShape->getLength() / 2) * sqrt(3) * i,
											  sShape->getLength() / 2 + (sShape->getLength() * j) + ((mContainer->getLength() / 2) - (i * (sShape->getLength() / 2))),
											  (sShape->getLength() / 2) * sqrt(3) + (sShape->getLength() / 2) * sqrt(3) * i, sShape->getColor(), 0, 0, 0,
											  sShape->getLength());

				*this += dynamic_cast<Shape *>(trig);
			}
		}
	}
	Triangle::setTotalAreas(-sShape->area());
	Triangle::setTotalPerimeters(-sShape->perimeter());
}

//Related functions is called according to shape type
//The shape is loaded into the vector
//Empty area is calculated
void ComposedShape::optimalFit()
{
	if (_main.getType() == ShapeElem::shapeType::Rectangle && _shape.getType() == ShapeElem::shapeType::Rectangle)
	{
		optimalRectRect((Rectangle *)_main.getPtrShape(), (Rectangle *)_shape.getPtrShape());
	}
	else if (_main.getType() == ShapeElem::shapeType::Rectangle && _shape.getType() == ShapeElem::shapeType::Circle)
	{
		optimalRectCirc((Rectangle *)_main.getPtrShape(), (Circle *)_shape.getPtrShape());
	}
	else if (_main.getType() == ShapeElem::shapeType::Rectangle && _shape.getType() == ShapeElem::shapeType::Triangle)
	{
		optimalRectTrig((Rectangle *)_main.getPtrShape(), (Triangle *)_shape.getPtrShape());
	}
	else if (_main.getType() == ShapeElem::shapeType::Circle && _shape.getType() == ShapeElem::shapeType::Rectangle)
	{
		optimalCircRect((Circle *)_main.getPtrShape(), (Rectangle *)_shape.getPtrShape());
	}
	else if (_main.getType() == ShapeElem::shapeType::Circle && _shape.getType() == ShapeElem::shapeType::Circle)
	{
		optimalCircCirc((Circle *)_main.getPtrShape(), (Circle *)_shape.getPtrShape());
	}
	else if (_main.getType() == ShapeElem::shapeType::Circle && _shape.getType() == ShapeElem::shapeType::Triangle)
	{
		optimalCircTrig((Circle *)_main.getPtrShape(), (Triangle *)_shape.getPtrShape());
	}
	else if (_main.getType() == ShapeElem::shapeType::Triangle && _shape.getType() == ShapeElem::shapeType::Rectangle)
	{
		optimalTrigRect((Triangle *)_main.getPtrShape(), (Rectangle *)_shape.getPtrShape());
	}
	else if (_main.getType() == ShapeElem::shapeType::Triangle && _shape.getType() == ShapeElem::shapeType::Circle)
	{
		optimalTrigCirc((Triangle *)_main.getPtrShape(), (Circle *)_shape.getPtrShape());
	}
	else if (_main.getType() == ShapeElem::shapeType::Triangle && _shape.getType() == ShapeElem::shapeType::Triangle)
	{
		optimalTrigTrig((Triangle *)_main.getPtrShape(), (Triangle *)_shape.getPtrShape());
	}
	setObjectCount(getShapes().size() - 1); //substract main shape object count
	setEmptyArea(_main.getArea() - (getObjectCount() * _shape.getArea()));
}

//reference composedshape+shapeelem += operator overloading
ComposedShape &ComposedShape::operator+=(Shape *shp)
{
	_shp.push_back(shp);

	return *this;
}

//reference shapeelem [] operator overloading
Shape *ComposedShape::operator[](int index) throw(out_of_range) //dynamic exception specifications are deprecated in C++11  //lvalue
{
	decltype(_shp.size()) ndx = index;
	if (ndx < _shp.size())
	{
		return getShapes()[index];
	}
	else
	{
		throw out_of_range("Illegal index value. return 0 element");
	}
}

//reference shapeelem [] operator overloading
const Shape *ComposedShape::operator[](int index) const throw(out_of_range) //dynamic exception specifications are deprecated in C++11  //rvalue
{
	decltype(_shp.size()) ndx = index;
	if (ndx < _shp.size())
	{
		return _shp[index];
	}
	else
	{
		throw out_of_range("Illegal index value. return 0 element");
	}
}

//reference ostream << operator overloading
ostream &operator<<(ostream &outs, ComposedShape &obj)
{

	for (decltype(obj.getShapes().size()) i = 0; i < obj.getShapes().size();
		 ++i)
	{
		outs << obj[i]; //polymorphism late binding different shape type
	}

	return outs;
}

int ComposedShape::svgOpen(string fileName, ofstream &svg)
{
	if (!svg.is_open())
	{
		svg.open(fileName.c_str());

		svg
			<< "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">"
			<< endl;
		return 1;
	}
	return 0;
}

int ComposedShape::svgClose(ofstream &svg)
{
	if (svg.is_open())
	{
		svg << "</svg>" << endl;
		svg.close();
		return 1;
	}
	return 0;
}

double ComposedShape::getEmptyArea() const
{
	return _emptyArea;
}

inline void ComposedShape::setEmptyArea(double emptyArea)
{
	if (emptyArea < 0.0000001) //linux based g++ compiler writing  -1.20792e-11 instead of  0, bug fix
	{
		_emptyArea = 0;
	}
	else
	{
		_emptyArea = emptyArea;
	}
}

int ComposedShape::getObjectCount() const
{
	return _objectCount;
}

inline void ComposedShape::setObjectCount(int objectCount)
{
	_objectCount = objectCount;
}

string ComposedShape::getMainColor() const
{
	return _mainColor;
}

void ComposedShape::setMainColor(string mainColor)
{
	_mainColor = mainColor;
}

void ComposedShape::ShapeElem::setType(ComposedShape::ShapeElem::shapeType type)
{
	_type = type;
}

ComposedShape::ShapeElem::shapeType ComposedShape::ShapeElem::getType() const
{
	return _type;
}

// ptrShape object get set pointer
void ComposedShape::ShapeElem::setPtrShape(void *ptrShape)
{
	_ptrShape = ptrShape;
}

void *ComposedShape::ShapeElem::getPtrShape()
{
	return _ptrShape;
}

// shapeelem object get reference
ComposedShape::ShapeElem &ComposedShape::getMainShape()
{
	return _main;
}

ComposedShape::ShapeElem &ComposedShape::getSmallShape()
{
	return _shape;
}

ComposedShape::ShapeElem::ShapeElem()
{
}

ComposedShape::ShapeElem::ShapeElem(void *ptrShape, ComposedShape::ShapeElem::shapeType type)
{
	setType(type);
	setPtrShape(ptrShape);
}

double ComposedShape::ShapeElem::getArea() throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (_type == shapeType::Rectangle)
	{
		return ((Rectangle *)getPtrShape())->area();
	}
	else if (_type == shapeType::Circle)
	{
		return ((Circle *)getPtrShape())->area();
	}
	else if (_type == shapeType::Triangle)
	{
		return ((Triangle *)getPtrShape())->area();
	}
	else
	{
		throw invalid_argument("Unknown Shape Type");
	}
}

double ComposedShape::ShapeElem::getPerimeter() throw(invalid_argument) //dynamic exception specifications are deprecated in C++11
{
	if (_type == shapeType::Rectangle)
	{
		return ((Rectangle *)getPtrShape())->perimeter();
	}
	else if (_type == shapeType::Circle)
	{
		return ((Circle *)getPtrShape())->perimeter();
	}
	else if (_type == shapeType::Triangle)
	{
		return ((Triangle *)getPtrShape())->perimeter();
	}
	else
	{
		throw invalid_argument("Unknown Shape Type");
	}
}

// vector Polygon get set reference
vector<Shape *> ComposedShape::getShapes()
{
	return _shp;
}

void ComposedShape::setShapes(vector<Shape *> shp)
{
	_shp = shp;
}

ostream &printAll(ostream &outs, vector<Shape *> obj)
{
	for (auto v : obj)
	{
		outs << v;
	}

	return outs;
}

ostream &printPoly(ostream &outs, vector<Shape *> obj)
{
	for (auto v : obj)
	{
		if (typeid(*v).name() == typeid(PolygonDyn).name() || typeid(*v).name() == typeid(PolygonVect).name())
			outs << v;
	}

	return outs;
}

vector<Shape *> convertAll(vector<Shape *> obj)
{
	vector<Shape *> newshp;

	for (auto v : obj)
	{
		if (typeid(*v).name() == typeid(Rectangle).name())
		{
			newshp.push_back(new PolygonDyn(dynamic_cast<Rectangle &>(*v)));
		}
		else if (typeid(*v).name() == typeid(Circle).name())
		{
			newshp.push_back(new PolygonDyn(dynamic_cast<Circle &>(*v)));
		}
		else if (typeid(*v).name() == typeid(Triangle).name())
		{
			newshp.push_back(new PolygonDyn(dynamic_cast<Triangle &>(*v)));
		}
		else if (typeid(*v).name() == typeid(PolygonDyn).name() || typeid(*v).name() == typeid(PolygonVect).name())
		{
			newshp.push_back(v);
		}
	}
	return newshp;
}

void sortShapes(vector<Shape *> &obj) //bubble sorting algoritm
{
	Shape *tmp;

	for (decltype(obj.size()) i = 1; i < obj.size(); ++i)
		for (decltype(obj.size()) j = obj.size() - 1; j >= i; --j)
			if (obj[j - 1]->area() > obj[j]->area())
			{
				tmp = obj[j - 1];
				obj[j - 1] = obj[j];
				obj[j] = tmp;
			}
}

Shape &ComposedShape::operator++() //Prefix version
{
	for (auto s : (this)->_shp)
	{
		s->operator++(); //late binding
	}

	return *this;
}

Shape &ComposedShape::operator++(int) //Postfix version
{
	for (auto s : (this)->_shp)
	{
		s->operator++(1); //late binding
	}

	return *this;
}

Shape &ComposedShape::operator--() //Prefix version
{
	for (auto s : (this)->_shp)
	{
		s->operator--(); //late binding
	}

	return *this;
}

Shape &ComposedShape::operator--(int) //Postfix version
{
	for (auto s : (this)->_shp)
	{
		s->operator--(1); //late binding
	}

	return *this;
}

double ComposedShape::area()
{
	return getMainShape().getArea() + (getObjectCount() * getSmallShape().getArea());
}

double ComposedShape::perimeter()
{
	return getMainShape().getPerimeter() + (getObjectCount() * getSmallShape().getPerimeter());
}

ostream &ComposedShape::draw(ostream &outs)
{
	outs << *this;
	return outs;
}