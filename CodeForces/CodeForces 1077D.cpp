/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-05
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
#define MAXN 200005

int cnt[MAXN];
int n,k;

bool check(int val) //二分的是删除的轮数
{
    int sum = 0;
    for(int i = 1; i <= 200000; i++)
    {
        if(cnt[i] >= val)
            sum += cnt[i] / val;
    }
    return sum >= k;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    int res = 1;
    int l = 1, r = n;
    while(l <= r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    //cout << res << endl;
    vector<int> ans;
    bool flag = false;
    for(int i = 1; i <= 200000; i++)
    {
        if(cnt[i] >= res)
        {
            for(int j = 1; j <= cnt[i]/res; j++)
            {
                ans.PB(i);
                if(ans.size() == k)
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            break;
    }
    for(int i = 0; i < ans.size(); i++)
    {
        if(i)
            printf(" %d",ans[i]);
        else
            printf("%d",ans[i]);
    }
    puts("");
    return 0;
}

/*
15 2
1 2 2 1 1 2 1 1 2 1 2 1 1 1 1
*/
