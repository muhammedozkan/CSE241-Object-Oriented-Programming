import java.awt.Graphics;
import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * class GlobalFunctions
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */

 public class GlobalFunctions{
	/**
     * drawAll
     * @param shape array
     *
     */
	public static void drawAll(Shape[] shape)
	{
		
		JFrame f = new JFrame();
		JPanel jp=new JPanel();
		
	    f.setSize(900, 900);
	    f.setTitle("Homework7 drawAll");
	    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    
	    
	    f.setVisible(true);
	    f.removeAll();
	    
	    Graphics gp=f.getGraphics();
	   
	    for (int i = 0; i < shape.length; i++) {
		shape[i].draw(gp);
		
		}
	    
	    f.repaint();
	    
	    
	  
	  
	}
	/**
     * convertAll convert shape elements polygon
     * @param shape array
     *
     * @return Shape[]
     */
	public static Shape[] convertAll(Shape[] shape)
	{
		
		Shape[] newshp=new Shape[shape.length];

		for (int i=0;i<shape.length;++i)
		{
			if (shape[i].getClass().getName() == Rectangle.class.getName())
			{
				newshp[i]=new PolygonDyn((Rectangle)shape[i]);
			}
			else if (shape[i].getClass().getName() == Circle.class.getName())
			{
				newshp[i]=new PolygonDyn((Circle)shape[i]);
			}
			else if (shape[i].getClass().getName() == Triangle.class.getName())
			{
				newshp[i]=new PolygonDyn((Triangle)shape[i]);
			}
			else if (shape[i].getClass().getName() == PolygonDyn.class.getName() || shape[i].getClass().getName() == PolygonVect.class.getName())
			{
				newshp[i]=shape[i];
			}
		}
		return newshp;
		
	}
	/**
     * sortShapes sorting shape ref
     * @param shape array
     *
     */
	public static void sortShapes(Shape[] shape)
	{
		
		Shape tmp;

		for (int i = 1; i < shape.length; ++i)
			for (int j = shape.length - 1; j >= i; --j)
				if (shape[j - 1].area() > shape[j].area())
				{
					tmp = shape[j - 1];
					shape[j - 1] = shape[j];
					shape[j] = tmp;
				}
		
	}

}
