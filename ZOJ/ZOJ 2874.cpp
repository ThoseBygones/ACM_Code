#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <queue>
#include <cmath>
using namespace std;

#define MAXN 110
#define MAXM 11010   //100*100+500*2
#define INF 1e9+7
#define EPS 1e-6

struct Edge
{
    int to;
    int next;
    double cap;
} edge[MAXM];

int head[MAXN]; //ǰ����
int cur[MAXN];  //�Ż���ǰ��
int level[MAXN];    //����
int num;    //�ߵ���Ŀ
int n,m,s;
int st,ed;

void addEdge(int u,int v,double w)
{
    edge[num].to=v;
    edge[num].cap=w;
    edge[num].next=head[u];
    head[u]=num++;
    edge[num].to=u;
    edge[num].cap=0.0;
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
    //queue <int> q;
    int q[MAXN<<1]; //��д����
    int fnt,rear;
    fnt=rear=0;
    memset(level,-1,sizeof(level));
    level[st]=0;
    q[rear++]=st;
    while(fnt<rear)
    {
        int u=q[fnt++];
        for(int i=head[u]; i!=-1; i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap>0 && level[v]==-1)   //������Ϊ�㣨��ǰ�򻡣��һ����յ�δ����ǹ�
            {
                level[v]=level[u]+1;
                q[rear++]=v;
            }
        }
    }
    if(level[ed]!=-1)
        return true;
    return false;
}

double dfs(int u,double flow)
{
    if(u==ed || fabs(flow)<=EPS)    //�����Ƶ���T�ڵ㣨��㣩,����
        return flow;
    double tempf=0;
    for(int& i=cur[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(level[u]+1==level[v] && edge[i].cap>0)   //1.����׷����ǰһ���㣻2.������Ϊ��
        {
            double f=dfs(v,min(edge[i].cap,flow));  //����������Ϊ��������·����С�Ļ�������
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            tempf+=f;
            flow-=f;
            if(fabs(flow)<=EPS)
                break;
        }
    }
    return tempf;
}

double Dinic()
{
    double res=0;
    while(bfs())
    {
        for(int i=0; i<=ed; i++)
            cur[i]=head[i];
        res+=dfs(st,INF);
        //cout << res << endl;
    }
    return res;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&s);
        init();
        st=0;
        ed=n+m+1;   //���к��зֱ𿴳ɵ�
        for(int i=1; i<=n; i++)
        {
            double c;
            scanf("%lf",&c);
            addEdge(st,i,log(c));    //�е�Ϊ1~n
        }
        for(int i=1; i<=m; i++)
        {
            double c;
            scanf("%lf",&c);
            addEdge(i+n,ed,log(c));  //�е�Ϊn+1~n+m
        }
        for(int i=1; i<=s; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v+n,INF);
        }
        double ans=exp(Dinic());
        printf("%.4f\n",ans);   //C++��Ϊ%.4lf
    }
    return 0;
}
