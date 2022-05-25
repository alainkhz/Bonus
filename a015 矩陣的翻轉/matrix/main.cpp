#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x,y;
    cin>>x>>y;
    int a[x][y];

    for (int i=0;i<=x-1;i++)
    {
        for(int j=0;j<=y-1;j++)
        {
            int t=0;
            cin>>t;
            a[i][j] = t;
        }
    }

    for (int i=0;i<=y-1;i++)
    {
        for(int j=0;j<=x-1;j++)
        {
            cout<<a[j][i]<<" ";
        }
        cout<<endl;
    }



}
