public class QuickUnionImprovementsPathCompressionUF
{
    private int[] id;
    private int[] sz;
    public QuickUnionImprovementsUF(int N)
    {
        id = new int[N];
        sz = new int[N];
        for(int i=0;i<N;i++)
        {
            id[i]=i;
            sz[i]=1;
        }
    }
    
    private int root(int p)
    {
        while(id[p]!=p)
        {
            id[p] = id[id[p]];
            p = id[p];
        }
        return p;
    }
    boolean connected(int p,int q)
        return (root(p)==root(q));
    
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