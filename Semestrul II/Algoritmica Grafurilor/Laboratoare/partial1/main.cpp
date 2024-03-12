#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

typedef struct{

    int src;
    int dest;
    float pret;

}Muchie;

vector<int> par;
vector<float> lun;
vector<Muchie> m;
vector<float> shortest_drum;
priority_queue<int, vector<int>, greater<int> > Q;

int main()
{
    ifstream in("graf.txt");
    int nr, nre, coord[100][100], x, y, n1, n2;
    in>>nr>>nre;
    nre=nre*2;
    int sem = 0;
    while(sem!=nr)
    {
        sem++;
        in>>x>>y;
        coord[x][y] = sem;
    }
    Muchie a;
    float pret;
    while(in>>x>>y)
    {
        int p1, q1, p2, q2;
        a.src = x;
        a.dest = y;
        for(int i=1;i<=nr;i++)
            for(int j=1;j<=nr;j++)
            {
                if(coord[i][j]==x)
                {
                    p1=i;
                    p2=j;
                }
                if(coord[i][j]==y)
                {
                    q1=i;
                    q2=j;
                }
            }
        pret = sqrt((q1-p1)*(q1-p1)+(q2-p2)*(q2-p2));
        a.pret = pret;
        m.push_back(a);
        a.src = y;
        a.dest = x;
        cout<<pret<<endl;
        m.push_back(a);
    }
   for(int i=0;i<=nr;i++)
    {
        par.push_back(0);
        lun.push_back(INT_MAX);
        shortest_drum.push_back(0);
    }
    cin>>n1;
    lun[n1] = 0;
    Q.push(n1);
    while (!Q.empty())
    {
        int x = Q.top();
        Q.pop();
        for(int y=1;y<=nr;y++)
        {
            int sem=0;
            for (int itr=0;itr<nre&&sem==0;itr++)
                if(m[itr].src == x && m[itr].dest == y)
                {
                    if(lun[x]+m[itr].pret < lun[y])
                    {
                        sem = 1;
                        par[y]=x;
                        lun[y]=lun[x]+m[itr].pret;
                        Q.push(y);
                    }
                }
        }
    }
    cin>>n2;
    int print[100], c=1, parst;
    print[0] = n2;
    parst = n2;
    while(parst!=n1)
    {
        print[c] = par[print[c-1]];
        parst = par[print[c-1]];
        c++;
    }
    for(int i = c-1;i>=0;i--)
        cout<<print[i]<<" ";
}
