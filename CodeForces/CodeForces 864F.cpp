#include <bits/stdc++.h>
using namespace std;

#define MAXN 3005
#define MAXM 3005
#define MAXQ 400010
#define INF 0x3fffffff

struct Query
{
    int s,t,k;
    int id;
    bool operator <(const Query &x) const
    {
        return s<x.s;
    }
} qry[MAXQ];

int dfn[MAXN];
int low[MAXN];
int sta[MAXN];  //数组模拟栈
bool instack[MAXN]; //判断是否在栈中
vector <int> g[MAXN];
vector <Query> Q[MAXN];
int ans[MAXQ];
int dfs_clock;
int top;    //栈顶指针

void tarjan(int u,bool flag)
{
    dfn[u]=++dfs_clock;
    low[u]=INF;
    sta[top++]=u;
    instack[u]=1;
    if(flag)    //没有形成环
    {
        for(int i=0; i<Q[u].size(); i++)    //枚举s->t点的不同k
        {
            if(Q[u][i].k<=top)
                ans[Q[u][i].id]=sta[Q[u][i].k-1];   //第k个点就是栈中存储的从u出发经过的第k-1个点
        }
    }
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(!dfn[v])
        {
            tarjan(v,flag&&dfn[u]<low[u]); //回边不能回到比当前结点时间戳还小的点，否则会形成环
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    instack[u]=0;
    --top;  //栈顶元素出栈（还原现场）
}

int main()
{
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0; i<m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
    for(int i=1; i<=n; i++) //对边按照结点编号的字典序排序
        sort(g[i].begin(),g[i].end());
    for(int i=0; i<q; i++)
    {
        scanf("%d%d%d",&qry[i].s,&qry[i].t,&qry[i].k);
        qry[i].id=i;
    }
    sort(qry,qry+q);
    memset(ans,-1,sizeof(ans));
    for(int i=0; i<q; i++)
    {
        Q[qry[i].t].push_back(qry[i]);  //对于已经枚举的一个s，根据不同的t，记录对应的查询信息
        if(qry[i].s!=qry[i+1].s)    //下一组询问的起点s不再与之前的相同，因此这次就可以开始处理所有起点为s的询问了
        {
            memset(dfn,0,sizeof(dfn));
            memset(low,0,sizeof(low));
            memset(instack,0,sizeof(instack));
            dfs_clock=top=0;
            tarjan(qry[i].s,1);
            memset(Q,0,sizeof(Q));
        }
    }
    for(int i=0; i<q; i++)
        printf("%d\n",ans[i]);
    return 0;
}
