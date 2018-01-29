#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005
#define LL long long

LL sum[MAXN];

LL getP(LL val)
{
    LL temp=val;
    while(temp)
    {
        val=val*10+temp%10;
        temp/=10;
    }
    return val;
}

int main()
{
    int n;
    LL p;
    scanf("%d%I64d",&n,&p);
    for(int i=1; i<=1e5; i++)
        sum[i]=(sum[i-1]+getP(i))%p;
    printf("%d\n",sum[n]);
    return 0;
}
