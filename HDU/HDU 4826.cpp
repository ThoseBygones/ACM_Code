#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

int maze[105][105],dpU[105],dpD[105];

int main()
{
    int t;
    cin >> t;
    for(int kase=1; kase<=t; kase++)
    {
        int m,n;
        cin >> m >> n;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
                cin >> maze[i][j];
        }
        for(int i=2; i<=m; i++)
            maze[i][1]+=maze[i-1][1];
        for(int j=2; j<=n; j++)
        {
            dpU[0]=dpD[0]=dpU[m+1]=dpD[m+1]=-INF;
            for(int i=1; i<=m; i++)
                dpU[i]=max(dpU[i-1],maze[i][j-1])+maze[i][j];
            for(int i=m; i>=1; i--)
                dpD[i]=max(dpD[i+1],maze[i][j-1])+maze[i][j];
            for(int i=1; i<=m; i++)
                maze[i][j]=max(dpU[i],dpD[i]);
        }
        cout << "Case #" << kase << ":" << endl;
        cout << maze[1][n] << endl;
    }
    return 0;
}
