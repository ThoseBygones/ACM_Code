/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-17
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: POJ
 *  Algorithm: 优先队列
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

priority_queue<int, vector<int>, greater<int> > pq;
int cnt[30];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    while(cin >> s)
    {
        if(s == "END")
            break;
        while(!pq.empty())
            pq.pop();
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '_')
                cnt[26]++;
            else
                cnt[s[i] - 'A']++;
        }
        for(int i = 0; i <= 26; i++)
        {
            if(cnt[i])
                pq.push(cnt[i]);
        }
        int ans = 0;
        while(pq.size() >= 2)
        {
            int sum = pq.top();
            pq.pop();
            sum += pq.top();
            pq.pop();
            ans += sum;
            pq.push(sum);
        }
        if(!ans)
            ans = s.length();
        cout << s.length() * 8 << " " << ans << " " << setprecision(1) << fixed << (double)s.length() * 8 / ans << endl;
    }
    return 0;
}
