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
	setContainerType('R');
	setShapeType('R');
	setMainRect(mContainer);
	setSmallRect(sShape);
	setMainColor(mContainer.getColor());
}
//constructer ex: ComposedShape(Rectangle&,Circle&) get reference object
ComposedShape::ComposedShape(Rectangle &mContainer, Circle &sShape)
{ //assign class member value
	setContainerType('R');
	setShapeType('C');
	setMainRect(mContainer);
	setSmallCirc(sShape);
	setMainColor(mContainer.getColor());
}
//constructer ex: ComposedShape(Rectangle&,Triangle&) get reference object
ComposedShape::ComposedShape(Rectangle &mContainer, Triangle &sShape)
{ //assign class member value
	setContainerType('R');
	setShapeType('T');
	setMainRect(mContainer);
	setSmallTrig(sShape);
	setMainColor(mContainer.getColor());
}
//constructer ex: ComposedShape(Circle&,Rectangle&) get reference object
ComposedShape::ComposedShape(Circle &mContainer, Rectangle &sShape)
{ //assign class member value
	setContainerType('C');
	setShapeType('R');
	setMainCirc(mContainer);
	setSmallRect(sShape);
	setMainColor(mContainer.getColor());
}
//constructer ex: ComposedShape(Circle&,Circle&) get reference object
ComposedShape::ComposedShape(Circle &mContainer, Circle &sShape)
{ //assign class member value
	setContainerType('C');
	setShapeType('C');
	setMainCirc(mContainer);
	setSmallCirc(sShape);
	setMainColor(mContainer.getColor());
}
//constructer ex: ComposedShape(Circle&,Triangle&) get reference object
ComposedShape::ComposedShape(Circle &mContainer, Triangle &sShape)
{ //assign class member value
	setContainerType('C');
	setShapeType('T');
	setMainCirc(mContainer);
	setSmallTrig(sShape);
	setMainColor(mContainer.getColor());
}
//constructer ex: ComposedShape(Triangle&,Rectangle&) get reference object
ComposedShape::ComposedShape(Triangle &mContainer, Rectangle &sShape)
{ //assign class member value
	setContainerType('T');
	setShapeType('R');
	setMainTrig(mContainer);
	setSmallRect(sShape);
	setMainColor(mContainer.getColor());
}
//constructer ex: ComposedShape(Triangle&,Circle&) get reference object
ComposedShape::ComposedShape(Triangle &mContainer, Circle &sShape)
{ //assign class member value
	setContainerType('T');
	setShapeType('C');
	setMainTrig(mContainer);
	setSmallCirc(sShape);
	setMainColor(mContainer.getColor());
}
//constructer ex: ComposedShape(Triangle&,Triangle&) get reference object
ComposedShape::ComposedShape(Triangle &mContainer, Triangle &sShape)
{ //assign class member value
	setContainerType('T');
	setShapeType('T');
	setMainTrig(mContainer);
	setSmallTrig(sShape);
	setMainColor(mContainer.getColor());
}

vector<Rectangle> ComposedShape::optimalRectRect(Rectangle &mContainer,
												 Rectangle &sShape)
{
	vector<Rectangle> finalRect;

	int row = mContainer.getHeight() / sShape.getHeight(); //calculating the maximum row
	int col = mContainer.getWidth() / sShape.getWidth();   //calculating the maximum column
	int row2 = mContainer.getHeight() / sShape.getWidth(); //calculating the maximum row
	int col2 = mContainer.getWidth() / sShape.getHeight(); //calculating the maximum column

	double temp;
	int i, j;
	//most circles drawn statement is selected.if row*col is maximum, following statement. if not, following the else statement
	if (row * col >= row2 * col2)
	{
		for (i = 0; i < row; i++) //row loop
		{
			for (j = 0; j < col; j++) //column loop
			{
				finalRect.push_back(
					Rectangle(j * sShape.getWidth() + sShape.getX(),
							  i * sShape.getHeight() + sShape.getY(),
							  sShape.getWidth(), sShape.getHeight(),
							  sShape.getColor(), 0, 0, 0, mContainer.getX(),
							  mContainer.getY()));
			}
		}

		double diffcol = mContainer.getWidth() - (col * sShape.getWidth());
		double diffrow = mContainer.getHeight() - (row * sShape.getHeight());

		if (diffcol >= sShape.getHeight()) //placing rotated rectangles in empty spaces
		{
			for (int t = 0;
				 t < (mContainer.getWidth() - (col * sShape.getWidth())) / sShape.getHeight() - 1; t++)
			{
				for (int k = 0;
					 k < mContainer.getHeight() / sShape.getWidth() - 1;
					 k++)
				{
					finalRect.push_back(
						Rectangle(
							(j * sShape.getWidth()) + sShape.getX() + (t * sShape.getHeight()),
							k * sShape.getWidth() + sShape.getY(),
							sShape.getHeight(), sShape.getWidth(),
							sShape.getColor(), 0, 0, 0,
							mContainer.getX(), mContainer.getY()));
				}
			}
		}
		else if (diffrow >= sShape.getWidth())
		{
			for (int t = 0;
				 t < (mContainer.getHeight() - (row * sShape.getHeight())) / sShape.getWidth() - 1; t++)
			{
				for (int k = 0;
					 k < mContainer.getWidth() / sShape.getHeight() - 1;
					 k++)
				{
					finalRect.push_back(
						Rectangle((k * sShape.getHeight()) + sShape.getX(),
								  (i * sShape.getHeight()) + sShape.getY() + (t * sShape.getWidth()),
								  sShape.getHeight(), sShape.getWidth(),
								  sShape.getColor(), 0, 0, 0,
								  mContainer.getX(), mContainer.getY()));
				}
			}
		}
	}
	else
	{
		//the data is swapped(width, height,row)
		temp = sShape.getWidth();
		sShape.setWidth(sShape.getHeight());
		sShape.setHeight(temp);
		int i, j;

		for (i = 0; i < row2; i++) //row loop
		{
			for (j = 0; j < col2; j++) //column loop
			{
				finalRect.push_back(
					Rectangle((j * sShape.getWidth()) + sShape.getX(),
							  (i * sShape.getHeight()) + sShape.getY(),
							  sShape.getWidth(), sShape.getHeight(),
							  sShape.getColor(), 0, 0, 0, mContainer.getX(),
							  mContainer.getY()));
			}
		}

		double diffcol = mContainer.getWidth() - (col2 * sShape.getWidth());
		double diffrow = mContainer.getHeight() - (row2 * sShape.getHeight());

		if (diffcol >= sShape.getHeight()) //placing rotated rectangles in empty spaces
		{
			for (int t = 0;
				 t < (mContainer.getWidth() - (col2 * sShape.getWidth())) / sShape.getHeight() - 1; t++)
			{
				for (int k = 0;
					 k < mContainer.getHeight() / sShape.getWidth() - 1;
					 k++)
				{
					finalRect.push_back(
						Rectangle(
							(j * sShape.getWidth()) + sShape.getX() + (t * sShape.getHeight()),
							(k * sShape.getWidth()) + sShape.getY(),
							sShape.getHeight(), sShape.getWidth(),
							sShape.getColor(), 0, 0, 0,
							mContainer.getX(), mContainer.getY()));
				}
			}
		}
		else if (diffrow >= sShape.getWidth())
		{
			for (int t = 0;
				 t < (mContainer.getHeight() - (row2 * sShape.getHeight())) / sShape.getWidth() - 1; t++)
			{
				for (int k = 0;
					 k < mContainer.getWidth() / sShape.getHeight() - 1;
					 k++)
				{
					finalRect.push_back(
						Rectangle((k * sShape.getHeight()) + sShape.getX(),
								  (i * sShape.getHeight()) + sShape.getY() + (t * sShape.getWidth()),
								  sShape.getHeight(), sShape.getWidth(),
								  sShape.getColor(), 0, 0, 0,
								  mContainer.getX(), mContainer.getY()));
				}
			}
		}
	}

	return finalRect;
}

vector<Circle> ComposedShape::optimalRectCirc(Rectangle &mContainer,
											  Circle &sShape)
{
	vector<Circle> finalCirc;

	int row1 = mContainer.getHeight() / (2 * sShape.getRadius()); //rectangle pattern calculating the maximum row
	int col1 = mContainer.getWidth() / (2 * sShape.getRadius());  //rectangle pattern calculating the maximum column
	int rectPattern = row1 * col1;								  // rectangle pattern max circle value
	int row2 = 0;
	int col2 = 0;

	row2 = (mContainer.getHeight() / (sShape.getRadius() + (sShape.getRadius() * sqrt(3)) - (sShape.getRadius() * (sqrt(3) / 1.7635)))) - 0.001; //triangle pattern calculating the maximum row
	col2 = ((mContainer.getWidth() - sShape.getRadius()) / (sShape.getRadius() * 2));															 //triangle pattern calculating the maximum column

	int trigeven = ceil((double)row2 / 2) * col1; //even rows
	int trigodd = row2 / 2 * col2;				  //odd rows
	int trigPattern = trigodd + trigeven;		  // triangle pattern max circle value
	//most circles drawn statement is selected.if trigPattern is maximum, following the else statement
	if (rectPattern >= trigPattern)
	{
		for (int i = 0; i < row1; i++) //row loop
		{
			for (int j = 0; j < col1; j++) //column loop
			{
				finalCirc.push_back(
					Circle(
						(j * 2 * sShape.getRadius()) + sShape.getRadius(),
						(i * 2 * sShape.getRadius()) + sShape.getRadius(),
						sShape.getRadius(), sShape.getColor(), 0, 0,
						0));
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
					finalCirc.push_back(
						Circle(
							(j * 2 * sShape.getRadius()) + sShape.getRadius(),
							((sShape.getRadius() * sqrt(3)) * i) + sShape.getRadius(),
							sShape.getRadius(), sShape.getColor(), 0, 0,
							0));
				}

				if (mContainer.getWidth() >= ((col2 * 2 * sShape.getRadius()) + (sShape.getRadius() * 2)))
				{
					finalCirc.push_back(
						Circle(
							(j * 2 * sShape.getRadius()) + sShape.getRadius(),
							((sShape.getRadius() * sqrt(3)) * i) + sShape.getRadius(),
							sShape.getRadius(), sShape.getColor(), 0, 0,
							0));
				}
			}
			else
			{
				if ((mContainer.getHeight() >= ((sShape.getRadius() * sqrt(3)) * i) + (sShape.getRadius() * sqrt(3))) || row2 % 2 == 1)
				{
					for (int j = 0; j < col2; j++) //column loop
					{
						finalCirc.push_back(
							Circle(
								(j * 2 * sShape.getRadius()) + sShape.getRadius() * 2,
								(sShape.getRadius() * sqrt(3) * i) + sShape.getRadius(),
								sShape.getRadius(), sShape.getColor(),
								0, 0, 0));
					}
				}
			}
		}
	}

	return finalCirc;
}

vector<Triangle> ComposedShape::optimalRectTrig(Rectangle &mContainer,
												Triangle &sShape)
{
	vector<Triangle> finalTrig;

	int row = mContainer.getHeight() / ((sShape.getLength() / 2) * sqrt(3)); //calculating the maximum row
	int col = mContainer.getWidth() / sShape.getLength();					 //calculating the maximum column

	for (int i = 0; i < row; i++) //row loop
	{
		for (int j = 0; j < col; j++) //column loop
		{
			finalTrig.push_back(
				Triangle(mContainer.getPosX(), mContainer.getPosY(),
						 (sShape.getLength() / 2) + sShape.getLength() * j,
						 (sShape.getLength() / 2) * sqrt(3) * i,
						 sShape.getLength() * j,
						 (sShape.getLength() / 2) * sqrt(3) + (sShape.getLength() / 2) * sqrt(3) * i,
						 sShape.getLength() + (sShape.getLength() * j),
						 (sShape.getLength() / 2) * sqrt(3) + (sShape.getLength() / 2) * sqrt(3) * i,
						 sShape.getColor(), 0, 0, 0, sShape.getLength()));
		}
	}

	col = (mContainer.getWidth() - (sShape.getLength() / 2)) / sShape.getLength(); //sliding pattern calculated

	for (int i = 0; i < row; i++) //row loop
	{
		for (int j = 0; j < col; j++) //column loop
		{
			finalTrig.push_back(
				Triangle(mContainer.getPosX(), mContainer.getPosY(),
						 (sShape.getLength() / 2) + sShape.getLength() * j,
						 (sShape.getLength() / 2) * sqrt(3) * i,
						 sShape.getLength() + (sShape.getLength() * j),
						 (sShape.getLength() / 2) * sqrt(3) + (sShape.getLength() / 2) * sqrt(3) * i,
						 (sShape.getLength() / 2) + (sShape.getLength() * j) + sShape.getLength(),
						 (sShape.getLength() / 2) * sqrt(3) * i,
						 sShape.getColor(), 0, 0, 0, sShape.getLength()));
		}
	}

	return finalTrig;
}

vector<Rectangle> ComposedShape::optimalCircRect(Circle &mContainer,
												 Rectangle &sShape)
{
	vector<Rectangle> finalRect;

	double coordinate = mContainer.getRadius() / sqrt(2); //45-45-90 triangle left-top cordinate
	double temp;
	double x;
	int t;

	//calculating the maximum line on the edges of the circle
	int ekstrarow = (mContainer.getRadius() - coordinate) / sShape.getHeight();
	int ekstrarow1 = (mContainer.getRadius() - coordinate) / sShape.getWidth();
	int boxcount1 = 0;
	int boxcount2 = 0;
	//rectangles in the rectangle function draws rectangles in the middle of the circle.
	Rectangle middle(0, 0, coordinate * 2, coordinate * 2,
					 mContainer.getColor(), 0, 0, 0, mContainer.getRadius() - coordinate,
					 mContainer.getRadius() - coordinate);

	finalRect = optimalRectRect(middle, sShape);

	//calculating the maximum line on the edges of the circle
	for (int p = 0; p < ekstrarow; p++)
	{
		x = sqrt(
			pow(mContainer.getRadius(), 2) - pow(
												 (coordinate + sShape.getHeight()) + (p * sShape.getHeight()), 2));
		t = x / sShape.getWidth();
		boxcount1 += t;
	}

	for (int p = 0; p < ekstrarow1; p++)
	{
		x = sqrt(
			pow(mContainer.getRadius(), 2) - pow(
												 (coordinate + sShape.getWidth()) + (p * sShape.getWidth()), 2));
		t = x / sShape.getHeight();
		boxcount2 += t;
	}
	//most rectangular drawn statement is selected.if boxcount2 is maximum, the data is swapped(width, height,row)
	if (boxcount2 > boxcount1)
	{
		temp = sShape.getWidth();
		sShape.setWidth(sShape.getHeight());
		sShape.setHeight(temp);
		ekstrarow = ekstrarow1;
	}

	for (int k = 0; k < 4; k++) //rotation loop
	{
		for (int p = 0; p < ekstrarow; p++) //row loop
		{
			x = sqrt(
				pow(mContainer.getRadius(), 2) - pow(
													 (coordinate + sShape.getHeight()) + (p * sShape.getHeight()), 2)); //the beam distance is calculated according to the sShape.getHeight().
			t = x / sShape.getWidth();																					//calculates how many boxes are drawn

			for (int j = 0; j < t; j++) //column loop
			{
				finalRect.push_back(
					Rectangle(
						mContainer.getRadius() + (j * sShape.getWidth()),
						(p * sShape.getHeight()) + (coordinate + mContainer.getRadius()),
						sShape.getWidth(), sShape.getHeight(),
						sShape.getColor(), k * 90,
						mContainer.getRadius(), mContainer.getRadius(),
						0, 0));
				finalRect.push_back(
					Rectangle(
						(mContainer.getRadius() - sShape.getWidth()) - (j * sShape.getWidth()),
						(p * sShape.getHeight()) + (coordinate + mContainer.getRadius()),
						sShape.getWidth(), sShape.getHeight(),
						sShape.getColor(), k * 90,
						mContainer.getRadius(), mContainer.getRadius(),
						0, 0));
			}
		}
	}

	return finalRect;
}

vector<Circle> ComposedShape::optimalCircCirc(Circle &mContainer,
											  Circle &sShape)
{
	vector<Circle> finalCirc;

	double angle;
	double diffangle;
	int val;
	double diff = fmod(mContainer.getRadius(), 2 * sShape.getRadius()); //mContainer.getRadius() % 2*sShape.getRadius(),  fmod, double type modulus function
	diff /= sShape.getRadius() * 2;

	for (int i = 0; i < mContainer.getRadius() / (2 * sShape.getRadius());
		 i++)
	{
		angle = asin(
			sShape.getRadius() / ((mContainer.getRadius() - sShape.getRadius()) - (2 * sShape.getRadius() * i)));
		val = M_PI / angle; //calculate how small circle fits diameter
		diffangle = fmod(M_PI, angle);
		diffangle /= val;
		angle += diffangle;
		angle = ((180 / M_PI) * (angle * 2)); //calculated angle

		for (int k = 0; k < val; k++)
		{
			finalCirc.push_back(
				Circle(mContainer.getRadius(),
					   sShape.getRadius() + (2 * sShape.getRadius() * i),
					   sShape.getRadius(), sShape.getColor(), k * angle,
					   mContainer.getRadius(), mContainer.getRadius()));
		}
	}

	if (diff >= 0.5 && diff < 1) //if there is enough space in the center, one more circle is added.
	{
		finalCirc.push_back(
			Circle(mContainer.getRadius(), mContainer.getRadius(),
				   sShape.getRadius(), sShape.getColor(), 0, 0, 0));
	}

	return finalCirc;
}

vector<Triangle> ComposedShape::optimalCircTrig(Circle &mContainer,
												Triangle &sShape)
{
	vector<Triangle> finalTrig;

	int row = (mContainer.getRadius() / 2 * sqrt(3)) / ((sShape.getLength() / 2) * sqrt(3)); //calculating line on the edges of the circle
	int i, j, t;
	double x;
	int ekstrarow = (mContainer.getRadius() - (row * (sShape.getLength() / 2) * sqrt(3))) / ((sShape.getLength() / 2) * sqrt(3)); //calculating the maximum line on the radius

	for (int k = 0; k < 6; k++) //rotation loop
	{
		for (i = 0; i < row; i++) //row loop
		{
			for (j = 0; j <= i; j++) //column loop
			{
				finalTrig.push_back(
					Triangle(0, 0,
							 (sShape.getLength() * j) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
							 (sShape.getLength() / 2) * sqrt(3) * i + mContainer.getRadius(),
							 ((sShape.getLength() * j) - (sShape.getLength() / 2)) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
							 (sShape.getLength() / 2) * sqrt(3) + ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
							 (sShape.getLength() / 2) + (sShape.getLength() * j) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
							 ((sShape.getLength() / 2) * sqrt(3)) + ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
							 sShape.getColor(), k * 60,
							 mContainer.getRadius(), mContainer.getRadius(),
							 sShape.getLength()));

				if (i < row - 1)
				{
					finalTrig.push_back(
						Triangle(0, 0,
								 (sShape.getLength() * j) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
								 ((sShape.getLength() / 2) * sqrt(3) * i) + 2 * (sShape.getLength() / 2) * sqrt(3) + mContainer.getRadius(),
								 ((sShape.getLength() * j) - (sShape.getLength() / 2)) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
								 (sShape.getLength() / 2) * sqrt(3) + ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
								 (sShape.getLength() / 2) + (sShape.getLength() * j) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
								 ((sShape.getLength() / 2) * sqrt(3)) + ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
								 sShape.getColor(), k * 60,
								 mContainer.getRadius(),
								 mContainer.getRadius(),
								 sShape.getLength()));
				}
			}
		}

		for (int p = 0; p < ekstrarow; p++) //row loop
		{
			x = sqrt(
				pow(mContainer.getRadius(), 2) - pow(
													 (row + 1 + p) * (sShape.getLength() / 2) * sqrt(3), 2));
			t = x / sShape.getLength(); //calculates how many boxes are drawn

			for (int l = (t - 2 + (p / 2)); l > ((p - t) - (p / 2) - 1); l--) //column loop odd
			{
				finalTrig.push_back(
					Triangle(0, 0,
							 (sShape.getLength() * l) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + (sShape.getLength() / 2),
							 ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
							 ((sShape.getLength() * l) - (sShape.getLength() / 2)) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + sShape.getLength() / 2,
							 (sShape.getLength() / 2) * sqrt(3) + ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
							 (sShape.getLength() / 2) + (sShape.getLength() * l) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + sShape.getLength() / 2,
							 (sShape.getLength() / 2) * sqrt(3) + ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
							 sShape.getColor(), k * 60,
							 mContainer.getRadius(), mContainer.getRadius(),
							 sShape.getLength()));
			}

			for (int m = (t - 1 + (p / 2)); m > ((p - t) - (p / 2) - 1); m--) //column loop even
			{
				finalTrig.push_back(
					Triangle(0, 0,
							 (sShape.getLength() * m) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + (sShape.getLength() / 2),
							 ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
							 ((sShape.getLength() * m) - (sShape.getLength() / 2)) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + sShape.getLength() / 2,
							 (sShape.getLength() / 2) * sqrt(3) + ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
							 (sShape.getLength() * m) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() - sShape.getLength() + (sShape.getLength() / 2),
							 ((sShape.getLength() / 2) * sqrt(3) * i) + mContainer.getRadius(),
							 sShape.getColor(), k * 60,
							 mContainer.getRadius(), mContainer.getRadius(),
							 sShape.getLength()));
			}
			i++;
		}
	}

	return finalTrig;
}

vector<Rectangle> ComposedShape::optimalTrigRect(Triangle &mContainer,
												 Rectangle &sShape)
{
	vector<Rectangle> finalRect;

	//calculating the maximum row
	int row = ((mContainer.getLength() / 2) * sqrt(3)) / sShape.getHeight();
	int row1 = ((mContainer.getLength() / 2) * sqrt(3)) / sShape.getWidth();
	int t;
	double temp;
	int boxcount1 = 0, boxcount2 = 0;
	double diff;
	//calculating the maximum line on the edges of the rectangles
	for (int p = 0; p < row; p++)
	{
		t = ((((mContainer.getLength() / 2) * sqrt(3) - (sShape.getHeight() * (p + 1))) / sqrt(3) * 2) / sShape.getWidth());
		boxcount1 += t;
	}

	for (int p = 0; p < row1; p++)
	{
		t = ((((mContainer.getLength() / 2) * sqrt(3) - (sShape.getWidth() * (p + 1))) / sqrt(3) * 2) / sShape.getHeight());
		boxcount2 += t;
	}
	//most rectangular drawn statement is selected.if boxcount2 is maximum, the data is swapped(width, height,row)
	if (boxcount2 > boxcount1)
	{
		temp = sShape.getWidth();
		sShape.setWidth(sShape.getHeight());
		sShape.setHeight(temp);
		row = row1;
	}

	for (int i = 0; i < row; i++) //row loop
	{
		t = ((((mContainer.getLength() / 2) * sqrt(3) - (sShape.getHeight() * (i + 1))) / sqrt(3) * 2) / sShape.getWidth());
		diff = fmod(
				   (((mContainer.getLength() / 2) * sqrt(3) - (sShape.getHeight() * (i + 1))) / sqrt(3) * 2),
				   sShape.getWidth()) /
			   2;

		for (int j = 0; j < t; j++) //column loop
		{
			finalRect.push_back(
				Rectangle(
					(sShape.getHeight() / sqrt(3)) + diff + (j * sShape.getWidth()) + (i * (sShape.getHeight() / sqrt(3))),
					((mContainer.getLength() / 2) * sqrt(3)) - (sShape.getHeight() * (i + 1)),
					sShape.getWidth(), sShape.getHeight(),
					sShape.getColor(), 0, 0, 0, 0, 0));
		}
	}

	return finalRect;
}

vector<Circle> ComposedShape::optimalTrigCirc(Triangle &mContainer,
											  Circle &sShape)
{
	vector<Circle> finalCirc;

	int row = ceil(
		(((mContainer.getLength() - sShape.getRadius() * 4)) / (2 * sShape.getRadius())) - 0.7275); //calculating row

	for (int i = 0; i <= row; i++) //row loop
	{
		for (int j = 0; j <= i / 2; j++) //column loop
		{
			if (i % 2 == 1)
			{
				finalCirc.push_back(
					Circle(
						(mContainer.getLength() / 2) - ((sShape.getRadius() * j * 2) + (sShape.getRadius())),
						(2 * sShape.getRadius()) + (sShape.getRadius() * sqrt(3) * i),
						sShape.getRadius(), sShape.getColor(), 0, 0,
						0));
				finalCirc.push_back(
					Circle(
						(mContainer.getLength() / 2) + ((sShape.getRadius() * j * 2) + (sShape.getRadius())),
						(2 * sShape.getRadius()) + (sShape.getRadius() * sqrt(3) * i),
						sShape.getRadius(), sShape.getColor(), 0, 0,
						0));
			}
			else
			{
				finalCirc.push_back(
					Circle(
						(mContainer.getLength() / 2) - (sShape.getRadius() * j * 2),
						(2 * sShape.getRadius()) + (sShape.getRadius() * sqrt(3) * i),
						sShape.getRadius(), sShape.getColor(), 0, 0,
						0));
			}
		}

		for (int k = 1; k <= i / 2; k++) //column loop
		{
			if (i % 2 != 1)
			{
				finalCirc.push_back(
					Circle(
						(mContainer.getLength() / 2) + (sShape.getRadius() * k * 2),
						(2 * sShape.getRadius()) + (sShape.getRadius() * sqrt(3) * i),
						sShape.getRadius(), sShape.getColor(), 0, 0,
						0));
			}
		}
	}

	return finalCirc;
}
//Related functions is called according to shape type
//The shape is loaded into the vector
//Empty area is calculated
void ComposedShape::optimalFit()
{
	if (getContainerType() == 'R' && getShapeType() == 'R')
	{
		setShapesRect(optimalRectRect(getMainRect(), getSmallRect()));
		setEmptyArea(
			getMainRect().area() - (getShapesRect().size() * getSmallRect().area()));
	}
	else if (getContainerType() == 'R' && getShapeType() == 'C')
	{
		setShapesCirc(optimalRectCirc(getMainRect(), getSmallCirc()));
		setEmptyArea(
			getMainRect().area() - (getShapesCirc().size() * getSmallCirc().area()));
	}
	else if (getContainerType() == 'R' && getShapeType() == 'T')
	{
		setShapesTrig(optimalRectTrig(getMainRect(), getSmallTrig()));
		setEmptyArea(
			getMainRect().area() - (getShapesTrig().size() * getSmallTrig().area()));
	}
	else if (getContainerType() == 'C' && getShapeType() == 'R')
	{
		setShapesRect(optimalCircRect(getMainCirc(), getSmallRect()));
		setEmptyArea(
			getMainCirc().area() - (getShapesRect().size() * getSmallRect().area()));
	}
	else if (getContainerType() == 'C' && getShapeType() == 'C')
	{
		setShapesCirc(optimalCircCirc(getMainCirc(), getSmallCirc()));
		setEmptyArea(
			getMainCirc().area() - (getShapesCirc().size() * getSmallCirc().area()));
	}
	else if (getContainerType() == 'C' && getShapeType() == 'T')
	{
		setShapesTrig(optimalCircTrig(getMainCirc(), getSmallTrig()));
		setEmptyArea(
			getMainCirc().area() - (getShapesTrig().size() * getSmallTrig().area()));
	}
	else if (getContainerType() == 'T' && getShapeType() == 'R')
	{
		setShapesRect(optimalTrigRect(getMainTrig(), getSmallRect()));
		setEmptyArea(
			getMainTrig().area() - (getShapesRect().size() * getSmallRect().area()));
	}
	else if (getContainerType() == 'T' && getShapeType() == 'C')
	{
		setShapesCirc(optimalTrigCirc(getMainTrig(), getSmallCirc()));
		setEmptyArea(
			getMainTrig().area() - (getShapesCirc().size() * getSmallCirc().area()));
	}
	else if (getContainerType() == 'T' && getShapeType() == 'T')
	{
		setShapesTrig(optimalTrigTrig(getMainTrig(), getSmallTrig()));
		setEmptyArea(
			getMainTrig().area() - (getShapesTrig().size() * getSmallTrig().area()));
	}
}

vector<Triangle> ComposedShape::optimalTrigTrig(Triangle &mContainer,
												Triangle &sShape)
{
	vector<Triangle> finalTrig;

	//calculating the maximum row
	int row = (mContainer.getLength() / 2 * sqrt(3)) / ((sShape.getLength() / 2) * sqrt(3));

	for (int i = 0; i < row; i++) //row loop
	{
		for (int j = 0; j <= i; j++) //column loop
		{
			finalTrig.push_back(
				Triangle(0, 0,
						 sShape.getLength() * j + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
						 (sShape.getLength() / 2) * sqrt(3) * i,
						 ((sShape.getLength() * j) - (sShape.getLength() / 2)) + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
						 (sShape.getLength() / 2) * sqrt(3) + (sShape.getLength() / 2) * sqrt(3) * i,
						 sShape.getLength() / 2 + (sShape.getLength() * j) + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
						 (sShape.getLength() / 2) * sqrt(3) + (sShape.getLength() / 2) * sqrt(3) * i,
						 sShape.getColor(), 0, 0, 0, sShape.getLength()));

			if (i < row - 1)
			{
				finalTrig.push_back(
					Triangle(0, 0,
							 sShape.getLength() * j + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
							 ((sShape.getLength() / 2) * sqrt(3) * i) + 2 * (sShape.getLength() / 2) * sqrt(3),
							 ((sShape.getLength() * j) - (sShape.getLength() / 2)) + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
							 (sShape.getLength() / 2) * sqrt(3) + (sShape.getLength() / 2) * sqrt(3) * i,
							 sShape.getLength() / 2 + (sShape.getLength() * j) + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
							 (sShape.getLength() / 2) * sqrt(3) + (sShape.getLength() / 2) * sqrt(3) * i, sShape.getColor(), 0, 0, 0,
							 sShape.getLength()));
			}
		}
	}

	return finalTrig;
}
//get reference ofstream parameter
void ComposedShape::draw(ofstream &svg)
{

	if (getContainerType() == 'R')
	{
		getMainRect().draw(svg);
	}
	else if (getContainerType() == 'C')
	{
		getMainCirc().draw(svg);
	}
	else if (getContainerType() == 'T')
	{
		getMainTrig().draw(svg);
	}

	if (getShapeType() == 'R')
	{
		for (decltype(getShapesRect().size()) i = 0; i < getShapesRect().size();
			 ++i)
		{
			getShapesRect()[i].draw(svg);
		}
		setObjectCount(getShapesRect().size());
	}
	else if (getShapeType() == 'C')
	{
		for (decltype(getShapesCirc().size()) i = 0; i < getShapesCirc().size();
			 ++i)
		{

			getShapesCirc()[i].draw(svg);
		}
		setObjectCount(getShapesCirc().size());
	}
	else if (getShapeType() == 'T')
	{
		for (decltype(getShapesTrig().size()) i = 0; i < getShapesTrig().size();
			 ++i)
		{

			getShapesTrig()[i].draw(svg);
		}
		setObjectCount(getShapesTrig().size());
	}
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

vector<Rectangle> &ComposedShape::getShapesRect()
{
	return _shapesRect;
}

void ComposedShape::setShapesRect(vector<Rectangle> shapesRect)
{
	_shapesRect = shapesRect;
}

vector<Circle> &ComposedShape::getShapesCirc()
{
	return _shapesCirc;
}

void ComposedShape::setShapesCirc(vector<Circle> shapesCirc)
{
	_shapesCirc = shapesCirc;
}
vector<Triangle> &ComposedShape::getShapesTrig()
{
	return _shapesTrig;
}

void ComposedShape::setShapesTrig(vector<Triangle> shapesTrig)
{
	_shapesTrig = shapesTrig;
}

char ComposedShape::getContainerType() const
{
	return _mContainerType;
}

void ComposedShape::setContainerType(char containerType)
{
	_mContainerType = containerType;
}

char ComposedShape::getShapeType() const
{
	return _sShapeType;
}

void ComposedShape::setShapeType(char shapeType)
{
	_sShapeType = shapeType;
}

Circle &ComposedShape::getMainCirc()
{
	return _mainCirc;
}

void ComposedShape::setMainCirc(Circle mainCirc)
{
	_mainCirc = mainCirc;
}

Rectangle &ComposedShape::getMainRect()
{
	return _mainRect;
}

void ComposedShape::setMainRect(Rectangle mainRect)
{
	_mainRect = mainRect;
}

Triangle &ComposedShape::getMainTrig()
{
	return _mainTrig;
}

void ComposedShape::setMainTrig(Triangle mainTrig)
{
	_mainTrig = mainTrig;
}

Circle &ComposedShape::getSmallCirc()
{
	return _smallCirc;
}

void ComposedShape::setSmallCirc(Circle smallCirc)
{
	_smallCirc = smallCirc;
}

Rectangle &ComposedShape::getSmallRect()
{
	return _smallRect;
}

void ComposedShape::setSmallRect(Rectangle smallRect)
{
	_smallRect = smallRect;
}

Triangle &ComposedShape::getSmallTrig()
{
	return _smallTrig;
}

void ComposedShape::setSmallTrig(Triangle smallTrig)
{
	_smallTrig = smallTrig;
}

string ComposedShape::getMainColor() const
{
	return _mainColor;
}

void ComposedShape::setMainColor(string mainColor)
{
	_mainColor = mainColor;
}
