/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-03-23
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: dp + STL multiset
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

const int MAXN = 150005;

vector<int> dgw[4][MAXN];   //the (dgw[i][j][k])-th type of the the (i - 1)-th course don't go well with the j-th type of the i-th course
int a[4][MAXN];
int dp[4][MAXN];    //dp[i][j] means the minimum cost when choosing the j-th type of the i-th course
int main()
{
    int n[4];
    for(int i = 0; i < 4; i++)
        scanf("%d", &n[i]);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < n[i]; j++)
            scanf("%d", &a[i][j]);
    }
    int m[4];
    for(int i = 1; i < 4; i++)
    {
        scanf("%d", &m[i]);
        for(int j = 0; j < m[i]; j++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            x--, y--;
            dgw[i][y].PB(x);
        }
    }
    for(int i = 0; i < n[0]; i++)
        dp[0][i] = a[0][i];
    for(int i = 1; i < 4; i++)
    {
        multiset<int> ms;
        for(int j = 0; j < n[i - 1]; j++)   //insert all result until previous course ((i - 1)-th course) to the multiset
            ms.insert(dp[i - 1][j]);
        for(int j = 0; j < n[i]; j++)   //enumerate all type of current course
        {
            for(auto &val: dgw[i][j])   //find the don't go well type from the previous course and delete the exact result
                ms.erase(ms.find(dp[i - 1][val]));
            if(ms.empty())   //no reasonable result exist -> failed
                dp[i][j] = INF;
            else
                dp[i][j] = *ms.begin() + a[i][j];    //minimum cost of the result until previous course + j-th type of current course
            for(auto &val: dgw[i][j])   //retrieve to the previous recorded scene
                ms.insert(dp[i - 1][val]);
        }
    }
    int ans = INF;
    for(int i = 0; i < n[3]; i++)
        ans = min(ans, dp[3][i]);
    if(ans == INF)
        puts("-1");
    else
        printf("%d\n", ans);
    return 0;
}
