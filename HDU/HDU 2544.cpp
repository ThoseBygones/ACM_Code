#include<iostream>
#include<algorithm>
using namespace std;

//Floyd
#define INF 0x3f3f3f3f
int path[105][105],a,b,d;

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        if(n==0 && m==0)
            break;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                path[i][j]=INF;
            path[i][i]=0;
        }
        for(int i=0;i<m;i++)
        {
            cin >> a >> b >> d;
            path[a][b]=path[b][a]=d;
        }

        for(int k=1;k<=n;k++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    path[i][j]=min(path[i][k]+path[k][j],path[i][j]);
            }
        }
        cout << path[1][n] << endl;
    }
    return 0;
}
