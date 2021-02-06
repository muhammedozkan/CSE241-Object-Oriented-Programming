import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.AffineTransform;
import java.awt.geom.Path2D;
import java.security.InvalidParameterException;

/**
 * class Triangle
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */

public class Triangle extends Shape {
	private static double _totalAreas;
	private static double _totalPerimeters;

	private double _posX;
	private double _posY;
	private double _point1X;
	private double _point1Y;
	private double _point2X;
	private double _point2Y;
	private double _point3X;
	private double _point3Y;
	private String _color;
	private double _rotateAngle;
	private double _rotateX;
	private double _rotateY;
	private double _length;
	
	Triangle()
	{
	}

	//Constructor ex: Triangle(color,length)
	/**
     * Constructor Rectangle
     * @param color String
     * @param length Double
     * @return Shape[]
     */
	Triangle(String color, double length)
	{ //assign class member value
		setPosX(0);
		setPosY(0);
		setPoint1X(length / 2);
		setPoint1Y(0);
		setPoint2X(0);
		setPoint2Y((length / 2) * Math.sqrt(3));
		setPoint3X(length);
		setPoint3Y((length / 2) * Math.sqrt(3));
		setColor(color);
		setRotateAngle(0);
		setRotateX(0);
		setRotateY(0);
		setLength(length);
		setTotalAreas(area());
		setTotalPerimeters(perimeter());
	}

	//Constructor ex: Triangle(posX,posY,point1X,.....,point3Y,color,rotateAngle,rotateX,rotateY,length)
	Triangle(double posX, double posY, double point1X, double point1Y,
					   double point2X, double point2Y, double point3X, double point3Y,
					   String color, double rotateAngle, double rotateX, double rotateY,
					   double length)
	{ //assign class member value
		setPosX(posX);
		setPosY(posY);
		setPoint1X(point1X);
		setPoint1Y(point1Y);
		setPoint2X(point2X);
		setPoint2Y(point2Y);
		setPoint3X(point3X);
		setPoint3Y(point3Y);
		setColor(color);
		setRotateAngle(rotateAngle);
		setRotateX(rotateX);
		setRotateY(rotateY);
		setLength(length);

		//if points value is equal 0, point value is assigned to calculated value
		if (_point1X == 0 && _point1Y == 0 && _point2X == 0 && _point2Y == 0 && _point3X == 0 && _point3Y == 0)
		{
			setPoint1X(_length / 2);
			setPoint1Y(0);
			setPoint2X(0);
			setPoint2Y((_length / 2) * Math.sqrt(3));
			setPoint3X(_length);
			setPoint3Y((_length / 2) * Math.sqrt(3));
		}
		setTotalAreas(area());
		setTotalPerimeters(perimeter());
	}
	
	public Shape increment()
	{
		setPosX(getPosX() + 1.0);
		setPosY(getPosY() + 1.0);
		setRotateX(getRotateX() + 1.0);
		setRotateY(getRotateY() + 1.0);
		Shape shp = new Triangle(getPosX(), getPosY(), getPoint1X(), getPoint1Y(), getPoint2X(), getPoint2Y(), getPoint3X(), getPoint3Y(), getColor(), getRotateAngle(), getRotateX(), getRotateY(), getLength());
		return shp;
	}
	
	public Shape decrement()
	{
		setPosX(getPosX() - 1.0);
		setPosY(getPosY() - 1.0);
		setRotateX(getRotateX() - 1.0);
		setRotateY(getRotateY() - 1.0);
		Shape shp = new Triangle(getPosX(), getPosY(), getPoint1X(), getPoint1Y(), getPoint2X(), getPoint2Y(), getPoint3X(), getPoint3Y(), getColor(), getRotateAngle(), getRotateX(), getRotateY(), getLength());
		return shp;
	}
	
	
	
	public void draw(Graphics gg)  {
		
		 Graphics2D g = (Graphics2D) gg;
		
		g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
	    g.setRenderingHint(RenderingHints.KEY_STROKE_CONTROL, RenderingHints.VALUE_STROKE_PURE);
	    
	    Path2D.Double t=new Path2D.Double();
	    
	    t.moveTo((getPoint1X() + getPosX()), (getPoint1Y() + getPosY()));
	    t.lineTo((getPoint2X() + getPosX()), (getPoint2Y() + getPosY()));
	    t.lineTo((getPoint3X() + getPosX()), (getPoint3Y() + getPosY()));
	    t.closePath();
	  
		   g.rotate(Math.toRadians(getRotateAngle()),getRotateX(),getRotateY());
		
		    g.setColor(Color.black);
	    	g.draw(t);
	    	g.setColor(Color.decode(getColor()));
		    g.fill(t);
		    
		    
		    
	}
	
	String getColor() 
	{
		return _color;
	}
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
	    draw(g);
	}
	void setColor(String color)
	{
		_color = color;
	}

	double getPoint1X() 
	{
		return _point1X;
	}

	//if the point1X value is  smaller than 0, point1X value is assigned 0
	void setPoint1X(double point1X)  
	{
		if (point1X >= 0)
		{
			_point1X = point1X;
		}
		else
		{
			_point1X = 0;
			throw new  InvalidParameterException("Invalid point1X Value assigned 0");
		}
	}

	double getPoint1Y() 
	{
		return _point1Y;
	}

	//if the point1Y value is  smaller than 0, point1Y value is assigned 0
	void setPoint1Y(double point1Y)  
	{
		if (point1Y >= 0)
		{
			_point1Y = point1Y;
		}
		else
		{
			_point1Y = 0;
			throw new  InvalidParameterException("Invalid point1Y Value assigned 0");
		}
	}

	double getPoint2X() 
	{
		return _point2X;
	}

	//if the point2X value is  smaller than 0, point2X value is assigned 0
	void setPoint2X(double point2X)  
	{
		if (point2X >= 0)
		{
			_point2X = point2X;
		}
		else
		{
			_point2X = 0;
			throw new  InvalidParameterException("Invalid point2X Value assigned 0");
		}
	}

	double getPoint2Y() 
	{
		return _point2Y;
	}

	//if the point2Y value is  smaller than 0, point2Y value is assigned 0
	void setPoint2Y(double point2Y)  
	{
		if (point2Y >= 0)
		{
			_point2Y = point2Y;
		}
		else
		{
			_point2Y = 0;
			throw new  InvalidParameterException("Invalid point2Y Value assigned 0");
		}
	}

	double getPoint3X() 
	{
		return _point3X;
	}

	//if the point3X value is  smaller than 0, point3X value is assigned 0
	/**
     * setPoint3X
     * @exception InvalidParameterException
     */
	void setPoint3X(double point3X)  
	{
		if (point3X >= 0)
		{
			_point3X = point3X;
		}
		else
		{
			_point3X = 0;
			throw new  InvalidParameterException("Invalid point3X Value assigned 0");
		}
	}

	double getPoint3Y() 
	{
		return _point3Y;
	}

	//if the point3Y value is  smaller than 0, point3Y value is assigned 0
	void setPoint3Y(double point3Y)  
	{
		if (point3Y >= 0)
		{
			_point3Y = point3Y;
		}
		else
		{
			_point3Y = 0;
			throw new  InvalidParameterException("Invalid point3Y Value assigned 0");
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
	/**
     * setPosY
     * @exception InvalidParameterException
     */
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
	void setRotateAngle(double rotateAngle)  
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

	double getRotateY() 
	{
		return _rotateY;
	}

	//if the radius rotateY is 0 or  smaller than 0, rotateY value is assigned 0
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

	double getLength() 
	{
		return _length;
	}

	//area calculating
	public double area()
	{
		return ((getLength() * getLength() * Math.sqrt(3)) / 4);
	}

	//perimeter calculating
	public double perimeter()
	{
		return (getLength() * 3);
	}

	//if the length value is 0 or  smaller than 0, length value is assigned 1
	void setLength(double length)  
	{
		if (length > 0)
		{
			_length = length;
		}
		else
		{
			_length = 1;
			throw new  InvalidParameterException("Invalid length Value assigned 1");
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
