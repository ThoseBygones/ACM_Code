/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.1
 *  Date: 2018-02-11
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
#define MAXN 100005
using namespace std;

map <int,int> cnt;

int main()
{
    LL n;
    int k;
    scanf("%I64d%d",&n,&k);
    int pos=0;
    int high=0; //最高位
    while(n)
    {
        cnt[pos]=n&1;
        n>>=1;
        if(cnt[pos])
        {
            k--;
            high=pos;
        }
        pos++;
    }
    if(k<0)
        puts("No");
    else
    {
        puts("Yes");
        while(cnt[high]<=k)
        {
            cnt[high-1]+=cnt[high]*2;    //从最高位开始，每一个高位拆成两个低一位
            k-=cnt[high];
            cnt[high]=0;
            high--;
        }
        int low=min(high,0);
        while(!cnt[low])    //找到非0最低位
            low++;
        while(k)    //从最低位开始，每一个高位拆成两个低一位
        {
            if(cnt[low])
            {
                cnt[low-1]+=2;
                cnt[low]--;
                k--;
            }
            low--;
        }
        for(int i=pos-1; i>=low; i--)
        {
            for(int j=0; j<cnt[i]; j++)
                printf("%d ",i);
        }
        puts("");
    }
    return 0;
}
