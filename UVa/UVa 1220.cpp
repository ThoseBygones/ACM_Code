/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-21
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: UVa
 *  Algorithm: 树形dp
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

const int MAXN = 205;

/* 方法一 */

vector<int> G[MAXN];
unordered_map<string, int> mp;
//map<string, int> mp;
int dp[2][MAXN];    //dp[0/1][u]表示以结点u为根结点的子树，不取/取结点u时的最大结点数

void dfs(int u)
{
    dp[0][u] = 0;
    dp[1][u] = 1;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v);
        dp[0][u] += max(dp[0][v], dp[1][v]);    //该结点不取，子结点取或者不取选最大的结果
        dp[1][u] += dp[0][v];   //该结点取，子结点不能取
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str1, str2;
    while(cin >> n && n)
    {
        mp.clear();
        for(int i = 0; i <= n; i++)
            G[i].clear();
        int cnt = 0;
        cin >> str1;
        mp[str1] = ++cnt;
        for(int i = 1; i < n; i++)
        {
            cin >> str1 >> str2;
            if(!mp[str1])
                mp[str1] = ++cnt;
            if(!mp[str2])
                mp[str2] = ++cnt;
            G[mp[str2]].emplace_back(mp[str1]);
        }
        bool flag = true;
        dfs(1);
        cout << max(dp[0][1], dp[1][1]) << " ";
        for(int u = 1; u <= n; u++)
        {
            if(dp[0][u] > dp[1][u]) //结点u不取的情况比取了的更优
            {
                for(int i = 0; i < G[u].size(); i++)
                {
                    int v = G[u][i];
                    if(dp[0][v] == dp[1][v])
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(flag && dp[0][1] != dp[1][1])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}


/* 方法二 */

vector<int> G[MAXN];
unordered_map<string, int> mp;
//map<string, int> mp;
int dp[2][MAXN];    //dp[0/1][u]表示以结点u为根结点的子树，不取/取结点u时的最大结点数
int uni[2][MAXN];   //uni[0/1][u]表示以结点u为根结点的子树，不取/取结点u时的最优解方案是否唯一
void dfs(int u)
{
    dp[0][u] = 0, dp[1][u] = 1;
    uni[0][u] = uni[1][u] = true;
    for(int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i];
        dfs(v);
        dp[0][u] += max(dp[0][v], dp[1][v]);    //该结点不取，子结点取或者不取选最大的结果
        dp[1][u] += dp[0][v];   //该结点取，子结点不能取
        if(dp[0][v] == dp[1][v])    //子结点存在可取可不取的
            uni[0][u] = false;  //该结点不取肯定存在多种方案
        if(!uni[0][v])  //子结点不取的时候方案都不是唯一的
            uni[1][u] = false;  //那该结点取的时候肯定也存在多种方案
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string str1, str2;
    while(cin >> n && n)
    {
        mp.clear();
        for(int i = 0; i <= n; i++)
            G[i].clear();
        int cnt = 0;
        cin >> str1;
        mp[str1] = ++cnt;
        for(int i = 1; i < n; i++)
        {
            cin >> str1 >> str2;
            if(!mp[str1])
                mp[str1] = ++cnt;
            if(!mp[str2])
                mp[str2] = ++cnt;
            G[mp[str2]].emplace_back(mp[str1]);
        }
        bool flag = true;
        dfs(1);
        if(dp[0][1] > dp[1][1] && uni[0][1])
            cout << dp[0][1] << " Yes" << endl;
        else if(dp[0][1] < dp[1][1] && uni[1][1])
            cout << dp[1][1] << " Yes" << endl;
        else
            cout << max(dp[0][1], dp[1][1]) << " No" << endl;
    }
    return 0;
}

/*
4
Jack
Alice Jack
Bob Alice
Dave Bob
*/
