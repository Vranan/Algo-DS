#include <iostream>
using namespace std;

class UF
{
  private:
    int *id;
  public:
    UF(int N)
    {
        id = new int[N];
        for(int i=0;i<N;i++)
            id[i]=i;
    }
  private:
	int root(int p)
    {
        int i = p;
        while(i != id[i])
            i = id[i];
        return i;    
    }
  public:	
    bool connected(int p,int q)
        { return(root(p)==root(q));}
    void unionfind(int p,int q)
    {
        int pid = root(p);
        int qid = root(q);
        if(!connected(p,q))
            id[p] = qid;
    }
    
};


int main()
{
    int N;
    cin >> N;
    UF uf(N);
    uf.unionfind(1,2);
    uf.unionfind(2,3);
    uf.unionfind(1,3);
    uf.unionfind(4,5);
    if(uf.connected(1,5))
        cout << "1 is connected to 5 " << endl;
    else
        cout << "1 is not connected to 5 " << endl;
    if(uf.connected(1,3))
        cout << "1 is connected to 3 " << endl;
    else
        cout << "1 is not connected to 3 " << endl;
}
