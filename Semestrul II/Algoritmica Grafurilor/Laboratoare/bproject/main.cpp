#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

typedef struct{

    int src;
    int dest;
    int pret;

}Arce;

vector<Arce> arc;
vector<int> dist;

int main()
{
    ifstream in("case.txt");
    int nr, nre, x, y, z, n1, n2;
    in>>nr;
    in>>nre;
    Arce a;
    while(in>>x>>y>>z)
    {
        a.src = x;
        a.dest = y;
        a.pret = z;
        arc.push_back(a);
    }
    for(int i=0;i<nr;i++)
        dist.push_back(INT_MAX);
    cin>>n1;
    dist[n1] = 0;
    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nre;j++)
        {
            int u = arc[j].src;
            int v = arc[j].dest;
            int pr = arc[j].pret;
            if(dist[u]!=INT_MAX && dist[u]+ pr < dist[v])
                dist[v] = dist[u] + pr;
        }

    }
    cin>>n2;
    if(dist[n2] > 20000)
        cout<<"INF";
    else cout<<dist[n2];

}
