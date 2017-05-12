#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;

char maze[35][35][35];
int vis[35][35][35];
int dx[]= {-1,0,1,0,0,0};
int dy[]= {0,-1,0,1,0,0};
int dz[]= {0,0,0,0,1,-1};
int l,r,c;
int sx,sy,sz;
int cnt;

struct Status
{
    int x;
    int y;
    int z;
    int step;
};

queue <Status> q;

bool inMap(int x,int y,int z)
{
    if(x>=0 && x<r && y>=0 && y<c && z>=0 && z<l)
        return true;
    return false;
}

void bfs()
{
    Status now,next;
    now.x=sx;
    now.y=sy;
    now.z=sz;
    now.step=0;
    cnt=INF;
    vis[sx][sy][sz]=1;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        next.x=now.x;
        next.y=now.y;
        next.z=now.z;
        if(maze[now.x][now.y][now.z]=='E')
        {
            cnt=min(now.step,cnt);
            while(!q.empty())
                q.pop();
        }
        for(int i=0; i<6; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            next.z=now.z+dz[i];
            if(inMap(next.x,next.y,next.z) && !vis[next.x][next.y][next.z] && maze[next.x][next.y][next.z]!='#')
            {
                vis[next.x][next.y][next.z]=1;
                next.step=now.step+1;
                q.push(next);
            }
        }
    }
    if(cnt==INF)
        cout << "Trapped!" << endl;
    else
        cout << "Escaped in " << cnt << " minute(s)." << endl;
}

int main()
{
    while(cin >> l >> r >> c)
    {
        memset(vis,0,sizeof(vis));
        if(l==0 && r==0 && c==0)
            break;
        for(int k=0; k<l; k++)
        {
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                    cin >> maze[i][j][k];
            }
        }
        for(int k=0; k<l; k++)
        {
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    if(maze[i][j][k]=='S')
                    {
                        sx=i;
                        sy=j;
                        sz=k;
                        break;
                    }
                }
            }
        }
        bfs();
    }
    return 0;
}
