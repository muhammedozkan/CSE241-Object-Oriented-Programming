#include <iostream>
#include <string>
#include <fstream>
#include <cmath>


//if pi number is not defined in cmath library, pi is defined
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

using namespace std;
//enum class declaration
enum class Shape { Rect, Circ, Trig };

//functions prototype 
//call by reference to return multiple values
void getTypeValue(Shape&, double&, double&, double&, double&);//function that takes properties (width, height, length, etc.) according to the type of shapes
Shape getShapeType(); //function that retrieves the type of the shapes
double getValue();
void writeresult(int, double);
double drawMainContainer(Shape, string&, double, double, double, double);

int drawSmallRectInRect(string&, double, double, double, double, double, double);//it is drawing function of rectangles in a rectangle
int drawSmallCircInRect(string&, double, double, double);//it is drawing function of circles in a rectangle
int drawSmallTrigInRect(string&, double, double, double);//it is drawing function of triangles in a rectangle

int drawSmallCircInCirc(string&, double, double);//it is drawing function of circles in a circle
int drawSmallRectInCirc(string&, double, double, double);//it is drawing function of rectangles in a circle
int drawSmallTrigInCirc(string&, double, double);//it is drawing function of triangles in a circle

int drawSmallTrigInTrig(string&, double, double);//it is drawing function of triangles in a triangle
int drawSmallCircInTrig(string&, double, double);//it is drawing function of circles in a triangle
int drawSmallRectInTrig(string&, double, double, double);//it is drawing function of rectangles in a triangle

int main()
{
	double mWidth, mHeight, mRadius, mLength, mArea;
	double sWidth, sHeight, sRadius, sLength;
	int smallObjectCount;
	string svgFile;
	Shape mainContainer, smallShape;
	ofstream outStream;

	cout << "Please enter the main container shape (R, C, T)" << endl;
	//main container information is requested from the user
	mainContainer = getShapeType();
	getTypeValue(mainContainer, mWidth, mHeight, mRadius, mLength);

	svgFile = "<svg version=\"1.1\" baseProfile=\"full\" xmlns=\"http://www.w3.org/2000/svg\">\n";
	//main container is drawn
	mArea = drawMainContainer(mainContainer, svgFile, mWidth, mHeight, mRadius, mLength);

	cout << "Please enter the small shape (R, C, T)" << endl;
	//small shape information is requested from the user
	smallShape = getShapeType();
	getTypeValue(smallShape, sWidth, sHeight, sRadius, sLength);


	//small shape is sent to the corresponding function according to the main container information
	//small shape is draw
	//area are calculating by the value returned from function
	if (mainContainer == Shape::Rect && smallShape == Shape::Rect)
	{
		smallObjectCount = drawSmallRectInRect(svgFile, mWidth, mHeight, sWidth, sHeight, 0, 0);
		writeresult(smallObjectCount, mArea - (sWidth * sHeight* smallObjectCount));
	}
	else if (mainContainer == Shape::Rect && smallShape == Shape::Circ)
	{
		smallObjectCount = drawSmallCircInRect(svgFile, mWidth, mHeight, sRadius);
		writeresult(smallObjectCount, mArea - (M_PI * sRadius * sRadius * smallObjectCount));
	}
	else if (mainContainer == Shape::Rect && smallShape == Shape::Trig)
	{
		smallObjectCount = drawSmallTrigInRect(svgFile, mWidth, mHeight, sLength);
		writeresult(smallObjectCount, mArea - (((sLength*sLength*sqrt(3)) / 4)* smallObjectCount));
	}
	else if (mainContainer == Shape::Circ && smallShape == Shape::Circ)
	{
		smallObjectCount = drawSmallCircInCirc(svgFile, mRadius, sRadius);
		writeresult(smallObjectCount, mArea - (M_PI * sRadius * sRadius * smallObjectCount));
	}
	else if (mainContainer == Shape::Circ && smallShape == Shape::Rect)
	{
		smallObjectCount = drawSmallRectInCirc(svgFile, mRadius, sWidth, sHeight);
		writeresult(smallObjectCount, mArea - (sWidth * sHeight* smallObjectCount));
	}
	else if (mainContainer == Shape::Circ && smallShape == Shape::Trig)
	{
		smallObjectCount = drawSmallTrigInCirc(svgFile, mRadius, sLength);
		writeresult(smallObjectCount, mArea - (((sLength*sLength*sqrt(3)) / 4)* smallObjectCount));
	}
	else if (mainContainer == Shape::Trig && smallShape == Shape::Trig)
	{
		smallObjectCount = drawSmallTrigInTrig(svgFile, mLength, sLength);
		writeresult(smallObjectCount, mArea - (((sLength*sLength*sqrt(3)) / 4)* smallObjectCount));
	}
	else if (mainContainer == Shape::Trig && smallShape == Shape::Rect)
	{
		smallObjectCount = drawSmallRectInTrig(svgFile, mLength, sWidth, sHeight);
		writeresult(smallObjectCount, mArea - (sWidth * sHeight* smallObjectCount));
	}
	else if (mainContainer == Shape::Trig && smallShape == Shape::Circ)
	{
		smallObjectCount = drawSmallCircInTrig(svgFile, mLength, sRadius);
		writeresult(smallObjectCount, mArea - (M_PI * sRadius * sRadius * smallObjectCount));
	}

	svgFile += "</svg>";
	// svg file saving
	outStream.open("output.svg");
	outStream << svgFile;
	outStream.close();

	return 0;
}

void writeresult(int objectCount, double emptyArea)//function showing the result of the program to the user
{
	if (emptyArea < 0)//linux based g++ compiler writing  -1.20792e-11 instead of  0, bug fix
	{
		emptyArea = 0;
	}
	cout << "I can fit at most " << objectCount << " small shapes into the main container. The empty area (red) in container is " << emptyArea << endl;
}

Shape getShapeType()//function of taking shape type from user according to entered character
{
	string input;
	bool flag;

	do {
		cin >> input;

		if (input == "R" || input == "C" || input == "T" || input == "r" || input == "c" || input == "t")
		{
			flag = false;
		}
		else
		{
			flag = true;
			cout << "Not a R,C,T. Please enter the again" << endl;
		}
	} while (flag);

	if (input == "R" || input == "r")
	{
		return Shape::Rect;
	}
	else if (input == "C" || input == "c")
	{
		return Shape::Circ;
	}
	else if (input == "T" || input == "t")
	{
		return Shape::Trig;
	}
}

double getValue()//function that getting values
{
	double input;
	bool flag;

	do {
		cin >> input;

		flag = cin.fail();
		cin.clear();
		cin.ignore(INT8_MAX, '\n');

		if (flag)
		{
			cout << "Not a integer or decimal number. Please enter the again" << endl;
		}
		else if (input <= 0)
		{
			flag = true;
			cout << "Value cannot be zero or smaller than zero. Please enter the again" << endl;
		}
	} while (flag);

	return input;
}

void getTypeValue(Shape &shape, double &width, double &height, double &radius, double &length)//function that takes properties (width, height, length, etc.) according to the type of shapes
{
	if (shape == Shape::Rect)
	{
		cout << "Please enter the width" << endl;
		width = getValue();
		cout << "Please enter the height" << endl;
		height = getValue();
	}
	else if (shape == Shape::Circ)
	{
		cout << "Please enter the radius" << endl;
		radius = getValue();
	}
	else if (shape == Shape::Trig)
	{
		cout << "Please enter edge length" << endl;
		length = getValue();
	}
}

double drawMainContainer(Shape shape, string &svg, double width, double height, double radius, double length)//function that drawing main container
{
	if (shape == Shape::Rect)
	{
		svg += "<rect x=\"0\"  y=\"0\" width=\"" + to_string(width) + "\" height=\"" + to_string(height) + "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.5\" />\n";
		return (width * height);
	}
	else if (shape == Shape::Circ)
	{
		svg += "<circle cx=\"" + to_string(radius) + "\" cy=\"" + to_string(radius) + "\" r=\"" + to_string(radius) + "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.5\" />\n";
		return (M_PI * radius * radius);
	}
	else if (shape == Shape::Trig)
	{
		svg += "<polygon points=\"" + to_string(length / 2) + "," + to_string(0) + " " + to_string(0) + "," + to_string((length / 2) * sqrt(3)) + " " + to_string(length) + "," + to_string((length / 2) * sqrt(3)) + "\" fill=\"red\" stroke=\"black\" stroke-width=\"0.5\" />\n";
		return ((length * length * sqrt(3)) / 4);
	}
}


int drawSmallCircInTrig(string &svg, double length, double radius)//it is drawing function of circles in a triangle.
{
	int counter = 0;
	int row = ceil((((length - radius * 4)) / (2 * radius)) - 0.7275);//calculating row

	for (int i = 0; i <= row; i++)//row loop
	{
		for (int j = 0; j <= i / 2; j++)//column loop
		{
			if (i % 2 == 1)
			{
				svg += "<circle cx=\"" + to_string((length / 2) - ((radius * j * 2) + (radius))) + "\" cy=\"" + to_string((2 * radius) + (radius*sqrt(3)*i)) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				svg += "<circle cx=\"" + to_string((length / 2) + ((radius * j * 2) + (radius))) + "\" cy=\"" + to_string((2 * radius) + (radius*sqrt(3)*i)) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter += 2;
			}
			else
			{
				svg += "<circle cx=\"" + to_string((length / 2) - (radius * j * 2)) + "\" cy=\"" + to_string((2 * radius) + (radius*sqrt(3)*i)) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;;
			}
		}

		for (int k = 1; k <= i / 2; k++)//column loop
		{
			if (i % 2 != 1)
			{
				svg += "<circle cx=\"" + to_string((length / 2) + (radius * k * 2)) + "\" cy=\"" + to_string((2 * radius) + (radius*sqrt(3)*i)) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;;
			}
		}
	}

	return counter;
}

int drawSmallRectInRect(string &svg, double mWidth, double mHeight, double Width, double Height, double x, double y)//it is drawing function of rectangles in a rectangle
{
	int row = mHeight / Height;//calculating the maximum row
	int col = mWidth / Width;//calculating the maximum column
	int row2 = mHeight / Width;//calculating the maximum row
	int col2 = mWidth / Height;//calculating the maximum column

	int counter = 0;
	double temp;
	int i, j;
	//most circles drawn statement is selected.if row*col is maximum, following statement. if not, following the else statement
	if (row * col >= row2 * col2)
	{
		for (i = 0; i < row; i++)//row loop
		{
			for (j = 0; j < col; j++)//column loop
			{
				svg += "<rect x=\"" + to_string(j * Width + x) + "\"  y=\"" + to_string(i * Height + y) + "\" width=\"" + to_string(Width) + "\" height=\"" + to_string(Height) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;
			}
		}

		double diffcol = mWidth - (col * Width);
		double diffrow = mHeight - (row * Height);

		if (diffcol >= Height)//placing rotated rectangles in empty spaces
		{
			for (int t = 0; t < (mWidth - (col * Width)) / Height - 1; t++)
			{
				for (int k = 0; k < mHeight / Width - 1; k++)
				{
					svg += "<rect x=\"" + to_string((j * Width) + x + (t * Height)) + "\"  y=\"" + to_string(k * Width + y) + "\" width=\"" + to_string(Height) + "\" height=\"" + to_string(Width) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
					counter++;
				}
			}
		}
		else if (diffrow >= Width)
		{
			for (int t = 0; t < (mHeight - (row * Height)) / Width - 1; t++)
			{
				for (int k = 0; k < mWidth / Height - 1; k++)
				{
					svg += "<rect x=\"" + to_string(k * Height + x) + "\"  y=\"" + to_string((i * Height) + y + (t * Width)) + "\" width=\"" + to_string(Height) + "\" height=\"" + to_string(Width) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
					counter++;
				}
			}
		}
	}
	else
	{
		//the data is swaped(width, height,row)
		temp = Width;
		Width = Height;
		Height = temp;
		int i, j;

		for (i = 0; i < row2; i++)//row loop
		{
			for (j = 0; j < col2; j++)//column loop
			{
				svg += "<rect x=\"" + to_string(j * Width + x) + "\"  y=\"" + to_string(i * Height + y) + "\" width=\"" + to_string(Width) + "\" height=\"" + to_string(Height) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;
			}
		}

		double diffcol = mWidth - (col2 * Width);
		double diffrow = mHeight - (row2 * Height);

		if (diffcol >= Height)//placing rotated rectangles in empty spaces
		{
			for (int t = 0; t < (mWidth - (col2 * Width)) / Height - 1; t++)
			{
				for (int k = 0; k < mHeight / Width - 1; k++)
				{
					svg += "<rect x=\"" + to_string((j * Width) + x + (t * Height)) + "\"  y=\"" + to_string(k * Width + y) + "\" width=\"" + to_string(Height) + "\" height=\"" + to_string(Width) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
					counter++;
				}
			}
		}
		else if (diffrow >= Width)
		{
			for (int t = 0; t < (mHeight - (row2 * Height)) / Width - 1; t++)
			{
				for (int k = 0; k < mWidth / Height - 1; k++)
				{
					svg += "<rect x=\"" + to_string(k * Height + x) + "\"  y=\"" + to_string((i * Height) + y + (t * Width)) + "\" width=\"" + to_string(Height) + "\" height=\"" + to_string(Width) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
					counter++;
				}
			}
		}
	}

	return counter;
}

int drawSmallCircInRect(string &svg, double mWidth, double mHeight, double radius)//it is drawing function of circles in a rectangle
{
	int row1 = mHeight / (2 * radius);//rectangle pattern calculating the maximum row
	int col1 = mWidth / (2 * radius);//rectangle pattern calculating the maximum column
	int rectPattern = row1 * col1;// rectangle pattern max circle value
	int row2 = 0;
	int col2 = 0;

	row2 = (mHeight / (radius + (radius * sqrt(3)) - (radius * (sqrt(3) / 1.7635)))) - 0.001;//triangle pattern calculating the maximum row
	col2 = ((mWidth - radius) / (radius * 2));//triangle pattern calculating the maximum column

	int trigeven = ceil((double)row2 / 2) * col1;//even rows
	int trigodd = row2 / 2 * col2;//odd rows
	int trigPattern = trigodd + trigeven; // triangle pattern max circle value
	int counter = 0;
	//most circles drawn statement is selected.if trigPattern is maximum, following the else statement
	if (rectPattern >= trigPattern)
	{
		for (int i = 0; i < row1; i++)//row loop
		{
			for (int j = 0; j < col1; j++)//column loop
			{
				svg += "<circle cx=\"" + to_string((j * 2 * radius) + radius) + "\" cy=\"" + to_string((i * 2 * radius) + radius) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;
			}
		}
	}
	else
	{
		for (int i = 0; i < row2; i++)//row loop
		{
			if (i % 2 == 0)
			{
				int j;

				for (j = 0; j < col2; j++)//column loop
				{
					svg += "<circle cx=\"" + to_string((j * 2 * radius) + radius) + "\" cy=\"" + to_string(((radius*sqrt(3))*i) + radius) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
					counter++;
				}

				if (mWidth >= ((col2 * 2 * radius) + (radius * 2)))
				{
					svg += "<circle cx=\"" + to_string(((j) * 2 * radius) + radius) + "\" cy=\"" + to_string(((radius*sqrt(3))*i) + radius) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
					counter++;
				}
			}
			else
			{
				if ((mHeight >= ((radius*sqrt(3))*i) + (radius*sqrt(3))) || row2 % 2 == 1)
				{
					for (int j = 0; j < col2; j++)//column loop
					{
						svg += "<circle cx=\"" + to_string((j * 2 * radius) + radius * 2) + "\" cy=\"" + to_string(((radius*sqrt(3))*i) + radius) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
						counter++;
					}
				}
			}
		}
	}

	return counter;
}

int drawSmallTrigInRect(string &svg, double mWidth, double mHeight, double length)//it is drawing function of triangles in a rectangle
{
	int counter = 0;
	int row = mHeight / ((length / 2) * sqrt(3));//calculating the maximum row
	int col = mWidth / length;//calculating the maximum cloumn

	for (int i = 0; i < row; i++)//row loop
	{
		for (int j = 0; j < col; j++)//column loop
		{
			svg += "<polygon points=\"" + to_string((length / 2) + length * j) + "," + to_string((length / 2) * sqrt(3) * i) + " " + to_string(length * j) + "," + to_string((length / 2) * sqrt(3) + (length / 2) * sqrt(3) * i) + " " + to_string(length + (length*j)) + "," + to_string((length / 2)  * sqrt(3) + (length / 2) * sqrt(3) * i) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
			counter++;
		}
	}

	col = (mWidth - (length / 2)) / length;//sliding pattern calculated

	for (int i = 0; i < row; i++)//row loop
	{
		for (int j = 0; j < col; j++)//column loop
		{
			svg += "<polygon points=\"" + to_string((length / 2) + length * j) + "," + to_string((length / 2) * sqrt(3) * i) + " " + to_string(length + (length * j)) + "," + to_string((length / 2)  * sqrt(3) + (length / 2) * sqrt(3) * i) + " " + to_string((length / 2) + (length * j) + length) + "," + to_string((length / 2) * sqrt(3) * i) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
			counter++;
		}
	}

	return counter;
}

int drawSmallTrigInTrig(string &svg, double mLength, double length)//it is drawing function of triangles in a triangle
{
	int counter = 0;
	//calculating the maximum row
	int row = (mLength / 2 * sqrt(3)) / ((length / 2) * sqrt(3));

	for (int i = 0; i < row; i++)//row loop
	{
		for (int j = 0; j <= i; j++)//column loop
		{
			svg += "<polygon points=\"" + to_string(length * j + ((mLength / 2) - (i * (length / 2)))) + "," + to_string((length / 2) * sqrt(3) * i) + " " + to_string(((length * j) - (length / 2)) + ((mLength / 2) - (i * (length / 2)))) + "," + to_string((length / 2) * sqrt(3) + (length / 2) * sqrt(3) * i) + " " + to_string(length / 2 + (length * j) + ((mLength / 2) - (i *  (length / 2)))) + "," + to_string((length / 2)  * sqrt(3) + (length / 2) * sqrt(3) * i) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
			counter++;

			if (i < row - 1)
			{
				svg += "<polygon points=\"" + to_string(length * j + ((mLength / 2) - (i * (length / 2)))) + "," + to_string(((length / 2) * sqrt(3) * i) + 2 * (length / 2) * sqrt(3)) + " " + to_string(((length * j) - (length / 2)) + ((mLength / 2) - (i * (length / 2)))) + "," + to_string((length / 2) * sqrt(3) + (length / 2) * sqrt(3) * i) + " " + to_string(length / 2 + (length * j) + ((mLength / 2) - (i * (length / 2)))) + "," + to_string((length / 2) * sqrt(3) + (length / 2) * sqrt(3) * i) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;
			}
		}
	}

	return counter;
}

int drawSmallRectInTrig(string &svg, double mLength, double Width, double Height)//it is drawing function of rectangles in a triangle
{
	int counter = 0;
	//calculating the maximum row
	int row = ((mLength / 2) * sqrt(3)) / Height;
	int row1 = ((mLength / 2) * sqrt(3)) / Width;
	int t;
	double temp;
	int boxcount1 = 0, boxcount2 = 0;
	double diff;
	//calculating the maximum line on the edges of the rectangles
	for (int p = 0; p < row; p++)
	{
		t = ((((mLength / 2) * sqrt(3) - (Height*(p + 1))) / sqrt(3) * 2) / Width);
		boxcount1 += t;
	}

	for (int p = 0; p < row1; p++)
	{
		t = ((((mLength / 2) * sqrt(3) - (Width*(p + 1))) / sqrt(3) * 2) / Height);
		boxcount2 += t;
	}
	//most rectangular drawn statement is selected.if boxcount2 is maximum, the data is swaped(width, height,row)
	if (boxcount2 > boxcount1)
	{
		temp = Width;
		Width = Height;
		Height = temp;
		row = row1;
	}

	for (int i = 0; i < row; i++)//row loop
	{
		t = ((((mLength / 2) * sqrt(3) - (Height*(i + 1))) / sqrt(3) * 2) / Width);
		diff = fmod((((mLength / 2) * sqrt(3) - (Height*(i + 1))) / sqrt(3) * 2), Width) / 2;

		for (int j = 0; j < t; j++)//column loop
		{
			svg += "<rect x=\"" + to_string((Height / sqrt(3)) + diff + (j * Width) + (i * (Height / sqrt(3)))) + "\"  y=\"" + to_string(((mLength / 2) * sqrt(3)) - (Height*(i + 1))) + "\" width=\"" + to_string(Width) + "\" height=\"" + to_string(Height) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
			counter++;
		}
	}

	return counter;
}

int drawSmallTrigInCirc(string &svg, double mRadius, double length)//it is drawing function of triangles in a circle
{
	int counter = 0;
	int row = (mRadius / 2 * sqrt(3)) / ((length / 2) * sqrt(3));//calculating line on the edges of the circle
	int i, j, t;
	double x;
	int ekstrarow = (mRadius - (row * (length / 2) * sqrt(3))) / ((length / 2) * sqrt(3));//calculating the maximum line on the radius

	for (int k = 0; k < 6; k++)//rotation loop
	{
		for (i = 0; i < row; i++)//row loop
		{
			for (j = 0; j <= i; j++)//column loop
			{
				svg += "<polygon points=\"" + to_string((length * j) + ((mRadius / 2) - (i * (length / 2))) + mRadius / 2) + "," + to_string((length / 2) * sqrt(3) * i + mRadius) + " " + to_string(((length * j) - (length / 2)) + ((mRadius / 2) - (i * (length / 2))) + mRadius / 2) + "," + to_string((length / 2) * sqrt(3) + ((length / 2) * sqrt(3) * i) + mRadius) + " " + to_string((length / 2) + (length * j) + ((mRadius / 2) - (i * (length / 2))) + mRadius / 2) + "," + to_string(((length / 2)  * sqrt(3)) + ((length / 2) * sqrt(3) * i) + mRadius) + "\" transform=\"rotate(" + to_string(k * 60) + " " + to_string(mRadius) + " " + to_string(mRadius) + ")\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;

				if (i < row - 1)
				{
					svg += "<polygon points=\"" + to_string((length * j) + ((mRadius / 2) - (i * (length / 2))) + mRadius / 2) + "," + to_string(((length / 2) * sqrt(3) * i) + 2 * (length / 2) * sqrt(3) + mRadius) + " " + to_string(((length * j) - (length / 2)) + ((mRadius / 2) - (i * (length / 2))) + mRadius / 2) + "," + to_string((length / 2) * sqrt(3) + ((length / 2) * sqrt(3) * i) + mRadius) + " " + to_string((length / 2) + (length * j) + ((mRadius / 2) - (i * (length / 2))) + mRadius / 2) + "," + to_string(((length / 2)  * sqrt(3)) + ((length / 2) * sqrt(3) * i) + mRadius) + "\" transform=\"rotate(" + to_string(k * 60) + " " + to_string(mRadius) + " " + to_string(mRadius) + ")\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
					counter++;
				}
			}
		}

		for (int p = 0; p < ekstrarow; p++)//row loop
		{
			x = sqrt(pow(mRadius, 2) - pow((row + 1 + p) * (length / 2) * sqrt(3), 2));
			t = x / length;//calculates how many boxes are drawn

			for (int l = (t - 2 + (p / 2)); l > ((p - t) - (p / 2) - 1); l--)//column loop odd
			{
				svg += "<polygon points=\"" + to_string((length * l) + ((mRadius / 2) - (i * (length / 2))) + mRadius + (length / 2)) + "," + to_string(((length / 2) * sqrt(3) * i) + mRadius) + " " + to_string(((length * l) - (length / 2)) + ((mRadius / 2) - (i * (length / 2))) + mRadius + length / 2) + "," + to_string((length / 2) * sqrt(3) + ((length / 2) * sqrt(3) * i) + mRadius) + " " + to_string((length / 2) + (length * l) + ((mRadius / 2) - (i * (length / 2))) + mRadius + length / 2) + "," + to_string((length / 2)  * sqrt(3) + ((length / 2) * sqrt(3) * i) + mRadius) + "\" transform=\"rotate(" + to_string(k * 60) + " " + to_string(mRadius) + " " + to_string(mRadius) + ")\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;
			}

			for (int m = (t - 1 + (p / 2)); m > ((p - t) - (p / 2) - 1); m--)//column loop even
			{
				svg += "<polygon points=\"" + to_string((length * m) + ((mRadius / 2) - (i * (length / 2))) + mRadius + (length / 2)) + "," + to_string(((length / 2) * sqrt(3) * i) + mRadius) + " " + to_string(((length * m) - (length / 2)) + ((mRadius / 2) - (i * (length / 2))) + mRadius + length / 2) + "," + to_string((length / 2) * sqrt(3) + ((length / 2) * sqrt(3) * i) + mRadius) + " " + to_string((length * m) + ((mRadius / 2) - (i * (length / 2))) + mRadius - length + (length / 2)) + "," + to_string(((length / 2) * sqrt(3) * i) + mRadius) + "\" transform=\"rotate(" + to_string(k * 60) + " " + to_string(mRadius) + " " + to_string(mRadius) + ")\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter++;
			}
			i++;
		}
	}

	return counter;
}


int drawSmallCircInCirc(string &svg, double mRadius, double radius)//it is drawing function of circles in a circle
{
	int counter = 0;
	double angle;
	double diffangle;
	int val;
	double diff = fmod(mRadius, 2 * radius);//mRadius % 2*radius,  fmod, double type modulus function
	diff /= radius * 2;

	for (int i = 0; i < mRadius / (2 * radius); i++)
	{
		angle = asin(radius / ((mRadius - radius) - (2 * radius * i)));
		val = M_PI / angle;//calculate how small circle fits diameter
		diffangle = fmod(M_PI, angle);
		diffangle /= val;
		angle += diffangle;
		angle = ((180 / M_PI) * (angle * 2));//calculated angle

		for (int k = 0; k < val; k++)
		{
			svg += "<circle cx=\"" + to_string(mRadius) + "\" cy=\"" + to_string(radius + (2 * radius * i)) + "\" r=\"" + to_string(radius) + "\" transform=\"rotate(" + to_string(k * angle) + " " + to_string(mRadius) + " " + to_string(mRadius) + ")\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
			counter++;
		}
	}

	if (diff >= 0.5 && diff < 1)//if there is enough space in the center, one more circle is added.
	{
		svg += "<circle cx=\"" + to_string(mRadius) + "\" cy=\"" + to_string(mRadius) + "\" r=\"" + to_string(radius) + "\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
		counter++;
	}

	return counter;
}


int drawSmallRectInCirc(string &svg, double mRadius, double Width, double Height)//it is drawing function of rectangles in a circle
{
	int counter = 0;
	double coordinate = mRadius / sqrt(2);//45-45-90 triangle left-top cordinate 
	double temp;
	double x;
	int t;

	//calculating the maximum line on the edges of the circle
	int ekstrarow = (mRadius - coordinate) / Height;
	int ekstrarow1 = (mRadius - coordinate) / Width;
	int boxcount1 = 0;
	int boxcount2 = 0;
	//rectangles in the rectangle function draws rectangles in the middle of the circle.
	counter += drawSmallRectInRect(svg, coordinate * 2, coordinate * 2, Width, Height, mRadius - coordinate, mRadius - coordinate);
	//calculating the maximum line on the edges of the circle
	for (int p = 0; p < ekstrarow; p++)
	{
		x = sqrt(pow(mRadius, 2) - pow((coordinate + Height) + (p*Height), 2));
		t = x / Width;
		boxcount1 += t;
	}

	for (int p = 0; p < ekstrarow1; p++)
	{
		x = sqrt(pow(mRadius, 2) - pow((coordinate + Width) + (p*Width), 2));
		t = x / Height;
		boxcount2 += t;
	}
	//most rectangular drawn statement is selected.if boxcount2 is maximum, the data is swaped(width, height,row)
	if (boxcount2 > boxcount1)
	{
		temp = Width;
		Width = Height;
		Height = temp;
		ekstrarow = ekstrarow1;
	}

	for (int k = 0; k < 4; k++)//rotation loop
	{
		for (int p = 0; p < ekstrarow; p++)//row loop
		{
			x = sqrt(pow(mRadius, 2) - pow((coordinate + Height) + (p * Height), 2));//the beam distance is calculated according to the Height.
			t = x / Width;//calculates how many boxes are drawn

			for (int j = 0; j < t; j++)//column loop
			{
				svg += "<rect x=\"" + to_string(mRadius + (j * Width)) + "\"  y=\"" + to_string((p * Height) + (coordinate + mRadius)) + "\" width=\"" + to_string(Width) + "\" height=\"" + to_string(Height) + "\" transform=\"rotate(" + to_string(k * 90) + " " + to_string(mRadius) + " " + to_string(mRadius) + ")\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				svg += "<rect x=\"" + to_string((mRadius - Width) - (j * Width)) + "\"  y=\"" + to_string((p * Height) + (coordinate + mRadius)) + "\" width=\"" + to_string(Width) + "\" height=\"" + to_string(Height) + "\" transform=\"rotate(" + to_string(k * 90) + " " + to_string(mRadius) + " " + to_string(mRadius) + ")\" fill=\"green\" stroke=\"black\" stroke-width=\"0.5\" />\n";
				counter += 2;
			}
		}
	}

	return counter;
}