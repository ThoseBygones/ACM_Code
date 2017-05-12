#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005

struct Graph
{
    int from;
    int to;
    int next;
} g1[MAXN*10],g2[MAXN*10];    //����ͼ����ͼ

int order[MAXN];    //��������ʱ��¼�Ľ��˳��
int head1[MAXN];    //ԭͼ��ͷ���
int head2[MAXN];    //��ͼ��ͷ���
int belong[MAXN];   //���Ĺ���
int out[MAXN];  //ת��ΪDAG��ÿ���������㣨ǿ��ͨ�������ĳ���
int vis[MAXN];
int e;  //�ߵ�����
int num;    //�ڵ�����
int cnt;    //ת��ΪDAG���㣨�������㣩��������ǿ��ͨ����������
int n,m;

void addEdge(int u,int v)
{
    g1[e].from=u;
    g1[e].to=v;
    g1[e].next=head1[u];
    head1[u]=e;
    g2[e].from=v;
    g2[e].to=u;
    g2[e].next=head2[v];
    head2[v]=e++;
}

void dfs1(int u)    //�������������ʱ���
{
    vis[u]=1;
    for(int i=head1[u]; i!=-1; i=g1[i].next)
    {
        int v=g1[i].to;
        if(!vis[v])
            dfs1(v);
    }
    order[++num]=u;
}

void dfs2(int u)    //����������Ѱ��ǿ��ͨ�������������
{
    vis[u]=1;
    belong[u]=cnt;
    for(int i=head2[u]; i!=-1; i=g2[i].next)
    {
        int v=g2[i].to;
        if(!vis[v])
            dfs2(v);
    }
}

void kosaraju()
{
    num=0;
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=n; i>=1; i--)
    {
        int v=order[i];
        if(!vis[v])
        {
            cnt++;
            dfs2(v);
        }
    }
    memset(out,0,sizeof(out));
    for(int i=1; i<=n; i++)
    {
        for(int j=head1[i]; j!=-1; j=g1[j].next)
        {
            if(belong[i]!=belong[g1[j].to])
                out[belong[i]]++;
        }
    }
}

int main()
{
    while(~scanf("%d",&n),n)
    {
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        e=0;
        scanf("%d",&m);
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
        }
        kosaraju();
        memset(vis,0,sizeof(vis));
        for(int i=1; i<=n; i++) //sink���ʵ���ǳ���Ϊ0��ǿ��ͨ�����е����е㣬��Ϊǿ��ͨ�����������һ�����ǻ�㣬���������е㶼�ǻ�㣨����ǿ��ͨ�������壩������һ���㻹�ܵ��������������㣬������Ҫ��
        {
            if(!out[belong[i]]) //���ĳ����������ǿ��ͨ��������Ϊ�㣬���ǿ��ͨ��������Ҫ��
                vis[i]=1;
        }
        bool flag=true;
        for(int i=1; i<=n; i++)
        {
            if(vis[i])  //���ֱ���ǵĶ���
            {
                if(flag)
                {
                    printf("%d",i);
                    flag=false;
                }
                else
                    printf(" %d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
