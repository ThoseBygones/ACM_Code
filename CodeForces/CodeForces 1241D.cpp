/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-22
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
#define MAXN 300005

int a[MAXN];
int l[MAXN], r[MAXN];   //l[i]/r[i]表示数字i在序列中出现的最左/最右位置

int main()
{
    int q;
    scanf("%d", &q);
    while(q--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            l[i] = r[i] = 0;
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            if(!l[x])   //第一次出现则记录最右位置
            {
                l[x] = i;
                ans++;
            }
            r[x] = i;   //记录最右位置
        }
        int stay = 0, cnt = 0, last = 0; //不需要移动的数字个数、局部最长不下降子序列、上一个数字的最右位置
        for(int i = 1; i <= n; i++)
        {
            if(l[i])    //该数字在序列中存在
            {
                if(last < l[i]) //序列不下降
                    cnt++;
                else
                    cnt = 1;
                stay = max(stay, cnt);  //保留最长不下降子序列
                last = r[i];
            }
        }
        printf("%d\n", ans - stay);
    }
    return 0;
}
