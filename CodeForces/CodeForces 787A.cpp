/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-06
 *  Subject: ACM-ICPC
 *  Language: C/C++
 *  OJ: CodeForces
 *  Algorithm: 扩展欧几里得求不定方程
 ********************************************************************************
 *  Algo-Description:
 *  > 两人同时尖叫需满足 b + a * x = d + c * y  =>  a * x - c * y = d - b
 *  > 令 m = exgcd(a,c), n = d - b, 则 m | n 时存在整数解
 *  > 求出最小正整数解
 *  > 由于y可能为负值，因此需要修正解
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

using namespace std;

int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int d=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return d;
}

int main()
{
    int a,b,c,d;
    int x,y;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int m=exgcd(a,c,x,y);
    int n=d-b;
    if(n%m)
    {
        puts("-1");
        return 0;
    }
    int k=c/m;
    x=((x*n/m)%k+k)%k;    //求最小正整数解
    y=(a*x+b-d)/c;    //y可能小于0
    while(y<0)  //找到y为正整数值的第一个解
    {
        x+=k;
        y=(a*x+b-d)/c;
    }
    printf("%d\n",b+a*x);
    return 0;
}
