import edu.princeton.cs.algs4.StdDraw;
import java.util.Comparator;

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
    
    public static void main(String[] args) {
        int x1 = 1;
        int y1 = 2;
        int x2 = 30000;
        int y2 = 40000;
        Point pt = new Point(x1, y1);
        Point p = new Point(x2, y2);
        
        System.out.println(pt.toString());
        System.out.println(pt.compareTo(p));
        System.out.println("slope = " + pt.slopeTo(p));
        // pt.draw();
        
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        pt.drawTo(p);
        StdDraw.show();        
    }
}