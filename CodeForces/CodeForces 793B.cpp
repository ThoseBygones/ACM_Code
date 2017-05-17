//记忆化搜索
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

char mp[MAXN][MAXN];
int vis[MAXN][MAXN][5][3];  //行、列、方向、拐弯次数
int sx,sy,ex,ey;
int n,m;
int dx[]={-1,0,1,0};    //上右下左
int dy[]={0,1,0,-1};    //上右下左
bool flag;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

void dfs(int x,int y,int d,int t)
{
    if((!inMap(x,y)) || mp[x][y]=='*' || t>2 || flag || vis[x][y][d][t])
        return ;
    vis[x][y][d][t]=1;
    if(x==ex && y==ey)
    {
        flag=true;
        return ;
    }
    dfs(x+dx[d],y+dy[d],d,t);
    for(int i=0; i<4; i++)
    {
        if(i!=d)
            dfs(x+dx[i],y+dy[i],i,t+1);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(vis,0,sizeof(vis));
        flag=false;
        for(int i=1; i<=n; i++)
            scanf("%s",mp[i]+1);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(mp[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                if(mp[i][j]=='T')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        for(int i=0; i<4; i++)
            dfs(sx,sy,i,0);
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
