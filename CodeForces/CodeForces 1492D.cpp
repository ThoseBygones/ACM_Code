/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2022-03-28
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    if(!k)
    {
        cout << "Yes" << endl;
        for(int i = 0; i < 2; i++)
        {
            for(int i = 0; i < b; i++)
                cout << '1';
            for(int i = 0; i < a; i++)
                cout << '0';
            cout << endl;
        }
    }
    else
    {
        if(a >= 1 && b >= 2 && a + b - 2 >= k)
        {
            cout << "Yes" << endl;
            string s = "11", t = "10";
            a--, b -= 2;
            for(int i = 1; i < k; i++)
            {
                if(a > 0)
                {
                    s += "0", t += "0";
                    a--;
                }
                else if(b > 0)
                {
                    s += "1", t += "1";
                    b--;
                }
            }
            s += "0", t += "1";
            while(a--)
                s += "0", t += "0";
            while(b--)
                s += "1", t += "1";
            cout << s << endl;
            cout << t << endl;
        }
        else
            cout << "No" << endl;
    }
    return 0;
}
