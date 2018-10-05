public class WeightedQuickUnionUF {
    private int[] id;
    private int[] sz;
    private int array_size;
    public WeightedQuickUnionUF(int N)
    {
        array_size = N*N + 2;
        id = new int[array_size];
        sz = new int[array_size];
        for (int i = 0; i < array_size; i++)
        {
             id[i]=i;
             sz[i]=1;
        }
    }
    
    private int root(int p)
    {
        while (id[p] != p)
        {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    boolean connected(int p,int q)
    {
        return (root(p)==root(q));
    }
    
    void union(int p,int q)
    {
        int i = root(p);
        int j = root(q);
        if(i==j)
            return;
        if(sz[i]<sz[j])
        {
           id[i]=j;
           sz[j] += sz[i];
        }
         else
        {
           id[j]=i;
           sz[i] += sz[j];
        }
    }
}