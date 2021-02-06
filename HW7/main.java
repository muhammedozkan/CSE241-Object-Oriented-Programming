import javax.swing.JFrame;
/**
 * class main
 *
 * @author MuhammedOZKAN 151044084 @pithblood
 * @version 1.0.0
 * @since  2019
 */

public class main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//Test Code
		try {
			Rectangle rc=new Rectangle("0xF00000",400,600);
			Rectangle rc1=new Rectangle("0x00F000",45,50);
			rc.increment();
			rc.increment();
			rc.increment();
			rc.increment();
			rc.decrement();
			
			Circle cr=new Circle("0xF00000",300);
			Circle cr1=new Circle("0x00F000",39);
			cr.increment();
			cr.increment();
			cr.increment();
			cr.increment();
			cr.decrement();
			
			Triangle tr=new Triangle("0xF00000",300);
			Triangle tr1=new Triangle("0x00F000",39);
			tr.increment();
			tr.increment();
			tr.increment();
			tr.increment();
			tr.decrement();
			
			
			PolygonDyn plydyn =new PolygonDyn(cr);
			plydyn.increment();
			plydyn.increment();
			plydyn.increment();
			plydyn.increment();
			plydyn.decrement();
			
			PolygonVect plyvect=new PolygonVect(cr);
			
			plyvect.increment();
			plyvect.increment();
			plyvect.increment();
			plyvect.increment();
			plyvect.decrement();
			
			ComposedShape cmp=new ComposedShape( rc, rc1);
			ComposedShape cmp1=new ComposedShape( rc, cr1);
			ComposedShape cmp2=new ComposedShape( rc, tr1);
			ComposedShape cmp3=new ComposedShape( cr, rc1);
			ComposedShape cmp4=new ComposedShape( cr, cr1);
			ComposedShape cmp5=new ComposedShape( cr, tr1);
			ComposedShape cmp6=new ComposedShape( tr, rc1);
			ComposedShape cmp7=new ComposedShape( tr, cr1);
			ComposedShape cmp8=new ComposedShape( tr, tr1);
			
			cmp1.increment();
			cmp1.increment();
			cmp1.increment();
			cmp1.increment();
			cmp1.increment();
			cmp1.decrement();
			
			
			System.out.println("Main Shape Area= "+rc.area());
		    System.out.println("Main Shape Perimeter= "+rc.perimeter());
		    
		    System.out.println("Static Rectangle Area= "+Rectangle.getTotalAreas());
		    System.out.println("Static Rectangle Perimeter= "+Rectangle.getTotalPerimeters());
		    
		    System.out.println("Small Shape Area= "+cr1.area());
		    System.out.println("Small Shape Perimeter= "+cr1.perimeter());
		    
		    System.out.println("Static Circle Area= "+Circle.getTotalAreas());
		    System.out.println("Static Circle Perimeter= "+Circle.getTotalPerimeters());
		    
		    System.out.println("Composed Shape Area= "+cmp.area());
		    System.out.println("Composed Shape Perimeter= "+cmp.perimeter());
		    System.out.println("Composed Shape Empty Area= "+cmp.getEmptyArea());
		    System.out.println("Composed Shape Object Count= "+cmp.getObjectCount());
			
			
		///*
		JFrame.setDefaultLookAndFeelDecorated(true);
		JFrame f = new JFrame();
		
	    f.setSize(900, 900);
	    f.setTitle("Homework7");
	    f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	    f.setContentPane(cmp1);
	    f.setVisible(true);
		//*/
		
	    //to test all global functions 
		/*GlobalFunctions.drawAll(GlobalFunctions.convertAll(cmp1.shaperef));//if you are running this blog, you must make a comment line above(// // between) this block.
		GlobalFunctions.sortShapes(cmp1.shaperef);*/
		
	    
	    
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}
		
		
    
	
	
    
	}

}
