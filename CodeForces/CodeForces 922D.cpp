/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-02-27
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
#define MAXN 100005

struct String
{
    int id;
    int cnts,cnth;  //字符串中s和h的数量
    string s;
} str[MAXN];

bool cmp(String x,String y) //两个字符串接起来的时候，顺序不影响两子串内部原本能组成的"sh"数量，顺序影响前面子串中's'与后面子串中'h'能组成的"sh"数量
{
    return (LL)x.cnts*y.cnth>(LL)y.cnts*x.cnth;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> str[i].s;
        str[i].id=i;
        str[i].cnts=str[i].cnth=0;
        int len=str[i].s.length();
        for(int j=0; j<len; j++)
        {
            if(str[i].s[j]=='s')
                str[i].cnts++;
            else
                str[i].cnth++;
        }
    }
    sort(str,str+n,cmp);
    LL ans=0,sum=0;
    for(int i=0; i<n; i++)
    {
        int len=str[i].s.length();
        for(int j=0; j<len; j++)
        {
            if(str[i].s[j]=='s')
                sum++;
            else
                ans+=sum;
        }
    }
    cout << ans << endl;
    return 0;
}
