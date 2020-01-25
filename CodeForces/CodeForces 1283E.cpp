/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2020-01-25
 *  Subject: ACM-ICPC
 *  Language: C/C++11
 *  OJ: CodeForces
 *  Algorithm: 贪心
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
#define MAXN 200005

int vis1[MAXN],vis2[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        vis1[x]++;
        vis2[x]++;
    }
    int Min = 0;
    for(int i=1; i<=n; i++)
    {
        if(vis1[i]) //第i间房子有人，则第i间房和的第i+2间房的人去第i+1间房
        {
            Min++;
            i += 2;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(vis2[i])
        {
            if(!vis2[i-1])   //第i-1间房没人，则移过去一人
            {
                vis2[i]--;
                vis2[i-1]++;
            }
            if(vis2[i] > 1) //如果第i间房的人超过两个，则一个人移到第i+1间房
            {
                vis2[i]--;
                vis2[i+1]++;
            }
        }
    }
    int Max = 0;
    for(int i=0; i<=n+1; i++)
    {
        if(vis2[i])
            Max++;
    }
    printf("%d %d\n",Min,Max);
    return 0;
}
