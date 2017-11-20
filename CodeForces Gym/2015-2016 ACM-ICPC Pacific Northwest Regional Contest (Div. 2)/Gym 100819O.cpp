#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 505

struct Node
{
    int x;
    int y;
    int step;
} node[MAXN];

int n,m;
int grid[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

int bfs()
{
    queue <Node> q;
    int sx=1,sy=1;
    int ex=n,ey=m;
    Node temp,now,next;
    temp.x=sx;
    temp.y=sy;
    temp.step=0;
    q.push(temp);
    vis[temp.x][temp.y]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==ex && now.y==ey)
            return now.step;
        for(int i=0; i<4; i++)
        {
            next.x=now.x+dx[i]*grid[now.x][now.y];
            next.y=now.y+dy[i]*grid[now.x][now.y];
            if(inMap(next.x,next.y) && !vis[next.x][next.y])
            {
                vis[next.x][next.y]=1;
                next.step=now.step+1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char temp;
            scanf("%c",&temp);
            grid[i][j]=temp-'0';
        }
        getchar();
    }
    int ans=bfs();
    if(ans==-1)
        puts("IMPOSSIBLE");
    else
        printf("%d\n",ans);
    return 0;
}
