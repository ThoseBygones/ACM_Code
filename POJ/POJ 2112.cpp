#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 240    //200+30
#define INF 0x3f3f3f3f

int dis[MAXN][MAXN];    //�����·���ڽӾ���
int cap[MAXN][MAXN];    //����������ڽӾ���
int level[MAXN];    //��¼ͼ�и���Ĳ��
int k,c,m,n;
int st,ed;  //Դ�㣬���

void build(int x)
{
    memset(cap,0,sizeof(cap));
    st=0;   //����Դ��
    ed=n+1; //�������
    for(int i=1; i<=k; i++)
        cap[st][i]+=m;   //Դ�㵽ţ֮��Ļ�
    for(int i=k+1; i<=k+c; i++)
        cap[i][ed]+=1;  //�����������֮��Ļ�
    for(int i=1; i<=k; i++)
    {
        for(int j=k+1; j<=k+c; j++)
        {
            if(dis[i][j]<=x)    //���ţ��������֮������·<=���ֲ��ҳ���������ֵ
                cap[i][j]+=1;
        }
    }
}

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
        for(int v=0; v<=ed; v++)   //ע��˴������ж���(0,n+1�ǳ���Դ��,���)
        {
            if(level[v]==-1 && cap[u][v])   //�˴�Ӧ��cap[v][i]!=0,��Ϊdfs�ǿ��ܻ��ߴ��������Զ������������
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(level[ed]!=-1)   //���Ĳ�β�����-1˵���ҵ�
        return 1;
    return 0;
}

int dfs(int u,int cur_flow)
{
    int tempf=cur_flow;
    if(u==ed)
        return cur_flow;
    for(int v=0; v<=ed; v++) //ע��˴������ж���
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

void Floyd()
{
    for(int l=1; l<=n; l++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
                dis[i][j]=min(dis[i][j],dis[i][l]+dis[l][j]);
        }
    }
}

int main()
{
    scanf("%d%d%d",&k,&c,&m);
    n=k+c;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&dis[i][j]);
            if(dis[i][j]==0)
                dis[i][j]=INF;
        }
    }
    Floyd();
    int left=0;
    int right=200*n;
    int ans=0;
    while(left<=right)  //���ֲ�������ţ�������·���Ｗ���������ֵ����ʹ�������·���Ｗ����������������һͷţ�ߵ�·������ţ������ģ�
    {
        int mid=(left+right)>>1;
        build(mid);
        if(Dinic()==c)
        {
            ans=mid;
            right=mid-1;
        }
        else
            left=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}
