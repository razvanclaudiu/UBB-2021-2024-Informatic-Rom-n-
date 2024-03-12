#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main()
{
    char graf[20];
    cin>>graf;
    strcat(graf,".txt");
    ifstream in(graf);
    int a[100][100], nr, x, y, l[100], p[100], u[100], u1;
    in>>nr;
    while(in>>x>>y)
    {
        a[x][y] = 1;
        a[y][x] = 1;
    }
    cout<<"Selecatati nodul sursa: ";
    cin>>u1;
    int v, sem=0;
    l[u1] = 0;
    for(v=1;v<=nr;v++)
        if(v!=u1)
            l[v]= -1;
    int Q[100] = {0};
    Q[0] = u1;
    while(Q[0]!=0)
    {
        x = Q[0];
        for(int i=0;i<=99;i++)
            Q[i]=Q[i+1];
        for(y=1;y<=nr;y++)
            if(a[x][y]==1)
                if(l[y]==-1)
                {
                    p[y]=x;
                    l[y]=l[x]+1;
                    sem = 0;
                    for(int i=0;i<=100&&sem==0;i++)
                    {
                        if(Q[i]==0)
                        {
                            sem=1;
                            Q[i]=y;
                        }
                    }
                }
    }
    cout<<"Selectati un al doilea nod: ";
    cin>>v;
    int k;
    k = l[v];
    u[k]=v;
    while (k!=0)
    {
        u[k-1]=p[u[k]];
        k=k-1;
    }
    for(int i=0;i<=nr-1;i++)
        cout<<u[i]<<" ";

}
