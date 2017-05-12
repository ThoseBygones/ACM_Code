#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 110    //50*2
#define MAXM 2005
#define INF 0x3fffffff

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXN*MAXN*2];

int head[MAXN]; //ǰ����
int cur[MAXN];  //�Ż���ǰ��
int level[MAXN];    //����
int val[MAXN];
int input[MAXN][15];   //������Ե������0,1,2��ʾ��0�������Ʒ����Ҫ�ܹ��������иò�����1���������иò�����2������û�иò�������ν��
int output[MAXN][15];  //������Ե������0,1��ʾ��0����������Զ�Ӧ�Ĳ���δװ�ã�1������Ӧ�Ĳ�����װ��
int g[MAXN][MAXN];  //��¼��������֮������ͨ�ģ�������������װ·��
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
    memset(g,0,sizeof(g));
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
        //cout << res << endl;
        //system("pause");
    }
    return res;
}

bool check(int x,int y)
{
    if(x==y || y==2)
        return true;
    return false;
}

bool check0(int x)  //�ж��Ƿ�ȫΪ1
{
    for(int i=0; i<n; i++)
    {
        if(input[x][i]==1)  //���ȫΪ1�Ͳ��ô�����
            return false;
    }
    return true;
}

bool check1(int x)  //�ж��Ƿ�ȫΪ1
{
    for(int i=0; i<n; i++)
    {
        if(output[x][i]!=1) //�����Ϊ1��˵����û���
            return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d",val+i);
        for(int j=0; j<n; j++)
            scanf("%d",&input[i][j]);
        for(int j=0; j<n; j++)
            scanf("%d",&output[i][j]);
    }
    init();
    st=0;
    ed=2*m+1;
    for(int i=1; i<=m; i++) //���
    {
        for(int j=1; j<=m; j++)
        {
            if(i==j)
                continue;
            bool flag=true; //���õ����Ƿ�װ����
            for(int k=0; k<n; k++)
            {
                if(!check(output[i][k],input[j][k]))
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                addEdge(i+m,j,val[i]);  //����ĵ���������ĵ�������
                g[i+m][j]=1;
            }
        }
    }
    for(int i=1; i<=m; i++)
    {
        addEdge(i,i+m,val[i]);
        if(check0(i))
            addEdge(st,i,val[i]);   //��δ��ȫװ��������Ҫ��ļ�����볬��Դ������
        if(check1(i))
            addEdge(i+m,ed,val[i]); //�Ѿ���ȫװ��������Ҫ��ļ�����볬���������
    }
    int sum=Dinic();
    int cnt=0;
    for(int i=1; i<=m; i++) //��������Ѱ���м��������������ܴ��Ͷ��ٵ��ԣ�
    {
        for(int j=head[i+m]; j!=-1; j=edge[j].next)
        {
            if(g[i+m][edge[j].to] && edge[j].cap<val[i])
                cnt++;
        }
    }
    printf("%d %d\n",sum,cnt);
    for(int i=1; i<=m; i++) //�ٴα������������
    {
        for(int j=head[i+m]; j!=-1; j=edge[j].next)
        {
            if(g[i+m][edge[j].to] && edge[j].cap<val[i])
                printf("%d %d %d\n",i,edge[j].to,val[i]-edge[j].cap);
        }
    }
    return 0;
}
