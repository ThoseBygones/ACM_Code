/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-02-12
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 贪心
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

vector<int> t;  //每只怪兽最后收人头需要你攻击的次数

int main()
{
    int n,a,b,k;
    scanf("%d%d%d%d",&n,&a,&b,&k);
    int sum = a + b;    //一回合两人的伤害总数
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        int hp;
        scanf("%d",&hp);
        hp = (hp - 1) % sum + 1;    //留下一回合的余地供操作
        if(hp <= a) //剩余血量可以一次收掉，则不需要费技能点
            ans++;
        else
            t.PB((hp+a-1)/a);
    }
    sort(t.begin(),t.end());    //按照需要攻击的次数从小到大排序
    for(auto val: t)
    {
        if(k < val-1)  //技能点不够用了，结束
            break;
        k -= (val - 1);
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
