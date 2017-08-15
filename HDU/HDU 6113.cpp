#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

#define MAXN 110
#define LL long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int,int>
#define MP make_pair

char g[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int n,m;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

int bfs(int x,int y,char c)
{
    int inc=1;
    queue <PII> q;
    q.push(MP(x,y));
    vis[x][y]=1;
    while(!q.empty())
    {
        PII temp=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            int nx=temp.first+dx[i];
            int ny=temp.second+dy[i];
            if(inMap(nx,ny))
            {
                if(!vis[nx][ny] && g[nx][ny]==c)
                {
                    vis[nx][ny]=1;
                    q.push(MP(nx,ny));
                }
            }
            else
                inc=0;
        }
    }
    return inc;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(g,0,sizeof(g));
        for(int i=1; i<=n; i++)
            scanf("%s",g[i]+1);
        memset(vis,0,sizeof(vis));
        int cnt0=0,cnt1=0;
        int inc0=0,inc1=0;  //inc0：0字被包围的数量；inc1：1字被包围的数量
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(g[i][j]=='0' && !vis[i][j])
                {
                    cnt0++;
                    inc0+=bfs(i,j,'0');
                }
                if(g[i][j]=='1' && !vis[i][j])
                {
                    cnt1++;
                    inc1+=bfs(i,j,'1');
                }
            }
        }
        //cout << inc0 << " " << inc1 << endl;
        if(cnt1==1 && inc0==1)
            puts("0");
        else if(cnt1==1 && inc0==0)
            puts("1");
        else
            puts("-1");
    }
    return 0;
}
