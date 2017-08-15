#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

LL getSum(LL val)
{
    LL sum=0;
    while(val)
    {
        sum+=val%10;
        val/=10;
    }
    return sum;
}

int main()
{
    LL n,s;
    scanf("%I64d%I64d",&n,&s);
    LL l=0,r=n;
    LL ans=0;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(mid-getSum(mid)<s)
            l=mid+1;
        else
            r=mid-1;
    }
    //cout << l << " " << getSum(l) << endl;
    if(l-getSum(l)<s)
        puts("0");
    else
        printf("%I64d\n",n-l+1);
    return 0;
}
