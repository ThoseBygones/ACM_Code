/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-04-30
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 排序 + 贪心
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

struct Friend
{
    int w, h, id;
    Friend() {}
    Friend(int w, int h, int id) : w(w), h(h), id(id) {}
    bool operator < (const Friend &f) const
    {
        if(h == f.h)
            return w < f.w;
        return h < f.h;
    }
} f[MAXN];

int ans[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            int w, h;
            scanf("%d%d", &w, &h);
            if(w > h)
                swap(w, h);
            f[i] = Friend(w, h, i);
        }
        sort(f, f + n);
        int pos = 0, minw = INF, minpos = -1;
        for(int i = 0; i < n; i++)
        {
            if(f[i].h != f[i - 1].h)    //相邻两个人身高不等
            {
                while(pos < i)
                {
                    if(minw > f[pos].w) //找到一个更瘦的
                    {
                        minw = f[pos].w;
                        minpos = f[pos].id;
                    }
                    pos++;
                }
            }
            if(minw < f[i].w)   //这个人前面最瘦的都比这个人瘦，则那个人可以站在这个人前面
                ans[f[i].id] = minpos + 1;
            else
                ans[f[i].id] = -1;
        }
        for(int i = 0; i < n; i++)
            printf("%d%c", ans[i], (i == n - 1 ? '\n' : ' '));
    }
    return 0;
}
