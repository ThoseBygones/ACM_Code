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

int head[MAXN]; //前向星
int level[MAXN];    //层数
int num;    //边的数目
int n,m,k;
int st,ed;  //源点，汇点
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
            if(edge[i].cap>0 && level[v]==-1)   //流量不为零（是前向弧）且弧的终点未被标记过
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
    if(u==ed)    //把流推到了T节点（汇点）,结束
        return flow;
    int tempf=0;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(level[u]+1==level[v] && edge[i].cap>0)   //1.倒序追踪找前一个点；2.流量不为负
        {
            int f=dfs(v,min(edge[i].cap,flow-tempf));  //可行流流量为整个增广路中最小的弧的增量
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
    int cnt=1;  //求字符串的Hash值（即将字符串对应各点）
    char name[30];
    char type[30];
    st=0;   //超级源点
    ed=MAXN-1; //汇点
    for(int i=1; i<=n; i++)
    {
        scanf("%s",type);
        mp[type]=cnt++;
        addEdge(st,mp[type],1);  //表示可能需要插到房间插座的插头类型（可能从源点流出的流）
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
        addEdge(mp[type2],mp[type],INF);    //建模后的流流向：房间插座->适配器插头->适配器插座->电器
        //cout << mp[type2] << " - " << mp[type] << " = INF" << endl;
    }
    //system("pause");
    Dinic();
    printf("%d\n",m-ans);
    return 0;
}
