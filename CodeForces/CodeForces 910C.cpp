/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-12
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
#define MAXN 1005

string num[MAXN];

map <char,LL> w;    //每个字母的权值
set <char> s;   //不能作为前导零的字母集合
vector <pair<LL,char> > v;
map <char,int> mp;  //每个字母最终被赋予的权值

LL pow10[20];

void init()
{
    pow10[0]=1;
    for(int i=1; i<20; i++)
        pow10[i]=pow10[i-1]*10;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> num[i];
        s.insert(num[i][0]);
        int len=num[i].length();
        for(int j=0; j<len; j++)
            w[num[i][j]]+=pow10[len-j-1];
    }
    for(int i=0; i<10; i++)
    {
        if(w[i+'a'])
            v.PB(MP(w[i+'a'],i+'a'));
    }
    sort(v.begin(),v.end());
    int id=1;
    bool flag=true;
    for(vector<pair<LL,char> >::reverse_iterator rit=v.rbegin(); rit!=v.rend(); rit++)
    {
        if(!s.count(rit->second) && flag)
        {
            mp[rit->second]=0;
            flag=false;
        }
        else
            mp[rit->second]=id++;
        //cout << rit->second << " -> " << mp[rit->second] << endl;
    }
    LL sum=0;
    for(int i=0; i<n; i++)
    {
        int len=num[i].size();
        for(int j=0; j<len; j++)
            sum+=mp[num[i][j]]*pow10[len-j-1];
    }
    cout << sum << endl;
    return 0;
}
