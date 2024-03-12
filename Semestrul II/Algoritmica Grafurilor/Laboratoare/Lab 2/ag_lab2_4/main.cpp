#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct nod
{
    char color[20];
    int parinte, d;
}u[100];

int main()
{
    ifstream in("graf.txt");
    int a[100][100], nr, x, y, l[100], p[100], u1;
    in>>nr;
    while(in>>x>>y)
        a[x][y] = 1;
    cout<<"Selecatati nodul sursa: ";
    cin>>u1;
    int sem=0;
    u[u1].d = 0;
    strcpy(u[u1].color, "gri");
    for(int i=1;i<=nr;i++)
        if(i!=u1)
        {
            u[i].d= -1;
            strcpy(u[i].color,"alb");
        }
    int Q[100] = {0};
    Q[0] = u1;
    while(Q[0]!=0)
    {
        x = Q[0];
        for(int i=0;i<=99;i++)
            Q[i]=Q[i+1];
        for(y=1;y<=nr;y++)
            if(a[x][y]==1)
                if(strcmp(u[y].color,"alb")==0)
                {
                    strcpy(u[y].color,"gri");
                    u[y].parinte=x;
                    u[y].d=u[x].d+1;
                    sem = 0;
                    for(int i=0;i<=100&&sem==0;i++)
                        if(Q[i]==0)
                        {
                            sem=1;
                            Q[i]=y;
                        }
                }
        strcpy(u[x].color,"negru");
    }
    cout<<"Lungimea: "<<endl;
    for(int i=1;i<=nr;i++)
        if (strcmp(u[i].color,"negru")==0)
        cout<<i<<": "<<u[i].d<<endl;
    cout<<endl;

}
