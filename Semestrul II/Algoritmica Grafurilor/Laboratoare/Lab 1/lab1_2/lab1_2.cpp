#include <iostream>
#include <fstream>
using namespace std;

void DFS(int x);

int viz[100]={0}, nr, a[100][100];

int main()
{
   ifstream in("date.in");
   int i,j,reg = 1,iz[100]={0},sem,n=0,ver=-1;
   in>>nr;
   while(in>>i>>j)
   {
       a[i][j]=1;
       a[j][i]=1;
   }
   for(i=1;i<=nr;i++)
   {
       sem = 0;
       for(j=1;j<=nr;j++)
            if(a[i][j] == 1)
                sem++;
       if(sem == 0)
           iz[++n] = i;
       if(ver==-1)
        ver = sem;
       else if(ver != sem)
                reg = 0;
   }
   if(reg == 1)
    cout<<"Graful este regular!";
   else  cout<<"Graful nu este regular!";
   if(n>0)
   {
    cout<<"Puncte inzolate: ";
    for(i=1;i<=n;i++)
        cout<<iz[i];
   }
   else cout<<"Nu exista puncte izolate!";
   DFS(1);
   for(int i=1;i<=nr;i++)
        if(viz[i]==0)
        {
            cout<<"Nu este conex";
            return 0;
        }
    cout<<"Este conex";

}
void DFS(int x)
{
    int i;
    viz[x]=1;
    for(i=1;i<=nr;i++)
        if(a[x][i]==1&&viz[i]==0)
            DFS(i);
}
