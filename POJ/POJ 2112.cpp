#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 240    //200+30
#define INF 0x3f3f3f3f

int dis[MAXN][MAXN];    //求最短路的邻接矩阵
int cap[MAXN][MAXN];    //容量网络的邻接矩阵
int level[MAXN];    //记录图中各点的层次
int k,c,m,n;
int st,ed;  //源点，汇点

void build(int x)
{
    memset(cap,0,sizeof(cap));
    st=0;   //超级源点
    ed=n+1; //超级汇点
    for(int i=1; i<=k; i++)
        cap[st][i]+=m;   //源点到牛之间的弧
    for(int i=k+1; i<=k+c; i++)
        cap[i][ed]+=1;  //挤奶器到汇点之间的弧
    for(int i=1; i<=k; i++)
    {
        for(int j=k+1; j<=k+c; j++)
        {
            if(dis[i][j]<=x)    //如果牛到挤奶器之间的最短路<=二分查找出的这个最大值
                cap[i][j]+=1;
        }
    }
}

int bfs()
{
    queue <int> q;
    memset(level,-1,sizeof(level));
    level[st]=0;    //如果处理不慎就很容易死循环
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0; v<=ed; v++)   //注意此处是所有顶点(0,n+1是超级源点,汇点)
        {
            if(level[v]==-1 && cap[u][v])   //此处应是cap[v][i]!=0,因为dfs是可能会走错，这样可以对其进行修正。
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(level[ed]!=-1)   //汇点的层次不等于-1说明找到
        return 1;
    return 0;
}

int dfs(int u,int cur_flow)
{
    int tempf=cur_flow;
    if(u==ed)
        return cur_flow;
    for(int v=0; v<=ed; v++) //注意此处是所有顶点
    {
        if(cap[u][v]>0 && level[u]+1==level[v])
        {
            int flow=dfs(v,min(tempf,cap[u][v]));
            cap[u][v]-=flow;
            cap[v][u]+=flow;
            tempf-=flow;
        }
    }
    return cur_flow-tempf;
}

int Dinic()
{
    int ans=0;
    while(bfs())    //一次bfs可以找到几条增广路
        ans+=dfs(st,INF);
    return ans;
}

void Floyd()
{
    for(int l=1; l<=n; l++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
        }
    }
}

int main()
{
    scanf("%d%d%d",&k,&c,&m);
    n=k+c;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&dis[i][j]);
            if(dis[i][j]==0)
                dis[i][j]=INF;
        }
    }
    Floyd();
    int left=0;
    int right=200*n;
    int ans=0;
    while(left<=right)  //二分查找所有牛中走最短路到达挤奶器的最大值（即使都走最短路到达挤奶器，但总有至少一头牛走的路在所有牛中是最长的）
    {
        int mid=(left+right)>>1;
        build(mid);
        if(Dinic()==c)
        {
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
