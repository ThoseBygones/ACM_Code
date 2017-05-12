#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char fl[25][25];
int vis[25][25];
int sum;

void dfs(int x,int y)
{
    if(vis[x-1][y]==0 && fl[x-1][y]=='.')
    {
        vis[x-1][y]=1;
        sum++;
        dfs(x-1,y);
    }
    if(vis[x+1][y]==0 && fl[x+1][y]=='.')
    {
        vis[x+1][y]=1;
        sum++;
        dfs(x+1,y);
    }
    if(vis[x][y-1]==0 && fl[x][y-1]=='.')
    {
        vis[x][y-1]=1;
        sum++;
        dfs(x,y-1);
    }
    if(vis[x][y+1]==0 && fl[x][y+1]=='.')
    {
        vis[x][y+1]=1;
        sum++;
        dfs(x,y+1);
    }
}

int main()
{
    int m,n;
    while(scanf("%d %d",&m,&n))
    {
        if(m==0 && n==0)
            break;
        memset(vis,0,sizeof(vis));
        memset(fl,'#',sizeof(fl));
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> fl[i][j];
        sum=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(fl[i][j]=='@')
                {
                    vis[i][j]=1;
                    dfs(i,j);
                    i=n-1;
                    j=m-1;
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
