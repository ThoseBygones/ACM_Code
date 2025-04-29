/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-04-27
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 前缀差和 + 后缀差和 + STL map + 取模
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>
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
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const LL LINF = INF * 1ll * INF;
const double PI = acos(-1.0);

#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lowbit(u) (u&(-u))

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        map<int, int> cnt;
        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            cnt[x]++;
        }
        vector<int> a;
        for(auto it: cnt)
        {
            if(it.second & 1)   //某个数出现奇数次
                a.PB(it.first);
        }
        if(a.size() <= 1)   //数组长度为奇数时1个数出现奇数次 或 数组长度为偶数时0个数出现奇数次
        {
            puts("0");
            continue;
        }
        map<int, vector<int>> modk;
        for(auto x: a)
            modk[x % k].PB(x);
        int ans = 0;
        int oddcnt = 0; //模 k 后数组长度为奇数的个数
        bool flag = true;
        for(auto it: modk)
        {
            bool odd = false;
            vector v = it.second;
            if(v.size() & 1)
            {
                oddcnt++;
                odd = true;
                if(oddcnt > 1)  //模 k 后数组长度为奇数的个数超过一个，那么无法变成美丽数组
                {
                    flag = false;
                    break;
                }
            }
            sort(v.begin(), v.end());
            if(odd)
            {
                int m = v.size();
                if(m > 1)
                {
                    vector<LL> pre(m), suf(m);   //前缀差和、后缀差和数组
                    pre[1] = v[1] - v[0];
                    for(int i = 3; i < v.size(); i += 2)
                        pre[i] = pre[i - 2] + v[i] - v[i - 1];
                    suf[m - 2] = v[m - 1] - v[m - 2];
                    for(int i = v.size() - 4; i >= 0; i -= 2)
                        suf[i] = suf[i + 2] + v[i + 1] - v[i];
                    LL Min = min(pre[m - 2], suf[1]);
                    for(int i = 2; i < m - 2; i += 2)
                        Min = min(Min, pre[i - 1] + suf[i + 1]);
                    ans += Min / k;
                }
            }
            else
            {
                for(int i = 1; i < v.size(); i += 2)
                    ans += (v[i] - v[i - 1]) / k;
            }
        }
        if(flag)
            printf("%d\n", ans);
        else
            puts("-1");
    }
    return 0;
}
