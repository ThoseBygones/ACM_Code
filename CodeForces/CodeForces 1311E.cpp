/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-03-06
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 二叉树构造 + 前缀和
 ********************************************************************************
 *  Algo-Description:
 * > 先构造一条链，然后把深度最深的结点调整至能插入结点的最高层中。
 * > 不断调整，如果调整完以后无法满足题意，则判断构造失败，否则利用前缀和关系输出每个非根结点的父结点。
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
#define MAXN 5005

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,d;
        scanf("%d%d",&n,&d);
        vector<int> cnt(n+1,1); //cnt数组表示每个深度结点的数量
        cnt[0] = 0;
        int cursum = n * (n - 1) / 2 - d;
        int l = 2, r = n;
        while(l <= r)   //把深度为r的结点调至深度l
        {
            if(cursum < r - l || cnt[l] == cnt[l-1] * 2)  //该调整方案会使得所有结点的深度和小于d，且该层结点已满
                l++;
            else
            {
                cursum -= (r - l);
                cnt[l]++;
                cnt[r]--;
                r--;
            }
        }
        if(cursum)
        {
            puts("NO");
            continue;
        }
        puts("YES");
        vector<int> ans = cnt;
        int dep = ans.size() - 1;
        for(int i=1; i<=dep; i++)
            ans[i] += ans[i-1];
        for(int i=2; i<=dep; i++)
        {
            for(int j=0; j<cnt[i]; j++)
                printf("%d ",ans[i-2]+1+j/2);   //找到上两层最后一个结点+1（上一层的第一个结点）
        }
        puts("");
    }
    return 0;
}
