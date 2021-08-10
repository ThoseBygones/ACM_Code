/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-10
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 拓扑排序 + DFS
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

const int MAXN = 30;

vector<int> G[MAXN];
vector<int> ans;
int ind[MAXN];  //入度
bool vis[MAXN]; //某个字母是否存在

void init()
{
    ans.clear();
    for(int i = 0; i < 26; i++)
        G[i].clear();
    memset(ind, 0, sizeof(ind));
    memset(vis, false, sizeof(vis));
}

void print()
{
    for(int i = 0; i < ans.size(); i++)
        cout << char(ans[i] + 'a');
    cout << endl;
}

void dfs(int x, int n)
{
    if(x > n)
        print();
    for(int u = 0; u < 26; u++)
    {
        if(!ind[u] && vis[u])   //如果入度为0且该字母出现了
        {
            vis[u] = false;
            for(int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i];
                ind[v]--;
            }
            ans.PB(u);
            dfs(x + 1, n);
            //还原现场
            ans.pop_back();
            for(int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i];
                ind[v]++;
            }
            vis[u] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str, lim;
    while(getline(cin, str))
    {
        init();
        int cnt = 0;    //字母个数
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] != ' ')
            {
                vis[str[i] - 'a'] = true;
                cnt++;
            }
        }
        getline(cin, lim);
        for(int i = 0; i < lim.length(); i += 4)
        {
            int u = lim[i] - 'a', v = lim[i + 2] - 'a';
            G[u].PB(v);
            ind[v]++;
        }
        dfs(1, cnt);
        cout << endl;
    }
    return 0;
}
