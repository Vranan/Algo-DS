import java.util.ArrayList;
import java.util.Arrays;

public class BruteCollinearPoints {
    private ArrayList<LineSegment> arr = new ArrayList<LineSegment>();
    
    public BruteCollinearPoints(Point[] points) {
        if (points == null) throw new java.lang.IllegalArgumentException("The argument to the constructor is Null");
                
        int ptlen = points.length;
        for (int i = 0; i < ptlen; i++) {
            if (points[i] == null) throw new java.lang.IllegalArgumentException("Entry in the array is Null");
        }
        
        Point[] pt = Arrays.copyOf(points, points.length);
        Arrays.sort(pt);        
        for (int i = 1; i < ptlen; i++) {
        	if (pt[i].compareTo(pt[i - 1]) == 0) throw new java.lang.IllegalArgumentException("Points are repeated in the Array");
        }
        
        for (int i = 0; i < ptlen; i++) {
            for (int  j = i + 1; j < ptlen; j++) {
                for (int k = j + 1; k < ptlen; k++) {
                    for (int m = k + 1; m < ptlen; m++) {
                        if (pt[i].slopeTo(pt[j]) == pt[i].slopeTo(pt[k]) && pt[i].slopeTo(pt[j]) == pt[i].slopeTo(pt[m])) {
                            arr.add(new LineSegment(pt[i], pt[m]));
                        }
                    }     
                }
            }
        }
    }
    
    public int numberOfSegments() {          
        return arr.size();
    }
    
    public LineSegment[] segments() {
        LineSegment[] seg = new LineSegment[arr.size()];
        return arr.toArray(seg);
    }
    
    /* public static void main(String[] args) {
        
        // read the n points from a file
        In in = new In(args[0]);
        int n = in.readInt();
        System.out.println("n = " + n);
        Point[] points = new Point[n];
        for (int i = 0; i < n; i++) {
            int x = in.readInt();
            int y = in.readInt();
            System.out.println("x = " + x + ", y = " + y);
            points[i] = new Point(x, y);
        }
        
        // draw the points
        StdDraw.enableDoubleBuffering();
        StdDraw.setXscale(0, 32768);
        StdDraw.setYscale(0, 32768);
        for (Point p : points) {
            p.draw();
        }
        StdDraw.show();
        
        // print and draw the line segments
        FastCollinearPoints collinear = new FastCollinearPoints(points);
        for (LineSegment segment : collinear.segments()) {
            StdOut.println(segment);
            segment.draw();
        }
        StdDraw.show();
    } */
}