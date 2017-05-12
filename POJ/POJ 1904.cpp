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
        for(int i=0; i<=n; i++)
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
