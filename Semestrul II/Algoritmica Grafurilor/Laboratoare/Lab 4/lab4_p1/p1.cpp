#include <iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:268435456");

using namespace std;

typedef struct
{
    int src;
    int dest;
}Muchie;

vector<Muchie> m;

int main(int argc, char * argv[])
{
    for (int itr=1;itr<=17;itr=itr+2)
    {
        ifstream in(argv[itr]);
        ofstream out(argv[itr+1]);
        int nr, ct, x, ns;
        in>>nr;
        ct=0;
        Muchie a;
        while(in>>x)
        {
            if(x!=-1)
            {
                a.src=x;
                a.dest=ct;
                m.push_back(a);
            }
            else ns = ct;
            ct++;
        }
        unordered_set<int> vecini[nr+1];
       // cout << vecini.max_size();
        for( int i = 0; i < m.size(); i++ )
        {
            int u = m[i].src; int v = m[i].dest;
            vecini[u].insert(v);
            vecini[v].insert(u);
        }

        priority_queue<int> frunze;
        for ( int i = 0; i <= nr; i++ )
            if (vecini[i].size() == 1 )
                frunze.push(-i);
        vector<int> pruferCode;
        int sem = nr - 1;
        while(sem--)
        {
            int leaf = -frunze.top();
            frunze.pop();
            int vecinfrunza = *(vecini[leaf].begin());
            pruferCode.push_back(vecinfrunza);
            vecini[vecinfrunza].erase(leaf);
            vecini[leaf].erase(vecinfrunza);
            if(vecini[vecinfrunza].size() == 1)
            {
                if(vecinfrunza != ns)
                    frunze.push(-vecinfrunza);
            }

        }
        out<<nr-1<<endl;
        for(int i=0;i<nr-1;i++)
            out<<pruferCode[i]<<" ";
        m.clear();
        pruferCode.clear();
        in.close();
        out.close();
    }
}
