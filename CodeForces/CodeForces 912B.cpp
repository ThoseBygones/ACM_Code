#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    if(k==1)
        printf("%I64d\n",n);
    else
    {
        LL cnt=0;
        while(n)
        {
            n>>=1;
            cnt++;
        }
        printf("%I64d\n",(1LL<<cnt)-1);
    }
    return 0;
}
