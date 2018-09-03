/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-09-03
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    queue<LL> q;
    deque<LL> dq;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        LL x;
        cin >> x;
        q.push(x);
    }
    while(!q.empty())
    {
        LL x=q.front();
        //cout << x << endl;
        q.pop();
        if(dq.empty())
            dq.push_back(x);
        else
        {
            if(x==dq.front()*3)
                dq.push_front(x);
            else if(x*2==dq.front())
                dq.push_front(x);
            else if(x==dq.back()*2)
                dq.push_back(x);
            else if(x*3==dq.back())
                dq.push_back(x);
            else
                q.push(x);
        }
    }
    while(!dq.empty())
    {
        LL x=dq.front();
        dq.pop_front();
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
