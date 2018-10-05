import edu.princeton.cs.algs4.StdDraw;
import java.util.Comparator;

/**
 * @author nxa27422
 *
 */
/**
 * @author nxa27422
 *
 */
public class Point implements Comparable<Point> {
    private int x;
    private int y;
    
    public Point(int x, int y) {                         // constructs the point (x, y)        
        this.x = x;
        this.y = y;
    }
    
    public void draw() {
        StdDraw.point(x, y);
    }
    
    public void drawTo(Point that) {
        StdDraw.line(this.x, this.y, that.x, that.y);
    }
    
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
    
    public int compareTo(Point that)  {       // compare two points by y-coordinates, breaking ties by x-coordinates
        if (that == null) throw new java.lang.NullPointerException();
        
        if (this.y == that.y) return (this.x - that.x);
        return (this.y - that.y);
    }
    public double slopeTo(Point that) {         // the slope between this point and that point
        if (that == null) throw new java.lang.NullPointerException();        
        if (that.y == this.y && that.x == this.x) return Double.NEGATIVE_INFINITY;
        if (that.x == this.x) return Double.POSITIVE_INFINITY;
        if (that.y == this.y) return +0.0;
        
        return (double) (that.y - this.y)/ (that.x - this.x);
    }
    public Comparator<Point> slopeOrder() { // compare two points by slopes they make with this point
        return new Comparator<Point>() {
            public int compare(Point o1, Point o2) {
                double val = slopeTo(o1) - slopeTo(o2);
                if (val > 0) return 1;
                else if (val < 0) { return -1; }
                else return 0;
            }
        };
    }
  
    /* public static void main(String[] args) {
        Point p1 = new Point(1, 2);
        Point p2 = new Point(1000, 20000);
        Point p3 = new Point(500, 1000);
        Point p4 = new Point(8000, 10000);
        
        System.out.println(p1.toString());
        System.out.println(p1.compareTo(p2));
        System.out.println("slope = " + p1.slopeTo(p2));
        // pt.draw();
        
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        p1.draw();
        p2.draw();
        p3.draw();
        p4.draw();
        StdDraw.show();        
    } */
}