import java.awt.Graphics;
import javax.swing.JPanel;

/**
 * class Shape
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */

//interface
public abstract class Shape extends JPanel implements Comparable<Shape>  {
	
	public abstract double area();				  
	public abstract double perimeter();			  
		
	
	public abstract Shape increment();	
	public abstract Shape decrement(); 
	
	public abstract void draw(Graphics g);  
	
	
		@Override
	    public  int compareTo(Shape other) {
	        if (this.area() < other.area()) {
	            return -1;
	        }
	        if (this.area() == other.area()) {
	            return 0;
	        }
	        return 1;
	    }
		
		
	  

	
}
