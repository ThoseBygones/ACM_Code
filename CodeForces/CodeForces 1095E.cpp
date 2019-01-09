/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-02
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
#define MAXN 1000005

char str[MAXN];
int pre[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i = 1; i <= n; i++)
    {
        if(str[i] == '(')
            pre[i] = pre[i-1] + 1;
        else
            pre[i] = pre[i-1] - 1;
    }
    for(int i = n-1; i; i--)
        pre[i] = min(pre[i],pre[i+1]);
    int cnt = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cnt < 0) //如果当前右括号数已经多于左括号数，则后面的括号再怎么修改也无法使序列合法
            break;
        if(str[i] == '(')
        {
            cnt++;
            if(pre[i] >= 2 && pre[n] == 2)
                ans++;
        }
        else
        {
            cnt--;
            if(pre[i] >= -2 && pre[n] == -2)
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
