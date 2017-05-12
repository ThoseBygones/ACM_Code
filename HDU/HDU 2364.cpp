#include <iostream>
#include <cstring>
#include <queue>
#define MAXN 85
using namespace std;

struct Point
{
    int x;
    int y;
    int step;
    int pre;
};

Point s;
char maze[MAXN][MAXN];
int vis[MAXN][MAXN][5]; //记录访问的数组变成了三维的，因为还要记录某个点从不同方向的访问情况
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};    //左上右下（同个方向同为偶数或者奇数）
int n,m;

queue <Point> q;

bool reachEdge(int x,int y) //判断是否到达迷宫边界（也就是是否已经走出迷宫了）
{
    if(x==0 || x==n-1 || y==0 || y==m-1)
        return true;
    return false;
}

int bfs()
{
    while(!q.empty())
        q.pop();
    q.push(s);
    Point now,next;
    bool flag;  //能否尽量拐弯到达终点的标志
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        flag=true;
        for(int i=0; i<4; i++)
        {
            if(i%2==now.pre%2)  //如果下一步与这一步方向同向或反向，跳过
                continue;
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            next.step=now.step+1;
            next.pre=i;
            if(maze[next.x][next.y]=='#')
                continue;
            flag=false; //左转或右转碰到的不是墙壁，可行
            if(vis[next.x][next.y][i])  //若被访问过，则说明当前走的路径无法走出迷宫
                continue;
            vis[next.x][next.y][i]=1;
            if(reachEdge(next.x,next.y))
                return next.step;
            q.push(next);
        }
        if(flag)    //左转或右转都不可行，只能直走！
        {
            int temp=now.pre;
            next.x=now.x+dx[temp];
            next.y=now.y+dy[temp];
            next.step=now.step+1;
            next.pre=temp;
            if(maze[next.x][next.y]=='#')
                continue;
            if(vis[next.x][next.y][temp])
                continue;
            vis[next.x][next.y][temp]=1;
            if(reachEdge(next.x,next.y))
                return next.step;
            q.push(next);
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
        cin >> n >> m;
        for(int i=0; i<n; i++)
            cin >> maze[i];
        bool flag=false;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(maze[i][j]=='@')
                {
                    s.x=i;
                    s.y=j;
                    s.step=0;
                    s.pre=-1;
                    flag=true;
                    break;
                }
            }
            if(flag)
                break;
        }
        memset(vis,0,sizeof(vis));
        for(int i=0; i<4; i++)
            vis[s.x][s.y][i]=1; //起点不能再被重复走，否则肯定不是最短的
        if(reachEdge(s.x,s.y))  //若起点即是终点，则直接输出0
        {
            cout << "0" << endl;
            continue;
        }
        int ans=bfs();
        cout << ans << endl;
    }
    return 0;
}
