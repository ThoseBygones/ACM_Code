/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2021-08-03
 *  Subject: ACM-ICPC
 *  Language: C/C++14
 *  OJ: HDU
 *  Algorithm: STL
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

map<string, bool> mp1, mp2;
vector<string> tmp, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    while(cin >> a >> b >> c)
    {
        mp1.clear(), mp2.clear();
        tmp.clear(), ans.clear();
        string name;
        for(int i = 0; i < a; i++)
        {
            cin >> name;
            mp1[name] = true;
        }
        for(int i = 0; i < b; i++)
        {
            cin >> name;
            if(mp1[name])
                tmp.PB(name);
            //cout << name << endl;
        }
        for(int i = 0; i < c; i++)
        {
            cin >> name;
            mp2[name] = true;
        }
        for(auto &name: tmp)
        {
            if(mp2[name])
                continue;
            else
                ans.PB(name);
            //cout << name << endl;
        }
        if(ans.size())
        {
            for(int i = 0; i < ans.size(); i++)
            {
                if(i == ans.size() - 1)
                    cout << ans[i] << endl;
                else
                    cout << ans[i] << " ";
            }
        }
        else
            cout << "No enemy spy" << endl;
    }
    return 0;
}
