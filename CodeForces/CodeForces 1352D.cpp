/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-05-09
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

const int MAXN = 1005;

int a[MAXN];
int cnt[2];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        cnt[0] = cnt[1] = 0;
        int l = 1, r = n;
        int turn = 0, mov = 0, pre = 0;
        while(l <= r)
        {
            mov++;
            if(mov == 1)
            {
                cnt[turn] += a[l];
                //printf("%d: %d\n", turn, a[l]);
                pre = a[l++];
                turn ^= 1;
                continue;
            }
            int tmp = 0;
            while(tmp <= pre && l <= r)
            {
                if(turn)
                    tmp += a[r--];
                else
                    tmp += a[l++];
            }
            pre = tmp;
            cnt[turn] += tmp;
            //printf("%d: %d\n", turn, tmp);
            turn ^= 1;
        }
        printf("%d %d %d\n", mov, cnt[0], cnt[1]);
    }
    return 0;
}
