#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

#define MAXN 505
#define INF 0x3f3f3f3f

map <string,int> mp;

int cap[MAXN][MAXN];    //记录图的邻接矩阵
int level[MAXN];    //记录图中各点的层次
int n,m,k;    //点,边
int st,ed;  //源点，汇点

int bfs()
{
    queue <int> q;
    memset(level,-1,sizeof(level));
    level[st]=0;    //如果处理不慎就很容易死循环
    q.push(st);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=0; v<=ed; v++)   //注意此处是所有顶点(0,n+1是超级源点,汇点)
        {
            if(level[v]==-1 && cap[u][v])   //此处应是cap[v][i]!=0,因为dfs是可能会走错，这样可以对其进行修正。
            {
                level[v]=level[u]+1;
                q.push(v);
            }
        }
    }
    if(level[ed]!=-1)   //汇点的层次不等于-1说明找到
        return 1;
    return 0;
}

int dfs(int u,int cur_flow)
{
    int tempf=cur_flow;
    if(u==ed)
        return cur_flow;
    for(int v=0; v<=ed; v++) //注意此处是所有顶点
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
    while(bfs())    //一次bfs可以找到几条增广路
        ans+=dfs(st,INF);
    return ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        mp.clear();
        int cnt=1;  //求字符串的Hash值（即将字符串对应各点）
        char name[30];
        char type[30];
        st=0;   //超级源点
        ed=MAXN-1; //汇点
        memset(cap,0,sizeof(cap));
        for(int i=1; i<=n; i++)
        {
            scanf("%s",type);
            mp[type]=cnt++;
            cap[st][mp[type]]=1;  //表示可能需要插到房间插座的插头类型（可能从源点流出的流）
        }
        scanf("%d",&m);
        for(int i=1; i<=m; i++)
        {
            scanf("%s%s",name,type);
            mp[name]=cnt++;
            if(!mp[type])
                mp[type]=cnt++;
            cap[mp[type]][mp[name]]=1;
            cap[mp[name]][ed]=1;
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
            cap[mp[type2]][mp[type]]=INF;    //建模后的流流向：房间插座->适配器插头->适配器插座->电器
        }
        int ans=Dinic();
        printf("%d\n",m-ans);
        if(t)
            puts("");
    }
    return 0;
}
