#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define LL long long

int main()
{
    int kase=1;
    LL n,k;
    while(~scanf("%lld%lld",&n,&k))
    {
        printf("Case #%d: ",kase++);
        if(k<=n)
            printf("%lld\n",k);
        else
        {
            if((k-n)%(2*n-2)==n-1)
                printf("%lld\n",n-1);
            else if((k-n)%(2*n-2)==0)
                printf("%lld\n",n);
            else
                printf("%lld\n",(k-n)%(n-1));
        }
    }
    return 0;
}
