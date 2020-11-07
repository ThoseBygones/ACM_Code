/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-11-03
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm:
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

queue<int> q;
vector<int> ans;

void solve(int k)
{
    int x = 0, cnt = 1;
    while(x < q.front())
    {
        if(cnt % k)
        {
            x = q.front();
            q.push(x);
        }
        q.pop();
        cnt++;
        //cout << x << " - " << q.front() << endl;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            q.push(i);
        int cnt = 1;
        while(q.size() > 3)
        {
            if(cnt & 1)
                solve(2);
            else
                solve(3);
            cnt++;
        }
        ans.clear();
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            ans.PB(tmp);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
            printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
    }
    return 0;
}
