#include <bits/stdc++.h>
using namespace std;

#define MAXN 105

struct Point
{
    int x;
    int y;
};

char mp[MAXN][MAXN];
int vis[MAXN][MAXN];
int pre[MAXN][MAXN][2]; //记录上一个点（输出路径用）
int path[MAXN*MAXN][2];  //记录输出的路径
int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
char dc[]= {'L','U','R','D'};
int ex,ey;
int cnt;
int n,m;

bool inMap(int x,int y)
{
    if(x>=1 && x<=n && y>=1 && y<=m)
        return true;
    return false;
}

void bfs()
{
    memset(vis,0,sizeof(vis));
    queue <Point> q;
    Point now,next;
    now.x=1;
    now.y=1;
    q.push(now);
    vis[1][1]=1;
    pre[1][1][0]=1;
    pre[1][1][1]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==ex && now.y==ey)
            return ;
        for(int i=0; i<4; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            if(inMap(next.x,next.y) && !vis[next.x][next.y] && mp[next.x][next.y]!='*')
            {
                vis[next.x][next.y]=1;
                q.push(next);
                pre[next.x][next.y][0]=now.x;
                pre[next.x][next.y][1]=now.y;
            }
        }
    }
}

void getPath()
{
    cnt=0;
    while(true)
    {
        path[cnt][0]=ex;
        path[cnt][1]=ey;
        int tx=ex,ty=ey;
        ex=pre[tx][ty][0];
        ey=pre[tx][ty][1];
        cnt++;
        if(ex==1 && ey==1)
        {
            path[cnt][0]=ex;
            path[cnt][1]=ey;
            break;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",mp[i]+1);
        if(!ex && !ey)
        {
            for(int j=1; j<=m; j++)
            {
                if(mp[i][j]=='F')
                {
                    ex=i;
                    ey=j;
                    break;
                }
            }
        }
    }
    bfs();
    getPath();
    //puts("ok");
    while(cnt)
    {
        int p=-1;
        for(int i=0; i<4; i++)
        {
            int nx=path[cnt][0]+dx[i];
            int ny=path[cnt][1]+dy[i];
            if(nx==path[cnt-1][0] && ny==path[cnt-1][1])
            {
                p=i;
                break;
            }
        }
        printf("%c\n",dc[p]);
        fflush(stdout);
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        if(tx==path[cnt-1][0] && ty==path[cnt-1][1])
            cnt--;
        else
        {
            if(dc[p]=='L' || dc[p]=='R')
                swap(dc[0],dc[2]);
            else
                swap(dc[1],dc[3]);
        }
    }
    return 0;
}
