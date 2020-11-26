/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-26
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 二分图匹配
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

const int MAXN = 1030;  //2^10

class Hungary_DFS
{
private:
    int g[MAXN][MAXN];
    int vis[MAXN];
    int mx[MAXN], my[MAXN];
    int n, m;
    int nx, ny;

    vector<int> ans;

    bool dfs(int u)
    {
        for(int v = 0; v < ny; v++)
        {
            if(!vis[v] && g[u][v])
            {
                vis[v] = true;
                if(my[v] == -1 || dfs(my[v]))
                {
                    my[v] = u;
                    mx[u] = v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    void init(int n, int m)
    {
        this -> n = n;
        this -> m = m;
        memset(mx, -1, sizeof(mx));
        memset(my, -1, sizeof(my));
    }

    int hungary()
    {
        int res = 0;
        for(int i = 0; i < nx; i++)
        {
            if(mx[i] == -1)
            {
                memset(vis, 0, sizeof(vis));
                if(dfs(i))
                    res++;
            }
        }
        return res;
    }

    void buildGraph()
    {
        memset(g, 0, sizeof(g));
        for(int i = 0; i < ans.size(); i++)
        {
            for(int j = i + 1; j < ans.size(); j++)
            {
                int tmp = (ans[i] ^ ans[j]);    //找到不同的位
                if(tmp && (tmp & (tmp - 1)) == 0)  //只有一位不同
                    g[i][j] = g[j][i] = 1;
            }
        }
    }

    void solve()
    {
        ans.clear();
        for(int i = 0; i < m; i++)
        {
            char str[12];
            scanf("%s", str);
            int num1 = 0, num2 = 0;
            int c = 1;
            for(int j = n - 1; j >= 0; j--)
            {
                if(str[j] != '*')
                {
                    num1 += c * (str[j] - '0');
                    num2 += c * (str[j] - '0');
                }
                else
                    num2 += c;
                c <<= 1;

            }
            ans.PB(num1);
            if(num1 != num2)
                ans.PB(num2);
        }
        /*
        for(int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);
        puts("");
        */
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());   //去重
        //printf("size: %d\n", ans.size());
        buildGraph();
        nx = ny = ans.size();
        int val = hungary();
        //printf("val: %d\n", val);
        printf("%d\n", ans.size() - val / 2);
    }
} hungaryDFS;

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        if(!n && !m)
            break;
        hungaryDFS.init(n, m);
        hungaryDFS.solve();
    }
    return 0;
}
