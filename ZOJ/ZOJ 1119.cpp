#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 1005

int edge[MAXN][MAXN];   //�ڽӾ���
int vis[MAXN];  //����ķ���״̬
int dfn[MAXN];  //ÿ�������dfn�������������������ֵ
int low[MAXN];  //ÿ�������lowֵ
int subnets[MAXN];  //��¼ÿ���ڵ㣨ȥ���ýڵ��ʣ�ࣩ����ͨ��������
int son;    //���ڵ����Ů����
int nodes;  //��¼����Ľڵ���
int tempdfn;    //��¼dfs���������е�ǰ״̬�µ�dfnֵ

void dfs(int u) //ʹ��tarjan�㷨���㣨�ؽڵ㣩
{
    for(int v=1; v<=nodes; v++)
    {
        if(edge[u][v])  //u��v�����ڽӣ�����������������е���������֣�1.v��u��һ���ӽڵ㣨���ӣ���2.v��u�����ȣ���(u,v)��һ���ر�
        {
            if(!vis[v]) //������ĵ�1�����
            {
                vis[v]=1;
                tempdfn++;
                dfn[v]=low[v]=tempdfn;
                dfs(v);
                low[u]=min(low[u],low[v]);  //���˵�ʱ�����low��ֵ
                if(low[v]>=dfn[u])  //u��Ϊ�ؽڵ�ĳ�Ҫ����֮һ
                {
                    //u��Ϊ�ؽڵ����һ����Ҫ����
                    if(u!=1)    //�������㲻�Ǹ��ڵ㣬���¼���ӽڵ�������ͨ����������һ
                        subnets[u]++;
                    if(u==1)    //���������Ǹ��ڵ㣬���¼���ڵ�Ķ������һ
                        son++;
                }
            }
            else    //���˵��ѱ����ʹ�������2�������
                low[u]=min(low[u],dfn[v]);
        }
    }
}

void init()
{
    memset(vis,0,sizeof(vis));
    memset(subnets,0,sizeof(subnets));
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    son=0;
    dfn[1]=low[1]=1;
    tempdfn=1;
    vis[1]=1;
}

int main()
{
    int kase=1;
    int u,v;
    while(~scanf("%d",&u),u)
    {
        memset(edge,0,sizeof(edge));
        nodes=0;
        scanf("%d",&v);
        nodes=max(nodes,u);
        nodes=max(nodes,v);
        edge[u][v]=edge[v][u]=1;
        while(~scanf("%d",&u),u)
        {
            scanf("%d",&v);
            nodes=max(nodes,u);
            nodes=max(nodes,v);
            edge[u][v]=edge[v][u]=1;
        }
        init();
        dfs(1);
        if(kase>1)
            printf("\n");
        printf("Network #%d\n",kase++);
        if(son>1)
            subnets[1]=son-1;   //�ȼ�ȥ1���Ա���һ���ı������нڵ��ʱ��ͳһ����1
        bool flag=false;
        for(int i=1; i<=nodes; i++)
        {
            if(subnets[i])
            {
                flag=true;
                printf("  SPF node %d leaves %d subnets\n",i,subnets[i]+1);
            }
        }
        if(!flag)
            printf("  No SPF nodes\n");
        //printf("\n");
    }
    return 0;
}
