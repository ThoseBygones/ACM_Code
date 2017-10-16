#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 50005
#define LL long long
#define INF 1e18

/*
计算方案的优劣性：
方案一：risk1 = sumw - w1 - s1，risk2 = sumw - w1 - w2 - s2，1在2下方
方案二：risk1' = sumw - w1 - w2 - s1，risk2' = sumw - w2 - s2，2在1下方
比较后知wi+si越大的应该在越下方
*/

struct Cow
{
    int w;
    int s;
} cow[MAXN];

bool cmp(const Cow &x,const Cow &y)
{
    return x.w+x.s>y.w+y.s;
}

int main()
{
    int n;
    scanf("%d",&n);
    LL sum=0;
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&cow[i].w,&cow[i].s);
        sum+=cow[i].w;
    }
    sort(cow,cow+n,cmp);
    LL ans=-INF;
    for(int i=0; i<n; i++)
    {
        sum-=cow[i].w;
        ans=max(ans,sum-cow[i].s);
    }
    printf("%lld\n",ans);
    return 0;
}
