/*
 ********************************************************************************
 *  Author: ThoseBygones
 *  Version: V1.0
 *  Date: 2018-05-13
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

int a[MAXN],b[MAXN];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    if(n==1)
    {
        puts("0");
        return 0;
    }
    int ans=INF;
    //第一种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    bool flag=true;
    b[1]--,b[n]--;
    int cnt=2;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    //第二种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    flag=true;
    b[1]--;
    cnt=1;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    //第三种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    flag=true;
    b[1]--,b[n]++;
    cnt=2;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    //第四种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    flag=true;
    b[n]--;
    cnt=1;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    //第五种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    flag=true;
    cnt=0;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    //第六种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    flag=true;
    b[n]++;
    cnt=1;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    //第七种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    flag=true;
    b[1]++,b[n]--;
    cnt=2;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    //第八种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    flag=true;
    b[1]++;
    cnt=1;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    //第九种情况
    for(int i=1; i<=n; i++)
        b[i]=a[i];
    flag=true;
    b[1]++,b[n]++;
    cnt=2;
    if((b[n]-b[1])%(n-1)==0)
    {
        int cha=(b[n]-b[1])/(n-1);
        for(int i=2; i<n; i++)
        {
            if(b[i]!=(b[1]+(i-1)*cha))
            {
                if(b[i]==(b[1]+(i-1)*cha+1) || b[i]==(b[1]+(i-1)*cha-1))
                    cnt++;
                else
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            ans=min(ans,cnt);
    }
    if(ans==INF)
        puts("-1");
    else
        printf("%d\n",ans);
    return 0;
}
