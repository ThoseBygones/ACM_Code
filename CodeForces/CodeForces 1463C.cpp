/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-06-22
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
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

LL t[MAXN], x[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%lld%lld", &t[i], &x[i]);
        t[n + 1] = LINF;
        int ans = 0;
        LL pos = 0, tgt = 0;
        for(int i = 1; i <= n; i++)
        {
            if(pos == tgt)  //如果上一条指令执行后机器人已经到达了x[i]，那就更新新的目的
                tgt = x[i];
            LL dt = t[i + 1] - t[i];    //前后两条指令的时间差
            if(pos <= tgt && pos <= x[i] && min(pos + dt, tgt) >= x[i]) //方向对且确实能在[t[i], t[i + 1]]之间经过x[i]
                ans++;
            else if(pos >= tgt && pos >= x[i] && max(pos - dt, tgt) <= x[i])    //方向对且确实能在[t[i], t[i + 1]]之间经过x[i]
                ans++;
            if(pos <= tgt)
                pos = min(pos + dt, tgt);
            else
                pos = max(pos - dt, tgt);
        }
        printf("%d\n", ans);
    }
    return 0;
}
