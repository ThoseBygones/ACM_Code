#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 25

char room[MAXN][MAXN];
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

void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny) && !vis[nx][ny] && room[nx][ny]=='.')
        {
            cnt++;
            dfs(nx,ny);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        if(n==0 && m==0)
            break;
        getchar();
        for(int i=1; i<=n; i++)
            scanf("%s",room[i]+1);
        /*for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                printf("%c",room[i][j]);
            }
            puts("");
        }
        */
        int sx,sy;
        bool flag=false;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(room[i][j]=='@')
                {
                    sx=i;
                    sy=j;
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        //cout << sx << " " << sy << endl;
        cnt=1;
        memset(vis,0,sizeof(vis));
        dfs(sx,sy);
        printf("%d\n",cnt);
    }
    return 0;
}
