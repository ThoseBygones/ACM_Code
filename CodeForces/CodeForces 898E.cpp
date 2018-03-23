/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-23
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

vector <LL> v1,v2;

int main()
{
    int n;
    scanf("%d",&n);
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        LL x;
        scanf("%I64d",&x);
        LL y=sqrt(x);
        if(y*y==x)
        {
            cnt++;
            if(x==0)
                v1.PB(2);
            else
                v1.PB(1);
        }
        else
        {
            int temp=min(x-y*y,(y+1)*(y+1)-x);
            v2.PB(temp);
        }
    }
    LL ans=0;
    if(cnt==n/2)
    {
        puts("0");
        return 0;
    }
    if(cnt>n/2)
    {
        sort(v1.begin(),v1.end());
        int p=0;
        while(cnt>n/2)
        {
            ans+=v1[p];
            p++;
            cnt--;
        }
    }
    else
    {
        sort(v2.begin(),v2.end());
        int p=0;
        while(cnt<n/2)
        {
            ans+=v2[p];
            p++;
            cnt++;
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
