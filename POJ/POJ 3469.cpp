#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 40010  //20000*2
#define MAXM 500100 //200000*2+20000*2*2
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
int a[MAXN];
int b[MAXN];

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
    if(!tempf)
        level[u]=-1;
    return tempf;
}

int Dinic()
{
    int res=0;
    while(bfs())
    {
        for(int i=0; i<=ed; i++)
            cur[i]=head[i];
        res+=dfs(st,INF);
    }
    return res;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        st=0;
        ed=n+1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",a+i,b+i);
            addEdge(st,i,a[i]);
            addEdge(i,st,0);
            addEdge(i,ed,b[i]);
            addEdge(ed,i,0);
        }
        for(int i=1; i<=m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w); //��ģ�鲻��ͬһ��core�����У���˽�˫���
        }
        int ans=Dinic();    //�����=��С��
        printf("%d\n",ans);
    }
    return 0;
}
