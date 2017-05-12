#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 205
#define MAXM 205
#define INF 0x3fffffff

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXM*MAXM];

int head[MAXN]; //ǰ����
int level[MAXN];    //����
int num;    //�ߵ���Ŀ
int n,m;
int ans;

void addEdge(int u,int v,int w)
{
    edge[num].to=v;
    edge[num].cap=w;
    edge[num].next=head[u];
    head[u]=num++;
}

void init()
{
    num=0;
    memset(head,-1,sizeof(head));
}

bool bfs()
{
    queue <int> q;
    memset(level,-1,sizeof(level));
    level[1]=0;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>0 && level[v]==-1)   //������Ϊ�㣨��ǰ�򻡣��һ����յ�δ����ǹ�
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(level[n]!=-1)
        return true;
    return false;
}

int dfs(int u,int flow)
{
    if(u==n)    //�����Ƶ���T�ڵ㣨��㣩,����
        return flow;
    int tempf=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(level[u]+1==level[v] && edge[i].cap>0)   //1.����׷����ǰһ���㣻2.������Ϊ��
        {
            int f=dfs(v,min(edge[i].cap,flow-tempf));  //����������Ϊ��������·����С�Ļ�������
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            tempf+=f;
        }
    }
    return tempf;
}

void Dinic()
{
    while(bfs())
        ans+=dfs(1,INF);
}

int main()
{
    int kase=1;
    int t;
    while(~scanf("%d%d",&m,&n)) //��ˮ����������ˮ��������
    {
        init();
        ans=0;
        for(int i=0; i<m; i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            addEdge(x,y,c);
            addEdge(y,x,0);
        }
        Dinic();
        printf("%d\n",ans);
    }
    return 0;
}
