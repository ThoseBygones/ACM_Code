#include<iostream>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
int path[1005][1005],a,b,d,s,t;

int main()
{
    int m,n;
    while(cin >> n >> m)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0;j<n;j++)
            {
                path[i][j]=INF;
            }
            path[i][i]=0;
        }
        for(int i=0;i<m;i++)
        {
            cin >> a >> b >> d;
            path[a][b]=path[b][a]=min(d,path[a][b]);
        }
        cin >> s >> t;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    path[i][j]=min(path[i][k]+path[k][j],path[i][j]);
            }
        }
        if(path[s][t]==INF)
            cout << "-1" << endl;
        else
            cout << path[s][t] << endl;
    }
}
