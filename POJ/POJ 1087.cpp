#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
using namespace std;

#define MAXN 510    //100+100*2+100*2
#define MAXM 1005
#define INF 0x3fffffff

struct Edge
{
    int to;
    int next;
    int cap;
} edge[MAXN*MAXN];

map <string,int> mp;

int head[MAXN]; //ǰ����
int level[MAXN];    //����
int num;    //�ߵ���Ŀ
int n,m,k;
int st,ed;  //Դ�㣬���
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
}

int bfs()
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
        //if(u==ed)
            //return true;
    }
    if(level[ed]!=-1)
        return 1;
    return 0;
}

int dfs(int u,int flow)
{
    if(u==ed)    //�����Ƶ���T�ڵ㣨��㣩,����
        return flow;
    int tempf=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(level[u]+1==level[v] && edge[i].cap>0)   //1.����׷����ǰһ���㣻2.������Ϊ��
        {
            int f=dfs(v,min(edge[i].cap,flow-tempf));  //����������Ϊ��������·����С�Ļ�������
            edge[i].cap-=f;
            edge[i^1].cap+=f;
            tempf+=f;
        }
    }
    return tempf;
}

void Dinic()
{
    while(bfs())
    {
        ans+=dfs(0,INF);
        //cout << ans << endl;
    }

}

int main()
{
    init();
    ans=0;
    scanf("%d",&n);
    int cnt=1;  //���ַ�����Hashֵ�������ַ�����Ӧ���㣩
    char name[30];
    char type[30];
    st=0;   //����Դ��
    ed=MAXN-1; //���
    for(int i=1; i<=n; i++)
    {
        scanf("%s",type);
        mp[type]=cnt++;
        addEdge(st,mp[type],1);  //��ʾ������Ҫ�嵽��������Ĳ�ͷ���ͣ����ܴ�Դ������������
        //cout << st << " - " << mp[type] << " = 1" << endl;
    }
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%s%s",name,type);
        mp[name]=cnt++;
        if(!mp[type])
            mp[type]=cnt++;
        addEdge(mp[type],mp[name],1);
        //cout << mp[type] << " - " << mp[name] << " = 1" << endl;
        addEdge(mp[name],ed,1);
        //cout << mp[name] << " - " << ed << " = 1" << endl;
    }
    scanf("%d",&k);
    for(int i=1; i<=k; i++)
    {
        char type2[30];
        scanf("%s%s",type,type2);
        if(!mp[type])
            mp[type]=cnt++;
        if(!mp[type2])
            mp[type2]=cnt++;
        addEdge(mp[type2],mp[type],INF);    //��ģ��������򣺷������->��������ͷ->����������->����
        //cout << mp[type2] << " - " << mp[type] << " = INF" << endl;
    }
    //system("pause");
    Dinic();
    printf("%d\n",m-ans);
    return 0;
}
