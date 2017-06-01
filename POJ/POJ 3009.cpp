#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

struct Stone
{
    int x;
    int y;
    int step;
};

int board[MAXN][MAXN];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int n,m;
int ex,ey;
int step;
int Min;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

void dfs(int x,int y)
{
    if(step>=10)
        return ;
    for(int i=0; i<4; i++)
    {
        int nx=x;
        int ny=y;
        while(true)
        {
            nx+=dx[i];
            ny+=dy[i];
            if(!inMap(nx,ny))
                break;
            if(nx==ex && ny==ey)
            {
                step++;
                Min=min(Min,step);
                step--;
                return ;
            }
            if(board[nx][ny]==1)
            {
                if(nx-dx[i]!=x || ny-dy[i]!=y)
                {
                    board[nx][ny]=0;
                    step++;
                    dfs(nx-dx[i],ny-dy[i]);
                    step--;
                    board[nx][ny]=1;
                }
                break;
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        if(n==0 && m==0)
            break;
        int sx,sy;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&board[i][j]);
                if(board[i][j]==2)
                {
                    sx=i;
                    sy=j;
                }
                if(board[i][j]==3)
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        Min=INF;
        step=0;
        dfs(sx,sy);
        if(Min==INF)
            puts("-1");
        else
            printf("%d\n",Min);
    }
    return 0;
}
