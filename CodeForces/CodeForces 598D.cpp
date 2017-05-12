#include <cstring>
#include <cstdio>
#define MAXN 1005
using namespace std;

int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
char museum[MAXN][MAXN];
int vis[MAXN][MAXN];
int ans[MAXN*MAXN];
int n,m,k;
int x,y;
int sum,cnt;

bool inMap(int x,int y)
{
    if(x>0 && x<=n && y>0 && y<=m)
        return true;
    return false;
}

void dfs(int x,int y)
{
    vis[x][y]=cnt;
    for(int i=0; i<4; i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(inMap(nx,ny) && !vis[nx][ny])
        {
            if(museum[nx][ny]=='.')
                dfs(nx,ny);
            else
                sum++;
        }
    }
}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1; i<=n; i++)
        scanf("%s",museum[i]+1);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(museum[i][j]=='.' && !vis[i][j])
            {
                sum=0;
                cnt++;
                dfs(i,j);
                ans[cnt]=sum;
            }
        }
    }
    while(k--)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",ans[vis[x][y]]);
    }
    return 0;
}
