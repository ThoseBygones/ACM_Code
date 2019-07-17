/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:2019-07-05
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: HDU
 *  Algorithm: BFS + STL Map
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

//#include <bits/stdc++.h>  //For CodeForces only

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
#define MAXN 1505

typedef pair<string, int> PSI;

int n,q;
map<string,int> n2i;
map<int,string> i2n;
vector<int> G[MAXN<<1]; //人数应该是两倍
vector<PSI> ans;
int vis[MAXN<<1];

bool cmp(PSI a, PSI b)
{
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

void bfs(int x)
{
    memset(vis,0,sizeof(vis));
    queue<PII> q;
    vis[x] = 1;
    q.push(MP(x,0));
    while(!q.empty())
    {
        PII nd = q.front();
        q.pop();
        int u = nd.first;
        int dep = nd.second;
        if(dep == 2)
        {
            //cout << i2n[u] << endl;
            ans.PB(MP(i2n[u],vis[u]));
        }
        else
        {
            for(int i=0; i<G[u].size(); i++)
            {
                int v = G[u][i];
                if(!vis[v])
                    q.push(MP(v,dep+1));
                vis[v]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int kase = 1;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        string str1,str2;
        int id = 1;
        n2i.clear();
        i2n.clear();
        for(int i=0; i<2*n; i++)
            G[i].clear();
        ans.clear();
        while(n--)
        {
            cin >> str1 >> str2;
            if(!n2i[str1])
            {
                n2i[str1] = id;
                i2n[id++] = str1;
            }
            int u = n2i[str1];
            if(!n2i[str2])
            {
                n2i[str2] = id;
                i2n[id++] = str2;
            }
            int v = n2i[str2];
            //cout << u << " " << v << endl;
            G[u].PB(v);
            G[v].PB(u);
        }
        cout << "Case " << kase++ << ":" << endl;
        for(int i=0; i<q; i++)
        {
            ans.clear();
            string str;
            cin >> str;
            int u = n2i[str];
            bfs(u);
            sort(ans.begin(),ans.end(),cmp);
            int sz = ans.size();
            if(sz)
            {
                cout << ans[0].first;
                for(int i=1; i<sz; i++)
                {
                    if(ans[i].second == ans[0].second)
                        cout << " " << ans[i].first;
                    else
                        break;
                }
                cout << endl;
            }
            else
                cout << "-" << endl;
        }
    }
    return 0;
}
