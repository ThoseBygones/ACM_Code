#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 105
using namespace std;

char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]= {-1,0,0,1};
int dy[]= {0,-1,1,0};
int m,n;
int k,sx,sy,ex,ey;

struct Gloria
{
    int x;
    int y;
    int step;
};

queue <Gloria> q;

bool inMap(int x,int y)
{
    if(x>0 && x<=m && y>0 && y<=n)
        return true;
    return false;
}

void bfs(int sx,int sy)
{
    Gloria a,b;
    b.x=sx;
    b.y=sy;
    b.step=-1;
    vis[sx][sy]=1;
    q.push(b);
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        if(a.x==ex && a.y==ey && a.step<=k)
        {
            cout << "yes" << endl;
            return ;
        }
        for(int i=0; i<4; i++)
        {
            b.x=a.x+dx[i];
            b.y=a.y+dy[i];
            b.step=a.step+1;
            if(b.step>k)
                continue;
            while(inMap(b.x,b.y) && maze[b.x][b.y]=='.')
            {
                if(!vis[b.x][b.y])
                {
                    vis[b.x][b.y]=1;
                    q.push(b);
                }
                b.x+=dx[i];
                b.y+=dy[i];
                if(b.x==ex && b.y==ey && b.step<=k)
                {
                    cout << "yes" << endl;
                    return ;
                }
            }
        }
    }
    cout << "no" << endl;
    return ;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(maze,0,sizeof(maze));
        memset(vis,0,sizeof(vis));
        while(!q.empty())
            q.pop();
        cin >> m >> n;
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
                cin >> maze[i][j];
        }
        cin >> k >> sy >> sx >> ey >> ex;
        bfs(sx,sy);
    }
    return 0;
}
