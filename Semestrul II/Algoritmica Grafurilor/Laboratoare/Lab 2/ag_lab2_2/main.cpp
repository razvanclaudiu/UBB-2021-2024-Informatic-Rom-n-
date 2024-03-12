#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("graf.txt");
    int a[100][100], nr, x, y;
    in>>nr;
    while(in>>x>>y)
         a[x][y] = 1;
    for(int k = 1 ; k <= nr ; k++)
        for(int i = 1 ; i <= nr ; i++)
            for(int j = 1 ; j <= nr ; j++)
                if( i != j && a[i][j] == 0 &&  a[i][k] == 1 && a[k][j] == 1)
                    a[i][j] = 1;
    for(int i=1;i<=nr;i++)
        a[i][i]=1;
    for(int i=1;i<=nr;i++)
    {
        for(int j=1;j<=nr;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
