/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-02-05
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: LCA���߱��� + dp
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x)
{
    return x * x;
}
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

const int MAXN = 50005;
const int MAXE = 100005;

class LCA_Multiplication
{
public:

    int head[MAXN], nxt[MAXE], e[MAXE];
    int cnt;

    void init(int n)
    {
        this -> n = n;
        cnt = 0;
        memset(head, -1, sizeof(head));
    }

    inline void addEdge(int u, int v)
    {
        e[cnt] = v;
        int tmp = head[u];
        head[u] = cnt;
        nxt[cnt++] = tmp;
    }

    int dep[MAXN], val[MAXN];
    int p[MAXN][20];
    int n;

    int Max[MAXN][20], Min[MAXN][20];   //Max/Min[i][j]��ʾ��i��i����2^j�����֮���Ȩ�����ֵ/��Сֵ�����/С�۸�
    int up[MAXN][20], down[MAXN][20];   //up/down[i][j]��ʾ��i��i����/����2^j����������Ȩ�����ۣ�

    void dfs(int u, int fa, int d)
    {
        dep[u] = d;
        p[u][0] = fa;
        for(int i = head[u]; ~i; i = nxt[i])
        {
            int v = e[i];
            if(v == fa)
                continue;
            Max[v][0] = max(val[u], val[v]);
            Min[v][0] = min(val[u], val[v]);
            up[v][0] = max(0, val[u] - val[v]); //v -> u
            down[v][0] = max(0, val[v] - val[u]);   //u -> v
            dfs(v, u, d + 1);
        }
    }

    int LCA(int u, int v)
    {
        if(dep[u] > dep[v])
            swap(u, v);
        if(dep[u] < dep[v])
        {
            int offset = dep[v] - dep[u];
            for(int i = 0; (1 << i) <= n; i++)
            {
                if(offset & (1 << i))
                    v = p[v][i];
            }
        }
        if(u != v)
        {
            for(int i = log2(n); i >= 0; i--)
            {
                if(p[u][i] != p[v][i])
                    u = p[u][i], v = p[v][i];
            }
            u = p[u][0], v = p[v][0];
        }
        return u;
    }

    void buildGraph()
    {
        for(int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        for(int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
    }

    int queryUp(int u, int s, int &minval)  //���ϲ�ѯ
    {
        int ans = 0;
        for(int i = 16; i >= 0; i--)    //2 ^ 16 = 65536 > 50000
        {
            if(s & (1 << i))
            {
                ans = max(max(up[u][i], Max[u][i] - minval), ans);  //����������;��Ȩ��
                minval = min(Min[u][i], minval);    //����������;��Ȩ��Сֵ
                u = p[u][i];
            }
        }
        return ans;
    }

    int queryDown(int u, int s, int &maxval)    //���²�ѯ
    {
        int ans = 0;
        for(int i = 16; i >= 0; i--)    //2 ^ 16 = 65536 > 50000
        {
            if(s & (1 << i))
            {
                ans = max(max(down[u][i], maxval - Min[u][i]), ans);    //����������;��Ȩ��
                maxval = max(Max[u][i], maxval);    //����������;��Ȩ���ֵ
                u = p[u][i];
            }
        }
        return ans;
    }

    void solve()
    {
        buildGraph();
        dfs(1, -1, 1);
        for(int j = 1; (1 << j) <= n; j++)
        {
            for(int i = 1; i <= n; i++)
            {
                if(~p[i][j - 1])
                {
                    int fa = p[i][j - 1];
                    p[i][j] = p[fa][j - 1];
                    Max[i][j] = max(Max[i][j - 1], Max[fa][j - 1]);
                    Min[i][j] = min(Min[i][j - 1], Min[fa][j - 1]);
                    up[i][j] = max(max(Max[fa][j - 1] - Min[i][j - 1], 0), max(up[i][j - 1], up[fa][j - 1]));
                    down[i][j] = max(max(Max[i][j - 1] - Min[fa][j - 1], 0), max(down[i][j - 1], down[fa][j - 1]));
                }
                else
                    p[i][j] = -1;
            }
        }
        int q;
        scanf("%d", &q);
        while(q--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            int lca = LCA(u, v);
            //printf("lca: %d\n", lca);
            int minval = INF, maxval = 0;
            int ans = max(queryUp(u, dep[u] - dep[lca], minval), queryDown(v, dep[v] - dep[lca], maxval));  //��u->lca·���Ϲ���ͳ��۵�����������lca->v·���Ϲ���ͳ��۵����������ߵ���ֵ
            //printf("ans: %d\n", ans);
            //printf("%d - %d\n", maxval, minval);
            ans = max(maxval - minval, ans);  //��u->lca·���Ϲ�����v->lca·���ϳ��۵�������
            printf("%d\n", max(ans, 0));
        }
    }
} lca_multi;

int main()
{
    int n;
    scanf("%d", &n);
    lca_multi.init(n);
    lca_multi.solve();
    return 0;
}
