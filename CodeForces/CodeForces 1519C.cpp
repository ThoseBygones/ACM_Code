/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2023-09-19
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 前缀和
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

LL u[MAXN], sum[MAXN];
vector<LL> v[MAXN];
PLI p[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < MAXN; i++)
            v[i].clear();
        for(int i = 1; i <= n; i++)
            scanf("%lld", &u[i]);
        for(int i = 1; i <= n; i++)
        {
            LL x;
            scanf("%lld", &x);
            v[u[i]].PB(x);
            sum[i] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            sort(v[i].begin(), v[i].end(), greater<LL>());  //每个学校的选手按能力值逆序排序
            p[i] = MP(v[i].size(), i);
            for(int j = 1; j < v[i].size(); j++)    //每个学校学生的能力值求前缀和
                v[i][j] += v[i][j - 1];
        }
        sort(p + 1, p + 1 + n);
        /*
        for(int i = 1; i <= n; i++)
            printf("%lld - %lld\n", p[i].first, p[i].second);
        */
        int pos = 1;
        for(int k = 1; k <= n; k++) //枚举分组的大小k
        {
            while(pos <= n && p[pos].first < k) //凑不够k个选手的学校跳过
                pos++;
            for(int i = pos; i <= n; i++)
            {
                int len = p[i].first - p[i].first % k;  //能凑个k个选手的学校看能够凑成几队（即x * k名选手）
                sum[k] += v[p[i].second][len - 1];
            }
        }
        for(int i = 1; i <= n; i++)
            printf("%lld%c", sum[i], i == n ? '\n' : ' ');
    }
    return 0;
}
