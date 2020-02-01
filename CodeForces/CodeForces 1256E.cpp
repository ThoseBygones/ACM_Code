/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-17
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: dp
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

struct Student
{
    int id,a;
    bool operator <(const Student &s) const
    {
        return a < s.a;
    }
} stu[MAXN];

int dp[MAXN];   //dp[i]表示前i个学生组成队伍后能形成的最小diversity值
int cnt[MAXN];  //前i个学生组成的最后一支队伍的人数
int belong[MAXN];   //每个队员属于哪个队

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&stu[i].a);
        stu[i].id = i;
    }
    sort(stu+1,stu+1+n);
    fill(dp+1,dp+1+n,INF);
    dp[0] = 0;
    for(int i=0; i<=n; i++)
    {
        for(int j=3; j<=5 && i+j<=n; j++)
        {
            int dif = stu[i+j].a - stu[i+1].a;
            if(dp[i] + dif < dp[i+j])
            {
                dp[i+j] = dp[i] + dif;
                cnt[i+j] = j;   //最新组成的这支队伍有j人
            }
        }
    }
    int ans = 0, pos = n;
    while(pos)
    {
        ans++;
        int val = cnt[pos];
        while(val--)
        {
            belong[stu[pos].id] = ans;
            pos--;
        }
    }
    printf("%d %d\n",dp[n],ans);
    for(int i=1; i<=n; i++)
    {
        if(i != n)
            printf("%d ",belong[i]);
        else
            printf("%d\n",belong[i]);
    }
    return 0;
}
