//Kosaraju�㷨
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 10005

vector <int> g1[MAXN];  //����ͼ
vector <int> g2[MAXN];  //��ͼ

int vis1[MAXN]; //ԭͼ�Ľ����ʼ�¼����
int vis2[MAXN]; //��ͼ�Ľ����ʼ�¼����
int belong[MAXN];   //ÿ��������ڵ���ͨ�����ı��
int order[MAXN];    //��¼��������ʱ���ı��
int out[MAXN];  //ת��ΪDAG�������޻�ͼ������ĳ���
int ans[MAXN];  //ÿ����㣨�������㣩�����Ľ�㣨ǿ��ͨ�������ĸ���
int index;  //�����DAGͼ�н��ĸ�������
int cnt; //��������ʱ����ű���
int n,m;

void dfs1(int u)    //������������¼ʱ���������ţ�
{
    vis1[u]=1;
    for(int i=0; i<g1[u].size(); i++)
    {
        int v=g1[u][i];
        if(!vis1[v])
            dfs1(v);
    }
    order[cnt++]=u; //����ʱ��¼����ţ�ע�⣺��¼�Ľ��˳��������������˳���෴��
}

void dfs2(int u)
{
    vis2[u]=1;
    belong[u]=index;
    for(int i=0; i<g2[u].size(); i++)
    {
        int v=g2[u][i];
        if(!vis2[v])
        {
            dfs2(v);
            ans[index]++;   //��ͼ���������ĵ㣬˵����Щ�����㶼ͬ����һ��ǿ��ͨ����
        }
    }
}

void init()
{
    memset(out,0,sizeof(out));
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    index=1;
    cnt=1;
}

void kosaraju()
{
    for(int i=0; i<=n; i++)
        ans[i]=1;   //��ʼ��ÿ����㶼�������㣨ֻ����һ����㣩
    for(int i=1; i<=n; i++) //��������
    {
        if(!vis1[i])
            dfs1(i);
    }
    for(int i=cnt-1; i>=1; i--) //��ú��Ժ󣬰�������������˳�����¼˳���෴��˳��������ͼ
    {
        int v=order[i];
        if(!vis2[v])
        {
            dfs2(v);
            index++;
        }
    }
    for(int i=1; i<=n; i++) //����DAGͼ
    {
        for(int j=0; j<g1[i].size(); j++)
        {
            if(belong[i]!=belong[g1[i][j]])
                out[belong[i]]++;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int u,v;
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            g1[u].push_back(v);    //��������ͼ
            g2[v].push_back(u);    //������ͼ
        }
        init();
        kosaraju();
        int tot=0;
        int res=0;
        for(int i=1; i<index; i++)  //����ÿ����ɫ����Ϊ0�ĵ�����㣬����Ϊ0Ψһ
        {
            if(!out[i])
            {
                tot++;
                res=ans[i];
            }
        }
        if(tot>=2)  //�����޻�ͼ��Ψһ����Ϊ0�ĵ㣬һ���������κε�������ɴ�����޻������Դ��κε������ǰ�ߣ���Ȼ��ֹ��һ������Ϊ0�ĵ㣩
            res=0;
        printf("%d\n",res);
    }
    return 0;
}

//Tarjan�㷨
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN 10005

int N,M;

struct Edge
{
    int to,next;
} edge[MAXN*5];

int head[MAXN],tol;

void addEdge(int u,int v)
{
    edge[tol].to = v;
    edge[tol].next = head[u];
    head[u] = tol++;
}

//tarjan
int Belong[MAXN];
int dfn[MAXN];
int low[MAXN];
//int stack[MAXN];
int clock,Bcnt;
//int top;
bool instack[MAXN];
int out[MAXN];//��¼����

stack <int> sta;

void tarjan(int u)
{
    int v;
    dfn[u] = low[u] = ++clock;  //ʱ���
    //stack[top ++] = u;
    sta.push(u);
    instack[u] = true;
    for(int j = head[u]; j != -1; j = edge[j].next)
    {
        v = edge[j].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        Bcnt ++;
        while(!sta.empty())
        {
            v = sta.top();
            instack[v] = false;
            Belong[v] = Bcnt;
            sta.pop();
            if(u == v)
                break;
        }
    }
}

int main()
{
    int u,v;
    int a,b;//����Ҫ�õ���a,b
    scanf("%d%d",&N,&M);

    // ��ͼ
    tol = 0;
    memset(head,-1,sizeof(head));
    while(M --)
    {
        scanf("%d%d",&a,&b);
        addEdge(a,b);
    }

    //tarjan
    memset(dfn,0,sizeof(dfn));
    //Bcnt = top = clock = 0;
    Bcnt = clock = 0;
    for(u = 1; u <= N; u ++)
        if(!dfn[u])
            tarjan(u);

    //tarjan֮��������ĳ���
    memset(out,0,sizeof(out));
    for(u = 1; u <= N; u ++)
    {
        for(int j = head[u]; j != -1; j = edge[j].next)
        {
            v = edge[j].to;
            if(Belong[u] != Belong[v])
                out[Belong[u]] ++;
        }
    }
    int num = 0,ans = 0,flag;//num��¼��������Ϊ0�ĸ�����flag��¼���Ϊ0��������(Ҳ���ǵڼ�������ͨ����)
    for(int i = 1; i <= Bcnt; i ++)
    {
        if(out[i] == 0)
            num ++,flag = i;
    }
    if(num == 1)//ֻ��һ����ͨ����
    {
        for(int i = 1; i <= N; i ++)
        {
            if(Belong[i] == flag)//����������������ͨ����������ţ
                ans ++;
        }
        printf("%d\n",ans);
    }
    else
        printf("0\n");
    return 0;
}
