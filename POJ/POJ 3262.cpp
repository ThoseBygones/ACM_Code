#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100005
#define LL long long

struct Cow
{
    int t;
    int d;
} cow[MAXN];

bool cmp(Cow a,Cow b)
{
    return a.t*b.d<b.t*a.d;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%d%d",&cow[i].t,&cow[i].d);
    sort(cow,cow+n,cmp);
    LL tempsum=0;
    LL ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=tempsum*(LL)cow[i].d;
        tempsum+=2*cow[i].t;
    }
    printf("%lld\n",ans);
    return 0;
}
