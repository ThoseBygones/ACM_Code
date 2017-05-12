#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 105
#define MAXM 1005
#define INF 0x3f3f3f3f

int level[MAXN];    //�������
int flow[MAXN][MAXN];   //�������磨����������
int vis[MAXM];  //��¼��Ȧ���ĸ��˿ʹ򿪹�
int pigs[MAXM]; //��¼ÿ����Ȧ�����������
int maxflow;    //�����
int m,n;

int bfs()
{
    queue <int> q;
    memset(level,-1,sizeof(level));
    level[n+1]=0;
    q.push(n+1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<=n+1; i++)
        {
            if(level[i]==-1 && flow[i][u])
            {
                level[i]=level[u]+1;
                q.push(i);
            }
        }
        if(u==0)
            return 1;
    }
    return 0;
}

int dfs(int u,int f)    //ǰ����ǰ��
{
    if(u==n+1)
        return f;
    int tempf=f;
    int tf;
    for(int i=0; i<=n+1 && tempf; i++)
    {
        if(level[i]+1==level[u] && flow[u][i])
        {
            tf=dfs(i,min(flow[u][i],tempf));
            flow[u][i]-=tf;
            flow[i][u]+=tf;
            tempf-=tf;
        }
    }
    return f-tempf;
}

void Dinic()
{
    maxflow=0;
    while(bfs())
        maxflow+=dfs(0,INF);
}

int main()
{
    int k,a,b;
    scanf("%d%d",&m,&n);
    memset(flow,0,sizeof(flow));
    memset(vis,0,sizeof(vis));
    for(int i=1; i<=m; i++)
        scanf("%d",&pigs[i]);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a);
        for(int j=1; j<=a; j++)
        {
            scanf("%d",&k);
            if(!vis[k])
                flow[0][i]+=pigs[k];
            else
                flow[vis[k]][i]=INF; //������Ȧ�ѱ��򿪹�������Կ��Ǵӱ����Ȧ��������������Ȧ��
            vis[k]=i;   //��¼���һ�����ʸ���Ȧ�Ĺ˿ͱ��
        }
        scanf("%d",&b);
        flow[i][n+1]=b; //���пͻ���㶼��������
    }
    Dinic();
    printf("%d\n",maxflow);
    return 0;
}
