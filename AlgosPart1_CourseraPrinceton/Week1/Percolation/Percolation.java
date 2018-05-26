import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {
    private boolean[][] grid;
    private int os = 0;
    private final int size;
    private final WeightedQuickUnionUF wq;
    private final WeightedQuickUnionUF wqbw;
    
    public Percolation(int n)                // create n-by-n grid, with all sites blocked
    {
       if (n <= 0)
       {
           throw new IllegalArgumentException(Integer.toString(n));
       }
       
       size = n;
       grid = new boolean[n+1][n+1];
       wq = new WeightedQuickUnionUF((size*size) + 2);
       wqbw = new WeightedQuickUnionUF((size*size) + 1);
       
       for (int i = 1; i <= n; i++)
       {
           for (int j = 1; j <= n; j++)
               grid[i][j] = false;
       }
    }
    
    public void open(int row, int col)    // open site (row, col) if it is not open already
    {
       
       if (row > size || col > size || row <= 0 || col <= 0) {
           throw new IllegalArgumentException(Integer.toString(row) + ", " + Integer.toString(col));
       }
        
       if (isOpen(row, col)) {
           return;
       }
       
       grid[row][col] = true;
       os++;
        
        if (row-1 >= 1)
        {
        if (isOpen(row-1, col)) {
          wq.union((size*(row-1-1))+col, (size*(row-1)+col));
          wqbw.union((size*(row-1-1))+col, (size*(row-1)+col));
        }
        }
        
        if (row+1 <= size)
        {
        if (isOpen(row+1, col)) {
          wq.union((size*(row-1+1))+col, (size*(row-1)+col)); 
          wqbw.union((size*(row-1+1))+col, (size*(row-1)+col));
        }
        }
        
        if (col-1 >= 1)
        {
        if (isOpen(row, col-1)) {
          wq.union((size*(row-1)) + (col-1), (size*(row-1) + col));
          wqbw.union((size*(row-1)) + (col-1), (size*(row-1) + col));
        }
        }
        
        if (col+1 <= size)
        {
        if (isOpen(row, col+1)) {
          wq.union((size*(row-1))+(col)+1, (size*(row-1) + col));
          wqbw.union((size*(row-1))+(col)+1, (size*(row-1) + col));
        }
        }
        
        if (row == 1) {
            wq.union(0, (size*(row-1))+col);
            wqbw.union(0, (size*(row-1))+col);
        }
        
        if (row == size) {
            wq.union((size*size)+1, (size*(row-1))+col);
        }
   }
    
   public boolean isOpen(int row, int col)          // is site (row, col) open?
   {
       if (row <= 0 || col <= 0 || row > size || col > size) 
       {
           throw new IllegalArgumentException(Integer.toString(row) + ", " + Integer.toString(col));
       }
       
       return(grid[row][col]);
   }
   
   public boolean isFull(int row, int col)          // is site (row, col) full?
   {
       if (row <= 0 || col <= 0 || row > size || col > size) 
       {
           throw new IllegalArgumentException(Integer.toString(row) + ", " + Integer.toString(col));
       }
       
       if (isOpen(row, col))
       {
          if (wqbw.connected(0, (size*(row - 1)) + col))
              return true;
       }
       
       return false;
   }
   
   public int numberOfOpenSites()           // number of open sites
   {   
       return os;
   }
   
   public boolean percolates()                    // does the system percolate?
   {
       return (wq.connected(0, (size*size)+1));
   }

    /* public static void main(String[] args)         // test client (optional)
   {
       int N = 4;
       Percolation pr = new Percolation(N);
           pr.open(1,2);
           pr.open(1,3);
           pr.open(2,3);
           pr.open(2,4);
           pr.open(3,1);
           pr.open(3,2);
           pr.open(3,3);
           pr.open(4,2);
        if(pr.percolates())
           System.out.println("Percolates");
        else
           System.out.println("Does not Percolate");
        System.out.println("Open sites = " + pr.numberOfOpenSites());
   } */
}