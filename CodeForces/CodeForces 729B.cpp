#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int stage[1005][1005];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int n,m;
int cnt;

bool inMap(int x,int y)
{
    if(x>0 && x<=n && y>0 && y<=m)
        return true;
    return false;
}

void dfs(int x,int y,int k)
{
    int nx=x+dx[k];
    int ny=y+dy[k];
    if(inMap(nx,ny))
    {
        if(stage[nx][ny]==1)
            return ;
        else
        {
            cnt++;
            dfs(nx,ny,k);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&stage[i][j]);
        }
    }
    cnt=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(stage[i][j]==1)
            {
                for(int k=0; k<4; k++)
                {
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(inMap(nx,ny) && stage[nx][ny]==0)
                    {
                        cnt++;
                        dfs(nx,ny,k);
                    }
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
