#include<iostream>
#include<cmath>
using namespace std;

class DC
{
private:
    int *id;
public:
    int k,N;
    DC(int N1)
    {
        N = N1;
        k=pow(N,2);
        id = new int(k);
        for(int i=0;i<=(k-1);i++)
                id[i] = i;

        id[k] = k;
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

        if((0 <= pid) && (pid < (N-1)))
        {
            id[pid] = id[qid] = k;
            cout << p << " + " << q << endl;
        }
        else if((0 <= qid) && (qid <= N-1))
        {
            id[qid] = id[pid] = k;
            cout << q << " + " << p << endl;
        }
        else
        {
            id[pid] = root(qid);
            cout << p << " + " << q << endl;
        }
    }
};

int main()
{
    DC dc(4);
    dc.connect(5,0);
    dc.connect(8,5);
    dc.connect(9,8);
    dc.connect(6,9);
    dc.connect(11,6);
    dc.connect(10,11);
    dc.connect(13,10);

    if((dc.connected(16,15) == true) or (dc.connected(16,14) == true) or (dc.connected(16,13) == true) or (dc.connected(16,12) == true))
        cout << endl << "System Percolates" << endl;
    else
        cout << endl << "System does not percolate" << endl;

    return 0;
}

