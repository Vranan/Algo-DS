import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {
    private static final double CONS = 1.96;
    private final double[] prct;
    private final double mv;
    private final double stdv;
    private final double lo;
    private final double hi;
    
   public PercolationStats(int n, int trials)
   {
       if (n <= 0 || trials <= 0)
       {
           throw new IllegalArgumentException("n = " + Integer.toString(n) + ", trials = " + Integer.toString(trials));
       }
       
       prct = new double[trials];
       for (int i = 0; i < trials; i++)
       {
           int r, c; 
           Percolation pr = new Percolation(n);
           while (!pr.percolates())
           {
               r = StdRandom.uniform(1, n+1);
               c = StdRandom.uniform(1, n+1);
               pr.open(r, c);
           }
           double ops = pr.numberOfOpenSites();
           prct[i] = ops/(n*n);
       }
       mv = StdStats.mean(prct); 
       stdv = StdStats.stddev(prct);
       double ls = Math.sqrt(prct.length);
       lo = mv - (CONS*stdv)/ls;
       hi = mv + (CONS*stdv)/ls;
           
   }
   public double mean()
   {       
       return mv;
   }
   
   public double stddev()
   {
       return stdv;
   }
       
   public double confidenceLo()
   {
       return lo;
   }
   
   public double confidenceHi()
   {
       return hi; 
   }

   public static void main(String[] args) 
   {  
       PercolationStats ps = new PercolationStats(Integer.parseInt(args[0]), Integer.parseInt(args[1]));
       System.out.println("mean                    = " + ps.mean());
       System.out.println("standard deviation      = " + ps.stddev());
       System.out.println("95% Confidence interval = [" + ps.confidenceLo() + ", " + ps.confidenceHi() + "]");
   }
}