#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100010

struct Edge
{
    int to;
    int next;
} edge[MAXN*10];

int head[MAXN];
int cat[MAXN];  //某个节点是否有猫
int n,m;
int cnt;    //连续猫的数量
int e;  //边的数量

void addEdge(int u,int v)
{
    edge[e].to=v;
    edge[e].next=head[u];
    head[u]=e++;
}

void dfs(int u,int fa,int num)
{
    if(cat[u])  //如果连续有猫，继续累加
        num++;
    else    //否则归零
        num=0;
    if(num>m)   //剪枝：如果连续数超过忍耐连续数量，这条路就不能走了，不必继续搜下去
        return ;
    bool flag=true;  //判断是否到达终点的标志
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)   //到达终点？
        {
            flag=false;
            dfs(v,u,num);
        }
    }
    if(flag)
        cnt++;
}

void init()
{
    memset(head,-1,sizeof(head));
    memset(cat,0,sizeof(cat));
    e=0;
    cnt=0;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1; i<=n; i++)
            scanf("%d",&cat[i]);
        for(int i=1; i<n; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        cnt=0;
        dfs(1,-1,0);
        printf("%d\n",cnt);
    }
    return 0;
}
