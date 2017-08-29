//bfs+状态压缩dp
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <vector>
#include <map>
using namespace std;

#define MAXN 20
#define INF 0x3f3f3f3f
#define PII pair
#define MP make_pair
#define LL long long
#define PB push_back
#define MOD 1000000007

struct Tunnel
{
    int sx;
    int sy;
    int ex;
    int ey;
} t[MAXN];

struct Status
{
    int x;
    int y;
    int step;
};

char g[MAXN][MAXN];
int vis[MAXN][MAXN];
int dis[MAXN][MAXN];
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int dp[1<<16][MAXN]; //dp[i][j]表示在j点状态为i时花费的最少时间
int n,m;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=n)
        return true;
    return false;
}

int bfs(Status a,Status b)
{
    if(a.x==b.x && a.y==b.y)
        return 0;
    memset(vis,0,sizeof(vis));
    queue <Status> q;
    q.push(a);
    vis[a.x][a.y]=1;
    while(!q.empty())
    {
        Status now=q.front();
        q.pop();
        if(now.x==b.x && now.y==b.y)
            return now.step;
        for(int i=0; i<4; i++)
        {
            Status next;
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            if(inMap(next.x,next.y) && !vis[next.x][next.y] && g[next.x][next.y]=='.')
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
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
            scanf("%s",g[i]+1);
        for(int i=1; i<=m; i++)
            scanf("%d%d%d%d",&t[i].sx,&t[i].sy,&t[i].ex,&t[i].ey);
        //bfs求出每一个隧道出口到另一个隧道入口之间的最短距离
        memset(dis,-1,sizeof(dis));
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(i==j)
                    dis[i][j]=0;
                else
                {
                    Status a,b;
                    a.x=t[i].ex;
                    a.y=t[i].ey;
                    a.step=0;
                    b.x=t[j].sx;
                    b.y=t[j].sy;
                    b.step=0;
                    dis[i][j]=bfs(a,b);
                }
            }
        }
        //状态压缩dp求解TSP问题
        for(int i=0; i<(1<<m); i++)
        {
            for(int j=1; j<=m; j++)
                dp[i][j]=INF;
        }
        for(int i=1; i<=m; i++)
            dp[1<<(i-1)][i]=0;
        int ans=INF;
        for(int i=0; i<(1<<m); i++) //枚举现在的状态
        {
            for(int j=1; j<=m; j++) //枚举现在要走的隧道
            {
                if(i&(1<<(j-1)))    //判断该点未被访问
                {
                    for(int k=1; k<=m; k++)  //枚举之前所在的隧道
                    {
                        //同一个隧道不重复走、下一个隧道未被访问过、下一个隧道可达
                        if(k==j || (i&(1<<(k-1)))==0 || dis[k][j]==-1)
                            continue;
                        dp[i][j]=min(dp[i][j],dp[i^(1<<(j-1))][k]+dis[k][j]);
                    }
                }
                if(i==(1<<m)-1)
                    ans=min(ans,dp[i][j]);
            }
        }
        if(ans==INF)
            puts("-1");
        else
            printf("%d\n",ans);
    }
    return 0;
}
