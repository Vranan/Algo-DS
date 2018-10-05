#include <iostream>
#include <queue>
#include <vector>
#define dim1 25
#define dim2 25

using namespace std;

class node
{
    public:
        int x,y;	
        node(int x1,int y1) {x=x1;y=y1;}
};

int bfs(int x,int y,bool fill[][dim2])
{
    queue<node> gr;
    gr.push(node(x,y));
    int result = 0;
    while(gr.empty() == false)
    {
        node top = gr.front();
        gr.pop();
        if(top.x < 0 || top.x > dim1)
            continue;
        if(top.y < 0 || top.y > dim2)
            continue;
        if(fill[top.x][top.y])
            continue;

        fill[top.x][top.y] = 1;
        result++;
        gr.push(node(top.x + 1,top.y));
        gr.push(node(top.x - 1,top.y));
        gr.push(node(top.x,top.y + 1));
        gr.push(node(top.x,top.y - 1));
    }
    return result;
}

int main()
{
    int N=0,i=0,j=0;
    bool fill[dim1][dim2];
    for(i=0;i<dim1;i++)
    {
        for(j=0;j<dim2;j++)
            fill[i][j] = false;
    }

    for(i=10;i<15;i++)
    {
        for(j=0;j<25;j++)
            fill[j][i] = true;
    }

   /* for(i=0;i<dim1;i++)
    {
        for(j=0;j<dim2;j++)
            cout << fill[i][j];
        cout << endl;
    }*/

    cout << "Calling the bfs Function" << endl;
    vector<int> area;
    for(i=0;i<dim1;i++)
    {
        for(j=0;j<dim2;j++)
        {
            if(fill[i][j] == 0)
                  area.push_back(bfs(i,j,fill));
        }
    }
    for(vector<int>::iterator it = area.begin();it < area.end();it++)
            cout << *it << " ";
    cout << endl;


    /*for(i=0;i<dim1;i++)
    {
        for(j=0;j<dim2;j++)
            cout << fill[i][j];
        cout << endl;
    }*/

    return 0;

}
