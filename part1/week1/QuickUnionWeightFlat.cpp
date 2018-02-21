#include <iostream>
using namespace std;

class UF
{
private:
    int *id;
    int *sz;
public:
    UF(int N)
    {
        id = new int[N];
        sz = new int[N];
        for(int i=0;i<N;i++)
        {
            id[i]=i;
            sz[i]=1;
        }
    }
    int root(int p)
    {
        while(id[p] != p)
            {
                id[p] = id[id[p]];
                p = id[p];

            }
        return(p);

    }
    bool connected(int p,int q)
    {
        return(root(p)==root(q));
    }
    void connect(int p,int q)
    {
        int pid = root(p);
        int qid = root(q);
        if(pid==qid)
            return;

          if(sz[pid]<sz[qid])
            {
                id[pid]=qid;
                sz[qid]=sz[pid]+sz[qid];
            }
          else
            {
                id[qid]=pid;
                sz[pid]=sz[qid]+sz[pid];
            }

     }
};

int main()
{
    int N=5;
    //cin >> N;
    UF uf(N);
    uf.connect(0,1);
    uf.connect(1,2);
    uf.connect(0,2);
    uf.connect(3,4);
    if(uf.connected(0,4))
        cout << "0 is connected to 4 " << endl;
    else
        cout << "0 is not connected to 4 " << endl;
    if(uf.connected(0,2))
        cout << "0 is connected to 2 " << endl;
    else
        cout << "0 is not connected to 2 " << endl;
}
