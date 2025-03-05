/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 树+分类讨论
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

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        if(a != c - 1)
        {
            puts("-1");
            continue;
        }
        if(a)
        {
            int dep = 0;
            while(a >= (1 << dep) - 1)
                dep++;
            //int step = 1 << dep;
            //int now = (1 << dep) - 1;
            int pre = (1 << (dep - 1)) - 1; //上一层摆满的情况
            int remain = (1 << dep) - 1 - a;    //目前树上摆放完所有2-child结点后还剩下的位置数
            int leaf = (a - pre) * 2 + remain; //目前可以摆放的叶子结点数
            if(a == pre && !b)  //上一层摆满且剩下的叶结点都是0-child结点
            {
                printf("%d\n", dep - 1);
                continue;
            }
            if(b <= remain) //1-child结点数本层就摆满了
                printf("%d\n", dep);    //0-child结点摆满剩下部分即可
            else
                printf("%d\n", dep + (b - remain - 1) / leaf + 1);
        }
        else if(b)
            printf("%d\n", b);
        else if(c)
            puts("0");
    }
    return 0;
}
