#include <bits/stdc++.h>
#define LL long long
using namespace std;

#define INF 1e9
#define MAXN 310

int grid[MAXN][MAXN];
int vis[MAXN][MAXN][30][10];    //vis[i][j][k][l]为第k步点(i,j)是否被从方向l访问过
int a[35];
int dx[]= {1,1,0,-1,-1,-1,0,1}; //正下、左下、正左、左上、正上、右上、正右、右下
int dy[]= {0,-1,-1,-1,0,1,1,1}; //正下、左下、正左、左上、正上、右上、正右、右下
int n;

struct Node
{
    int x;
    int y;
    int step;   //烟花的层数
    int dir;    //烟花的方向
};

void bfs()
{
    queue <Node> q;
    Node temp,now,next;
    temp.x=150;
    temp.y=150;
    temp.step=1;
    temp.dir=0;
    q.push(temp);
    vis[150][150][1][0]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        int nx=now.x;
        int ny=now.y;
        for(int i=1; i<=a[now.step]; i++)
        {
            nx+=dx[now.dir];
            ny+=dy[now.dir];
            grid[nx][ny]=1;
        }
        if(now.step!=n)
        {
            int l=(now.dir-1+8)%8;  //逆时针偏转45度
            int r=(now.dir+1)%8;    //顺时针偏转45度
            next.x=nx;
            next.y=ny;
            next.step=now.step+1;
            if(!vis[next.x][next.y][next.step][l])  //某个方向逆时针偏45度未被访问
            {
                vis[next.x][next.y][next.step][l]=1;
                next.dir=l;
                q.push(next);
            }
            if(!vis[next.x][next.y][next.step][r])  //某个方向顺时针偏45度未被访问
            {
                vis[next.x][next.y][next.step][r]=1;
                next.dir=r;
                q.push(next);
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",a+i);
    memset(grid,0,sizeof(grid));
    memset(vis,0,sizeof(vis));
    bfs();
    int ans=0;
    for(int i=0; i<=305; i++)
    {
        for(int j=0; j<=305; j++)
        {
            if(grid[i][j])
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
