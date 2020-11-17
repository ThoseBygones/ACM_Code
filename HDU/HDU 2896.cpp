/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: AC自动机
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

class ACautomation
{
public:
#define LETTER 128
#define MAXNODE 500005

    char key[201];   //模板串（待插入字典树中的单词）
    char s[10001];    //主串（待查询的串）

    int n, cnt = 0, root;

    vector<int> v;

    struct node
    {
        int id;
        int fail;
        int next[LETTER];
        void init()
        {
            memset(next, -1, sizeof(next));
            id = 0;
        }
    } nd[MAXNODE];

    void init()
    {
        cnt = 0;
        root = newnode();
        nd[root].fail = root;
    }

    int newnode()
    {
        nd[cnt].init();
        return cnt++;
    }

    void insert(const char *str, int id)
    {
        int temp = root;
        for(int i = 0; str[i]; i++)
        {
            int c = str[i];
            if(nd[temp].next[c] == -1)
                nd[temp].next[c] = newnode();
            temp = nd[temp].next[c];
        }
        nd[temp].id = id;
    }

    void getFail()
    {
        queue<int> q;
        for(int i = 0; i < LETTER; i++)
        {
            int node = nd[root].next[i];
            if(~node)
            {
                nd[node].fail = root;
                q.push(node);
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < LETTER; i++)
            {
                int v = nd[u].next[i];
                if(~v)
                {
                    int fa = nd[u].fail;
                    while(fa != root && nd[fa].next[i] == -1)
                        fa = nd[fa].fail;
                    nd[v].fail = nd[fa].next[i] == -1 ? root : nd[fa].next[i];
                    q.push(v);
                }
            }
        }
    }

    bool find()
    {
        bool flag = false;
        int cur = root;
        for(int i = 0; s[i]; i++)
        {
            int c = s[i];
            while(cur != root && nd[cur].next[c] == -1)
                cur = nd[cur].fail;
            cur = nd[cur].next[c] == -1 ? root : nd[cur].next[c];
            int ptr = cur;
            while(ptr != root)
            {
                if(nd[ptr].id)
                {
                    flag = true;
                    v.PB(nd[ptr].id);
                    ptr = nd[ptr].fail;
                }
                else
                    break;
            }
        }
        return flag;
    }

    void solve(int n)
    {
        init();
        for(int i = 1; i <= n; i++)
        {
            scanf("%s", key);
            insert(key, i);
        }
        getFail();
        int m;
        scanf("%d", &m);
        int ans = 0;
        for(int i = 1; i <= m; i++)
        {
            v.clear();
            scanf("%s", s);
            if(find())
            {
                ans++;
                sort(v.begin(), v.end());
                printf("web %d:", i);
                for(int i = 0; i < v.size(); i++)
                    printf(" %d", v[i]);
                puts("");
            }
        }
        printf("total: %d\n", ans);
    }
} ac_auto;

int main()
{
    int n;
    while(~scanf("%d", &n))
        ac_auto.solve(n);
    return 0;
}
