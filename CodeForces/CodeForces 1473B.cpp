/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-07-01
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: CodeForces
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

string solve(string str)
{
    for(int len = 1; len <= str.length(); len++)
    {
        bool flag = true;
        int pos = 0;
        while(pos < str.length() - len)
        {
            if(str.substr(pos, len) != str.substr(pos + len, len))
            {
                flag = false;
                break;
            }
            pos += len;
        }
        if(flag)
            return str.substr(0, len);
    }
    return str; //返回本身
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        string s, t;
        cin >> s >> t;
        string a = solve(s), b = solve(t);
        if(a == b)  //有相同的最小循环子串
        {
            int cnt1 = s.length() / a.length();
            int cnt2 = t.length() / b.length();
            int lcm = cnt1 * cnt2 / __gcd(cnt1, cnt2);
            for(int i = 0; i < lcm; i++)
                cout << a;
            cout << endl;
        }
        else
            cout << "-1" << endl;
    }
    return 0;
}
