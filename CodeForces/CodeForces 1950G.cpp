/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2025-03-04
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
 *  Algorithm: 状压dp
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

const int MAXN = 16;

string s[MAXN][2];
bool G[MAXN][MAXN];
bool dp[1 << MAXN + 5][MAXN];    //dp[i][j]表示所选歌曲集对应状态为i，且歌曲集最后一首歌为j时，该方案是否可行

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> s[i][0] >> s[i][1];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                G[i][j] = G[j][i] = false;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(s[i][0] == s[j][0] || s[i][1] == s[j][1])
                    G[i][j] = G[j][i] = true;
            }
        }
        for(int i = 0; i < (1 << n); i++)
        {
            for(int j = 0; j < n; j++)
                dp[i][j] = false;
        }
        for(int i = 0; i < n; i++)  //初始化
            dp[1 << i][i] = true;   //歌曲集里只有一首歌（这首歌是最后一首）时是可行的
        int ans = 0;
        for(int s = 0; s < (1 << n); s++)   //枚举所有状态
        {
            for(int i = 0; i < n; i++)  //枚举每一首歌作为当前歌单最后一首歌
            {
                if(!dp[s][i])    //如果该状态不合法
                    continue;
                for(int j = 0; j < n; j++)  //枚举下一首歌
                {
                    if(!(s & (1 << j)) && G[i][j])  //该歌曲还未在当前歌单中，且这首歌可以接在歌单的最后
                        dp[s | (1 << j)][j] = true;
                }
                int cnt = 0;
                for(int j = 0; j < n; j++)
                {
                    if(s & (1 << j))    //统计当前合法歌单状态中有几首歌
                        cnt++;
                }
                //printf("%d: %d\n", s, cnt);
                ans = max(ans, cnt);
            }
        }
        cout << n - ans << endl;
    }
    return 0;
}
