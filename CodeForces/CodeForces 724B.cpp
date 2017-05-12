#include <iostream>
#include <algorithm>
using namespace std;

int n,m,mat[25][25];

void swapColumn(int x,int y)
{
    for(int i=1; i<=n; i++)
        swap(mat[i][x],mat[i][y]);
}

bool judge()
{
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        for(int j=1; j<=m; j++)
        {
            if(mat[i][j]!=j)
                cnt++;
        }
        if(cnt>2)
            return false;
    }
    return true;
}

int main()
{

    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cin >> mat[i][j];
    }
    for(int i=1; i<=m; i++)
    {
        for(int j=i; j<=m; j++)
        {
            swapColumn(i,j);
            if(judge())
            {
                cout << "YES" << endl;
                return 0;
            }
            swapColumn(i,j);
        }
    }
    cout << "NO" << endl;
    return 0;
}
