//邻接矩阵（vector）
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define MAXN 4010   //扩展结点，王子编号1~2000，女孩编号2001~4000

vector <int> g[MAXN];
vector <int> ans[MAXN];
stack <int> s;

int dfn[MAXN];
int low[MAXN];
int belong[MAXN];
int instack[MAXN];
int dfs_clock;  //时间戳
int cnt;    //强连通分量数量
int n;

void tarjan(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    s.push(u);
    instack[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        while(!s.empty())
        {
            int temp=s.top();
            belong[temp]=cnt;
            instack[temp]=0;
            s.pop();
            if(temp==u)
                break;
        }
    }
}

void init()
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
    memset(instack,0,sizeof(instack));
    while(!s.empty())
        s.pop();
    dfs_clock=0;
    cnt=0;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=0; i<=2*n; i++)
        {
            g[i].clear();
            ans[i].clear();
        }
        for(int i=1; i<=n; i++)
        {
            int num;
            scanf("%d",&num);
            while(num--)
            {
                int t;
                scanf("%d",&t);
                g[i].push_back(t+n);
            }
        }
        for(int i=1; i<=n; i++) //完备匹配——形成强连通分量
        {
            int t;
            scanf("%d",&t);
            g[t+n].push_back(i);
        }
        init();
        for(int i=1; i<=n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<g[i].size(); j++)    //对于王子喜欢的女孩，如果该女孩跟王子在同一个强连通分量内，则将其记录在该王子名字的后面（即可选项）
            {
                int v=g[i][j];
                if(belong[i]==belong[v])
                {
                    ans[i].push_back(v-n);
                }
            }
            sort(ans[i].begin(),ans[i].end());  //从大到小输出
        }
        for(int i=1; i<=n; i++)
        {
            int sz=ans[i].size();
            printf("%d",sz);
            for(int j=0; j<sz; j++)
                printf(" %d",ans[i][j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


//邻接表
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXN 4010

struct Edge
{
    int from;
    int to;
    int next;
} edge[300010];

int head[MAXN];
int dfn[MAXN];
int low[MAXN];
int instack[MAXN];
int belong[MAXN];
int ans[MAXN];  //记录女孩编号的数组
int e;  //边的数量
int dfs_clock;  //时间戳
int cnt;    //强连通分量的数量
int n;

stack <int> sta;

void AddEdge(int u,int v)
{
    edge[e].to=v;
    edge[e].next=head[u];
    head[u]=e++;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++dfs_clock;
    sta.push(u);
    instack[u]=1;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v=edge[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        cnt++;
        while(!sta.empty())
        {
            int temp=sta.top();
            sta.pop();
            instack[temp]=0;
            belong[temp]=cnt;
            if(temp==u)
                break;
        }
    }
}

void init()
{
    cnt=dfs_clock=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(instack,0,sizeof(instack));
    memset(belong,0,sizeof(belong));
    while(!sta.empty())
        sta.pop();
}

int main()
{
    while(~scanf("%d",&n))
    {
        int m,x;
        e=0;
        memset(head,-1,sizeof(head));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(int j=1; j<=m; j++)
            {
                scanf("%d",&x);
                AddEdge(i,n+x);
            }
        }
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            AddEdge(n+x,i);
        }
        init();
        for(int i=1; i<=2*n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        for(int i=1; i<=n; i++) //遍历图中的边,如果起点终点在同一个连通分量,那么就是合法点对
        {
            int num=0;
            for(int j=head[i]; j!=-1; j=edge[j].next)
            {
                int v=edge[j].to;
                if(belong[i]==belong[v])
                {
                    ans[num++]=v-n;
                }
            }
            sort(ans,ans+num);
            printf("%d",num);
            for(int j=0; j<num; j++)
                printf(" %d", ans[j]);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
