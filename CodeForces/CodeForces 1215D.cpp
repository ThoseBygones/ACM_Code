/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 博弈
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define istr stringstream
#define FOR(i,n) for(int i=0;i<(n);++i)
#define forIt(mp,it) for(__typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))
#define MAXN 200005

char t[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",t);
    int lsum = 0, rsum = 0;
    int lcnt = 0, rcnt = 0;
    int half = n / 2;
    for(int i=0; i<half; i++)
    {
        if(t[i] == '?')
            lcnt++;
        else
            lsum += t[i] - '0';
    }
    for(int i=half; i<n; i++)
    {
        if(t[i] == '?')
            rcnt++;
        else
            rsum += t[i] - '0';
    }
    if(lcnt == rcnt)    //左右半'?'数量相等
    {
        if(lsum == rsum)    //左右半数字和相等，Bicarp赢
            puts("Bicarp");
        else    //不等则Monocarp赢
            puts("Monocarp");
    }
    else if((lcnt>rcnt && lsum>=rsum) || (lcnt<rcnt && lsum<=rsum))   //'?'数量多的一半数字和也大，则Monocarp赢
        puts("Monocarp");
    else
    {
        if(abs(lsum-rsum) == abs(lcnt-rcnt)/2*9)    //左右两半的数字和之差正好等于左右两半'?'数量之差的一半乘以9，则Bicarp赢
            puts("Bicarp");
        else    //否则Monocarp赢
            puts("Monocarp");
    }
    return 0;
}
