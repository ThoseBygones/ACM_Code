/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2019-01-10
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm:
 ********************************************************************************
 *  Algo-Description:
 ********************************************************************************
 */

#include <bits/stdc++.h>  //For CodeForces only
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
#define MAXN 105

string str[MAXN<<1];
string ans;
int n,m;
map<string,int> mp;

bool check(string s)
{
    for(int i = 0; i < m; i++)
    {
        bool fit = false;
        int len = str[i].length();
        if(s.substr(0,len) == str[i])
            fit = true;
        else if(s.substr(n-len) == str[i])
            fit = true;
        if(!fit)
            return false;
    }
    for(int i = 0; i < m; i++)
    {
        int len = str[i].length();
        if(s.substr(0,len) == str[i])
        {
            if(!mp[str[i]])
            {
                ans += "P";
                mp[str[i]]++;
            }
            else
                ans += "S";
        }
        else
            ans += "S";
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    m = 2 * n - 2;
    for(int i = 0; i < m; i++)
        cin >> str[i];
    bool flag = false;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(str[i].length() == n - 1 && str[j].length() == 1)
            {
                if(check(str[i]+str[j]))
                {
                    cout << ans << endl;
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            break;
    }
    return 0;
}
