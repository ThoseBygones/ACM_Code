/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-15
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 差分数组 + 前缀和 / STL vector + set
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
#define MAXN 200

struct Segment
{
    int id,r;
    Segment() {}
    Segment(int id,int r):id(id),r(r) {}
    bool operator <(const Segment &s) const
    {
        if(r == s.r)
            return id < s.id;
        return r < s.r; //右端点从小到大排序
    }
};

vector<Segment> v[MAXN+5];
set<Segment> s;
vector<int> ans;    //结果数组

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        Segment seg = Segment(i,r);
        v[l].PB(seg);
    }
    for(int i=1; i<=MAXN; i++)
    {
        while(!s.empty() && (*s.begin()).r < i)   //对于新的端点i，从set中删除没有覆盖到它的线段
            s.erase(*s.begin());    //*号可以去掉
        for(int j=0; j<v[i].size(); j++)    //遍历以i为左端点的所有线段，插入set中
            s.insert(v[i][j]);
        while(s.size() > k) //当覆盖端点i的线段数量超过k条时，删除右端点距离端点i最远的线段
        {
            //cout << (*s.rbegin()).id << endl;
            ans.PB((*s.rbegin()).id);
            s.erase(*s.rbegin());   //s.erase(--s.end());
        }
    }
    printf("%d\n",ans.size());
    for(int i=0; i<ans.size(); i++)
    {
        if(i)
            printf(" %d",ans[i]);
        else
            printf("%d",ans[i]);
    }
    puts("");
    return 0;
}
