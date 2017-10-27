#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MAXE 2000005

class TwoSat
{
public:
    int head[MAXN<<1];
    struct Edge
    {
        int to,next;
        Edge() {}
        Edge(int to,int next):to(to),next(next) {}
    } e[MAXE];

    int mark[MAXN<<1];  //mark[i<<1]==1，表示点i被选择；mark[i<<1|1]==1，表示点i没有被选择
    int cnt,scc_cnt,dfs_clock;
    int n,m;
    int c;

    stack <int> sta;
    vector <int> nG[MAXN];    //缩点后建立的新图

    int dfn[MAXN<<1];
    int low[MAXN<<1];
    int belong[MAXN<<1];
    int color[MAXN<<1]; //求解任意一组可行解时记录点的颜色
    int s[MAXN<<1];
    int conflict[MAXN<<1];  //记录新图中的冲突点
    int indegree[MAXN<<1];  //入度

    int l[MAXN];
    vector <int> str[MAXN];
    vector <int> ans;

    //使用前调用
    void init(int m,int n)
    {
        this -> n = n;
        this -> m = m;
        cnt = scc_cnt = dfs_clock = 0;
        memset(dfn,0,sizeof(dfn));
        memset(belong,0,sizeof(belong));
        memset(conflict,0,sizeof(conflict));
        memset(color,0,sizeof(color));
        memset(indegree,0,sizeof(indegree));
        for(int i=0; i<MAXN; i++)
            nG[i].clear();
        while(!sta.empty())
            sta.pop();
    }

    inline void addEdge(int u,int v)
    {
        e[cnt].to = v;
        e[cnt].next = head[u];
        head[u] = cnt++;
    }


    /*判断2-SAT问题是否有解*/
    void tarjan(int u)  //Tarjan算法求解强连通分量并缩点
    {
        dfn[u] = low[u] = ++dfs_clock;
        mark[u] = 1;
        sta.push(u);
        for(int i = head[u]; ~i; i = e[i].next)
        {
            int v = e[i].to;
            if(!dfn[v])
            {
                tarjan(v);
                low[u] = min(low[u],low[v]);
            }
            if(mark[v]==1)
                low[u] = min(low[u],dfn[v]);
        }
        if(dfn[u]==low[u])
        {
            scc_cnt++;
            int temp;
            do
            {
                temp = sta.top();
                belong[temp] = scc_cnt;
                mark[temp] = 0;
                sta.pop();
            }
            while(temp!=u);
        }
    }

    bool check()    //判断缩点后有没有冲突
    {
        for(int i = 1; i<=2*n; i++)
        {
            if(!dfn[i])
                tarjan(i);
        }
        for(int i = 1; i<=n; i++)
        {
            if(belong[i]==belong[i+n])
                return false;
        }
        return true;
    }


    /*求2-SAT问题的任意一组可行解*/
    void cal()  //建立缩点后的新图并为之后的拓扑排序染色做准备
    {
        for(int i = 1; i<=n; i++)
        {
            if(!conflict[belong[i]])
            {
                conflict[belong[i]] = belong[i+n];
                conflict[belong[i+n]] = belong[i];
            }
        }
        for(int i = 1; i<=2*n; i++)
        {
            for(int j = head[i]; ~j; j = e[j].next)
            {
                int v = e[j].to;
                if(belong[i]!=belong[v])
                {
                    indegree[belong[i]]++;
                    nG[belong[v]].push_back(belong[i]);
                }
            }
        }
    }

    void topoSort() //拓扑排序
    {
        queue <int> q;
        for(int i = 1; i<=scc_cnt; i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            if(!color[u])
            {
                color[u] = 1;
                color[conflict[u]] = 2; //conflict数组记录的是与当前点冲突的点
            }
            for(int i = 0; i<nG[u].size(); i++)
            {
                int v = nG[u][i];
                indegree[v]--;
                if(!indegree[v])
                    q.push(v);
            }
        }
    }

    bool buildGraph()
    {
        for(int i = 1; i<=4*n; i++) head[i] = -1,mark[i] = 0;
        for(int i=1; i<=m; i++)
        {
            scanf("%d",&l[i]);
            for(int j=0; j<l[i]; j++)
            {
                int val;
                scanf("%d",&val);
                str[i].push_back(val);
            }
        }
        for(int i=1; i<m; i++)
        {
            bool flag=true;
            for(int j=0; j<min(l[i],l[i+1]); j++)
            {
                if(flag && str[i][j]!=str[i+1][j])
                {
                    flag=false;
                    int u=str[i][j];
                    int v=str[i+1][j];
                    if(u<v)   //已经满足字典序
                    {
                        addEdge(v,u);
                        addEdge(u+n,v+n);
                    }
                    else
                    {
                        addEdge(u+n,u);
                        addEdge(v,v+n);
                    }
                }
            }
            if(flag && l[i]>l[i+1]) //字符一样但是前串长度比后串长
                return false;
        }
        return true;
    }

    void solve()
    {
        if(!buildGraph())
        {
            puts("No");
            return ;
        }
        if(!check())
        {
            puts("No");
            return ;
        }
        cal();
        topoSort();
        puts("Yes");
        for(int i=1; i<=n; i++)
        {
            if(color[belong[i]]==1)
                ans.push_back(i);
        }
        printf("%d\n",ans.size());
        for(int i=0; i<ans.size(); i++)
        {
            if(i)
                printf(" %d",ans[i]);
            else
                printf("%d",ans[i]);
        }
        puts("");
    }
} twosat;

int main()
{
    int n,m;
    scanf("%d%d",&m,&n);
    twosat.init(m,n);
    twosat.solve();
    return 0;
}
