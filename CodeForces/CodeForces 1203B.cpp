/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-09
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
#define MAXN 10005

int cnt[MAXN];

int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        int Min = INF, Max = 0;
        for(int i=0; i<n*4; i++)
        {
            int x;
            scanf("%d",&x);
            cnt[x]++;
            Min = min(x,Min);
            Max = max(x,Max);
        }
        bool flag = true;
        for(int i=1; i<=10000; i++)
        {
            if(cnt[i] & 1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            int tmp = Min * Max;
            int l = 1, r = 10000;
            while(l <= r)
            {
                while(!cnt[l] && l <= r)
                    l++;
                while(!cnt[r] && l <= r)
                    r--;
                if(l > r)
                    break;
                //cout << "l: " << l << " , r = " << r << endl;
                if(l * r != tmp)
                {
                    flag = false;
                    break;
                }
                cnt[l] -= 2;
                cnt[r] -= 2;
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
