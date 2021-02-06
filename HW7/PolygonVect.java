import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.Path2D;
import java.util.ArrayList;

/**
 * class PolygonVect
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */

public class PolygonVect extends Polygon {
	
private ArrayList<Point2D> _points= new ArrayList<Point2D>();
	
	PolygonVect() {
	}
	
	PolygonVect(ArrayList<Point2D> vectPoint) {
		//assign class member value
		setPointCount(vectPoint.size());
		setColor("white");
		setRotateAngle(0);
		setRotateX(0);
		setRotateY(0);
		

		for (int i = 0; i < getPointCount(); ++i)
		{
			_points.add(vectPoint.get(i));
		}

		setArea(0);		 // not calculated
		setPerimeter(0); // not calculated
	}
	
	PolygonVect(Rectangle rect) {
		//assign class member value
		setPointCount(4);
		
		setColor(rect.getColor());
		setRotateAngle(rect.getRotateAngle());
		setRotateX(rect.getRotateX());
		setRotateY(rect.getRotateY());
		
		_points.add(new Point2D(rect.getPosX() + rect.xGet(),rect.getPosY() + rect.yGet()));
		
		_points.add(new Point2D(rect.getPosX() + rect.xGet(),rect.getPosY() + rect.heightGet() + rect.yGet()));
		
		_points.add(new Point2D(rect.getPosX() + rect.widthGet() + rect.xGet(),rect.getPosY() + rect.heightGet() + rect.yGet()));
	
		_points.add(new Point2D(rect.getPosX() + rect.widthGet() + rect.xGet(),rect.getPosY() + rect.yGet()));
		

		setArea(rect.area());
		setPerimeter(rect.perimeter());
	}
	
	PolygonVect(Circle circ) {
		//assign class member value
int side = 100; //circle represented side value 100 default value
setPointCount(side);
setColor(circ.getColor());
setRotateAngle(circ.getRotateAngle());
setRotateX(circ.getRotateX());
setRotateY(circ.getRotateY());

double angle = (2 * Math.PI) / side;



for (int i = 0; i < side; ++i)
{
	_points.add(new Point2D(circ.getPosX() + circ.getRadius() * Math.cos(angle * i),circ.getPosY() - circ.getRadius() * Math.sin(angle * i)));
}

setArea(circ.area());
setPerimeter(circ.perimeter());
	}
	
	PolygonVect(Triangle trig) {

		
		setPointCount(3);
		setColor(trig.getColor());
		setRotateAngle(trig.getRotateAngle());
		setRotateX(trig.getRotateX());
		setRotateY(trig.getRotateY());
		
		
		_points.add(new Point2D(trig.getPoint1X() + trig.getPosX(),trig.getPoint1Y() + trig.getPosY()));
		
		
		_points.add(new Point2D(trig.getPoint2X() + trig.getPosX(),trig.getPoint2Y() + trig.getPosY()));
		
		
		_points.add(new Point2D(trig.getPoint3X() + trig.getPosX(),trig.getPoint3Y() + trig.getPosY()));
		

		setArea(trig.area());
		setPerimeter(trig.perimeter());
	}
	
	PolygonVect(Point2D point2d) {
		setPointCount(1);
		setColor("white");
		setRotateAngle(0);
		setRotateX(0);
		setRotateY(0);
		
		_points.add(new Point2D(point2d.getX(),point2d.getY()));
		

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
			 _points.get(i).setX(_points.get(i).getX() + 1.0);
			 _points.get(i).setY(_points.get(i).getY() + 1.0);
			}

			return this;
	}
	 public Shape decrement() {
		 for (int i = 0; i < getPointCount(); ++i)
			{
			 _points.get(i).setX(_points.get(i).getX() - 1.0);
			 _points.get(i).setY(_points.get(i).getY() - 1.0);
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
	    
	    t.moveTo(_points.get(0).getX(), _points.get(0).getY());
	    for (int i = 1; i < getPointCount(); ++i)
	 	{
	 		t.lineTo(_points.get(i).getX(), _points.get(i).getY());
	 	}
	    
	    t.closePath();
	   
		    g.rotate(getRotateAngle(),getRotateX(),getRotateY());
		    g.setColor(Color.black);
	    	g.draw(t);
	    	g.setColor(Color.decode(getColor()));
		    g.fill(t);
		    
	}
}
