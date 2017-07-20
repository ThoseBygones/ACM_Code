#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005
#define LL long long

int main()
{
    LL m,b;
    scanf("%I64d%I64d",&m,&b);
    LL ans=0;
    for(int i=0; i<=b; i++)
    {
        LL r=(b-i)*m;
        LL sum=((r+1)*r/2)*(i+1)+(i*(i+1)/2)*(r+1);
        ans=max(ans,sum);
    }
    printf("%I64d\n",ans);
    return 0;
}
