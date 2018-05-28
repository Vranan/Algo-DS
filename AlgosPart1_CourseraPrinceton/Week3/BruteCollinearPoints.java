import java.util.ArrayList;
import java.util.Arrays;

public class BruteCollinearPoints {
    private ArrayList<LineSegment> arr = new ArrayList<LineSegment>();
    
    public BruteCollinearPoints(Point[] points) {
        if (points == null) throw new java.lang.IllegalArgumentException("The argument to the constructor is Null");
        Point[] pt = Arrays.copyOf(points, points.length);
        Arrays.sort(pt);
        
        int ptlen = pt.length;
        if (pt[0] == null) throw new java.lang.IllegalArgumentException("Entry in the array is Null");
        for (int i = 1; i < ptlen; i++) {
            if (pt[i] == null) throw new java.lang.IllegalArgumentException("Entry in the array is Null");
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
}