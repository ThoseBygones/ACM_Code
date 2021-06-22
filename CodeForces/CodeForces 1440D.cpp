/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 完全图（团） + 结点的度数 + BFS
 ********************************************************************************
 *  Algo-Description:
 * > 题意：给一个无向图，在图中找一个子图：
 *   > 条件 1 ：这个子图中每个点都连接 >= k 条边；
 *   > 条件 2 ：子图为 k 个点的完全图（每个点的度为 k - 1）
 * > 题解：
 *   > 对于每个点的子集，根据度数排序，通过标记法把度数小于 k 的点删除；
 *   > 如果度数为 k - 1，判断与其相连的点是否能构成完全图，如果能则符合条件二，输出答案。
 *   > 否则删掉，最后判断是否存在度数大于等于 k 的点，存在则计算个数并输出，不存在则输出 -1 。
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<LL, LL> PLL;
typedef pair<LL, int> PLI;
typedef pair<LD, LD> PDD;
#define MP make_pair
#define PB push_back
#define sz(x) ((int)(x).size())
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 100005;

//unordered_map<int, bool> ump[MAXN];   //Time limit exceeded on test 9
//map<int, bool> mp[MAXN];  //Time limit exceeded on test 4/6
vector<int> G[MAXN];
int deg[MAXN];  //结点的度数
bool del[MAXN]; //记录哪些结点的度数小于 k（将其删除）
bool vis[MAXN]; //记录哪些未被删除的结点被访问过（在团clique中）

void solve(int n, int k)
{
    vector<int> clique;
    queue<int> q;
    for(int i = 1; i <= n; i++)
    {
        if(deg[i] < k)  //度数小于k的结点入队
        {
            q.push(i);
            del[i] = true;
        }
    }
    bool flag = false;  //是否找得到符合条件二的 k 个点的完全子图
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(deg[u] == k - 1) //找到度数为 k - 1 的点，即找条件二中 k 个点的完全子图
        {
            clique.clear();
            clique.PB(u);
            for(auto &v: G[u])
            {
                if(!vis[v])
                    clique.PB(v);
            }
            bool com_g = true;  //是否是完全图
            for(auto &v: clique)
            {
                for(auto &w: clique)
                {
                    if(v == w)
                        break;
                    //if(!ump[v][w] || !ump[w][v])
                    //if(!mp[v][w] || !mp[w][v])
                    if(!binary_search(G[v].begin(), G[v].end(), w)) //在点v的邻接表（已经按照点的编号从小到大排序）中二分查找是否存在点 w（以此判断是否存在边(v, w)）。
                    {
                        com_g = false;
                        break;
                    }
                }
                if(!com_g)
                    break;
            }
            if(com_g)   //是完全图，直接结束
            {
                flag = true;
                break;
            }
        }
        del[u] = true;  //点u不是构成条件二中 k 个点的完全子图，因此将其删除
        vis[u] = true;  //点u也不会作为团中某个点
        for(auto &v: G[u])
        {
            deg[v]--;   //修改与 u 相邻的点 v 的度数，即删除所有的边 (u, v)
            if(del[v])  //如果已经被删除，则不考虑这个点
                continue;
            if(deg[v] < k)    //度数小于 k，则加入队列
            {
                del[v] = true;
                q.push(v);
            }
        }
    }
    if(flag)    //找到符合条件二的 k 个点的完全子图
    {
        puts("2");
        for(int i = 0; i < clique.size(); i++)  //打印出团中的点
            printf("%d%c", clique[i], (i == clique.size() - 1 ? '\n' : ' '));
    }
    else    //找到符合条件一的每个点都连接大于等于 k 条边的子图
    {
        int cnt = 0;
        vector<int> ans;
        for(int i = 1; i <= n; i++) //记录没有被删除的点（度数大于等于k）
        {
            if(!del[i])
            {
                cnt++;
                ans.PB(i);
            }
        }
        if(cnt)
        {
            printf("1 %d\n", cnt);
            for(int i = 0; i < ans.size(); i++)
                printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
        }
        else
            puts("-1");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
        {
            G[i].clear();
            deg[i] = 0;
            del[i] = vis[i] = false;
            //ump[i].clear();
            //mp[i].clear();
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u].PB(v);
            G[v].PB(u);
            deg[u]++, deg[v]++;
            //ump[u][v] = ump[v][u] = true;
            //mp[u][v] = mp[v][u] = true;
        }
        if(1LL * k * (k - 1) / 2 > (LL)m)   //边数不足以构成 k 完全子图
        {
            puts("-1");
            continue;
        }
        for(int i = 1; i <= n; i++)
            sort(G[i].begin(), G[i].end()); //对每个点的邻接表排序（邻接点按照编号从小到大排序）
        solve(n, k);
    }
    return 0;
}
