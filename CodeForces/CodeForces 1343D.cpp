/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-21
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 差分 + 前缀和
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

int a[MAXN];
int pre[MAXN<<1];  //前缀和数组

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= k * 2; i++)
            pre[i] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for(int i = 1; i <= n / 2; i++)
        {
            int tmp = a[i] + a[n-i+1];
            pre[tmp]++;
            pre[tmp+1]--;
            int x = min(a[i], a[n-i+1]);
            int y = max(a[i], a[n-i+1]);
            //printf("x: %d, y: %d\n", x, y);
            pre[x+1]++;
            pre[y+k+1]--;
        }
        int Max = 0, sum = 0, ans = 0;  //求出最合适的目标值
        for(int i = 1; i <= k * 2; i++)
        {
            sum += pre[i];
            if(sum > Max)
            {
                Max = sum;
                ans = i;
            }
        }
        //printf("-- %d\n", ans);
        int cnt = 0;
        for(int i = 1; i <= n / 2; i++)
        {
            if(a[i] + a[n-i+1] != ans)  //和不等于目标值
            {
                if(min(a[i], a[n-i+1]) + 1 <= ans && ans <= max(a[i], a[n-i+1]) + k)    //改其中一个数就能使和等于目标值
                    cnt++;
                else    //两个数都得改才能使和等于目标值
                    cnt += 2;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
