#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <algorithm>
#define MAXN 55
#define INF 0x3f3f3f3f
using namespace std;

struct Points
{
    int x;
    int y;
};

char maze[MAXN][MAXN];  //记录输入的地图
int vis[MAXN][MAXN];    //记录地图上的点的访问情况
int dis[MAXN*MAXN][MAXN*MAXN];    //记录两点之间距离的邻接矩阵
int d[MAXN*MAXN];    //记录两顶点之间的最小距离
int used[MAXN*MAXN];    //标记某个编号的顶点是否已经加入最小生成树
int num[MAXN][MAXN];    //记录顶点的编号
int len[MAXN][MAXN];    //记录某点到这个点(x,y)点的最短距离

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int n,m,cnt;

bool inMap(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m)
        return true;
    return false;
}

void bfs(int x,int y)
{
    queue <Points> q;
    memset(vis,0,sizeof(vis));
    Points now,next;
    now.x=x;
    now.y=y;
    q.push(now);
    vis[now.x][now.y]=1;
    len[now.x][now.y]=0;
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if(num[now.x][now.y]!=-1)
            dis[num[x][y]][num[now.x][now.y]]=len[now.x][now.y];
        for(int i=0; i<4; i++)
        {
            next.x=now.x+dx[i];
            next.y=now.y+dy[i];
            if(inMap(next.x,next.y) && !vis[next.x][next.y] && maze[next.x][next.y]!='#')
            {
                vis[next.x][next.y]=1;
                len[next.x][next.y]=len[now.x][now.y]+1;
                q.push(next);
            }
        }
    }
}

int prim()
{
    memset(used,0,sizeof(used));
    int ans=0;
    for(int i=0; i<cnt; i++)
        d[i]=dis[0][i];
    used[0]=1;
    d[0]=0;
    int temp;
    for(int i=0; i<cnt-1; i++)
    {
        int Min=INF;
        for(int j=0; j<cnt; j++)
        {
            if(!used[j] && d[j]<Min)
            {
                temp=j;
                Min=d[j];
            }
        }
        used[temp]=1;
        ans+=Min;
        for(int j=0; j<cnt; j++)
        {
            if(!used[j] && dis[temp][j]<d[j])
                d[j]=dis[temp][j];
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        char temp[MAXN];
        cin >> m >> n;
        gets(temp); //输入数据比较奇葩，据说有多个空格，因此需要排除他们对下面输入的影响
        for(int i=0; i<n; i++)
            gets(maze[i]);  //地图中有空格
        /*for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout << maze[i][j];
            cout << endl;
        }*/
        cnt=1;  //S点直接编号为0
        memset(num,0,sizeof(num));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(maze[i][j]=='A') //A点从1开始编号
                    num[i][j]=cnt++;
                if(maze[i][j]=='S') //S点直接编号为0
                    num[i][j]=0;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(maze[i][j]=='S' || maze[i][j]=='A')
                    bfs(i,j);
            }
        }
        int ans=prim();
        cout << ans << endl;
    }
    return 0;
}
