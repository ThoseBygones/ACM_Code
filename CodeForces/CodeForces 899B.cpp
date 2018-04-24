/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-04-24
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

int m1[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int m2[] = {31,29,31,30,31,30,31,31,30,31,30,31};

int m[30];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d",&m[i]);
    bool flag=false;
    for(int i=0; i<12; i++)
    {
        if(m[0]==m1[i] || m[0]==m2[i])
        {
            if(m[0]==29)
                m2[i]=28;
            int j=i;
            int cnt=1;
            int pos=0;
            while(true)
            {
                pos++;
                j++;
                j%=12;
                if(cnt==n)
                {
                    flag=true;
                    break;
                }
                if(m[pos]==m1[j] || m[pos]==m2[j])
                {
                    if(m[pos]==29)
                        m2[1]=28;
                }
                else
                    break;
                cnt++;
            }
        }
        if(flag)
            break;
    }
    puts(flag?"Yes":"No");
    return 0;
}
