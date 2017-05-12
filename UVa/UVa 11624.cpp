/*#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1005
using namespace std;

struct Point
{
    int x;
    int y;
    int step;
    bool fire;
};

Point fire[MAXN*MAXN],q[MAXN*MAXN],start;

char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int r,c;
int cnt;

bool inMap(int x,int y)
{
    if(x>0 && x<=r && y>0 && y<=c)
        return true;
    return false;
}

int bfs()
{
    int fnt=0,rear=0;
    for(int i=0; i<cnt; i++)
        q[rear++]=fire[i];
    q[rear++]=start;
    while(fnt<rear)
    {
        Point &temp=q[fnt];
        if(temp.fire)
        {
            for(int i=0; i<4; i++)
            {
                int nx=temp.x+dx[i];
                int ny=temp.y+dy[i];
                if(inMap(nx,ny) && !vis[nx][ny])
                {
                    vis[nx][ny]=1;
                    q[rear].x=nx;
                    q[rear].y=ny;
                    q[rear].fire=true;
                    q[rear].step=temp.step+1;
                    rear++;
                }
            }
        }
        else if(maze[temp.x][temp.y]=='J')
        {
            for(int i=0; i<4; i++)
            {
                int nx=temp.x+dx[i];
                int ny=temp.y+dy[i];
                if(!vis[nx][ny])
                {
                    vis[nx][ny]=1;
                    maze[nx][ny]='J';
                    q[rear].x=nx;
                    q[rear].y=ny;
                    q[rear].fire=false;
                    q[rear].step=temp.step+1;
                    if(!inMap(nx,ny))
                        return q[rear].step;
                    rear++;
                }
            }
        }
        fnt++;
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(maze,'.',sizeof(maze));
        scanf("%d %d",&r,&c);
        for(int i=1; i<=r; i++)
            scanf("%s",maze[i]+1);
        cnt=0;
        //for(int i=0; i<=r; i++)
        //{
        //    for(int j=0; j<=c; j++)
        //        printf("%c",maze[i][j]);
        //    printf("\n");
        //}
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                if(maze[i][j]=='J')
                {
                    vis[i][j]=1;
                    start.x=i;
                    start.y=j;
                    start.step=0;
                    start.fire=false;
                }
                else if(maze[i][j]=='F')
                {
                    vis[i][j]=1;
                    fire[cnt].x=i;
                    fire[cnt].y=j;
                    fire[cnt].step=0;
                    fire[cnt++].fire=true;
                }
                else if(maze[i][j]=='#')
                    vis[i][j]=1;
            }
        }
        int ans=bfs();
        if(ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
*/


#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1005
#define INF 0x3f3f3f3f
using namespace std;

int r,c;
char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int times[MAXN][MAXN];
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int sx,sy;

struct Point
{
    int x;
    int y;
    int t;
}s,e;

queue <Point> q;

bool inMap(int x,int y)
{
    if(x>0 && x<=r && y>0 && y<=c)
        return true;
    return false;
}

void bfs_fire()
{
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            e.x=s.x+dx[i];
            e.y=s.y+dy[i];
            e.t=s.t+1;
            if(inMap(e.x,e.y) && !vis[e.x][e.y] && times[e.x][e.y]==INF)
            {
                times[e.x][e.y]=e.t;
                q.push(e);
            }
        }
    }
    //printf("bfs_fire done!\n");
}

int bfs_escape()
{
    s.x=sx;
    s.y=sy;
    s.t=0;
    vis[sx][sy]=1;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        if(!inMap(s.x,s.y))
            return s.t;
        q.pop();
        for(int i=0; i<4; i++)
        {
            e.x=s.x+dx[i];
            e.y=s.y+dy[i];
            e.t=s.t+1;
            if(!vis[e.x][e.y] && e.t<times[e.x][e.y])
            {
                vis[e.x][e.y]=1;
                q.push(e);
            }
        }
    }
    return -1;
}

int main()
{
    int kase;
    scanf("%d",&kase);
    while(kase--)
    {
        memset(vis,0,sizeof(vis));
        memset(times,INF,sizeof(times));
        memset(maze,'.',sizeof(maze));
        while(!q.empty())
            q.pop();
        scanf("%d %d",&r,&c);
        for(int i=1; i<=r; i++)
            scanf("%s",maze[i]+1);
        for(int i=1; i<=r; i++)
        {
            for(int j=1; j<=c; j++)
            {
                if(maze[i][j]=='J')
                {
                    sx=i;
                    sy=j;
                }
                else if(maze[i][j]=='F')
                {
                    vis[i][j]=1;
                    times[i][j]=0;
                    s.x=i;
                    s.y=j;
                    s.t=0;
                    q.push(s);
                }
                else if(maze[i][j]=='#')
                    vis[i][j]=1;
            }
        }
        bfs_fire();
        int ans=bfs_escape();
        /*for(int i=0; i<=r; i++)
        {
            for(int j=0; j<=c; j++)
                printf("%d ",vis[i][j]);
            printf("\n");
        }*/
        if(ans==-1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}

/*
2
4 4
####
#JF#
#..#
#..#
3 3
###
#J.
#.F
*/
