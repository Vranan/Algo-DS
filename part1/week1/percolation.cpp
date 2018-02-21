#include<iostream>
#include<cmath>
using namespace std;

class DC
{
private:
    int *sz;
    int *id;
public:
    int k,N;
    DC(int N)
    {
        k=pow(N,2);
        //cout << "k = " << k << endl;
        //sz = new int(k-1);
        id = new int(k+1);
        //cout << "sz = " << sz << ", id = " << id << endl;
        for(int i=0;i<=(k-1);i++)
        {
            id[i] = i;
            //sz[i] = 1;
            //cout << "i = " << i << ", id[" << i << "] = " << id[i] << endl;
        }
        id[k] = k;
        id[k+1] = k+1;
    }

    int root(int p)
    {
        //cout << "inside root p = " << p << ", id[" << p << "] = " << id[p] << endl;
        while(id[p] != p)
            p = id[p];

        //cout << "Inside root p = " << p << endl;
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
        //cout << "p = " << p << ", pid = " << pid << " -- q = " << q << ", qid = " << qid << endl;
        if(pid==qid)
            return;
        if( 0 <= pid <= N-1)
        {
            id[pid] = id[qid] = root(k);
            cout << p << " + " << q << endl;
        }
        else if( 0 <= qid <= N-1)
        {
            id[qid] = id[pid] = root(k);
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
    //int N = 4;
    DC dc(4);
    dc.connect(5,0);
    dc.connect(8,5);
    dc.connect(9,8);
    dc.connect(6,9);
    dc.connect(11,6);
    dc.connect(10,11);
    dc.connect(13,10);

    if((dc.connected(16,15) == true) or (dc.connected(16,14) == true) or (dc.connected(16,13) == true) or (dc.connected(16,12) == true))
        cout << endl << "System percolates" << endl;
    else
        cout << endl << "System does not percolate" << endl;

}
