import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.Ellipse2D;
import java.security.InvalidParameterException;

/**
 * class Circle
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */
 
public class Circle  extends Shape{
	private static double _totalAreas;
	private static double _totalPerimeters;

	private double _posX;
	private double _posY;
	private double _radius;
	private String _color;
	private double _rotateAngle;
	private double _rotateX;
	private double _rotateY;
	
	Circle()
	{
	}

	//Constructor ex: Circle(color,radius)
	/**
     * Constructor Rectangle
     * @param color String
     * @param radius Double
     * @return Shape[]
     */
	Circle(String color, double radius)
	{ //assign class member value
		setPosX(radius);
		setPosY(radius);
		setRadius(radius);
		setColor(color);
		setRotateAngle(0);
		setRotateX(0);
		setRotateY(0);
		setTotalAreas(area());
		setTotalPerimeters(perimeter());
	}

	//Constructor ex: Circle(posX,posY,radius,color,rotateAngle,rotateX,rotateY)
	Circle(double posX, double posY, double radius, String color,
				   double rotateAngle, double rotateX, double rotateY)
	{ //assign class member value
		setPosX(posX);
		setPosY(posY);
		setRadius(radius);
		setColor(color);
		setRotateAngle(rotateAngle);
		setRotateX(rotateX);
		setRotateY(rotateY);

		//draw position assignment
		if (_posX < _radius)
		{
			setPosX(_radius);
		}
		if (_posY < _radius)
		{
			setPosY(_radius);
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
		Shape shp = new Circle(getPosX(), getPosY(), getRadius(), getColor(), getRotateAngle(), getRotateX(), getRotateY());

		return shp;
	}
	
	
	public Shape decrement()
	{
		setPosX(getPosX() - 1.0);
		setPosY(getPosY() - 1.0);
		setRotateX(getRotateX() - 1.0);
		setRotateY(getRotateY() - 1.0);
		Shape shp = new Circle(getPosX(), getPosY(), getRadius(), getColor(), getRotateAngle(), getRotateX(), getRotateY());
		return shp;
	}
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
	    draw(g);
	}
	
	
	
	public void draw(Graphics gg)  {
		
		 Graphics2D g = (Graphics2D) gg;
		 
		g.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
	    g.setRenderingHint(RenderingHints.KEY_STROKE_CONTROL, RenderingHints.VALUE_STROKE_PURE);
	    
	    Ellipse2D.Double c=new Ellipse2D.Double(getPosX()-getRadius(),getPosY()-getRadius(),getRadius()*2,getRadius()*2);
	   
		    g.rotate(Math.toRadians(getRotateAngle()),getRotateX(),getRotateY());
		    g.setColor(Color.black);
	    	g.draw(c);
	    	g.setColor(Color.decode(getColor()));
		    g.fill(c);
		    
	}
	
	String getColor()
	{
		return _color;
	}

	void setColor(String color)
	{
		_color = color;
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

	double getRadius() 
	{
		return _radius;
	}

	//if the radius value is 0 or  smaller than 0, radius value is assigned 1
	void setRadius(double radius)  
	{
		if (radius > 0)
		{
			_radius = radius;
		}
		else
		{
			_radius = 1;
			throw new  InvalidParameterException("Invalid radius Value assigned 1");
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

	//area calculating
	public double area()
	{
		return (Math.PI * _radius * _radius);
	}

	//perimeter calculating
	public double perimeter()
	{
		return (2 * Math.PI  * getRadius());
	}

	//if the radius rotateY is 0 or  smaller than 0, rotateY value is assigned 0
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
