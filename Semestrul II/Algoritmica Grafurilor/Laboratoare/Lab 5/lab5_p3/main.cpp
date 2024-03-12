#include<iostream>
#include <fstream>
#include <cstring>
#include <bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> graph;
int nrv;
vector<int>res;

int nod_sursa(){
   for(int i = 0; i<nrv; i++)
    {
      int deg = 0;
      for(int j = 0; j<nrv; j++){
         if(graph[i][j]==1)
         deg++;
      }
      if(deg % 2 != 0)
        return i;
   }
   return 0;
}
bool conectat(int u, int v){
   int deg = 0;
   for(int i = 0; i<nrv; i++)
      if(graph[v][i]==1)
         deg++;
      if(deg>1){
         return false;
      }
   return true;
}
int nrmuchie(){
   int ct = 0;
   for(int i = 0; i<nrv; i++)
      for(int j = i; j<nrv; j++)
         if(graph[i][j]==1)
            ct++;
   return ct;
}
void fleuryAlgorithm(int start)
{
   static int edge = nrmuchie();
   for(int v = 0; v < nrv; v++)
    {
      if(graph[start][v]==1)
      {

         if(edge <= 1 || !conectat(start, v))
         {
            res.push_back(start);
            graph[start][v] = graph[v][start] = 0;
            edge--;
            fleuryAlgorithm(v);
         }
      }
   }
}
int main(int argc, char * argv[])
{
     for (int itr=11;itr<=11;itr=itr+2)
     {
        ifstream in(argv[itr]);
        ofstream out(argv[itr+1]);
        int nre, x, y, z, s=0;
        in>>nrv>>nre;
        graph.resize(nrv);
        for(int i = 0 ; i < nrv ; ++i)
        {
            graph[i].resize(nrv);
        }
        for(int i=0;i<nrv;i++)
            for(int j=0;j<nrv;j++)
                graph[i][j]=0;
        while(in>>x>>y)
        {
            graph[x][y]=1;
            graph[y][x]=1;
        }
       fleuryAlgorithm(nod_sursa());
       for(int i=0;i<res.size();i++)
            out<<res[i]<< " ";
       graph.clear();
       res.clear();
       in.close();
       out.close();
    }
}
