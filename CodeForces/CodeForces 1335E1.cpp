/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-23
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 枚举 + 前缀和
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
#define MAXM 30

vector<int> pos[MAXM];
int a[MAXN];
int pre[MAXM][MAXN];    //前缀和数组，表示该串前j个字符中第i个字母出现的次数

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= 26; i++)
            pos[i].clear();
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            pos[a[i]].PB(i);
            for(int j = 1; j <= 26; j++)
            {
                pre[j][i] = pre[j][i-1];
                if(a[i] == j)
                    pre[j][i]++;
            }
        }
        int ans = 1;
        for(int i = 1; i <= 26; i++)    //枚举左右两端区间的字母
        {
            if(pos[i].size() < 2)   //无法构成左右两个区间
                continue;
            int l = 0, r = pos[i].size() - 1;
            while(pos[i][l] < pos[i][r])    //区间中间还有数
            {
                int cnt = 0;
                for(int j = 1; j <= 26; j++)    //枚举中间区间的字母
                {
                    int tmp = pre[j][pos[i][r]-1] - pre[j][pos[i][l]];
                    cnt = max(cnt, tmp);
                }
                ans = max(ans, cnt + 2 * (l + 1));
                l++, r--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
