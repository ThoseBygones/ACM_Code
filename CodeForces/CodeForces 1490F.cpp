/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-05-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: STL set + map
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
using namespace std;

template<class T> inline T sqr(T x) {return x * x;}
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

const int MAXN = 200005;

int a[MAXN];
map<int, int> mp;
set<int> s;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        mp.clear();
        s.clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            mp[a[i]]++;
        }
        if(mp.size() == n)
        {
            puts("0");
            continue;
        }
        for(auto &val: mp)
            s.insert(val.second);
        int ans = INF;
        for(auto &t: s)   //枚举最后每种数出现的次数
        {
            int cnt = 0;
            for(auto &val: mp)
            {
                if(val.second >= t)  //出现的次数多，可以删掉一些
                    cnt += val.second - t;
                else    //出现次数不够，全删了
                    cnt += val.second;
            }
            ans = min(ans, cnt);
        }
        printf("%d\n", ans);
    }
    return 0;
}
