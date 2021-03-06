/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-24
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
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

int main()
{
    int n;
    scanf("%d",&n);
    if(n<5)
        printf("%d\n",(n-1)*n/2);
    else
    {
        int cnt=0;  //9������
        LL num=5;
        for(int i=0; i<=10; i++)
        {
            if(n<num)
            {
                cnt=i;
                break;
            }
            num*=10;
        }
        num=0;
        for(int i=1; i<=cnt; i++)
            num=num*10+9;
        LL ans=0;
        for(int i=0; i<=8; i++)
        {
            LL sum=i*(num+1)+num;
            if(n<(sum+1)/2)
                break;
            if(n>sum-1)
                ans+=sum/2;
            else
                ans+=(n-sum/2);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
