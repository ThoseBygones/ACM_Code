/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-03-20
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
#define MAXN 200005

int a[MAXN];
bool vis[MAXN];
stack <int> s;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int idx=1;
    for(int i=1; i<=k; i++)
    {
        scanf("%d",&a[i]);
        s.push(a[i]);
        vis[a[i]]=true;
        while(!s.empty() && s.top()==idx)
        {
            s.pop();
            idx++;
        }
    }
    while((!s.empty() && idx<s.top()) || idx<=n)
    {
        int temp;
        if(!s.empty())  //例如：3 2 1 5，此时栈中还有5，需要构造4，才能把7 6丢进去
            temp=s.top()-1;
        else    //否则直接把剩下的数从大到小丢进去，例如：3 2 1，此时直接丢7 6 5 4进去
            temp=n;
        for(int i=temp; i>=idx; i--)
        {
            if(vis[i])
            {
                puts("-1");
                return 0;
            }
            s.push(i);
            a[++k]=i;
            vis[i]=true;
        }
        while(!s.empty() && s.top()==idx)
        {
            s.pop();
            idx++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(i!=n)
            printf("%d ",a[i]);
        else
            printf("%d\n",a[i]);
    }
    return 0;
}
