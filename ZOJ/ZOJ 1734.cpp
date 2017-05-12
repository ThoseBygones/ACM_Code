#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 105
#define INF 0x3f3f3f3f

int cap[MAXN][MAXN];    //��¼ͼ���ڽӾ���
int level[MAXN];    //��¼ͼ�и���Ĳ��
int n,m;    //��,��
int np,nc;
int st,en;  //Դ�㣬���

int bfs()
{
    queue <int> q;
    memset(level,-1,sizeof(level));
    level[st]=0;    //����������ͺ�������ѭ��
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0; v<=n+1; v++)   //ע��˴������ж���(0,n+1�ǳ���Դ��,���)
        {
            if(level[v]==-1 && cap[u][v])   //�˴�Ӧ��cap[v][i]!=0,��Ϊdfs�ǿ��ܻ��ߴ��������Զ������������
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(level[en]!=-1)   //���Ĳ�β�����-1˵���ҵ�
        return 1;
    return 0;
}

int dfs(int u,int cur_flow)
{
    int tempf=cur_flow;
    if(u==en)
        return cur_flow;
    for(int v=0; v<=n+1; v++) //ע��˴������ж���
    {
        if(cap[u][v]>0 && level[u]+1==level[v])
        {
            int flow=dfs(v,min(tempf,cap[u][v]));
            cap[u][v]-=flow;
            cap[v][u]+=flow;
            tempf-=flow;
        }
    }
    return cur_flow-tempf;
}

int Dinic()
{
    int ans=0;
    while(bfs())    //һ��bfs�����ҵ���������·
        ans+=dfs(st,INF);
    return ans;
}

int main()
{
    while(~scanf("%d%d%d%d",&n,&np,&nc,&m))
    {
        int u,v,c;
        memset(cap,0,sizeof(cap));
        for(int i=1; i<=m; i++)
        {
            scanf(" (%d,%d)%d",&u,&v,&c);
            cap[u+1][v+1]+=c;
        }
        for(int i=1; i<=np; i++)
        {
            scanf(" (%d)%d",&v,&c);
            cap[0][v+1]+=c;
        }
        for(int i=1; i<=nc; i++)
        {
            scanf(" (%d)%d",&u,&c);
            cap[u+1][n+1]+=c;
        }
        st=0;
        en=n+1;
        int ans=Dinic();
        printf("%d\n",ans);
    }
    return 0;
}
