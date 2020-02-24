/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-23
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

struct Node
{
    int i,d;
    bool operator <(const Node &nd) const
    {
        return d > nd.d;    //从大到小排序，保证距离最大的两个点能被满足（距离差为n时能直接接在最远端）
    }
} nd[MAXN<<1];

vector<int> v;

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&nd[i].d);
        nd[i].i = 2 * i;
    }
    sort(nd+1,nd+1+n);
    for(int i=1; i<n; i++)
    {
        printf("%d %d\n",nd[i].i,nd[i+1].i);
        v.PB(nd[i].i);
    }
    v.PB(nd[n].i);
    int last = n;   //链最远端的结点编号
    for(int i=1; i<=n; i++)
    {
        if(i + nd[i].d <= last) //在链的某个中间结点处延伸出一个分支
            printf("%d %d\n",nd[i].i-1,v[i+nd[i].d-2]);
        else    //在链的最远端插入一个结点（延伸链）
        {
            printf("%d %d\n",nd[i].i-1,v[last-1]);
            v.PB(nd[i].i-1);    //在链上插入新的结点
            last++;
        }
    }
    return 0;
}
