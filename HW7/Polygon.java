import java.security.InvalidParameterException;
/**
 * class Polygon
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */
 
public abstract class Polygon extends Shape{
	
	public class Point2D
	{
		
		//Constructor initialize
		Point2D()
		{
		}
		
		//Constructor ex: Point2D(x,y)
		Point2D(double x, double y)
		{ //assign class member value
			setX(x);
			setY(y);
		}

		public double getX() 
		{
			return _x;
		}
		/**
		* setX
		* @exception InvalidParameterException
		*/
		public void setX(double x)  
		{
			if (x >= 0)
			{
				_x = x;
			}
			else
			{
				_x = 0;
				throw new  InvalidParameterException("Invalid Point2D X Value assigned 0");
			}
		}
		
		public double getY() 
		{
			return _y;
		}

		public void setY(double y) 
		{
			if (y >= 0)
			{
				_y = y;
			}
			else
			{
				_y = 0;
				throw new  InvalidParameterException("Invalid Point2D Y Value assigned 0");
			}
		}
		//private members
	  
		private double _x;
		private double _y;
	}
	
	abstract public double area();
	abstract public double perimeter();
	
	abstract public Shape increment();
	abstract public Shape decrement();
	
	
	
	protected	int _pointCount;
	protected	String _color;
	protected	double _area;
	protected	double _perimeter;
	protected	double _rotateAngle;
	protected	double _rotateX;
	protected	double _rotateY;
	
	protected void setPointCount(int pointCount) {
		_pointCount = pointCount;
	}
	
	String getColor() {
		return _color;
	}
	void setColor(String color) {
		_color = color;
	}
	double getRotateAngle() {
		return _rotateAngle;
	}
	void setRotateAngle(double rotateAngle) {
		_rotateAngle = rotateAngle;
	}
	double getRotateX() {
		return _rotateX;
	}
	void setRotateX(double rotateX) {
		_rotateX = rotateX;
	}
	double getRotateY() {
		return _rotateY;
	}
	void setRotateY(double rotateY) {
		_rotateY = rotateY;
	}

	void setArea(double area) {
		_area = area;
	}
	void setPerimeter(double perimeter) {
		_perimeter = perimeter;
	}
	double getArea() {
		return _area;
	}
	double getPerimeter() {
		return _perimeter;
	}
	int getPointCount() {
		return _pointCount;
	}

}
