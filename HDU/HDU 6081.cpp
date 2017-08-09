/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXN 3005

int sum[MAXN];
int fa[MAXN];

int findset(int x)
{
    if(x!=fa[x])
        return fa[x]=findset(fa[x]);
    return fa[x];
}

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1; i<=n; i++)
        {
            sum[i]=0;
            fa[i]=i;
        }
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(u==v)
                continue;
            sum[u]+=w;
            sum[v]+=w;
            int uu=findset(u);
            int vv=findset(v);
            if(uu!=vv)
                fa[uu]=vv;
        }
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(fa[i]==i)
                cnt++;
        }
        if(cnt==1)
        {
            sort(sum+1,sum+1+n);
            printf("%d\n",sum[1]);
        }
        else
            puts("0");
    }
    return 0;
}
*/

//O(n^3)复杂度... 超时！
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 3005
#define INF 0x3f3f3f3f

int g[MAXN][MAXN];
int v[MAXN], dis[MAXN]; //v数组是马甲数组，dis数组用来表示该点与A集合中所有点之间的边的长度之和
bool vis[MAXN]; //用来标记是否该点加入了A集合

int Stoer_Wagner(int n)
{
    int i, j, res = INF;
    for(i = 0; i < n; i ++)
        v[i] = i;   //初始马甲为自己
    while(n > 1)
    {
        int k, pre = 0; //pre用来表示之前加入A集合的点，我们每次都以0点为第一个加入A集合的点
        memset(vis, 0, sizeof(vis));
        memset(dis, 0, sizeof(dis));
        for(i = 1; i < n; i ++)
        {
            k = -1;
            for(j = 1; j < n; j ++) //根据之前加入的点，要更新dis数组，并找到最大的dis
                if(!vis[v[j]])
                {
                    dis[v[j]] += g[v[pre]][v[j]];
                    if(k == -1 || dis[v[k]] < dis[v[j]])
                        k = j;
                }
            vis[v[k]] = true;   //标记该点已经加入A集合
            if(i == n - 1)  //最后一次加入的点就要更新答案了
            {
                res = min(res, dis[v[k]]);
                for(j = 0; j < n; j ++) //将该点合并到pre上，相应的边权就要合并
                {
                    g[v[pre]][v[j]] += g[v[j]][v[k]];
                    g[v[j]][v[pre]] += g[v[j]][v[k]];
                }
                v[k] = v[-- n]; //删除最后一个点
            }
            pre = k;
        }
    }
    return res;
}

int main()
{
    int n, m, u, v, w;
    while(~scanf("%d%d", &n, &m))
    {
        memset(g, 0, sizeof(g));
        while(m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            u--;
            v--;
            g[u][v] += w;
            g[v][u] += w;
        }
        printf("%d\n", Stoer_Wagner(n));
    }
    return 0;
}

