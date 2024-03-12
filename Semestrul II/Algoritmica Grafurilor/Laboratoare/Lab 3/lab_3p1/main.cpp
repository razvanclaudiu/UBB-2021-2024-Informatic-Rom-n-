#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int src;
    int dest;
    int pret;
}Arc;

vector<Arc> arce;
vector<int> dist;

//Bellman-Ford
int main(int argc, char * argv[])
{
    for (int itr=1;itr<=13;itr=itr+2)
    {
        ifstream in(argv[itr]);
        ofstream out(argv[itr+1]);
        int nr,nre,ns, x, y, z,i=0;
        in>>nr;
        nr++;
        in>>nre;
        in>>ns;
        Arc a;
        while(in>>x>>y>>z)
        {
            a.src=x;
            a.dest=y;
            a.pret=z;
            arce.push_back(a);
        }
        for (int i = 0; i < nr; i++)
            dist.push_back(INT_MAX);
        dist[ns] = 0;
        for (i = 1; i <= nr - 1; i++)
        {
            for (int j = 0; j < nre; j++)
            {
                int u = arce[j].src;
                int v = arce[j].dest;
                int pr = arce[j].pret;
                if (dist[u] != INT_MAX && dist[u] + pr < dist[v])
                     dist[v] = dist[u] + pr;
            }
        }

        for (int i = 0; i < nr-1; i++)
        {
            if(dist[i] > 2000)
                out<<"INF"<<" ";
            else out<<dist[i]<<" ";
        }
        in.close();
        out.close();
        arce.clear();
        dist.clear();
    }

}
