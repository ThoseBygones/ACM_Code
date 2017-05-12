//����ģ��ջ
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 10005

struct Node
{
    int v;
    int next;
} edge[MAXN*10];

int head[MAXN]; //ͷ�������
int sta[MAXN];    //��ջ����
int dfn[MAXN]; //�������������
int low[MAXN];  //�ý����߸ý��ĵ������������׷�ݵ�������ջ�н������������
int belong[MAXN];   //ÿ������Ӧ��ǿ��ͨ�����������
int instack[MAXN];  //ÿ������Ƿ��ڶ�ջ�еı������
int n,m;
int cnt;    //�ڽӱ�����
int scnt;   //��ͨ�������
int index;  //ʱ���
int top;    //ջ��ָ��

void init()
{
    memset(head,-1,sizeof(head));
    memset(sta,0,sizeof(sta));
    memset(dfn,0,sizeof(dfn));
    memset(belong,0,sizeof(belong));
    memset(instack,0,sizeof(instack));
    top=0;
    cnt=scnt=0;
    index=0;
}

void addEdge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void tarjan(int u)  //Tarjan�㷨������ͼ��ǿ��ͨ����
{
    dfn[u]=low[u]=++index;
    sta[top++]=u;   //��ջ;
    instack[u]=true;    //�����ջ��
    for(int i=head[u]; i!=-1; i=edge[i].next)   //ö��u��ÿһ����
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);  //dfs����
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]) //�����㻹��ջ��
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])  //����������ͨ�����ĸ�
    {
        scnt++; //��ͨ��������+1
        while(top!=0)   //������ͨ�����е�ÿһ������ջ
        {
            int temp=sta[--top];
            instack[temp]=0;
            belong[temp]=scnt;
            if(temp==u) //ֱ������ͨ�����ĸ����Ҳ��ջʱֹͣ
                break;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m),m,n)
    {
        init();
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
        for(int i=1; i<=n; i++) //ö��ÿ����㣬������ͨ����
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(scnt==1) //���ֻ����һ����ͨ����
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}


//����STLջ
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXN 10005

struct Node
{
    int v;
    int next;
} edge[MAXN*10];

stack <int> sta;

int head[MAXN]; //ͷ�������
int dfn[MAXN]; //�������������
int low[MAXN];  //�ý����߸ý��ĵ������������׷�ݵ�������ջ�н������������
int belong[MAXN];   //ÿ������Ӧ��ǿ��ͨ�����������
int instack[MAXN];  //ÿ������Ƿ��ڶ�ջ�еı������
int n,m;
int cnt;    //�ڽӱ�����
int scnt;   //��ͨ�������
int index;  //ʱ���

void init()
{
    memset(head,-1,sizeof(head));
    memset(dfn,0,sizeof(dfn));
    memset(belong,0,sizeof(belong));
    memset(instack,0,sizeof(instack));
    while(!sta.empty()) //���ջ
        sta.pop();
    cnt=scnt=0;
    index=0;
}

void addEdge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}

void tarjan(int u)  //Tarjan�㷨������ͼ��ǿ��ͨ����
{
    dfn[u]=low[u]=++index;
    sta.push(u);    //��ջ
    instack[u]=true;    //�����ջ��
    for(int i=head[u]; i!=-1; i=edge[i].next)   //ö��u��ÿһ����
    {
        int v=edge[i].v;
        if(!dfn[v])
        {
            tarjan(v);  //dfs����
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]) //�����㻹��ջ��
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])  //����������ͨ�����ĸ�
    {
        scnt++; //��ͨ��������+1
        while(!sta.empty())   //������ͨ�����е�ÿһ������ջ
        {
            int temp=sta.top();
            instack[temp]=0;
            belong[temp]=scnt;
            sta.pop();
            if(temp==u) //ֱ������ͨ�����ĸ����Ҳ��ջʱֹͣ
                break;
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m),m,n)
    {
        init();
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
        for(int i=1; i<=n; i++) //ö��ÿ����㣬������ͨ����
        {
            if(!dfn[i])
                tarjan(i);
        }
        if(scnt==1) //���ֻ����һ����ͨ����
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
