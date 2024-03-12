#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int nr, time, sem=1;

void DFS(int a[][100]);
void DFS_VISIT(int a[][100], int i);

struct nod
{
    char color[20];
    int parinte, d, f;
}u[100];

void DFS(int a[][100])
{
    for(int i=1;i<=nr;i++)
    {
        strcpy(u[i].color,"alb");
        u[i].parinte = -1;
    }
    time = 0;
    for(int i=1;i<=nr;i++)
        if (strcmp(u[i].color,"alb")==0)
        {
            cout<<"Componenta conexa "<<sem<<": ";
            DFS_VISIT(a,i);
            cout<<endl;
            sem++;
        }
}

void DFS_VISIT(int a[][100], int i)
{
    cout<<i<<" ";
    time = time+1;
    u[i].d = time;
    strcpy(u[i].color,"gri");
    for(int j=1;j<=nr;j++)
        if(a[i][j] == 1)
            if(strcmp(u[j].color,"alb")==0)
            {
                u[j].parinte = i;
                DFS_VISIT(a,j);
            }
    strcpy(u[i].color,"negru");
    time = time +1;
    u[i].f = time;
}
int main()
{
    ifstream in("graf.txt");
    int a[100][100], x, y;
    in>>nr;
    while(in>>x>>y)
        a[x][y] = 1;
    DFS(a);
    cout<<endl;
    cout<<"Nodurile descoperite: ";
    for(int i=1;i<=nr;i++)
        if(strcmp(u[i].color,"negru")==0)
            cout<<i<<" ";
}
