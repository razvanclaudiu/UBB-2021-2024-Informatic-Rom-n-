#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int src;
    int dest;
}Muchie;


vector<int> par;
vector<int> lun;
vector<Muchie> drum;
vector<int> shortest_drum;
priority_queue<int> Q;


int main()
{
    ifstream in("graf.txt");
    int nr, x, y, n1, n2, nrm=0;
    in>>nr;
    Muchie m;
    while(in>>x>>y)
    {
        m.src=x;
        m.dest=y;
        drum.push_back(m);
        m.src=y;
        m.dest=x;
        drum.push_back(m);
        nrm=nrm+2;
    }
    for(int i=0;i<nr;i++)
    {
        par.push_back(0);
        lun.push_back(-1);
        shortest_drum.push_back(0);
    }
    cin>>n1;
    lun[n1] = 0;
    Q.push(n1);
    while (!Q.empty())
    {
        int x = Q.top();
        Q.pop();
        for(int y=0;y<nr;y++)
        {
            int sem=0;
            for (int itr=0;itr<nrm&&sem==0;itr++)
                if(drum[itr].src == x && drum[itr].dest == y)
                {
                    if(lun[y]==-1)
                    {
                        sem = 1;
                        par[y]=x;
                        lun[y]=lun[x]+i;
                        Q.push(y);
                    }
                }
        }
    }
    cin>>n2;
    int k = lun[n2];
    if(k==-1)
        cout<<"Nu exista";
    else
    {
        shortest_drum[k] = n2;
        while(k!=0)
        {
            shortest_drum[k-1]=par[shortest_drum[k]];
            k--;
        }
        for(int i=0;i<nr;i++)
            cout<<shortest_drum[i]<<" ";
    }

}
