import java.awt.Graphics;
import java.util.ArrayList;// holder for temporary object in functions

/**
 * class ComposedShape
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */

public class ComposedShape extends Shape{
	
	
	public Shape[] shaperef;//for Accessible global func. ex. drawall convertall etc.
	
	private int rectflag=0;
	//Constructor ex: ComposedShape(Rectangle,Rectangle) get reference object
	/**
     * Constructor ComposedShape
     * @param Rectangle
     * @param Rectangle
     */
	ComposedShape(Rectangle mContainer, Rectangle sShape)
	{ //assign class member value

		rectflag=1;
		setMainColor(mContainer.getColor());
		optimalRectRect(mContainer, sShape);
	}

	//Constructor ex: ComposedShape(Rectangle,Circle) get reference object
	/**
     * Constructor ComposedShape
     * @param Rectangle
     * @param Circle
     */
	ComposedShape(Rectangle mContainer, Circle sShape)
	{ //assign class member value

		rectflag=1;
		setMainColor(mContainer.getColor());
		optimalRectCirc(mContainer, sShape);
	}

	//Constructor ex: ComposedShape(Rectangle,Triangle) get reference object
	/**
     * Constructor ComposedShape
     * @param Rectangle
     * @param Triangle
     */
	ComposedShape(Rectangle mContainer, Triangle sShape)
	{ //assign class member value
		rectflag=1;
		setMainColor(mContainer.getColor());
		optimalRectTrig(mContainer, sShape);
	}

	//Constructor ex: ComposedShape(Circle,Rectangle) get reference object
	/**
     * Constructor ComposedShape
     * @param Circle
     * @param Rectangle
     */
	ComposedShape(Circle mContainer, Rectangle sShape)
	{ //assign class member value
		
		setMainColor(mContainer.getColor());
		optimalCircRect(mContainer, sShape);
	}

	//Constructor ex: ComposedShape(Circle,Circle) get reference object
	/**
     * Constructor ComposedShape
     * @param Circle
     * @param Circle
     */
	ComposedShape(Circle mContainer, Circle sShape)
	{ //assign class member value
		
		setMainColor(mContainer.getColor());
		optimalCircCirc(mContainer, sShape);
	}

	//Constructor ex: ComposedShape(Circle,Triangle) get reference object
	/**
     * Constructor ComposedShape
     * @param Circle
     * @param Triangle
     */
	ComposedShape(Circle mContainer, Triangle sShape)
	{ //assign class member value
		
		setMainColor(mContainer.getColor());
		optimalCircTrig(mContainer, sShape);
	}

	//Constructor ex: ComposedShape(Triangle,Rectangle) get reference object
	/**
     * Constructor ComposedShape
     * @param Triangle
     * @param Rectangle
     */
	ComposedShape(Triangle mContainer, Rectangle sShape)
	{ //assign class member value
		
		setMainColor(mContainer.getColor());
		optimalTrigRect(mContainer, sShape);
	}

	//Constructor ex: ComposedShape(Triangle,Circle) get reference object
	/**
     * Constructor ComposedShape
     * @param Triangle
     * @param Circle
     */
	ComposedShape(Triangle mContainer, Circle sShape)
	{ //assign class member value
		
		setMainColor(mContainer.getColor());
		optimalTrigCirc(mContainer, sShape);
	}

	//Constructor ex: ComposedShape(Triangle,Triangle) get reference object
	/**
     * Constructor ComposedShape
     * @param Triangle
     * @param Triangle
     */
	ComposedShape(Triangle mContainer, Triangle sShape)
	{ //assign class member value
		
		setMainColor(mContainer.getColor());
		optimalTrigTrig(mContainer, sShape);
	}
	
	void optimalRectRect(Rectangle mContainer, Rectangle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		int row = (int)(mContainer.heightGet() / sShape.heightGet()); //calculating the maximum row
		int col = (int)(mContainer.widthGet() / sShape.widthGet());   //calculating the maximum column
		int row2 = (int)(mContainer.heightGet() / sShape.widthGet()); //calculating the maximum row
		int col2 = (int)(mContainer.widthGet() / sShape.heightGet()); //calculating the maximum column

		double temp;
		int i=0, j=0;

		if (rectflag == 1)
		{
			tempshp.add(mContainer);
		}
		
		//most circles drawn statement is selected.if row*col is maximum, following statement. if not, following the else statement

		if (row * col >= row2 * col2)
		{
			for (i = 0; i < row; i++) //row loop
			{
				for (j = 0; j < col; j++) //column loop
				{

					Rectangle rect = new Rectangle(j * sShape.widthGet() + sShape.xGet() + mContainer.getPosX(),
													i * sShape.heightGet() + sShape.yGet() + mContainer.getPosY(),
													sShape.widthGet(), sShape.heightGet(),
													sShape.getColor(), 0, 0, 0, mContainer.xGet(),
													mContainer.yGet());
					
					tempshp.add(rect);
					
				}
			}

			double diffcol = mContainer.widthGet() - (col * sShape.widthGet());
			double diffrow = mContainer.heightGet() - (row * sShape.heightGet());

			if (diffcol >= sShape.heightGet()) //placing rotated rectangles in empty spaces
			{
				for (int t = 0;
					 t < (mContainer.widthGet() - (col * sShape.widthGet())) / sShape.heightGet() - 1; t++)
				{
					for (int k = 0;
						 k < mContainer.heightGet() / sShape.widthGet() - 1;
						 k++)
					{
						Rectangle rect = new Rectangle((j * sShape.widthGet()) + sShape.xGet() + (t * sShape.heightGet()) + mContainer.getPosX(),
														k * sShape.widthGet() + sShape.yGet() + mContainer.getPosY(), sShape.heightGet(), sShape.widthGet(),
														sShape.getColor(), 0, 0, 0, mContainer.xGet(), mContainer.yGet());

						tempshp.add(rect);
					}
				}
			}
			else if (diffrow >= sShape.widthGet())
			{
				for (int t = 0;
					 t < (mContainer.heightGet() - (row * sShape.heightGet())) / sShape.widthGet() - 1; t++)
				{
					for (int k = 0;
						 k < mContainer.widthGet() / sShape.heightGet() - 1;
						 k++)
					{
						Rectangle rect = new Rectangle((k * sShape.heightGet()) + sShape.xGet() + mContainer.getPosX(), (i * sShape.heightGet()) + sShape.yGet() + (t * sShape.widthGet()) + mContainer.getPosY(),
														sShape.heightGet(), sShape.widthGet(), sShape.getColor(), 0, 0, 0, mContainer.xGet(), mContainer.yGet());

						tempshp.add(rect);
					}
				}
			}
		}
		else
		{
			//the data is swapped(width, height,row)
			temp = sShape.widthGet();
			sShape.widthSet(sShape.heightGet());
			sShape.heightSet(temp);
			

			for (i = 0; i < row2; i++) //row loop
			{
				for (j = 0; j < col2; j++) //column loop
				{
					Rectangle rect = new Rectangle((j * sShape.widthGet()) + sShape.xGet() + mContainer.getPosX(),
													(i * sShape.heightGet()) + sShape.yGet() + mContainer.getPosY(),
													sShape.widthGet(), sShape.heightGet(),
													sShape.getColor(), 0, 0, 0, mContainer.xGet(),
													mContainer.yGet());

					tempshp.add(rect);
				}
			}

			double diffcol = mContainer.widthGet() - (col2 * sShape.widthGet());
			double diffrow = mContainer.heightGet() - (row2 * sShape.heightGet());

			if (diffcol >= sShape.heightGet()) //placing rotated rectangles in empty spaces
			{
				for (int t = 0;
					 t < (mContainer.widthGet() - (col2 * sShape.widthGet())) / sShape.heightGet() - 1; t++)
				{
					for (int k = 0;
						 k < mContainer.heightGet() / sShape.widthGet() - 1;
						 k++)
					{
						Rectangle rect = new Rectangle((j * sShape.widthGet()) + sShape.xGet() + (t * sShape.heightGet()) + mContainer.getPosX(),
														(k * sShape.widthGet()) + sShape.yGet() + mContainer.getPosY(), sShape.heightGet(), sShape.widthGet(),
														sShape.getColor(), 0, 0, 0, mContainer.xGet(), mContainer.yGet());

						tempshp.add(rect);
					}
				}
			}
			else if (diffrow >= sShape.widthGet())
			{
				for (int t = 0;
					 t < (mContainer.heightGet() - (row2 * sShape.heightGet())) / sShape.widthGet() - 1; t++)
				{
					for (int k = 0;
						 k < mContainer.widthGet() / sShape.heightGet() - 1;
						 k++)
					{
						Rectangle rect = new Rectangle((k * sShape.heightGet()) + sShape.xGet() + mContainer.getPosX(),
														(i * sShape.heightGet()) + sShape.yGet() + (t * sShape.widthGet()) + mContainer.getPosY(),
														sShape.heightGet(), sShape.widthGet(), sShape.getColor(), 0, 0, 0,
														mContainer.xGet(), mContainer.yGet());

						tempshp.add(rect);
					}
				}
			}
		}
		Rectangle.setTotalAreas(-sShape.area());
		Rectangle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		
		shaperef=new Shape[tempshp.size()];
		for (int h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
	}

	void optimalRectCirc(Rectangle mContainer, Circle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		int row1 = (int)(mContainer.heightGet() / (2 * sShape.getRadius())); //rectangle pattern calculating the maximum row
		int col1 = (int)(mContainer.widthGet() / (2 * sShape.getRadius()));  //rectangle pattern calculating the maximum column
		int rectPattern = row1 * col1;									// rectangle pattern max circle value
		int row2 = 0;
		int col2 = 0;
		row2 = (int)((mContainer.heightGet() / (sShape.getRadius() + (sShape.getRadius() * Math.sqrt(3)) - (sShape.getRadius() * (Math.sqrt(3) / 1.7635)))) - 0.001); //triangle pattern calculating the maximum row
		col2 = (int)(((mContainer.widthGet() - sShape.getRadius()) / (sShape.getRadius() * 2)));															 //triangle pattern calculating the maximum column

		int trigeven = (int)Math.ceil((double)row2 / 2) * col1; //even rows
		int trigodd = row2 / 2 * col2;				  //odd rows
		int trigPattern = trigodd + trigeven;		  // triangle pattern max circle value

		
		tempshp.add(mContainer);
		//most circles drawn statement is selected.if trigPattern is maximum, following the else statement
		if (rectPattern >= trigPattern)
		{
			for (int i = 0; i < row1; i++) //row loop
			{
				for (int j = 0; j < col1; j++) //column loop
				{
					Circle circ = new Circle((j * 2 * sShape.getRadius()) + sShape.getRadius() + mContainer.getPosX(),
											  (i * 2 * sShape.getRadius()) + sShape.getRadius() + mContainer.getPosY(),
											  sShape.getRadius(), sShape.getColor(), 0, 0, 0);

					tempshp.add(circ);
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
						Circle circ = new Circle((j * 2 * sShape.getRadius()) + sShape.getRadius() + mContainer.getPosX(),
												  ((sShape.getRadius() * Math.sqrt(3)) * i) + sShape.getRadius() + mContainer.getPosY(),
												  sShape.getRadius(), sShape.getColor(), 0, 0, 0);

						tempshp.add(circ);
					}

					if (mContainer.widthGet() >= ((col2 * 2 * sShape.getRadius()) + (sShape.getRadius() * 2)))
					{
						Circle circ = new Circle((j * 2 * sShape.getRadius()) + sShape.getRadius() + mContainer.getPosX(),
												  ((sShape.getRadius() * Math.sqrt(3)) * i) + sShape.getRadius() + mContainer.getPosY(),
												  sShape.getRadius(), sShape.getColor(), 0, 0, 0);

						tempshp.add(circ);
					}
				}
				else
				{
					if ((mContainer.heightGet() >= ((sShape.getRadius() * Math.sqrt(3)) * i) + (sShape.getRadius() * Math.sqrt(3))) || row2 % 2 == 1)
					{
						for (int j = 0; j < col2; j++) //column loop
						{
							Circle circ = new Circle((j * 2 * sShape.getRadius()) + sShape.getRadius() * 2 + mContainer.getPosX(),
													  (sShape.getRadius() * Math.sqrt(3) * i) + sShape.getRadius() + mContainer.getPosY(),
													  sShape.getRadius(), sShape.getColor(), 0, 0, 0);

							tempshp.add(circ);
						}
					}
				}
			}
		}
		Circle.setTotalAreas(-sShape.area());
		Circle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		if (rectflag == 1)
		{
		
		shaperef=new Shape[tempshp.size()];
		for (int h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
		}
	}

	void optimalRectTrig(Rectangle mContainer, Triangle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		int row = (int)(mContainer.heightGet() / ((sShape.getLength() / 2) * Math.sqrt(3))); //calculating the maximum row
		int col = (int)(mContainer.widthGet() / sShape.getLength());					   //calculating the maximum column

		tempshp.add(mContainer);
		for (int i = 0; i < row; i++) //row loop
		{
			for (int j = 0; j < col; j++) //column loop
			{
				Triangle trig = new Triangle(mContainer.getPosX(), mContainer.getPosY(),
											  (sShape.getLength() / 2) + sShape.getLength() * j,
											  (sShape.getLength() / 2) * Math.sqrt(3) * i, sShape.getLength() * j,
											  (sShape.getLength() / 2) * Math.sqrt(3) + (sShape.getLength() / 2) * Math.sqrt(3) * i,
											  sShape.getLength() + (sShape.getLength() * j),
											  (sShape.getLength() / 2) * Math.sqrt(3) + (sShape.getLength() / 2) * Math.sqrt(3) * i,
											  sShape.getColor(), 0, 0, 0, sShape.getLength());

				tempshp.add(trig);
			}
		}

		col = (int)((mContainer.widthGet() - (sShape.getLength() / 2)) / sShape.getLength()); //sliding pattern calculated

		for (int i = 0; i < row; i++) //row loop
		{
			for (int j = 0; j < col; j++) //column loop
			{
				Triangle trig = new Triangle(mContainer.getPosX(), mContainer.getPosY(),
											  (sShape.getLength() / 2) + sShape.getLength() * j,
											  (sShape.getLength() / 2) * Math.sqrt(3) * i,
											  sShape.getLength() + (sShape.getLength() * j),
											  (sShape.getLength() / 2) * Math.sqrt(3) + (sShape.getLength() / 2) * Math.sqrt(3) * i,
											  (sShape.getLength() / 2) + (sShape.getLength() * j) + sShape.getLength(),
											  (sShape.getLength() / 2) * Math.sqrt(3) * i,
											  sShape.getColor(), 0, 0, 0, sShape.getLength());

				tempshp.add(trig);
			}
		}
		Triangle.setTotalAreas(-sShape.area());
		Triangle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		
		shaperef=new Shape[tempshp.size()];
		for (int h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
	}

	void optimalCircRect(Circle mContainer, Rectangle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		double coordinate = mContainer.getRadius() / Math.sqrt(2); //45-45-90 triangle left-top cordinate
		double temp;
		double x;
		int t;

		//calculating the maximum line on the edges of the circle
		int ekstrarow = (int)((mContainer.getRadius() - coordinate) / sShape.heightGet());
		int ekstrarow1 = (int)((mContainer.getRadius() - coordinate) / sShape.widthGet());
		int boxcount1 = 0;
		int boxcount2 = 0;

		tempshp.add(mContainer);

		//rectangles in the rectangle function draws rectangles in the middle of the circle.
		Rectangle middle=new Rectangle(mContainer.getPosX() - mContainer.getRadius(), mContainer.getPosY() - mContainer.getRadius(), coordinate * 2, coordinate * 2,
						 mContainer.getColor(), 0, 0, 0, mContainer.getRadius() - coordinate,
						 mContainer.getRadius() - coordinate);

		optimalRectRect(middle, sShape);

		//calculating the maximum line on the edges of the circle
		for (int p = 0; p < ekstrarow; p++)
		{
			x = Math.sqrt(Math.pow(mContainer.getRadius(), 2) - Math.pow((coordinate + sShape.heightGet()) + (p * sShape.heightGet()), 2));
			t = (int)(x / sShape.widthGet());
			boxcount1 += t;
		}

		for (int p = 0; p < ekstrarow1; p++)
		{
			x = Math.sqrt(	Math.pow(mContainer.getRadius(), 2) - Math.pow((coordinate + sShape.widthGet()) + (p * sShape.widthGet()), 2));
			t = (int)(x / sShape.heightGet());
			boxcount2 += t;
		}
		//most rectangular drawn statement is selected.if boxcount2 is maximum, the data is swapped(width, height,row)
		if (boxcount2 > boxcount1)
		{
			temp = sShape.widthGet();
			sShape.widthSet(sShape.heightGet());
			sShape.heightSet(temp);
			ekstrarow = ekstrarow1;
		}

		for (int k = 0; k < 4; k++) //rotation loop
		{
			for (int p = 0; p < ekstrarow; p++) //row loop
			{
				x = Math.sqrt(Math.pow(mContainer.getRadius(), 2) - Math.pow((coordinate + sShape.heightGet()) + (p * sShape.heightGet()), 2)); //the beam distance is calculated according to the sShape.heightGet().
				t = (int)(x / sShape.widthGet());																							//calculates how many boxes are drawn

				for (int j = 0; j < t; j++) //column loop
				{
					Rectangle rect1 = new Rectangle(mContainer.getRadius() + (j * sShape.widthGet()) + mContainer.getPosX() - mContainer.getRadius(),
													 (p * sShape.heightGet()) + (coordinate + mContainer.getRadius()) + mContainer.getPosY() - mContainer.getRadius(),
													 sShape.widthGet(), sShape.heightGet(), sShape.getColor(), k * 90,
													 mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(), mContainer.getRadius() + mContainer.getPosY() - mContainer.getRadius(), 0, 0);

					tempshp.add(rect1);

					Rectangle rect2 = new Rectangle((mContainer.getRadius() - sShape.widthGet()) - (j * sShape.widthGet()) + mContainer.getPosX() - mContainer.getRadius(),
													 (p * sShape.heightGet()) + (coordinate + mContainer.getRadius()) + mContainer.getPosY() - mContainer.getRadius(),
													 sShape.widthGet(), sShape.heightGet(),
													 sShape.getColor(), k * 90, mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(), mContainer.getRadius() + mContainer.getPosY() - mContainer.getRadius(), 0, 0);

					tempshp.add(rect2);
				}
			}
		}
		Rectangle.setTotalAreas(-sShape.area());
		Rectangle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		
		
		
		
		int sumshp=shaperef.length+tempshp.size();
		Shape[] shapetmp=new Shape[shaperef.length];
		
		for (int m = 0; m < shaperef.length; m++) {
			
			shapetmp[m]=shaperef[m];
		}
		
		shaperef=new Shape[sumshp];
		int h=0;
		for (h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
		
		
		for (; h < shaperef.length; h++) {
			
			shaperef[h]=shapetmp[h-tempshp.size()];
		}
		
	}

	void optimalCircCirc(Circle mContainer, Circle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		double angle;
		double diffangle;
		int val;
		double diff = mContainer.getRadius()% 2 * sShape.getRadius(); //mContainer.getRadius() % 2sShape.getRadius(),  fmod, double type modulus function
		diff /= sShape.getRadius() * 2;

		tempshp.add(mContainer);
		for (int i = 0; i < mContainer.getRadius() / (2 * sShape.getRadius());
			 i++)
		{
			angle = Math.asin(sShape.getRadius() / ((mContainer.getRadius() - sShape.getRadius()) - (2 * sShape.getRadius() * i)));
			val =(int)(Math.PI / angle); //calculate how small circle fits diameter
			diffangle = Math.PI% angle;
			diffangle /= val;
			angle += diffangle;
			angle = ((180 / Math.PI) * (angle * 2)); //calculated angle

			for (int k = 0; k < val; k++)
			{
				Circle circ = new Circle(mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(),
										  sShape.getRadius() + (2 * sShape.getRadius() * i) + mContainer.getPosY() - mContainer.getRadius(),
										  sShape.getRadius(), sShape.getColor(), k * angle,
										  mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(), mContainer.getRadius() + mContainer.getPosY() - mContainer.getRadius());

				tempshp.add(circ);
			}
		}

		if (diff >= 0.5 && diff < 1) //if there is enough space in the center, one more circle is added.
		{
			Circle circ = new Circle(mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(), mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(),
									  sShape.getRadius(), sShape.getColor(), 0, 0, 0);

			tempshp.add(circ);
		}
		Circle.setTotalAreas(-sShape.area());
		Circle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		
		shaperef=new Shape[tempshp.size()];
		for (int h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
		
		
	}

	void optimalCircTrig(Circle mContainer, Triangle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		int row = (int)((mContainer.getRadius() / 2 * Math.sqrt(3)) / ((sShape.getLength() / 2) * Math.sqrt(3))); //calculating line on the edges of the circle
		int i, j, t;
		double x;
		int ekstrarow = (int)((mContainer.getRadius() - (row * (sShape.getLength() / 2) * Math.sqrt(3))) / ((sShape.getLength() / 2) * Math.sqrt(3))); //calculating the maximum line on the radius

		tempshp.add(mContainer);
		for (int k = 0; k < 6; k++) //rotation loop
		{
			for (i = 0; i < row; i++) //row loop
			{
				for (j = 0; j <= i; j++) //column loop
				{
					Triangle trig = new Triangle(mContainer.getPosX() - mContainer.getRadius(), mContainer.getPosY() - mContainer.getRadius(), (sShape.getLength() * j) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
												  (sShape.getLength() / 2) * Math.sqrt(3) * i + mContainer.getRadius(),
												  ((sShape.getLength() * j) - (sShape.getLength() / 2)) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
												  (sShape.getLength() / 2) * Math.sqrt(3) + ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
												  (sShape.getLength() / 2) + (sShape.getLength() * j) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
												  ((sShape.getLength() / 2) * Math.sqrt(3)) + ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
												  sShape.getColor(), (k * 60), mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(), mContainer.getRadius() + mContainer.getPosY() - mContainer.getRadius(), sShape.getLength());

					tempshp.add(trig);

					if (i < row - 1)
					{
						Triangle trig1 = new Triangle(mContainer.getPosX() - mContainer.getRadius(), mContainer.getPosY() - mContainer.getRadius(), (sShape.getLength() * j) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
													  ((sShape.getLength() / 2) * Math.sqrt(3) * i) + 2 * (sShape.getLength() / 2) * Math.sqrt(3) + mContainer.getRadius(),
													  ((sShape.getLength() * j) - (sShape.getLength() / 2)) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
													  (sShape.getLength() / 2) * Math.sqrt(3) + ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
													  (sShape.getLength() / 2) + (sShape.getLength() * j) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() / 2,
													  ((sShape.getLength() / 2) * Math.sqrt(3)) + ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
													  sShape.getColor(), (k * 60), mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(), mContainer.getRadius() + mContainer.getPosY() - mContainer.getRadius(), sShape.getLength());

						tempshp.add(trig1);
					}
				}
			}

			for (int p = 0; p < ekstrarow; p++) //row loop
			{
				x = Math.sqrt(
					Math.pow(mContainer.getRadius(), 2) - Math.pow((row + 1 + p) * (sShape.getLength() / 2) * Math.sqrt(3), 2));
				t = (int)(x / sShape.getLength()); //calculates how many boxes are drawn

				for (int l = (t - 2 + (p / 2)); l > ((p - t) - (p / 2) - 1); l--) //column loop odd
				{
					Triangle trig = new Triangle(mContainer.getPosX() - mContainer.getRadius(), mContainer.getPosY() - mContainer.getRadius(), (sShape.getLength() * l) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + (sShape.getLength() / 2),
												  ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
												  ((sShape.getLength() * l) - (sShape.getLength() / 2)) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + sShape.getLength() / 2,
												  (sShape.getLength() / 2) * Math.sqrt(3) + ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
												  (sShape.getLength() / 2) + (sShape.getLength() * l) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + sShape.getLength() / 2,
												  (sShape.getLength() / 2) * Math.sqrt(3) + ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
												  sShape.getColor(), k * 60, mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(), mContainer.getRadius() + mContainer.getPosY() - mContainer.getRadius(), sShape.getLength());

					tempshp.add(trig);
				}

				for (int m = (t - 1 + (p / 2)); m > ((p - t) - (p / 2) - 1); m--) //column loop even
				{
					Triangle trig = new Triangle(mContainer.getPosX() - mContainer.getRadius(), mContainer.getPosY() - mContainer.getRadius(), (sShape.getLength() * m) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + (sShape.getLength() / 2),
												  ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
												  ((sShape.getLength() * m) - (sShape.getLength() / 2)) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() + sShape.getLength() / 2,
												  (sShape.getLength() / 2) * Math.sqrt(3) + ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
												  (sShape.getLength() * m) + ((mContainer.getRadius() / 2) - (i * (sShape.getLength() / 2))) + mContainer.getRadius() - sShape.getLength() + (sShape.getLength() / 2),
												  ((sShape.getLength() / 2) * Math.sqrt(3) * i) + mContainer.getRadius(),
												  sShape.getColor(), k * 60, mContainer.getRadius() + mContainer.getPosX() - mContainer.getRadius(), mContainer.getRadius() + mContainer.getPosY() - mContainer.getRadius(), sShape.getLength());

					tempshp.add(trig);
				}
				i++;
			}
		}
		Triangle.setTotalAreas(-sShape.area());
		Triangle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		
		shaperef=new Shape[tempshp.size()];
		for (int h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
	}

	void optimalTrigRect(Triangle mContainer, Rectangle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		//calculating the maximum row
		int row = (int)(((mContainer.getLength() / 2) * Math.sqrt(3)) / sShape.heightGet());
		int row1 = (int)(((mContainer.getLength() / 2) * Math.sqrt(3)) / sShape.widthGet());
		int t;
		double temp;
		int boxcount1 = 0, boxcount2 = 0;
		double diff;

		tempshp.add(mContainer);
		//calculating the maximum line on the edges of the rectangles
		for (int p = 0; p < row; p++)
		{
			t = (int)(((((mContainer.getLength() / 2) * Math.sqrt(3) - (sShape.heightGet() * (p + 1))) / Math.sqrt(3) * 2) / sShape.widthGet()));
			boxcount1 += t;
		}

		for (int p = 0; p < row1; p++)
		{
			t = (int)(((((mContainer.getLength() / 2) * Math.sqrt(3) - (sShape.widthGet() * (p + 1))) / Math.sqrt(3) * 2) / sShape.heightGet()));
			boxcount2 += t;
		}
		//most rectangular drawn statement is selected.if boxcount2 is maximum, the data is swapped(width, height,row)
		if (boxcount2 > boxcount1)
		{
			temp = sShape.widthGet();
			sShape.widthSet(sShape.heightGet());
			sShape.heightSet(temp);
			row = row1;
		}

		for (int i = 0; i < row; i++) //row loop
		{
			t = (int)(((((mContainer.getLength() / 2) * Math.sqrt(3) - (sShape.heightGet() * (i + 1))) / Math.sqrt(3) * 2) / sShape.widthGet()));
			diff = ((((mContainer.getLength() / 2) * Math.sqrt(3) - (sShape.heightGet() * (i + 1))) / Math.sqrt(3) * 2)% sShape.widthGet()) / 2;

			for (int j = 0; j < t; j++) //column loop
			{
				Rectangle rect = new Rectangle((sShape.heightGet() / Math.sqrt(3)) + diff + (j * sShape.widthGet()) + (i * (sShape.heightGet() / Math.sqrt(3))) + mContainer.getPosX(),
												((mContainer.getLength() / 2) * Math.sqrt(3)) - (sShape.heightGet() * (i + 1)) + mContainer.getPosY(),
												sShape.widthGet(), sShape.heightGet(), sShape.getColor(), 0, 0, 0, 0, 0);

				tempshp.add(rect);
			}
		}
		Rectangle.setTotalAreas(-sShape.area());
		Rectangle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		
		shaperef=new Shape[tempshp.size()];
		for (int h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
	}

	void optimalTrigCirc(Triangle mContainer, Circle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		int row = (int)(Math.ceil((((mContainer.getLength() - sShape.getRadius() * 4)) / (2 * sShape.getRadius())) - 0.7275)); //calculating row

		tempshp.add(mContainer);
		for (int i = 0; i <= row; i++) //row loop
		{
			for (int j = 0; j <= i / 2; j++) //column loop
			{
				if (i % 2 == 1)
				{
					Circle circ1 = new Circle((mContainer.getLength() / 2) - ((sShape.getRadius() * j * 2) + (sShape.getRadius())) + mContainer.getPosX(),
											   (2 * sShape.getRadius()) + (sShape.getRadius() * Math.sqrt(3) * i) + mContainer.getPosY(),
											   sShape.getRadius(), sShape.getColor(), 0, 0, 0);

					tempshp.add(circ1);

					Circle circ2 = new Circle((mContainer.getLength() / 2) + ((sShape.getRadius() * j * 2) + (sShape.getRadius())) + mContainer.getPosX(),
											   (2 * sShape.getRadius()) + (sShape.getRadius() * Math.sqrt(3) * i) + mContainer.getPosY(),
											   sShape.getRadius(), sShape.getColor(), 0, 0, 0);

					tempshp.add(circ2);;
				}
				else
				{
					Circle circ = new Circle((mContainer.getLength() / 2) - (sShape.getRadius() * j * 2) + mContainer.getPosX(),
											  (2 * sShape.getRadius()) + (sShape.getRadius() * Math.sqrt(3) * i) + mContainer.getPosY(),
											  sShape.getRadius(), sShape.getColor(), 0, 0, 0);

					tempshp.add(circ);
				}
			}

			for (int k = 1; k <= i / 2; k++) //column loop
			{
				if (i % 2 != 1)
				{
					Circle circ = new Circle((mContainer.getLength() / 2) + (sShape.getRadius() * k * 2) + mContainer.getPosX(),
											  (2 * sShape.getRadius()) + (sShape.getRadius() * Math.sqrt(3) * i) + mContainer.getPosY(),
											  sShape.getRadius(), sShape.getColor(), 0, 0, 0);

					tempshp.add(circ);
				}
			}
		}
		Circle.setTotalAreas(-sShape.area());
		Circle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		
		shaperef=new Shape[tempshp.size()];
		for (int h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
	}

	void optimalTrigTrig(Triangle mContainer, Triangle sShape)
	{
		ArrayList<Shape> tempshp=new ArrayList<Shape>();
		//calculating the maximum row
		int row = (int)((mContainer.getLength() / 2 * Math.sqrt(3)) / ((sShape.getLength() / 2) * Math.sqrt(3)));

		tempshp.add(mContainer);
		for (int i = 0; i < row; i++) //row loop
		{
			for (int j = 0; j <= i; j++) //column loop
			{
				Triangle trig = new Triangle(mContainer.getPosX(), mContainer.getPosY(), sShape.getLength() * j + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
											  (sShape.getLength() / 2) * Math.sqrt(3) * i, ((sShape.getLength() * j) - (sShape.getLength() / 2)) + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
											  (sShape.getLength() / 2) * Math.sqrt(3) + (sShape.getLength() / 2) * Math.sqrt(3) * i,
											  sShape.getLength() / 2 + (sShape.getLength() * j) + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
											  (sShape.getLength() / 2) * Math.sqrt(3) + (sShape.getLength() / 2) * Math.sqrt(3) * i,
											  sShape.getColor(), 0, 0, 0, sShape.getLength());

				tempshp.add(trig);

				if (i < row - 1)
				{
					Triangle trig1 = new Triangle(mContainer.getPosX(), mContainer.getPosY(), sShape.getLength() * j + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
												  ((sShape.getLength() / 2) * Math.sqrt(3) * i) + 2 * (sShape.getLength() / 2) * Math.sqrt(3),
												  ((sShape.getLength() * j) - (sShape.getLength() / 2)) + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
												  (sShape.getLength() / 2) * Math.sqrt(3) + (sShape.getLength() / 2) * Math.sqrt(3) * i,
												  sShape.getLength() / 2 + (sShape.getLength() * j) + ((mContainer.getLength() / 2) - (i * (sShape.getLength() / 2))),
												  (sShape.getLength() / 2) * Math.sqrt(3) + (sShape.getLength() / 2) * Math.sqrt(3) * i, sShape.getColor(), 0, 0, 0,
												  sShape.getLength());

					tempshp.add(trig1);
				}
			}
		}
		Triangle.setTotalAreas(-sShape.area());
		Triangle.setTotalPerimeters(-sShape.perimeter());
		
		setObjectCount(tempshp.size()-1);
		setEmptyArea(mContainer.area() - (getObjectCount() * sShape.area()));
		
		_area=(mContainer.area() + (getObjectCount() * sShape.area()));
		_perimeter=(mContainer.perimeter() + (getObjectCount() * sShape.perimeter()));
		
		shaperef=new Shape[tempshp.size()];
		for (int h = 0; h < tempshp.size(); h++) {
			shaperef[h]=tempshp.get(h);
		}
	}
	
	
	public Shape increment()
	{
		for (int i=0;i<shaperef.length;++i)
		{
			shaperef[i].increment();
		}

		return this;
	}
	
	public Shape decrement()
	{
		for (int i=0;i<shaperef.length;++i)
		{
			shaperef[i].decrement();
		}

		return this;
	}
	private double _area;
	public double area()
	{
		return _area; 
	}
	private double _perimeter;
	public double perimeter()
	{
		return _perimeter; 
	}

	public void draw(Graphics gg) {
		for (int i = 0; i < shaperef.length; i++) {
			shaperef[i].draw(gg);
		}   
	}
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
	    draw(g);
	}
		
	private double _emptyArea;
	
	double getEmptyArea() 
	{
		return _emptyArea;
	}

	 void setEmptyArea(double emptyArea)
	{
		if (emptyArea < 0.0000001) 
		{
			_emptyArea = 0;
		}
		else
		{
			_emptyArea = emptyArea;
		}
	}
	 private int _objectCount;
	 
	int getObjectCount() 
	{
		return _objectCount;
	}

	void setObjectCount(int objectCount)
	{
		_objectCount = objectCount;
	}
	
	private String _mainColor;
	String getMainColor()
	{
		return _mainColor;
	}

	void setMainColor(String mainColor)
	{
		_mainColor = mainColor;
	}

}
