import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.Path2D;
import java.util.ArrayList;
/**
 * class PolygonDyn
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */
public class PolygonDyn extends Polygon {

	private Point2D[] _points = new Point2D[100];//default 100 points
	
	PolygonDyn() {
	}
	
	PolygonDyn(ArrayList<Point2D> vectPoint) {
		//assign class member value
		setPointCount(vectPoint.size());
		setColor("white");
		setRotateAngle(0);
		setRotateX(0);
		setRotateY(0);
		
		for (int i = 0; i < getPointCount(); i++) {
			_points[i]=new Point2D();
		}

		for (int i = 0; i < getPointCount(); ++i)
		{
			_points[i]=vectPoint.get(i);
		}

		setArea(0);		 // not calculated
		setPerimeter(0); // not calculated
	}
	
	PolygonDyn(Rectangle rect) {
		//assign class member value
		setPointCount(4);
		
		setColor(rect.getColor());
		setRotateAngle(rect.getRotateAngle());
		setRotateX(rect.getRotateX());
		setRotateY(rect.getRotateY());
		
		for (int i = 0; i < getPointCount(); i++) {
			_points[i]=new Point2D();
		}
		
		_points[0].setX(rect.getPosX() + rect.xGet());
		_points[0].setY(rect.getPosY() + rect.yGet());

		_points[1].setX(rect.getPosX() + rect.xGet());
		_points[1].setY(rect.getPosY() + rect.heightGet() + rect.yGet());

		_points[2].setX(rect.getPosX() + rect.widthGet() + rect.xGet());
		_points[2].setY(rect.getPosY() + rect.heightGet() + rect.yGet());

		_points[3].setX(rect.getPosX() + rect.widthGet() + rect.xGet());
		_points[3].setY(rect.getPosY() + rect.yGet());

		setArea(rect.area());
		setPerimeter(rect.perimeter());
	}
	
	PolygonDyn(Circle circ) {
		//assign class member value
int side = 100; //circle represented side value 100 default value
setPointCount(side);
setColor(circ.getColor());
setRotateAngle(circ.getRotateAngle());
setRotateX(circ.getRotateX());
setRotateY(circ.getRotateY());

double angle = (2 * Math.PI) / side;

for (int i = 0; i < getPointCount(); i++) {
	_points[i]=new Point2D();
}

for (int i = 0; i < side; ++i)
{
	_points[i].setX(circ.getPosX() + circ.getRadius() * Math.cos(angle * i));
	_points[i].setY(circ.getPosY() - circ.getRadius() * Math.sin(angle * i));
}

setArea(circ.area());
setPerimeter(circ.perimeter());
	}
	
	PolygonDyn(Triangle trig) {

		
		setPointCount(3);
		setColor(trig.getColor());
		setRotateAngle(trig.getRotateAngle());
		setRotateX(trig.getRotateX());
		setRotateY(trig.getRotateY());
		
		for (int i = 0; i < getPointCount(); i++) {
			_points[i]=new Point2D();
		}

		_points[0].setX(trig.getPoint1X() + trig.getPosX());
		_points[0].setY(trig.getPoint1Y() + trig.getPosY());

		_points[1].setX(trig.getPoint2X() + trig.getPosX());
		_points[1].setY(trig.getPoint2Y() + trig.getPosY());

		_points[2].setX(trig.getPoint3X() + trig.getPosX());
		_points[2].setY(trig.getPoint3Y() + trig.getPosY());

		setArea(trig.area());
		setPerimeter(trig.perimeter());
	}
	
	PolygonDyn(Point2D point2d) {
		setPointCount(1);
		setColor("white");
		setRotateAngle(0);
		setRotateX(0);
		setRotateY(0);
		for (int i = 0; i < getPointCount(); i++) {
			_points[i]=new Point2D();
		}
		_points[0]=point2d;

		setArea(0);
		setPerimeter(0);
	}
	
	 public double area() {
		 return (getArea());
	}
	 public double perimeter() {
		 return (getPerimeter());
	}
	
	 public Shape increment() {
		 for (int i = 0; i < getPointCount(); ++i)
			{
			 _points[i].setX(_points[i].getX() + 1.0);
			 _points[i].setY(_points[i].getY() + 1.0);
			}

			return this;
	}
	 public Shape decrement() {
		 for (int i = 0; i < getPointCount(); ++i)
			{
			 _points[i].setX(_points[i].getX() - 1.0);
			 _points[i].setY(_points[i].getY() - 1.0);
			}

			return this;
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
	    
	    Path2D.Double t=new Path2D.Double();
	    
	    t.moveTo(_points[0].getX(), _points[0].getY());
	    for (int i = 1; i < getPointCount(); ++i)
	 	{
	 		t.lineTo(_points[i].getX(), _points[i].getY());
	 	}
	    
	    t.closePath();
	   
		    g.rotate(getRotateAngle(),getRotateX(),getRotateY());
		    g.setColor(Color.black);
	    	g.draw(t);
	    	g.setColor(Color.decode(getColor()));
		    g.fill(t);
		    
	}
}
