/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-09
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 贪心 + 排序 + dp（类似01背包问题）
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
#define MAXN 105

struct Project
{
    int a,b;
};

bool cmp1(Project x,Project y)  //b>0的项目的排序方法
{
    if(x.a == y.a)
        return x.b > y.b;
    return x.a < y.a;
}

bool cmp2(Project x,Project y)  //b<0的项目的排序方法
{
    if(x.a + x.b == y.a + y.b)
        return x.a > y.a;
    return x.a + x.b > y.a + y.b;
}

vector<Project> v1,v2;
int dp[60005];   //dp[i]表示rating为i时能完成的最大任务数量

int main()
{
    int n,r;
    scanf("%d%d",&n,&r);
    for(int i=0; i<n; i++)
    {
        Project tmp;
        scanf("%d%d",&tmp.a,&tmp.b);
        if(tmp.b > 0)
            v1.PB(tmp);
        else
            v2.PB(tmp);
    }
    sort(v1.begin(),v1.end(),cmp1);
    sort(v2.begin(),v2.end(),cmp2);
    int cnt = 0;
    for(int i=0; i<v1.size(); i++)  //先尽量做rating值为正的项目
    {
        if(r >= v1[i].a)
        {
            r += v1[i].b;
            cnt++;
        }
        else
            break;
    }
    for(int i=0; i<v2.size(); i++)  //再做完rating值为负的项目
    {
        for(int j=max(v2[i].a,-v2[i].b); j<=r; j++)
            dp[j+v2[i].b] = max(dp[j+v2[i].b],dp[j]+1);
    }
    int ans = 0;
    for(int i=0; i<=r; i++)
        ans = max(ans,dp[i]);
    printf("%d\n",cnt+ans);
    return 0;
}
