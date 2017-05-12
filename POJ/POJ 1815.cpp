#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 20
#define MAXM 2005
#define INF 0x3fffffff

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXM];

int head[MAXN]; //ǰ����
int cur[MAXN];  //�Ż���ǰ��
int level[MAXN];    //����
int num;    //�ߵ���Ŀ
int n,m;
int st,ed;
int ans;

void addEdge(int u,int v,int w)
{
    edge[num].to=v;
    edge[num].cap=w;
    edge[num].next=head[u];
    head[u]=num++;
    edge[num].to=u;
    edge[num].cap=0;
    edge[num].next=head[v];
    head[v]=num++;
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
    level[st]=0;
    q.push(st);
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
    if(level[ed]!=-1)
        return true;
    return false;
}

int dfs(int u,int flow)
{
    if(u==ed)    //�����Ƶ���T�ڵ㣨��㣩,����
        return flow;
    int tempf=0;
    for(int& i=cur[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(level[u]+1==level[v] && edge[i].cap>0)   //1.����׷����ǰһ���㣻2.������Ϊ��
        {
            int f=dfs(v,min(edge[i].cap,flow));  //����������Ϊ��������·����С�Ļ�������
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            tempf+=f;
            flow-=f;
            if(!flow)
                break;
        }
    }
    return tempf;
}

void Dinic()
{
    while(bfs())
    {
        for(int i=0; i<=ed; i++)
            cur[i]=head[i];
        ans+=dfs(st,INF);
    }
}

int main()
{
    int kase=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        ans=0;
        st=0;
        ed=n;
        scanf("%d%d",&n,&m);
        for(int i=0; i<m; i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            addEdge(x,y,c);
        }
        Dinic();
        printf("Case %d: %d\n",kase++,ans);
    }
    return 0;
}
