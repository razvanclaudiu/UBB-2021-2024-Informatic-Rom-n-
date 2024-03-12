#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

struct arce
{
    int src;
    int dest;
    int pret;
}arc[150000];

int main(int argc, char * argv[])
{
    for (int itr=1;itr<=13;itr=itr+2)
    {
        ifstream in(argv[itr]);
        ofstream out(argv[itr+1]);
        int dist[10000], nr,nre,ns, x, y, z,i=0;
        in>>nr;
        nr++;
        in>>nre;
        in>>ns;
        while(in>>x>>y>>z)
        {
            arc[i].src=x;
            arc[i].dest=y;
            arc[i].pret=z;
            i++;
        }
        for (int i = 0; i < nr; i++)
            dist[i] = INT_MAX;
        dist[ns] = 0;
        for (i = 1; i <= nr - 1; i++)
        {
            for (int j = 0; j < nre; j++)
            {
                int u = arc[j].src;
                int v = arc[j].dest;
                int pr = arc[j].pret;
                if (dist[u] != INT_MAX && dist[u] + pr < dist[v])
                    dist[v] = dist[u] + pr;
            }
        }
        for (i = 0; i < nre; i++)
        {
            int u = arc[i].src;
            int v = arc[i].dest;
            int pr = arc[i].pret;
            if (dist[u] != INT_MAX && dist[u] + pr < dist[v])
            {
                cout<<"error";
                break;
            }
        }

        for (int i = 0; i < nr-1; i++)
        {
            if(dist[i] > 20000)
                out<<"INF"<<" ";
            else out<<dist[i]<<" ";
        }
        in.close();
        out.close();
    }

}
