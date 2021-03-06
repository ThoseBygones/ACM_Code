/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-23
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

map <string, set <string> > mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int num;
    string name,str;
    for(int i=0; i<n; i++)
    {
        cin >> name >> num;
        while(num--)
        {
            cin >> str;
            reverse(str.begin(),str.end());
            mp[name].insert(str);
        }
    }
    cout << mp.size() << endl;
    for(map<string,set<string> >::iterator it=mp.begin(); it!=mp.end(); it++)
    {
        set <string> st=it->second,ans;
        for(set<string>::iterator i=st.begin(); i!=st.end(); i++)
        {
            bool flag=false;
            for(set<string>::iterator j=st.begin(); j!=st.end(); j++)
            {
                if((*i).size()<(*j).size())
                {
                    if((*i)==(*j).substr(0,(*i).size()))
                       flag=true;
                }
            }
            if(!flag)
                ans.insert((*i));
        }
        cout << it->first << " " << ans.size() << " ";
        for(set<string>::iterator i=ans.begin(); i!=ans.end(); i++)
        {
            string str=*i;
            reverse(str.begin(),str.end());
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}
