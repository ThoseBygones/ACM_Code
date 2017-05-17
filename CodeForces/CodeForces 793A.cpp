#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL a[100005];

int main()
{
    LL n,k;
    scanf("%I64d%I64d",&n,&k);
    for(int i=0; i<n; i++)
        scanf("%I64d",&a[i]);
    sort(a,a+n);
    LL cnt=0;
    for(int i=1; i<n; i++)
    {
        if((a[i]-a[i-1])%k)
        {
            puts("-1");
            return 0;
        }
        cnt+=(a[i]-a[0])/k;
    }
    printf("%I64d\n",cnt);
    return 0;
}
