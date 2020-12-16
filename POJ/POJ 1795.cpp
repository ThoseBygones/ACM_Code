/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-12-02
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 状态压缩dp + DFS
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#pragma comment(linker,"/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <ctime>
#include <numeric>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <complex>
#include <deque>
#include <functional>
#include <list>
#include <map>
#include <string>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
//#include <bits/stdc++.h>
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

string s[MAXN];
int dp[1 << MAXN][MAXN];    //dp[s][i]表示在包含子串状态为s的情况下，最左侧为第i个子串时，整个序列的最短长度
int cost[MAXN][MAXN];   //cost[i][j]表示在第j个串左边拼上第i个串增加的长度（重叠部分不算）
string dna;
int n;

void init() //预处理
{
    /* 找到所有被包含的子串并替换为母串 */
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j && s[i].find(s[j]) != string::npos)
                s[j] = s[i];
        }
    }
    /* 去重 */
    sort(s, s + n);
    n = unique(s, s + n) - s;
    /* 计算串s[i]拼接到s[j]左侧使拼接后的字符串增加的长度（重叠部分不算） */
    for(int i = 0; i < n; i++)
    {
        int len = s[i].length();
        for(int j = 0; j < n; j++)
        {
            cost[i][j] = len;
            if(i != j)
            {
                for(int k = min(s[i].length(), s[j].length()); k; k--)
                {
                    if(s[i].substr(len - k) == s[j].substr(0, k))
                    {
                        cost[i][j] = len - k;
                        break;
                    }
                }
            }
        }
    }
}

void dfs(int pre, int sta)  //回溯拼接过程，从左往右拼接
{
    int prepos = -1;
    int presta = sta & (~(1 << pre));  //还原前一状态
    if(!presta)
        return ;
    string nxt; //下一个子串
    for(int cur = 0; cur < n; cur++)    //枚举当前状态下的最左端的子串（拼接状态为：pre|cur|...）
    {
        if(dp[presta][cur] != INF && dp[presta][cur] + cost[pre][cur] == dp[sta][pre])
        {
            string tmp = s[cur].substr(s[pre].length() - cost[pre][cur]);   //拼接的时候前后串重复的部分去掉
            if(prepos == -1 || nxt > tmp)   //拼接最短的字典序最小串
            {
                prepos = cur;
                nxt = tmp;
            }
        }
    }
    dna += nxt;
    dfs(prepos, presta);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int kase = 1; kase <= t; kase++)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> s[i];
        init();
        for(int i = 0; i < (1 << MAXN); i++)
            fill(dp[i], dp[i] + MAXN, INF);
        for(int i = 0; i < n; i++)
            dp[1 << i][i] = cost[i][i];
        for(int s = 0; s < (1 << n); s++)   //枚举状态
        {
            for(int i = 0; i < n; i++)  //枚举子串
            {
                if(dp[s][i] != INF)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if(!(s & (1 << j)))
                            dp[s | (1 << j)][j] = min(dp[s | (1 << j)][j], dp[s][i] + cost[j][i]);
                    }
                }
            }
        }
        int ans = INF, pos = 0;
        for(int i = 0; i < n; i++)
        {
            if(ans > dp[(1 << n) - 1][i] || (ans == dp[(1 << n) - 1][i] && s[i] < s[pos]))  //找到字典序最小的前缀子串
            {
                ans = dp[(1 << n) - 1][i];
                pos = i;
            }
            dna = s[pos];
        }
        dfs(pos, (1 << n) - 1);
        cout << "Scenario #" << kase <<  ":" << endl;
        cout << dna << endl << endl;
    }
    return 0;
}
