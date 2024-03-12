#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

int conducte[1000][1000];
int nrv;

bool BFS(int nrv, int conducte[][1000], int s, int t, int par[])
{
    bool vizitat[nrv];
    memset(vizitat, 0, sizeof(vizitat));

    queue<int> q;
    q.push(s);
    vizitat[s] = true;
    par[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < nrv; v++)
        {
            if (vizitat[v] == false && conducte[u][v] > 0)
            {
                if (v == t)
                {
                    par[v] = u;
                    return true;
                }
                q.push(v);
                par[v] = u;
                vizitat[v] = true;
            }
        }
    }
    return false;
}

int main(int argc, char * argv[])
{
        ifstream in("fis1.txt");
        int nre, x, y, z, u, v;
        in>> nrv >> nre;
        for(int i=0;i<nrv;i++)
            for(int j=0;j<nrv;j++)
               conducte[i][j]=0;
        while(in>>x>>y>>z)
        {
          conducte[x][y] = z;
        }
        int par[nrv];
        int debit_maxim = 0;
        while (BFS(nrv, conducte, 0, nrv-1, par))
        {
            int capacitate = INT_MAX;
            for (v = nrv-1; v != 0; v = par[v])
            {
                u = par[v];
                capacitate = min(capacitate, conducte[u][v]);
            }
            for (v = nrv-1; v != 0; v = par[v])
            {
                u = par[v];
                conducte[u][v] -= capacitate;
                conducte[v][u] += capacitate;
            }
            debit_maxim += capacitate;
        }
        cout << debit_maxim;
        in.close();
}
