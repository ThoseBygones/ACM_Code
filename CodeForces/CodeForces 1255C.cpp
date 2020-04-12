/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-08
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

vector<int> v[MAXN];
int cnt[MAXN];
bool vis[MAXN];
int ans[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n - 2; i++)
    {
        int q1, q2, q3;
        scanf("%d%d%d", &q1, &q2, &q3);
        cnt[q1]++;
        cnt[q2]++;
        cnt[q3]++;
        v[q1].PB(q2);
        v[q2].PB(q1);
        v[q1].PB(q3);
        v[q3].PB(q1);
        v[q2].PB(q3);
        v[q3].PB(q2);
    }
    for(int i = 1; i <= n; i++)
    {
        if(cnt[i] == 1) //找到其中一个只出现一次的数字作为序列起始
        {
            bool ok = false;
            for(int j = 0; j < v[i].size(); j++)
            {
                if(cnt[v[i][j]] == 2)
                {
                    ans[1] = i;
                    ans[2] = v[i][j];
                    vis[i] = vis[v[i][j]] = true;
                    ok = true;
                    break;
                }
            }
            if(ok)
                break;
        }
    }
    for(int i = 3; i <= n; i++)
    {
        bool ok = false;
        for(int j = 0; j < v[ans[i-2]].size(); j++)
        {
            for(int k = 0; k < v[ans[i-1]].size(); k++)
            {
                if(v[ans[i-2]][j] == v[ans[i-1]][k] && !vis[v[ans[i-2]][j]])
                {
                    ans[i] = v[ans[i-2]][j];
                    vis[v[ans[i-2]][j]] = true;
                    break;
                }
            }
            if(ok)
                break;
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%d%c", ans[i], (i == n ? '\n' : ' '));
    return 0;
}
