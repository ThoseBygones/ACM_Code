#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    LL x=n/((1+k)*2);
    LL a=x;
    LL b=k*x;
    LL c=n-a-b;
    printf("%I64d %I64d %I64d\n",a,b,c);
    return 0;
}
