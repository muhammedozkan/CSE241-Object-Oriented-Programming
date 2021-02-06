import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.Rectangle2D;
import java.security.InvalidParameterException;

/**
 * class Rectangle
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */
 
public class Rectangle extends Shape {
	
		
	private	static double _totalAreas;
	private	static double _totalPerimeters;

	private	double _posX;
	private	double _posY;
	private	double _width;
	private	double _height;
	private	String _color;
	private	double _rotateAngle;
	private	double _rotateX;
	private	double _rotateY;
	private	double _x;
	private	double _y;
	
	Rectangle()
	{
	}
	
	//Constructor ex: Rectangle(color,height,width)
	/**
     * Constructor Rectangle
     * @param color String
     * @param height Double
	 * @param width Double
     * @return Shape[]
     */
	Rectangle(String color, double height, double width)
	{ //assign class member value
		setPosX(0);
		setPosY(0);
		widthSet(width);
		heightSet(height);
		setColor(color);
		setRotateAngle(0);
		setRotateX(0);
		setRotateY(0);
		xSet(0);
		ySet(0);
		
		
		setTotalAreas(area());
		setTotalPerimeters(perimeter());
	}
	
	//Constructor ex: Circle(posX,posY,width,height,color,rotateAngle,rotateX,rotateY,x,y)
	Rectangle(double posX, double posY, double width, double height,
						 String color, double rotateAngle, double rotateX, double rotateY,
						 double x, double y)
	{ //assign class member value
		setPosX(posX);
		setPosY(posY);
		widthSet(width);
		heightSet(height);
		setColor(color);
		setRotateAngle(rotateAngle);
		setRotateX(rotateX);
		setRotateY(rotateY);
		xSet(x);
		ySet(y);
		
		setTotalAreas(area());
		setTotalPerimeters(perimeter());

	}
	
	
	
	
	public void draw(Graphics gg) {
		
		 Graphics2D g = (Graphics2D) gg;
		
		g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
	   g.setRenderingHint(RenderingHints.KEY_STROKE_CONTROL, RenderingHints.VALUE_STROKE_PURE);
	    
	    Rectangle2D.Double r=new Rectangle2D.Double((getPosX() + xGet()), (getPosY() + yGet()), widthGet(), heightGet());
		g.rotate(Math.toRadians(getRotateAngle()),(getRotateX() + xGet()),(getRotateY() + yGet()));
		    
	    	g.setColor(Color.black);
	    	g.draw(r);
	    	g.setColor(Color.decode(getColor()));
		    g.fill(r);
		    
		
	
		
		
		    
	}
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
	    draw(g);
	}
	
	public Shape increment()
	{
		setPosX(getPosX() + 1.0);
		setPosY(getPosY() + 1.0);
		setRotateX(getRotateX() + 1.0);
		setRotateY(getRotateY() + 1.0);
		Shape shp = new Rectangle(getPosX(), getPosY(), widthGet(), heightGet(), getColor(), getRotateAngle(), getRotateX(), getRotateY(), xGet(), yGet());

		return shp;
	}
	
	public Shape decrement()
	{
		setPosX(getPosX() - 1.0);
		setPosY(getPosY() - 1.0);
		setRotateX(getRotateX() - 1.0);
		setRotateY(getRotateY() - 1.0);
		Shape shp = new Rectangle(getPosX(), getPosY(), widthGet(), heightGet(), getColor(), getRotateAngle(), getRotateX(), getRotateY(), xGet(), yGet());
		return shp;
	}
	
	String getColor()
	{
		return _color;
	}

	void setColor(String color)
	{
		_color = color;
	}

	double heightGet()
	{
		return _height;
	}

	//if the height value is 0 or  smaller than 0, height value is assigned 1
	void heightSet(double height)  
	{
		if (height > 0)
		{
			_height = height;
		}
		else
		{
			_height = 1;
			throw new  InvalidParameterException("Invalid height Value assigned 1");
		}
	}

	double getPosX()
	{
		return _posX;
	}

	//if the posx value is  smaller than 0, posx value is assigned 0
	void setPosX(double posX)  
	{
		if (posX >= 0)
		{
			_posX = posX;
		}
		else
		{
			_posX = 0;
			throw new  InvalidParameterException("Invalid posX Value assigned 0");
		}
	}

	double getPosY() 
	{
		return _posY;
	}

	//if the posy value is  smaller than 0, posy value is assigned 0
	void setPosY(double posY) 
	{
		if (posY >= 0)
		{
			_posY = posY;
		}
		else
		{
			_posY = 0;
			throw new  InvalidParameterException("Invalid posY Value assigned 0");
		}
	}

	double getRotateAngle()
	{
		return _rotateAngle;
	}

	//if the rotateAngle value is smaller than -360 or greater than 360, rotateAngle value is assigned 0
	void setRotateAngle(double rotateAngle)  //dynamic exception specifications are deprecated in
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
			throw new  InvalidParameterException("Invalid rotateAngle Value assigned 0");
		}
	}

	double getRotateX()
	{
		return _rotateX;
	}

	//if the radius rotateX is 0 or  smaller than 0, rotateX value is assigned 0
	void setRotateX(double rotateX)  
	{
		if (rotateX >= 0)
		{
			_rotateX = rotateX;
		}
		else
		{
			_rotateX = 0;
			throw new  InvalidParameterException("Invalid rotateX Value assigned 0");
		}
	}

	//if the radius rotateY is 0 or  smaller than 0, rotateY value is assigned 0
	double getRotateY()
	{
		return _rotateY;
	}
	/**
     * setRotateY
     * @exception InvalidParameterException
     */
	void setRotateY(double rotateY)  
	{
		if (rotateY >= 0)
		{
			_rotateY = rotateY;
		}
		else
		{
			_rotateY = 0;
			throw new  InvalidParameterException("Invalid rotateY Value assigned 0");
		}
	}

	double widthGet() 
	{
		return _width;
	}

	//if the width value is 0 or  smaller than 0, width value is assigned 1
	/**
     * widthSet
     * @exception InvalidParameterException
     */
	void widthSet(double width)  
	{
		
		if (width > 0)
		{
			_width = width;
		}
		else
		{
			_width = 1;
			throw new  InvalidParameterException("Invalid width Value assigned 1");
		}
		
	}

	double xGet()
	{
		return _x;
	}

	//if the x value is  smaller than 0, x value is assigned 0
	void xSet(double x) 
	{
		if (x >= 0)
		{
			_x = x;
		}
		else
		{
			_x = 0;
			throw new  InvalidParameterException("Invalid x Value assigned 0");
		}
	}

	double yGet()
	{
		return _y;
	}

	//area calculating
	public double area()
	{
		return (_width * _height);
	}

	//perimeter calculating
	public double perimeter()
	{
		return ((widthGet() + heightGet()) * 2);
	}

	//if the y value is  smaller than 0, y value is assigned 0
	void ySet(double y)  
	{
		if (y >= 0)
		{
			_y = y;
		}
		else
		{
			_y = 0;
			throw new  InvalidParameterException("Invalid y Value assigned 0");
		}
	}
	
	//static functions
	static double getTotalAreas()
	{
		return _totalAreas;
	}

	static void setTotalAreas(double totalAreas)
	{
		_totalAreas += totalAreas;
	}

	static double getTotalPerimeters()
	{
		return _totalPerimeters;
	}

	static void setTotalPerimeters(double totalPerimeters)
	{
		_totalPerimeters += totalPerimeters;
	}
	
	
	
}

