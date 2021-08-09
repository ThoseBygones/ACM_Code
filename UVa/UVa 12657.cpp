/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-09
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 链表模拟
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

const int MAXN = 100005;

int pre[MAXN], nxt[MAXN];

void init(int n)
{
    for(int i = 0; i <= n; i++)
    {
        pre[i] = (i + n) % (n + 1);
        nxt[i] = (i + 1) % (n + 1);
    }
}

void ins(int x, int y, bool flag)   //flag = 0，从左边插入；flag = 1，从右边插入
{
    if(flag)    //从y右边插入
    {
        pre[nxt[y]] = x;
        nxt[x] = nxt[y];
        nxt[y] = x;
        pre[x] = y;
    }
    else    //从y左边插入
    {
        nxt[pre[y]] = x;
        pre[x] = pre[y];
        pre[y] = x;
        nxt[x] = y;
    }
}

void del(int x)
{
    nxt[pre[x]] = nxt[x];
    pre[nxt[x]] = pre[x];
}

void print(int n)
{
    int head = 0;
    for(int i = 1; i <= n; i++)
    {
        head = nxt[head];
        printf("%d%c", head, (i == n ? '\n' : ' '));
    }
}

int main()
{
    int kase = 1;
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        init(n);
        /*for(int i = 0; i <= n; i++)
            printf("%d - %d\n", pre[i], nxt[i]);
        */
        bool rev = false;
        while(m--)
        {
            int op;
            scanf("%d", &op);
            if(op == 4)
                rev ^= 1;
            else
            {
                int x, y;
                scanf("%d%d", &x, &y);
                if(op != 3 && rev)  //已经是逆序，则操作1和操作2取反
                    op = 3 - op;
                if(op == 1) //把x放到y左边
                {
                    if(pre[y] == x)
                        continue;
                    del(x);
                    ins(x, y, 0);
                }
                else if(op == 2)    //把x放到y右边
                {
                    if(nxt[y] == x)
                        continue;
                    del(x);
                    ins(x, y, 1);
                }
                else if(op == 3)    //交换x, y
                {
                    if(pre[y] == x) //x在y的左边
                    {
                        del(x);
                        ins(x, y, 1);
                    }
                    else if(nxt[y] == x)    //x在y的右边
                    {
                        del(x);
                        ins(x, y, 0);
                    }
                    else
                    {
                        int px = pre[x], py = pre[y];
                        del(x), del(y);
                        ins(y, px, 1), ins(x, py, 1);   //把y放到px的左边，把x放到py的右边
                    }
                }
            }
            //print(n);
        }
        LL ans = 0;
        int head = 0;
        for(int i = 1; i <= n; i++)
        {
            head = nxt[head];
            if(rev)
            {
                if(i % 2 == 0)
                    ans += head;
            }
            else
            {
                if(i & 1)
                    ans += head;
            }
        }
        printf("Case %d: %lld\n", kase++, ans);
    }
    return 0;
}
