#include<bits/stdc++.h>
using namespace std;

typedef long long int64;
vector< pair<int,int> > myvec[100001];
int64 dist[100001];
set< pair<int,int64> > myset;
int pred[100001];
stack<int> mystack;
int n,m;

int djikstra(int src)
{
    myset.insert(make_pair(0,src));
    for( int i = 1 ; i<= n ; i++ )
        dist[i] = 1e18;
    pred[src]=1;
    dist[src]=0;
    
    while(!myset.empty())
    {
        pair<int,int> tmp=*(myset.begin());
        myset.erase(myset.begin());
        int u=tmp.second;
        if( dist[u] < tmp.first )
            continue;
        vector< pair<int,int> >::iterator it;
        for(it=myvec[u].begin(); it!=myvec[u].end(); it++)
        {
            int vertex=(*it).first;
            int weight=(*it).second;
            
            if(dist[vertex]>dist[u]+weight)
            {
                    
                    dist[vertex]=dist[u]+weight;
                    myset.insert(make_pair(dist[vertex],vertex));
                    pred[vertex]=u;         
                
            }
        }   
        
    }
    if(pred[n]==0)
    {
        cout<<-1;
        return 0;
    }
    int f=n;
    mystack.push(n);
    
    while(f!=1)
    {
        int t=pred[f];
        f=t;
        mystack.push(t);
    }

    
        while (!mystack.empty()) {
        
        cout<<mystack.top()<<" ";
        mystack.pop();
    }
    return 0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    int u,v,w;
    vector< pair<int,int> >::iterator itr;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        myvec[u].push_back(make_pair(v,w));
        myvec[v].push_back(make_pair(u,w));
        
    }
    djikstra(1);
    return 0;
}