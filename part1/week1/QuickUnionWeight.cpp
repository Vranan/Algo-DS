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
            sz[i] = 1;
        }
    }
    int root(int p)
    {
        while(id[p] != p)
            p = id[p];
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
    int N;
    cin >> N;
    UF uf(N);
    uf.connect(1,2);
    uf.connect(2,3);
    uf.connect(1,3);
    uf.connect(4,0);
    if(uf.connected(1,0))
        cout << "1 is connected to 0 " << endl;
    else
        cout << "1 is not connected to 0 " << endl;
    if(uf.connected(1,3))
        cout << "1 is connected to 3 " << endl;
    else
        cout << "1 is not connected to 3 " << endl;
}
