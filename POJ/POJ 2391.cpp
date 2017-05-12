#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 410    //200*2
#define MAXM 1510
#define INF 0x3f3f3f3f
#define LINF 1e15
#define LL long long

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXN*MAXN];  //1500��·+200*200������������·*2��˫��

LL dis[MAXN][MAXN];    //�����·���ڽӾ���
int head[MAXN]; //ǰ����
int cur[MAXN];  //��ǰ���Ż�
int level[MAXN];    //����
int now[MAXN],c[MAXN];    //ÿ��ݵ�����ţ�����������ɱ����ţ������
int num;    //�ߵ���Ŀ
int n,m;
int st,ed;  //����Դ�㡢�������
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

int bfs()
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
        return 1;
    return 0;
}

int dfs(int u,int flow)
{
    if(u==ed || flow==0)    //�����Ƶ���T�ڵ㣨��㣩,����
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

void Floyd()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        }
    }
}

void build(LL x)
{
    init();
    for(int i=1; i<=n; i++)
    {
        addEdge(st,i,now[i]);   //����Դ����ÿ��ݵ��ϵ�ţ�����룩֮������
        addEdge(i+n,ed,c[i]); //ÿ��ݵ���Ҫȥ�����ţ���������볬�����֮������
    }
    for(int i=1; i<=n; i++)
        addEdge(i,i+n,INF); //ÿ��ݵ��ϵ�ţ�����룩��ÿ��ݵ���Ҫȥ�����ţ��������֮�����ߣ�����㣬��ÿ��ݵز�������㣩
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(dis[i][j]<=x)
            {
                addEdge(i,j+n,INF);
                addEdge(j,i+n,INF); //ţ���Ե���Ĳݵ�ȥ�������б�����ݵ��ϵ�ţҲ�ܵ���Ĳݵ���ȥ
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        st=0;
        ed=(n<<1)+1;  //��㣬������Դ��ͳ�����������е���������
        int sum=0;  //ţ��������
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&now[i],&c[i]);
            sum+=now[i];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                dis[i][j]=LINF;
        }
        for(int i=1; i<=m; i++)
        {
            int u,v,len;
            scanf("%d%d%d",&u,&v,&len);
            if(dis[u][v]>len)
                dis[u][v]=dis[v][u]=len;
        }
        Floyd();
        LL ans=-1;
        LL left=0,right=LINF;
        while(left<=right)  //���ֲ����ܱ����ţ���������
        {
            LL mid=(left+right)/2;
            build(mid);
            int temp=Dinic();
            if(temp>=sum)
            {
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        if(ans==LINF)
            puts("-1");
        else
            printf("%I64d\n",ans);
    }

    return 0;
}

/*
6 6
10 0
0 3
0 7
3 0
0 2
0 1
1 2 120
5 2 80
5 1 20
5 6 30
6 1 110
4 3 30

ans��-1


10 9
1 0
0 0
0 0
0 1
0 1
0 1
0 1
0 1
0 1
0 1
2 1 10
3 1 4
4 3 2
5 3 5
6 2 11
7 5 1
8 6 7
9 4 1
10 2 10

ans��6
*/
