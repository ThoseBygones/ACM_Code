#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 25
using namespace std;

char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int sx,sy,tx,ty;
int n,m,ans;
int dx[]= {1,0,-1,0};   //右下左上
int dy[]= {0,1,0,-1};   //右下左上

struct Harry
{
    int x;
    int y;
    int step;
    bool operator <(const Harry temp)const
    {
        return step>temp.step;
    }
};

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

bool stair(Harry a,Harry b,int i)
{
    if((maze[a.x][a.y]=='-' && i%2==1 && b.step%2==0) || (maze[a.x][a.y]=='|' && i%2==1 && b.step%2==1))    //判断到达楼梯时楼梯的方向和人前进的方向是否一致（横时）
        return true;
    if((maze[a.x][a.y]=='|' && i%2==0 && b.step%2==0) || (maze[a.x][a.y]=='-' && i%2==0 && b.step%2==1))    //判断到达楼梯时楼梯的方向和人前进的方向是否一致（竖时）
        return true;
    return false;
}

void bfs()
{
    priority_queue <Harry> pq;
    Harry a,b;
    a.x=sx;
    a.y=sy;
    a.step=0;
    pq.push(a);
    while(!pq.empty())
    {
        b=pq.top();
        pq.pop();
        if(b.x==tx && b.y==ty)
        {
            ans=b.step;
            return ;
        }
        for(int i=0; i<4; i++)
        {
            int nx=b.x+dx[i];
            int ny=b.y+dy[i];
            a.x=nx;
            a.y=ny;
            if(inMap(a.x,a.y) && maze[a.x][a.y]!='*' && !vis[a.x][a.y])
            {
                a.step=b.step+1;
                if(maze[a.x][a.y]=='.')
                {
                    vis[a.x][a.y]=1;
                    pq.push(a);
                }
                if(maze[a.x][a.y]=='|' || maze[a.x][a.y]=='-')  //判断楼梯处的行走情况
                {
                    if(stair(a,b,i))
                    {
                        a.x+=dx[i];
                        a.y+=dy[i];
                        if(inMap(a.x,a.y) && maze[a.x][a.y]!='*' && !vis[a.x][a.y])
                        {
                            vis[a.x][a.y]=1;
                            pq.push(a);
                        }
                    }
                    else
                    {
                        b.step++;
                        pq.push(b);
                    }
                }
                if(a.x==tx && a.y==ty)
                {
                    ans=a.step;
                    return ;
                }
            }
        }
    }
}

int main()
{
    while(cin >> n >> m)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin >> maze[i][j];
                if(maze[i][j]=='S')
                {
                    sx=i;
                    sy=j;
                }
                if(maze[i][j]=='T')
                {
                    tx=i;
                    ty=j;
                }
            }
        }
        memset(vis,0,sizeof(vis));
        vis[sx][sy]=1;
        bfs();
        cout << ans << endl;
    }
    return 0;
}
