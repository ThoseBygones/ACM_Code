/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date:
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ:
 *  Algorithm:
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

string p;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(char i = 'a'; i < 'a' + k; i++)
    {
        p += i;
        for(char j = i + 1; j < 'a' + k; j++)
        {
            p += i;
            p += j;
        }
    }
    int len = p.size();
    for(int i = 0; i < n; i++)
        cout << p[i % len];
    cout << endl;
    return 0;
}
