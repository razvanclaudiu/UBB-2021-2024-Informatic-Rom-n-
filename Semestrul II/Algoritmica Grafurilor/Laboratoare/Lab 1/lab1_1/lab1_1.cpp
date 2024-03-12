#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("date.in");
    int a[100][100],b[100][100],c[100][100],m[100], nr, i, j, x, y, n=0, nri=0;
    in>>nr;

    cout<<"Matrice de adicenta"<<endl;
    while(in>>x>>y)
    {
        a[x][y] = 1;
        a[y][x] = 1;
        nri++;
    }
    for(i=1;i<=nr;i++)
    {
        for(j=1;j<=nr;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;


    cout<<"Lista adiacenta";
    for(i=1;i<=nr;i++)
    {
        for(j=1;j<=nr;j++)
            if(a[i][j] == 1)
                b[i][j] = j;
    }
    cout<<endl;
    for(i=1;i<=nr;i++)
    {
        cout<<i<<": ";
        for(j=1;j<=nr;j++)
            if(b[i][j]!=0)
                cout<<j<<" ";
        cout<<endl;
    }
    cout<<endl;


    cout<<"Matrice de incidenta"<<endl;
    for(i=1;i<=nr;i++)
        for(j=1;j<=nr;j++)
            if(b[i][j]>0 && i <= j)
            {
                m[++n] = i;
                m[++n] = j;
            }
    int sem=1;
    for(j=2;j<=n;j=j+2)
    {
        c[m[j-1]][sem] =1;
        c[m[j]][sem] = 1;
        sem++;
    }
    for(i=1;i<=nr;i++)
    {
        for(j=1;j<=nri;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    for(i=1;i<=nr;i++)
        for(j=1;j<=nr;j++)
            b[i][j] = 0;


    cout<<"Matrice de adicenta"<<endl;
    for(i=1;i<=nr;i++)
        for(j=i;j<=nri;j++)
            if(c[i][j] == 1)
            {
                b[m[j*2-1]][m[j*2]] = 1;
                b[m[j*2]][m[j*2-1]] = 1;
            }
    for(i=1;i<=nr;i++)
    {
        for(j=1;j<=nr;j++)
            cout<<b[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    sem = 1;
    for(i=1;i<=nr;i++)
        for(j=1;j<=nr;j++)
            if(a[i][j] != b[i][j])
            {
                cout<<"Gresit!";
                sem = 0;
            }

    if(sem == 1)
        cout<<"Corect!";

}
