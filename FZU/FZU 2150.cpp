#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 12
#define INF 0x3f3f3f3f
using namespace std;

struct Fire
{
    int x;
    int y;
    int step;
};

char grid[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int n,m;
int grass;  //剩余（未被烧掉）的草地的数量

queue <Fire> q;

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

int bfs()
{
    int res=0;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            Fire now=q.front();
            q.pop();
            int x=now.x;
            int y=now.y;
            int s=now.step;
            res=max(res,s);
            Fire next;
            for(int i=0; i<4; i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(inMap(nx,ny) && !vis[nx][ny] && grid[nx][ny]=='#')
                {
                    vis[nx][ny]=1;
                    next.x=nx;
                    next.y=ny;
                    next.step=s+1;
                    q.push(next);
                    grass--;
                }
            }
        }
    }
    if(grass==0)
        return res;
    return -1;
}

int main()
{
    int t,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            scanf("%s",&grid[i]);
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='#')
                    cnt++;
            }
        }
        bool flag=false;
        int ans=INF;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='#')
                {
                    for(int k=i; k<n; k++)
                    {
                        for(int l=(k==i?j:0); l<m; l++)
                        {
                            if(grid[k][l]=='#')
                            {
                                Fire fire1,fire2;
                                memset(vis,0,sizeof(vis));
                                fire1.x=i;
                                fire1.y=j;
                                fire1.step=0;
                                grass=cnt-1;
                                q.push(fire1);
                                vis[i][j]=1;
                                if(!(i==k && j==l))
                                {
                                    fire2.x=k;
                                    fire2.y=l;
                                    fire2.step=0;
                                    q.push(fire2);
                                    vis[k][l]=1;
                                    grass--;
                                }
                                int res=bfs();
                                if(res!=-1)
                                {
                                    flag=true;
                                    ans=min(ans,res);
                                }
                            }
                        }
                    }
                }
            }
        }
        if(flag)
            printf("Case %d: %d\n",kase++,ans);
        else
            printf("Case %d: -1\n",kase++);
    }
    return 0;
}
