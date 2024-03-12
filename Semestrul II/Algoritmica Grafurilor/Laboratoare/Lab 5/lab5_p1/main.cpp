#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

int a[1000][1000];
int nrv;

bool BFS(int nrv, int a[][1000], int s, int t, int p[])
{
    bool vis[nrv];
    memset(vis, 0, sizeof(vis));

    queue<int> q;
    q.push(s);
    vis[s] = true;
    p[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < nrv; v++) {
            if (vis[v] == false && a[u][v] > 0) {
                if (v == t) {
                    p[v] = u;
                    return true;
                }
                q.push(v);
                p[v] = u;
                vis[v] = true;
            }
        }
    }
    return false;
}

int main(int argc, char * argv[])
{
    for (int itr=1;itr<=19;itr=itr+2)
    {
        ifstream in(argv[itr]);
        ofstream out(argv[itr+1]);
        int nre, x, y, z, u, v;
        in>>nrv >> nre;
        for(int i=0;i<nrv;i++)
            for(int j=0;j<nrv;j++)
               a[i][j]=0;
        while(in>>x>>y>>z)
        {
          a[x][y] = z;
        }
        //Ford-Fulkerson
        int p[nrv];
        int fluxmax = 0;
        while (BFS(nrv, a, 0, nrv-1, p))
        {
            int pprice = INT_MAX;
            for (v = nrv-1; v != 0; v = p[v])
            {
                u = p[v];
                pprice = min(pprice, a[u][v]);
            }
            for (v = nrv-1; v != 0; v = p[v])
            {
                u = p[v];
                a[u][v] -= pprice;
                a[v][u] += pprice;
            }

            fluxmax += pprice;
        }
        out << fluxmax;
        in.close();
        out.close();
    }
}
