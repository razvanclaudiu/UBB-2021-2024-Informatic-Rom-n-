#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;

# define INF 0x3f3f3f3f

typedef struct
{
    int src;
    int dest;
    int pret;
}Arc;

vector<Arc> arce;
vector<int> dist;
vector<pair<int,int>> matr[10001];
vector<pair<int,int>> mod_matr[10001];

int main(int argc, char * argv[])
{
    for (int itr=1;itr<=19;itr=itr+2)
    {
        ifstream in(argv[itr]);
        ofstream out(argv[itr+1]);
        int nr,nre, x, y, z,i=0,fnre, sem=1;
        in>>nr;
        in>>nre;
        fnre = nre;
        Arc a;
        //Citirea arcelor din fisier
        while(in>>x>>y>>z)
        {
            a.src=x;
            a.dest=y;
            a.pret=z;
            arce.push_back(a);
            matr[x].push_back({y,z});
        }
        //Bellman-Ford
        for (int i = 0; i <= nr; i++)
            dist.push_back(INT_MAX);
        dist[nr] = 0;
        for(int i=0;i<=nr;i++)
        {
            a.src=nr;
            a.dest=i;
            a.pret=0;
            arce.push_back(a);
            fnre++;
        }

        for (i = 0; i <= nr; i++)
        {
            for (int j = 0; j < fnre; j++)
            {
                int u = arce[j].src;
                int v = arce[j].dest;
                int pr = arce[j].pret;
                if (dist[u] != INT_MAX && dist[u] + pr < dist[v])
                    dist[v] = dist[u] + pr;
            }
        }

        //Reponderare
        for(int i=0;i<nr && sem==1;i++)
            if(matr[i].size()!=0)
                for(int j=0; j<matr[i].size() &&sem==1;j++)
                    if(dist[matr[i][j].first] > matr[i][j].second+dist[i])
                    {
                        sem=0;
                        break;
                    }
                    else  mod_matr[i].push_back({matr[i][j].first,matr[i][j].second+dist[i]-dist[matr[i][j].first]});
        if(sem!=0)
        {
            //Stocarea arcelor reponderate
            for(int i=0;i<nr;i++)
                if(matr[i].size()!=0)
                    for(int j=0; j<matr[i].size();j++)
                        out<<i<<" "<<mod_matr[i][j].first<<" "<<mod_matr[i][j].second<<endl;
            //Dijkstra
            for(int i=0;i<nr;i++)
            {
                priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

                vector<int> short_dist(nr, INF);

                pq.push(make_pair(0, i));
                short_dist[i] = 0;

                while (!pq.empty())
                {
                    int u = pq.top().second;
                    pq.pop();
                    vector< pair<int, int> >::iterator itr;
                    for (itr = matr[u].begin(); itr != matr[u].end(); itr++)
                    {
                        int v = (*itr).first;
                        int pr = (*itr).second;

                        if (short_dist[v] > short_dist[u] + pr)
                        {
                            short_dist[v] = short_dist[u] + pr;
                            pq.push(make_pair(short_dist[v], v));
                        }
                    }
                }

                // Stocarea celor mai scurte drumuri
                for (int j = 0; j < nr; j++)
                {
                    if(short_dist[j] > 2000)
                        out<<"INF"<<" ";
                    else out<<short_dist[j]<<" ";
                }
                out<<endl;
            }
        }
        else out<<-1;

        //Resetare
        arce.clear();
        dist.clear();
        for(int i=0;i<=nr;i++)
        {
            matr[i].clear();
            mod_matr[i].clear();
        }
        in.close();
        out.close();

    }


}


 //cout<<endl<<endl<<endl;
        /*for(int i=0;i<nr;i++)
            if(mod_matr[i].size()!=0)
            {
                int sem = 0;
                for(int j=0; j<matr[i].size();j++)
                {
                    while(sem != mod_matr[i][j].first && sem <nr)
                    {
                        sem++;
                        cout<<0<<" ";
                    }
                    cout<<mod_matr[i][j].second<<" ";
                    sem++;
                }
                while(sem<nr)
                {
                    sem++;
                    cout<<0<<" ";
                }
                cout<<endl;
            }
            else
            {
                int sem = 0;
                while(sem<nr)
                {
                    sem++;
                    cout<<0<<" ";
                }
                cout<<endl;
            }*/
