#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 105

char orc[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int n,m;
int cnt;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

void dfs(int x,int y,char c)
{
    vis[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny) && !vis[nx][ny] && orc[nx][ny]==c)
            dfs(nx,ny,c);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        for(int i=1; i<=n; i++)
            scanf("%s",orc[i]+1);
        memset(vis,0,sizeof(vis));
        cnt=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(!vis[i][j])
                {
                    dfs(i,j,orc[i][j]);
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
