import java.util.ArrayList;
import java.util.Arrays;
// import edu.princeton.cs.algs4.StdOut;
// import edu.princeton.cs.algs4.In;
// import edu.princeton.cs.algs4.StdDraw;

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
                    Point ptMax = p.compareTo(pt[end-1]) > 0 ? p : pt[end];
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
            Point[] points = new Point[n];
            for (int i = 0; i < n; i++) {
                int x = in.readInt();
                int y = in.readInt();
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
