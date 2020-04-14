/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-04-07
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
#define MAXM 1000005

vector<int> ans;
int a[MAXN];
map<int, bool> vis;  //此人是否已经访问过office
bool in[MAXM];  //此人此时是否在office内

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int cnt = 0;
    int pos = 0;
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > 0)    //进入记录
        {
            if(in[a[i]] || vis[a[i]])   //此人还在office内却还要进入，或此人已经进出过这个office，则记录有误
            {
                puts("-1");
                return 0;
            }
            cnt++;
            vis[a[i]] = true;
            in[a[i]] = true;
        }
        else    //出门记录
        {
            if(!in[-a[i]])  //此人已经不在office内，却还要出去，则记录有误
            {
                puts("-1");
                return 0;
            }
            cnt--;
            in[-a[i]] = false;
        }
        if(!cnt)    //办公室没人了，划分
        {
            vis.clear();
            ans.PB(i - pos);
            pos = i;
        }
    }
    if(cnt)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], (i == ans.size() - 1 ? '\n' : ' '));
    return 0;
}
