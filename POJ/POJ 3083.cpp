#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 50
using namespace std;

struct Point
{
    int x;
    int y;
    int step;
};

char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int dirx[4][2]= {{0,0},{-1,-1},{0,0},{1,1}};
int diry[4][2]= {{-1,1},{0,0},{1,-1},{0,0}};
int dl[4][2]= {{0,-1},{-1,0},{0,1},{1,0}};
int dr[4][2]= {{0,1},{-1,0},{0,-1},{1,0}};
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int w,h;
int sx,sy,ex,ey;
int nd1,nd2;

bool inMap(int x,int y)
{
    if(x>=0 && x<h && y>=0 && y<w)
        return true;
    return false;
}

int dfs(int x,int y,int d,int step,int dir)
{
    for(int i=0; i<4; i++)
    {
        int newd=((d-1+4)%4+i)%4;
        //cout << newd << endl;
        int nx=x+dirx[newd][dir];
        int ny=y+diry[newd][dir];
        if(nx==ex && ny==ey)
            return step+1;
        if(inMap(nx,ny) && maze[nx][ny]!='#')
            return dfs(nx,ny,newd,step+1,dir);
    }
}

int bfs()
{
    memset(vis,0,sizeof(vis));
    queue <Point> q;
    Point now,next;
    now.x=sx;
    now.y=sy;
    now.step=1;
    q.push(now);
    vis[sx][sy]=1;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(now.x==ex && now.y==ey)
            return now.step;
        for(int i=0; i<4; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            next.step=now.step+1;
            if(inMap(next.x,next.y) && !vis[next.x][next.y] && maze[next.x][next.y]!='#')
            {
                vis[next.x][next.y]=1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> w >> h;
        for(int i=0; i<h; i++)
            cin >> maze[i];
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(maze[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                else if(maze[i][j]=='E')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        /*for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
                cout << maze[i][j];
            cout << endl;
        }*/
        if(sx==0)
        {
            nd1=3;
            nd2=3;
        }
        else if(sx==h-1)
        {
            nd1=1;
            nd2=1;
        }
        else if(sy==0)
        {
            nd1=2;
            nd2=0;
        }
        else if(sy==w-1)
        {
            nd1=0;
            nd2=2;
        }
        int ansl=dfs(sx,sy,nd1,1,0);
        int ansr=dfs(sx,sy,nd2,1,1);
        int ans=bfs();
        cout << ansl << " " << ansr << " " << ans << endl;
    }
    return 0;
}
