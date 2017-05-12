#include <iostream>
#include <cstdio>
#include <cmath>
#define LL long long
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int kase=1;
    while(t--)
    {
        LL m;
        scanf("%lld",&m);
        LL k=m;
        //LL n=k*(k+1)/2;
        LL left=0,right=sqrt(3*m);
        while(left<=right)
        {
            LL mid=(left+right)>>1;
            if(mid*(mid+1)/2>m)
                right=mid-1;
            else
                left=mid+1;
        }
        //printf("%lld %lld\n",right,right*(right+1)/2);
        printf("Case #%d: %lld\n",kase++,right*(right+1)/2);
    }
    return 0;
}
