#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 300+1  //可以走到301处躲避

struct Point
{
    int x;
    int y;
    int t;
};

int hashTime[MAXN+5][MAXN+5];
int dx[]= {0,-1,0,0,1};
int dy[]= {0,0,-1,1,0};

bool inMap(int x,int y)
{
    if(x>=0 && x<=MAXN && y>=0 && y<=MAXN)
        return true;
    return false;
}

int bfs()
{
    if(hashTime[0][0]==0)
        return -1;
    queue <Point> q;
    Point now,next;
    now.x=now.y=now.t=0;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(int i=1; i<5; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            next.t=now.t+1;
            if(!inMap(next.x,next.y))
                continue;
            if(hashTime[next.x][next.y]==-1)
                return next.t;
            if(next.t<hashTime[next.x][next.y])
            {
                hashTime[next.x][next.y]=next.t;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    scanf("%d",&n);
    memset(hashTime,-1,sizeof(hashTime));
    while(n--)
    {
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        for(int i=0; i<5; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(inMap(nx,ny))
            {
                if(hashTime[nx][ny]==-1)
                    hashTime[nx][ny]=t;
                else
                    hashTime[nx][ny]=min(t,hashTime[nx][ny]);
            }
        }
    }
    printf("%d\n",bfs());
    return 0;
}
