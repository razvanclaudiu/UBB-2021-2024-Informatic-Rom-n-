#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int src;
    int dest;
    int flux;
    int cap;
}Arc;

typedef struct
{
    int h;
    int e;
}Nod;

vector<Arc> a;
vector<Nod> v;

int overflowvertex(vector<Nod>& v)
{
    for (int i = 1; i < v.size() - 1; i++)
       if (v[i].e > 0)
            return i;
    return -1;
}

void updateflux(int i, int flux)
{
    int u = a[i].dest, v = a[i].src;

    for (int j = 0; j < a.size(); j++)
    {
        if (a[j].dest == v && a[j].src == u)
        {
            a[j].flux -= flux;
            return;
        }
    }

    Arc ar;
    ar.src = u;
    ar.dest = v;
    ar.flux = 0;
    ar.cap = flux;
    a.push_back(ar);
}

bool pompare(int u)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].src == u)
        {
            if (a[i].flux == a[i].cap)
                continue;
            if (v[u].h > v[a[i].dest].h)
            {
                int flux = min(a[i].cap - a[i].flux, v[u].e);
                v[u].e -= flux;
                v[a[i].dest].e += flux;
                a[i].flux += flux;
                updateflux(i, flux);
                return true;
            }
        }
    }
    return false;
}

void inaltare(int u)
{
    int mh = INT_MAX;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i].src == u)
        {
            if (a[i].flux == a[i].cap)
                continue;

            if (v[a[i].dest].h < mh)
            {
                mh = v[a[i].dest].h;
                v[u].h = mh + 1;
            }
        }
    }
}

int getMaxflux(int s, int t)
{
    while (overflowvertex(v) != -1)
    {
        int u = overflowvertex(v);
        if (!pompare(u))
            inaltare(u);
    }

    return v.back().e;
}

int main(int argc, char * argv[])
{
    //pompare preflux
    for (int itr=1;itr<=15;itr=itr+2)
    {
        ifstream in(argv[itr]);
        ofstream out(argv[itr+1]);
        int nrv, nre, x, y, z, s=0;
        in>>nrv>>nre;
        Nod n;
        Arc ar;
        for (int i = 0; i < nrv; i++)
        {
            n.e = 0;
            n.h = 0;
            v.push_back(n);
        }
        while(in>>x>>y>>z)
        {
          ar.src = x;
          ar.dest = y;
          ar.flux = 0;
          ar.cap = z;
          a.push_back(ar);
        }

        v[s].h = v.size();

        for (int i = 0; i < a.size(); i++)
        {
            if (a[i].src == s)
            {
                a[i].flux = a[i].cap;

                v[a[i].dest].e += a[i].flux;

                ar.src = a[i].dest;
                ar.dest = s;
                ar.flux = -a[i].flux;
                ar.cap = 0;
                a.push_back(ar);
            }
        }

        out  << getMaxflux(s, nrv-1);
        a.clear();
        v.clear();
        in.close();
        out.close();
    }
}
