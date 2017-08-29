//暴力建图+SPFA：904ms 200KB
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10005
#define INF 0x3f3f3f3f

typedef int Type;

class SPFA
{
public:
    Type d[MAXN];
    int n,m,k;
    int s;
    bool flag;  //终点是否为永久亮点

    struct Node
    {
        int x,y;
    } p[MAXN];

    bool inq[MAXN];

    void init(int n,int m,int k)
    {
        flag = false;
        this -> n = n;
        this -> m = m;
        this -> k = k;
    }

    Type spfa(int s)
    {
        for(int i = 0; i <= k; i++) inq[i] = false,d[i] = INF;
        d[s] = 0;
        queue <int> q;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;
            for(int i = 1; i <= k; i++)
            {
                if(i == u)
                    continue;
                int w = INF;
                int dx = abs(p[u].x - p[i].x);
                int dy = abs(p[u].y - p[i].y);
                if(dx + dy == 1)    //坐标相邻直接可达
                    w = 0;
                else if(dx <= 2 || dy <= 2)  //坐标在相邻行（列）不相邻点或者隔着一行（列）都能通过点亮相邻行（列）来实现连通
                    w = 1;
                if(d[u] + w < d[i])
                {
                    d[i] = d[u] + w;
                    if(!inq[i])
                    {
                        inq[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        return d[k] == INF ? -1 : d[k];
    }

    void solve()
    {
        for(int i=1; i<=k; i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            if(p[i].x == 1 && p[i].y == 1) s = i;
            if(p[i].x == n && p[i].y == m) flag = true;
        }
        if(!flag)   //终点不是(n,m)则设置虚拟终点为(n+1,m+1)，这样能到达虚拟终点一定能到达真正的终点
        {
            k++;
            p[k].x = n + 1;
            p[k].y = m + 1;
        }
        int ans=spfa(s);
        printf("%d\n",ans);
    }
} spfa;

int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    spfa.init(n,m,k);
    spfa.solve();
    return 0;
}


//拆点建图+SPFA：31ms 7700KB
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
using namespace std;

const int maxn = 5e4 + 5;
const int INF = 1e9 + 5;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};

struct node
{
    int x, y;
    node() {}
    node(int xx, int yy): x(xx), y(yy) {}
} a[maxn];

vector<node> v[maxn];
map<int, int> mp[maxn];
int dis[maxn], book[maxn], n, m, k, star;

void spfa(int u)  //spfa
{
    memset(book, 0, sizeof(book));
    for(int i = 1; i < maxn; i++) dis[i] = INF;
    dis[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        book[u] = 0;
        for(int i = 0; i < v[u].size(); i++)
        {
            int to = v[u][i].x, w= v[u][i].y;
            if(dis[to] > dis[u]+w)
            {
                dis[to] = dis[u]+w;
                if(!book[to])
                {
                    book[to] = 1;
                    q.push(to);
                }
            }
        }
    }
    int ans = INF;
    for(int i = 1; i <= k; i++)
    {
        if(a[i].x == n && a[i].y == m)  //如果终点本来是亮着的，那就直接是到这个点的dis就好了
            ans = min(ans, dis[i]);
        if((n-a[i].x) <= 1 || (m-a[i].y) <= 1) //如果没亮着，只能跟在他某一行/列或者相邻行/列才行，相隔一行过不去，因为终点不是亮着的
            ans = min(ans, dis[i]+1);  //这两种方式取一个最小值
    }
    if(ans == INF)
        puts("-1");
    else
        printf("%d\n", ans);
}

int main()
{
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        memset(book, 0, sizeof(book));
        for(int i = 1; i <= maxn; i++)
            mp[i].clear(), v[i].clear();
        for(int i = 1; i <= k; i++)
        {
            scanf("%d%d", &a[i].x, &a[i].y);
            mp[a[i].x][a[i].y] = i;  //map记录每个横纵坐标是第几个出现的，也就是第几个点
            if(a[i].x == 1 && a[i].y == 1) //找出1,1点是第几个点，他肯定要亮着，否则走不到

                star = i;
        }
        for(int i = 1; i <= k; i++)  //把相邻的点之间建好边
        {
            for(int j = 0; j < 4; j++)  //看他周围有亮着点吗
            {
                int tx = a[i].x + dir[j][0];
                int ty = a[i].y + dir[j][1];
                if(mp[tx][ty])
                {
                    v[mp[tx][ty]].push_back(node(i, 0));
                    v[i].push_back(node(mp[tx][ty],0));
                }
            }
        }
        for(int i = 1; i <= k; i++)  //建立每行每列的出点入点
        {
            v[i].push_back(node(a[i].x+k, 0));
            v[a[i].x+k+n].push_back(node(i, 0));
            v[i].push_back(node(a[i].y+k+2*n, 0));
            v[a[i].y+k+2*n+m].push_back(node(i, 0));
        }
        for(int i = 1; i <= n; i++)  //建立每个点到相邻2个以内的行列的边，通过与对应行列的入点出点建边
        {
            for(int j = -2; j <= 2; j++)
            {
                int tmp = i+j;
                if(tmp >= 1 && tmp <= n)
                {
                    v[tmp+k].push_back(node(i+k+n,1));
                    v[i+k].push_back(node(tmp+k+n,1));
                }
            }
        }
        for(int i = 1; i <= m; i++)
        {
            for(int j = -2; j <= 2; j++)
            {
                int tmp = i+j;
                if(tmp >= 1 && tmp <= m)
                {
                    v[tmp+k+n*2].push_back(node(i+k+2*n+m,1));
                    v[i+k+n*2].push_back(node(tmp+k+n*2+m,1));
                }
            }
        }
        spfa(star);
    }
    return 0;
}
