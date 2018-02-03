#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    LL a,b;
    LL x,y,z;
    scanf("%I64d%I64d",&a,&b);
    scanf("%I64d%I64d%I64d",&x,&y,&z);
    LL sum1=x*2+y-a>0?x*2+y-a:0;
    LL sum2=y+z*3-b>0?y+z*3-b:0;
    printf("%I64d\n",sum1+sum2);
    return 0;
}
