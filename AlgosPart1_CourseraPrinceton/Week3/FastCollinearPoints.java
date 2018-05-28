import java.util.ArrayList;
import java.util.Arrays;
// import "Point.java";
// import "LineSegment.java";

public class FastCollinearPoints {
    private ArrayList<LineSegment> segList = new ArrayList<>();
    
    public FastCollinearPoints(Point[] points) {     // finds all line segments containing 4 or more points
        if (points == null) throw new java.lang.IllegalArgumentException("Null arguments have been passed");
        
        for(int i = 0; i < points.length; i++)
            if (points[i] == null) throw new java.lang.IllegalArgumentException("Null Array Argument");
        
        Point[] pt = Arrays.copyOf(points, points.length);
        for (int i = 0; i < points.length; i++) {
            Point p = points[i];
            Arrays.sort(pt);
            Arrays.sort(pt, p.slopeOrder());
            
            int strt = 0;
            while ((strt < pt.length) && p.slopeTo(pt[strt]) == Double.NEGATIVE_INFINITY) strt++;
            
            if (strt != 1) throw new java.lang.IllegalArgumentException("Duplicated values are present");
            int end = strt;
            while (strt < pt.length) {
                while (end < pt.length && p.slopeTo(pt[end]) == p.slopeTo(pt[strt])) end++;
                if (end - strt >= 3) {
                    Point ptMin = p.compareTo(pt[strt]) < 0 ? p : pt[strt];
                    Point ptMax = p.compareTo(pt[end-1]) > 0 ? p : pt[end-1];
                    if (p == ptMin) {
                        segList.add(new LineSegment(ptMin, ptMax));
                    }
                }   
                strt = end;
            }
        }
    }
        
        public int numberOfSegments() {                           // the number of line segments
            return segList.size();
        }
        public LineSegment[] segments() {                         // the line segments
            LineSegment[] seg = new LineSegment[segList.size()];
            return segList.toArray(seg);
        }
        
       /* public static void main(String[] args) {
            
            // read the n points from a file
            In in = new In(args[0]);
            int n = in.readInt();
            // System.out.println("n = " + n);
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
            	// StdOut.println("point = " + p);
                p.draw();
            }
            StdDraw.show();
            
            // print and draw the line segments
            FastCollinearPoints collinear = new FastCollinearPoints(points);
            // LineSegment[] seg = collinear.segments();
            // StdOut.println("seg = " + seg);
            for (LineSegment segment : collinear.segments()) {
                // StdOut.println("Segment = " + segment);
                segment.draw();
            } 
            StdDraw.show();
        } */
    }
