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
int cat[MAXN];  //ĳ���ڵ��Ƿ���è
int n,m;
int cnt;    //����è������
int e;  //�ߵ�����

void addEdge(int u,int v)
{
    edge[e].to=v;
    edge[e].next=head[u];
    head[u]=e++;
}

void dfs(int u,int fa,int num)
{
    if(cat[u])  //���������è�������ۼ�
        num++;
    else    //�������
        num=0;
    if(num>m)   //��֦���������������������������������·�Ͳ������ˣ����ؼ�������ȥ
        return ;
    bool flag=true;  //�ж��Ƿ񵽴��յ�ı�־
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(v!=fa)   //�����յ㣿
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
