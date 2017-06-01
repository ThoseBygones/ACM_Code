#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 1005

struct Cheese
{
    int x;
    int y;
    int step;
};

char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int tx[15];
int ty[15];
int n,m,k;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

int bfs(int sx,int sy,int ex,int ey)
{
    queue <Cheese> q;
    Cheese now,next;
    now.x=sx;
    now.y=sy;
    now.step=0;
    vis[now.x][now.y]=1;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==ex && now.y==ey)
            return now.step;
        for(int i=0; i<4; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            if(inMap(next.x,next.y) && maze[next.x][next.y]!='X' && !vis[next.x][next.y])
            {
                next.step=now.step+1;
                vis[next.x][next.y]=1;
                q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        scanf("%s",maze[i]+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(maze[i][j]=='S')
            {
                tx[0]=i;
                ty[0]=j;
                maze[i][j]=='.';
            }
            else if(maze[i][j]>='1' && maze[i][j]<='9')
            {
                tx[maze[i][j]-'0']=i;
                ty[maze[i][j]-'0']=j;
            }
        }
    }
    int ans=0;
    for(int i=0; i<k; i++)
    {
        memset(vis,0,sizeof(vis));
        ans+=bfs(tx[i],ty[i],tx[i+1],ty[i+1]);
    }
    printf("%d\n",ans);
}
