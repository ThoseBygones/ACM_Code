/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-11
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
#define MAXN 105

struct Exam
{
    int s,d,c;
    int idx;
    bool operator <(const Exam &e) const
    {
        return d<e.d;
    }
} e[MAXN];

int ans[MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&e[i].s,&e[i].d,&e[i].c);
        e[i].idx=i;
        ans[e[i].d]=m+1;    //考试当天安排考试
    }
    sort(e+1,e+1+m);
    for(int i=1; i<=n; i++)
    {
        if(!ans[i]) //当天未安排
        {
            for(int j=1; j<=m; j++)
            {
                if(e[j].s<=i && e[j].d>i && e[j].c) //处于该门课复习时间范围内且还未复习完
                {
                    //cout << i << endl;
                    ans[i]=e[j].idx;
                    e[j].c--;
                    break;
                }
            }
        }
    }
    for(int i=1; i<=m; i++)
    {
        if(e[i].c)  //有任何一门课没有复习完（就去考试）
        {
            puts("-1");
            return 0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(i!=n)
            printf("%d ",ans[i]);
        else
            printf("%d\n",ans[i]);
    }
    return 0;
}
