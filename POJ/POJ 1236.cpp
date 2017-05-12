//tarjan�㷨
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
#define MAXN 105

int g[MAXN][MAXN];
int out[MAXN],in[MAXN];
int dfn[MAXN];									//��һ�η��ʵĲ���
int low[MAXN];									//����������Ĳ���						//ģ��ջ
int instack[MAXN];								//�Ƿ���ջ��
int cnt;										//��¼��ͨ�����ĸ���
int dfs_clock;										//��¼����������ʱ�����
int belong[MAXN];								//�����ĸ���ͨ����
int n;

stack <int> sta;

void init()
{
    cnt=dfs_clock=0;
    while(!sta.empty())
        sta.pop();
    memset(instack,0,sizeof(instack));
    memset(g,0,sizeof(g));
    memset(dfn,0,sizeof(dfn));
}

void tarjan(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    sta.push(u);
    instack[u]=1;
    for(int v=1; v<=n; v++)
    {
        if(g[u][v])
        {
            if(!dfn[v])
            {
                tarjan(v);
                low[u]=min(low[u],low[v]);
            }
            else if(instack[v])
                low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        cnt++;
        while(!sta.empty())
        {
            int temp=sta.top();
            belong[temp]=cnt;
            instack[temp]=0;
            sta.pop();
            if(temp==u)
                break;
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i=1; i<=n; i++)
        {
            int a;
            while(scanf("%d",&a) && a)
                g[i][a]=1;
        }
        for(int i=1; i<=n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        int inzero=0,outzero=0; //��¼���Ϊ��ͳ���Ϊ��ĵ������
        for(int i=1; i<=n; i++)
        {
            in[i]=out[i]=0;
        }
        for(int i=1; i<=n; i++)				//����ͨ������������
        {
            for(int j=1; j<=n; j++)
            {
                if(g[i][j] && belong[i]!=belong[j])
                {
                    in[belong[j]]++;
                    out[belong[i]]++;
                }
            }
        }
        for(int i=1; i<=cnt; i++) 			//����������Ϊ0�ĵ�
        {
            if(!in[i])
                inzero++;
            if(!out[i])
                outzero++;
        }
        if(cnt==1)					//ֻ��1�����Ҫ���У���Ϊ��������B��Ȼ����Ҫ�ӱ߾���ʵ�֣��������н��õ�����Ĵ�0��
            printf("1\n0\n");
        else
            printf("%d\n%d\n",inzero,max(inzero,outzero));  //����B�Ĵ�Ϊ��Ⱥͳ���Ϊ��ĵ���������ֵ���ߣ�ʲôԭ����������ǻ�ͼ������������...��
    }
    return 0;
}
*/


//kosaraju�㷨
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 105

int g1[MAXN][MAXN];
int g2[MAXN][MAXN];
int order[MAXN];
int belong[MAXN];
int in[MAXN];
int out[MAXN];
int vis[MAXN];
int n;
int num,cnt;

void dfs1(int u)
{
    vis[u]=1;
    for(int v=1; v<=n; v++)
    {
        if(g1[u][v])
        {
            if(!vis[v])
                dfs1(v);
        }
    }
    order[++num]=u;
}

void dfs2(int u)
{
    belong[u]=cnt;		//��¼��������ĸ���ͨ����
    vis[u]=1;
    for(int i=1; i<=n; i++)
    {
        if(g2[u][i])
        {
            if(!vis[i])
                dfs2(i);
        }
    }
}

void kosaraju()
{
    memset(vis,0,sizeof(vis));
    num=cnt=0;
    for(int i=1; i<=n; i++)		//��һ��������ʱ�����С��������
    {
        if(!vis[i])
            dfs1(i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=n; i>=1; i--)		//�ڶ���������ʱ�����Ŀ�ʼ������ͨ����
    {
        int v=order[i];
        if(!vis[v])
        {
            cnt++;		//��ͨ��������
            dfs2(v);
        }
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1; i<=n; i++)
        {
            int a;
            while(scanf("%d",&a) && a)
            {
                g1[i][a]=1;
                g2[a][i]=1;
            }
        }
        kosaraju();
        int inzero=0,outzero=0;
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1; i<=n; i++)				//����ͨ������������
        {
            for(int j=1; j<=n; j++)
            {
                if(g1[i][j] && belong[i]!=belong[j])
                {
                    in[belong[j]]++;
                    out[belong[i]]++;
                }
            }
        }
        for(int i=1; i<=cnt; i++) 			//����������Ϊ0�ĵ�
        {
            if(!in[i])
                inzero++;
            if(!out[i])
                outzero++;
        }
        if(cnt==1)					//ֻ��1�����Ҫ����
            printf("1\n0\n");
        else
            printf("%d\n%d\n",inzero,max(inzero,outzero));
    }
    return 0;
}
