/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 思维 + 规律
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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

const int MAXN = 200005;

struct Grid
{
    int r, c;
    bool operator < (const Grid &g) const
    {
        if(c == g.c)
            return r < g.r;
        return c < g.c;
    }
} a[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < m; i++)
            scanf("%d%d", &a[i].r, &a[i].c);
        if(m & 1)
        {
            puts("NO");
            continue;
        }
        sort(a, a + m);
        bool flag = true;
        for(int i = 1; i < m; i ++)
        {
            if(i & 1)   //每两块分一组，一组内的两块
            {
                if(a[i].r != a[i - 1].r)    //相邻两个禁止块不在同一行
                {
                    if((a[i].c - a[i - 1].c) & 1) //相邻两个禁止块间隔列数为奇数
                    {
                        flag = false;
                        break;
                    }
                }
                else    //相邻两个禁止块在同一行
                {
                    if((a[i].c - a[i - 1].c) % 2 == 0)    //相邻两个禁止块间隔列数为偶数
                    {
                        flag = false;
                        break;
                    }
                }
            }
            else    //前一组的第二块和这一组的第一块之间
            {
                if(a[i].c == a[i - 1].c)    //如果在同一列
                {
                    flag = false;
                    break;
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
