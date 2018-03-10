/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-09
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 二分 + 容斥原理
 ********************************************************************************
 *  Algo-Description:
 *  > 小于等于10^6的数最多有10种质因子，因此把p分解质因子，然后二分求满足条件的数y；
 *  > 利用容斥原理计算前i个数中有多少数与p互质；
 *  > 当get(y)-get(x)>=k时，更新答案并调整右边界,否则调整左边界。
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

vector <int> fac;

void init(int n)
{
    fac.clear();
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)
        {
            fac.PB(i);
            n/=i;
            while(n%i==0)
                n/=i;
        }
    }
    if(n!=1)
        fac.PB(n);
}

int cal(int val) //容斥
{
    int ans=0;
    int sz=fac.size();
    for(int i=1; i<(1<<sz); i++)    //枚举各种状态（各种质因子的可能组合）
    {
        int x=1,flag=0; //flag为该状态中质因子个数的奇偶性
        for(int j=0; j<sz; j++)
        {
            if((i>>j)&1)
            {
                x*=fac[j];
                flag^=1;
            }
        }
        if(flag)    //根据容斥原理，加上奇数个质因子的情况，减去偶数个质因子的情况
            ans+=val/x;
        else
            ans-=val/x;
    }
    return val-ans;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,p,k;
        scanf("%d%d%d",&x,&p,&k);
        init(p);
        int pre=cal(x);
        int l=x,r=1e9;
        int ans=x;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(cal(mid)-pre>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
